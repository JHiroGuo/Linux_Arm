#-------------------------------------------------
#
# Project created by QtCreator 2019-03-22T22:24:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


if(contains(DEFINES,TYPE_TQIMX6Q)){
    INCLUDEPATH += /usr/local/arm-opencv/include \
                /usr/local/arm-opencv/include/opencv2

    LIBS +=-L/usr/local/arm-opencv/lib/libopencv_highgui.so \
        /usr/local/arm-opencv/lib/libopencv_core.so \
        /usr/local/arm-opencv/lib/libopencv_imgproc.so \
        /usr/local/arm-opencv/lib/libopencv_imgcodecs.so
}else{

    INCLUDEPATH += /usr/include/opencv
    LIBS += -L/usr/lib -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_datasets -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_line_descriptor -lopencv_optflow -lopencv_video -lopencv_plot -lopencv_reg -lopencv_saliency -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_rgbd -lopencv_viz -lopencv_surface_matching -lopencv_text -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_xobjdetect -lopencv_objdetect -lopencv_ml -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core

}

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    OpenCV/opencvtools.cpp

HEADERS  += mainwindow.h \
    OpenCV/opencvtools.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
