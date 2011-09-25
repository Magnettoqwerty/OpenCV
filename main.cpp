#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <assert.h>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include "MyCameraWindow.h"

int main(int argc, char **argv) {
    CvCapture * camera = cvCreateCameraCapture(0);
    //The function cvCreateCameraCapture allocates and initialized the CvCapture structure for reading a video stream from the camera.
    assert(camera);
    //Expression to be evaluated. If this expression evaluates to 0, this causes an assertion failure that terminates the program.
    IplImage * image=cvQueryFrame(camera);
    //The function cvQueryFrame grabs a frame from camera or video file, decompresses and returns it.
    assert(image);


    printf("Image depth=%i\n", image->depth);
    printf("Image nChannels=%i\n", image->nChannels);
    printf("Image size = %i x %i", image->width, image->height);

    QApplication app(argc, argv);
    MyCameraWindow *mainWin = new MyCameraWindow(camera);
    mainWin->setWindowTitle("OpenCV --> QtImage");
    mainWin->show();    
    int retval = app.exec();
    
    cvReleaseCapture(&camera);
    
    return retval;
}

