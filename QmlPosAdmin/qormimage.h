#ifndef QORMIMAGE_H
#define QORMIMAGE_H

#include <QPixmap>
#include <QQuickPaintedItem>

class QOrmImage : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap NOTIFY pixmapChanged)
public:
    QOrmImage(QQuickItem *parent = 0);

    QPixmap pixmap() const;

signals:
    void pixmapChanged(QPixmap value);

public slots:
    void setPixmap(QPixmap value);

private:
    QPixmap m_pixmap;

    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);
};

#endif // QORMIMAGE_H
