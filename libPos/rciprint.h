#ifndef RCIPRINT_H
#define RCIPRINT_H

#include<QtCore>
#include <QtQuick/QQuickItemGrabResult>

class RCIPrint : public QObject
{
    Q_OBJECT
public:
    explicit RCIPrint();

signals:

public slots:
    Q_INVOKABLE void print(QQuickItemGrabResult *result);
};

#endif // RCIPRINT_H
