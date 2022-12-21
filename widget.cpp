#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    rectPosX = 0.0f;
    rectPosY = 0.0f;
    rectSize = 250;

    xStep = 55.0f;
    yStep = 5.0f;

    radius = 0.05;
    delta_theta = 2*M_PI/20;
    theta = 0.0;
    cord_length = 0.5;

    bEdge = GL_FALSE;

    setWindowTitle("OpenGL EdgeFlag3D");
    resize( 600, 600);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(timerFunction()));
    timer->start(1000/600);
}

Widget::~Widget()
{
}
void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0 , 0.0, 1.0);
}

void Widget::resizeGL(int w, int h)
{
    windowWidth = w;
    windowHeight = h;

    glViewport(0,0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho( -1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEdgeFlag(TRUE);

    glBegin(GL_TRIANGLES);
    if(bEdge)
        glEdgeFlag(TRUE);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.5, 0.5);
    if (bEdge)
        glEdgeFlag(FALSE);
        glVertex2f(-0.5, -0.5);

        glVertex2f(0.0, 0.0);
        if (bEdge)
            glEdgeFlag(TRUE);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);

        if(bEdge)
            glEdgeFlag(FALSE);
        glVertex2f(0.0, 0.0);
        if(bEdge)
            glEdgeFlag(TRUE);
        glVertex2f(-0.5, -0.5);
        if(bEdge)
            glEdgeFlag(FALSE);
        glVertex2f(-.5, -0.5);


    glEnd();
    glFlush();
}
void Widget::timerFunction()
{
 atime++;
 update();

}
void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Up:
        bEdge = GL_TRUE;
        break;
    case Qt::Key_Down:
        bEdge = GL_FALSE;
        break;
    };
    update();
    }

