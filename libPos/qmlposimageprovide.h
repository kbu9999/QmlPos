#ifndef QMLPOSIMAGEPROVIDE_H
#define QMLPOSIMAGEPROVIDE_H

#include <QtQuick/QQuickImageProvider>

class QmlPosImageProvider : public QQuickImageProvider
{
public:
    QmlPosImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // QMLPOSIMAGEPROVIDE_H
