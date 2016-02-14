#include "imageprocess.h"

#include <QtMultimedia>
#include <QtQml>
#include <QtQuick>

ImageProcess::ImageProcess(QObject *parent) : QObject(parent)
{
}

QObject *ImageProcess::camera() const
{
    return m_camera;
}

QPixmap ImageProcess::image() const
{
    return m_image;
}

void ImageProcess::setCamera(QObject *cameraObject)
{
    QVariant cameraVariant = cameraObject->property("mediaObject");
    QCamera *camera = qvariant_cast<QCamera*>(cameraVariant);
    QMediaService *service = camera->service();
    QMediaControl *control = service->requestControl(QCameraImageCaptureControl_iid);
    QCameraImageCaptureControl *captureControl = qobject_cast<QCameraImageCaptureControl*>(control);

    connect(captureControl, SIGNAL(imageCaptured(int,QImage)), this, SLOT(processView(int,QImage)));

    emit cameraChanged(cameraObject);
}

void ImageProcess::processView(int id, const QImage &image)
{
    Q_UNUSED(id);
    m_image = QPixmap::fromImage(image);

    emit imageChanged(m_image);
}

