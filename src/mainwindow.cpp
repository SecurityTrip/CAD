#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Canvas *canvas = new Canvas(this);
    setCentralWidget(canvas);
    qDebug() << "Canvas initialized and set as central widget.";
}

MainWindow::~MainWindow()
{
    delete ui;
}
