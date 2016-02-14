#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtCore>
#include <QPixmap>

class ImageProcess : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* camera READ camera WRITE setCamera NOTIFY cameraChanged)
    Q_PROPERTY(QPixmap image READ image NOTIFY imageChanged)
public:
    explicit ImageProcess(QObject *parent = 0);

    QObject *camera() const;
    QPixmap image() const;


signals:
    void cameraChanged(QObject *camera);
    void imageChanged(QPixmap value);

public slots:
    void setCamera(QObject *cameraObject);

protected slots:
    void processView(int id, const QImage&image);

private:
    QObject *m_camera;
    QPixmap m_image;
};

#endif // IMAGEPROCESS_H
