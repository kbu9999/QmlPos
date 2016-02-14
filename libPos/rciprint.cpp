#include "rciprint.h"

#include <QtPrintSupport>

RCIPrint::RCIPrint() : QObject()
{
    QPrinter printer;
    printer.setPageSize(QPrinter::A4);
    //qDebug()<<printer.width()<<printer.height();
}

void RCIPrint::print(QQuickItemGrabResult *result)
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFileName("/tmp/file.pdf");

    QPainter p;
    p.begin(&printer);

    p.drawImage(0, 0, result->image());

    p.end();

    QDesktopServices::openUrl(QStringLiteral("/tmp/file.pdf"));
}

