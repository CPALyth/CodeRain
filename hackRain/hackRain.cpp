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
{   // ���� [beg,end)�ڵ�һ��intֵ
    return QRandomGenerator::global()->bounded(beg, end);
}


hackRain::hackRain(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // �ޱ߿򴰿�, ��ɫ����
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:black;");

    // ʹ����ȫ��
    m_Screen = QDesktopWidget().screenGeometry();   // ��ȡ���� QRect(0,0 2560x1440)
    this->resize(m_Screen.width(), m_Screen.height());  // ��ڴ�С�������Сһ��

    // ����m_rains
    initRain();

    m_painter = new QPainter(this);
    m_painter->setFont(QFont("Times", CharH));

    QTimer* timer = new QTimer(this);
    timer->start(50); // ÿ��50ms�����ź�
    connect(timer, &QTimer::timeout, [=]() {
        QWidget::update();  // �ػ滭��,����paintEvent()
    });
}

void hackRain::initRain()
{
    for (int i = 0; i < RainNum; i++) {
        m_rains[i].x = rnd(0, m_Screen.width());
        m_rains[i].y = rnd(0, m_Screen.height());
        for (int j = 0; j < StrNum; j++) {
            int type = rnd(0, 3);   // 0����,1Сд��ĸ,2��д��ĸ
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
        m_rains[i].y += CharH * rnd(1, 3);   // ����1~2���ַ�
        // ������Ѿ���ȫ����, ���������������¸���
        if (m_rains[i].y >= m_Screen.height() + StrNum * CharH) {
            m_rains[i].x = rnd(0, m_Screen.width());
            m_rains[i].y = 0;
        }
        for (int j = 0; j < StrNum; j++) {
            QPen penGreen(QColor(0, 255 - 20 * j, 0));    // ��ɫ��ǳ
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
    qApp->quit();   // �ƶ����˳�
}
