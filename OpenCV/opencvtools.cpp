#include "opencvtools.h"
#include <qdebug.h>
#include <iostream>

#include <stdio.h>

using namespace cv;
using namespace std;

#define IMG_SCALE 0.5

OpenCVTools::OpenCVTools(QObject *parent) : QObject(parent)
{

}


// Test Get CvImage
void OpenCVTools::GetCVImage(QImage &img,std::string imgPath)
{
    if(imgPath.empty())
        imgPath = ":/images/photo.jpg";

    cv::Mat image;
    image = cv::imread(imgPath,cv::IMREAD_COLOR);

    cv::Mat rgbImage;

    cv::cvtColor(image,rgbImage,CV_BGR2RGB);

    img = QImage((const unsigned char*)rgbImage.data,
                 rgbImage.cols,
                 rgbImage.rows,
                 rgbImage.cols*rgbImage.channels(),
                 QImage::Format_RGB888);

}

void OpenCVTools::GetOpenCVImage(QImage &cVimg,QImage qimg)
{

    cv::Mat image = QImage2cvMat(qimg);
    if(!image.data)
    {
        qDebug()<<"Can not imread image";
        return;
    }

    cv::Mat img_scale;
    ScaleCvImage(image,img_scale,IMG_SCALE);

    cv::Mat img_gray;
    cv::cvtColor(img_scale,img_gray,CV_BGR2GRAY);


    cv::Mat img_canny;
    cv::Canny(img_gray,img_canny,255,255);
    img_gray = img_canny;

   // std::cout<< "img_gray = " << endl << " " << img_gray << endl << endl;
    cVimg = cvMat2QImage(img_gray);

}

void OpenCVTools::ScaleCvImage(cv::Mat inputImg, cv::Mat &outputImg, double dScale)
{
    Size size = Size(inputImg.cols*dScale,inputImg.rows*dScale);
    outputImg = cv::Mat(size,dScale);
    cv::resize(inputImg,outputImg,size);
}

QImage OpenCVTools::cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
cv::Mat OpenCVTools::QImage2cvMat(QImage image)
{
    cv::Mat mat;
    qDebug() << image.format();
    switch(image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}
