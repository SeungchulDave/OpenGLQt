#include "widget.h"

#include <QApplication>
#include <GL/glut.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    Widget w;
    w.show();
    return a.exec();
}
