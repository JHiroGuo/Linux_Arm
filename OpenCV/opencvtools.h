#ifndef OPENCVTOOLS_H
#define OPENCVTOOLS_H

#include <QObject>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>

class OpenCVTools : public QObject
{
    Q_OBJECT
public:
    explicit OpenCVTools(QObject *parent = 0);


    static void GetCVImage(QImage &img,std::string imgPath);

    static void GetOpenCVImage(QImage &cVimg,QImage qimg);

    static cv::Mat QImage2cvMat(QImage image);

    static QImage cvMat2QImage(const cv::Mat& mat);

    static void ScaleCvImage(cv::Mat inputImg, cv::Mat &outputImg, double dScale);

signals:

public slots:
};

#endif // OPENCVTOOLS_H
