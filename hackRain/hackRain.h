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
    int x;  // �괮��ʼ��x
    int y;  // �괮��ʼ��y
    QString str;  // ��������ִ�
};

class hackRain : public QWidget
{
    Q_OBJECT

public:
    hackRain(QWidget *parent = Q_NULLPTR);

public:
    void initRain();
    // ��������ɫ
    void render();
    // ����λ��
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
