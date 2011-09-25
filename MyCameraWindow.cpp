
#include "MyCameraWindow.h"

MyCameraWindow::MyCameraWindow(CvCapture *cam, QWidget *parent) : QWidget(parent) {
    camera = cam;
    QVBoxLayout *layout = new QVBoxLayout;
    cvwidget = new QOpenCVWidget(this);
    layout->addWidget(cvwidget);
    setLayout(layout);
    resize(50, 50);

    but = new QPushButton("Take pic");

    layout->addWidget(but);

    connect(but, SIGNAL(clicked()), this, SLOT(takepic()));


    startTimer(100);  // 0.1-second timer
 }

void MyCameraWindow::timerEvent(QTimerEvent*) {
    IplImage *image=cvQueryFrame(camera);
    cvwidget->putImage(image);
}


void MyCameraWindow::takepic() {
    IplImage *image=cvQueryFrame(camera);
    cvSaveImage(QTime::currentTime().toString().toLatin1() + ".jpg", image);
}
