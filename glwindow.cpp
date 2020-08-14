#include "glwindow.h"
#include <QDebug>

#include <algorithm>

GLWindow::GLWindow(QWidget *parent) : QOpenGLWidget(parent)
{
    letfPressed = false;
    rightPressed = false;
    setMouseTracking(true);
    camera = new Camera(84.0f, -0.4f);

    connect(&t, SIGNAL(timeout()), this, SLOT(update()));
    t.start(16);
}

void GLWindow::initializeGL()
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawScene();
}

void GLWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWindow::addObject(Object *object)
{
    scene.push_back(object);
}

void GLWindow::drawScene()
{
    for(const auto& it : scene)
        it->draw(camera);
}

void GLWindow::mouseMoveEvent(QMouseEvent *event)
{

    if(letfPressed)
    {
        float xoffset = event->x() - lastPos.x();
        float yoffset = lastPos.y() - event->y();

        lastPos = event->pos();

        camera->moveView(xoffset, yoffset);

    }
    if(rightPressed)
    {
        float xoffset = event->x() - lastMovePos.x();
        float yoffset = lastMovePos.y() - event->y();

        lastMovePos = event->pos();

        if(xoffset < 0)
            camera->move(CameraMove::LEFT);
        if(xoffset > 0)
            camera->move(CameraMove::RIGHT);
        if(yoffset > 0)
            camera->move(CameraMove::UP);
        if(yoffset < 0)
            camera->move(CameraMove::DOWN);
    }
}

void GLWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        lastPos = event->pos();
        letfPressed = true;
    }
    if(event->button() == Qt::RightButton)
    {
        lastMovePos = event->pos();
        rightPressed = true;
    }
}

void GLWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)

        letfPressed = false;
    if(event->button() == Qt::RightButton)
        rightPressed = false;
}

void GLWindow::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0)
        camera->zoom();
    else if(event->angleDelta().y() < 0)
        camera->unzoom();
    update();
}

QVector<Object*> GLWindow::getCurrentScene()
{
    return scene;
}

void GLWindow::deleteObject(const int id)
{
    scene.erase(std::remove_if(scene.begin(), scene.end(), [id](Object* object){
                    return object->getId() == id;
    }));
}
