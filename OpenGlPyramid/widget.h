#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget, protected  QOpenGLFunctions
{
    Q_OBJECT

public:
Widget(QWidget *parent = 0);
~Widget();

GLfloat xAngle, yAngle, zAngle;

GLenum polygonMode;
GLenum shadeMode;


protected:
    void keyPressEvent(QKeyEvent* event);


private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
public slots:

};
#endif // WIDGET_H
