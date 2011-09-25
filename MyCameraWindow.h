#ifndef MYCAMERAWINDOW_H_
#define MYCAMERAWINDOW_H_

#include <QWidget>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QPushButton>


class MyCameraWindow : public QWidget
{
    Q_OBJECT
    private:
        QOpenCVWidget *cvwidget;
        CvCapture *camera;
        QPushButton *but;
        
    public:
        MyCameraWindow(CvCapture *cam, QWidget *parent=0);
         
    protected:
        void timerEvent(QTimerEvent*);

    public slots:
        void takepic(void);
};


#endif /*MYCAMERAWINDOW_H_*/
