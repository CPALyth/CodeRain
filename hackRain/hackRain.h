#pragma once

#include <QtWidgets/QWidget>
#include "ui_hackRain.h"
#include <QMouseEvent> 
#include <QVector>

#define RainNum 200
#define StrNum 10
#define CharH 30

struct Rain
{
    int x;  // 雨串开始点x
    int y;  // 雨串开始点y
    QString str;  // 代码雨的字串
};

class hackRain : public QWidget
{
    Q_OBJECT

public:
    hackRain(QWidget *parent = Q_NULLPTR);

public:
    void initRain();
    // 给字体着色
    void render();
    // 更新位置
    void update();

private:
    Ui::hackRainClass ui;
    QRect m_Screen;
    Rain m_rains[RainNum];
    QPainter* m_painter;

private:
    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};
