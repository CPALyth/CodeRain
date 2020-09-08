#include "hackRain.h"

#include <QDesktopWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>
#include <QIcon>

int rnd(int beg, int end)
{   // 返回 [beg,end)内的一个int值
    return QRandomGenerator::global()->bounded(beg, end);
}


hackRain::hackRain(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 无边框窗口, 黑色背景
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:black;");

    // 使画布全屏
    m_Screen = QDesktopWidget().screenGeometry();   // 获取桌面 QRect(0,0 2560x1440)
    this->resize(m_Screen.width(), m_Screen.height());  // 令窗口大小和桌面大小一样

    // 构建m_rains
    initRain();

    m_painter = new QPainter(this);
    m_painter->setFont(QFont("Times", CharH));

    QTimer* timer = new QTimer(this);
    timer->start(50); // 每隔50ms发送信号
    connect(timer, &QTimer::timeout, [=]() {
        QWidget::update();  // 重绘画面,调用paintEvent()
    });
}

void hackRain::initRain()
{
    for (int i = 0; i < RainNum; i++) {
        m_rains[i].x = rnd(0, m_Screen.width());
        m_rains[i].y = rnd(0, m_Screen.height());
        for (int j = 0; j < StrNum; j++) {
            int type = rnd(0, 3);   // 0数字,1小写字母,2大写字母
            char ch;
            if (type == 0)
                ch = rnd('0', '9' + 1);
            else if (type == 1)
                ch = rnd('a', 'z' + 1);
            else
                ch = rnd('A', 'Z' + 1);
            m_rains[i].str.append(ch);
        }
    }
}

void hackRain::paintEvent(QPaintEvent* event)
{
    m_painter->begin(this);

    for (int i = 0; i < RainNum; i++) {
        m_rains[i].y += CharH * rnd(1, 3);   // 降落1~2个字符
        // 若雨滴已经完全落下, 则让它从上面重新复活
        if (m_rains[i].y >= m_Screen.height() + StrNum * CharH) {
            m_rains[i].x = rnd(0, m_Screen.width());
            m_rains[i].y = 0;
        }
        for (int j = 0; j < StrNum; j++) {
            QPen penGreen(QColor(0, 255 - 20 * j, 0));    // 颜色渐浅
            m_painter->setPen(penGreen);
            int x = m_rains[i].x;
            int y = m_rains[i].y - j * CharH;
            m_painter->drawText(x, y, m_rains[i].str.at(j));
        }
    }

    m_painter->end();
}

void hackRain::mouseMoveEvent(QMouseEvent* event)
{
    qApp->quit();   // 移动后退出
}
