#include "qormimage.h"

#include <QtCore>
#include <QPainter>

QOrmImage::QOrmImage(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    //setFlags(QQuickItem::ItemHasContents);
}

QPixmap QOrmImage::pixmap() const
{
    return m_pixmap;
}

void QOrmImage::setPixmap(QPixmap value)
{
    m_pixmap = value;

    emit pixmapChanged(m_pixmap);

    update();
}

void QOrmImage::paint(QPainter *painter)
{
    //painter->drawPixmap(boundingRect(), m_pixmap, boundingRect());
    painter->drawPixmap(x(),y(), width(), height(), m_pixmap);
}
