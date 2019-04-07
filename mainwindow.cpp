#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QLabel>
#include <QVBoxLayout>

#include "OpenCV/opencvtools.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateUI();
}



void MainWindow::CreateUI()
{
     std::string imgPath = ":/images/photo.jpg";
     QString qStr = QString::fromUtf8(imgPath.c_str());
     QImage img ;
     img.load(qStr);

    QLabel *mLable = new QLabel(this);
    mLable->setScaledContents(true);
    mLable->setPixmap(QPixmap(QPixmap::fromImage(img)));

  //  mLable->resize(imageSize);

    // Get CVImage
    OpenCVTools::GetOpenCVImage(img,img);

    QLabel *cvLabel = new QLabel(this);
    cvLabel->setPixmap(QPixmap(QPixmap::fromImage(img)));
    cvLabel->setScaledContents(true);
   // cvLabel->resize(imageSize);

    // Set Layout
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(mLable);
    vBoxLayout->addWidget(cvLabel);

   QWidget *widget = new QWidget;
   widget->setLayout(vBoxLayout);



   setCentralWidget(widget);
}




MainWindow::~MainWindow()
{
    delete ui;
}
