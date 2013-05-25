#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generator.h"

extern double frameXleft;
extern double frameYleft;
extern double frameXright;
extern double frameYright;

extern double K_real;
extern double K_imag;

extern int maxIterations;

extern int Height;
extern int Width;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    double cX = ui->cenX->text().toDouble();
    double cY = ui->cenY->text().toDouble();
    long zoom = ui->zoom->text().toLong();

    maxIterations = ui->maxIter->text().toInt();
    K_real = ui->Kr->text().toDouble();
    K_imag = ui->Ki->text().toDouble();

    double xLen = (double)Width/zoom;
    double yLen = (double)Height/zoom;

    frameXleft = cX - xLen/2;
    frameXright = cX + xLen/2;
    frameYleft = cY - yLen/2;
    frameYright = cY + yLen/2;

    bool julia = ui->checkBox->isChecked();
    QImage img(Width, Height, QImage::Format_RGB888);
    Generator::generate(img, julia);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->setScaledContents(true);
    ui->label->show();
}
