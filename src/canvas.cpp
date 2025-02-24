#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Canvas::Canvas(QWidget *parent) : QWidget(parent), drawing(false) {
    qDebug() << "Canvas created.";
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (drawing) {
        painter.drawRect(QRect(startPoint, endPoint));
        qDebug() << "Drawing rectangle from" << startPoint << "to" << endPoint;
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        startPoint = event->pos();
        endPoint = startPoint;
        update();
        qDebug() << "Mouse pressed at" << startPoint;
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing) {
        endPoint = event->pos();
        update();
        qDebug() << "Mouse moved to" << endPoint;
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        drawing = false;
        endPoint = event->pos();
        update();
        qDebug() << "Mouse released at" << endPoint;
    }
}