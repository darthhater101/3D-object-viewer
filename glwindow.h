#pragma once

#include <QMouseEvent>
#include <QOpenGLWidget>
#include "object.h"
#include "cube.h"
#include "model.h"
#include "camera.h"

class GLWindow : public QOpenGLWidget
{
private:
    QVector<Object> scene;
    Camera* camera;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    bool letfPressed;
    bool rightPressed;

    QPoint lastPos;
    QPoint lastMovePos;

public:
    GLWindow(QWidget *parent = 0);
    ~GLWindow() { delete camera; }

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void addObject(const Object &object);
    void drawScene();
};
