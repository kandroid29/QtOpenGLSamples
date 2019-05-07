#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QScreen>
#include <QtCore/QtMath>
#include "main.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize( 4 );
    format.setSamples(24);
    format.setVersion(3, 1);
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile( QSurfaceFormat::CoreProfile );

    ModernTriangle window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    return a.exec();
}
