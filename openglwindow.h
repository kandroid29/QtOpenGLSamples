#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions_3_1>

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE


class OpenGLWindow : public QWindow, protected QOpenGLFunctions_3_1
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();

    virtual void render(QPainter *painter);
    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

    public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_paint_device;
};

#endif // OPENGLWINDOW_H
