#pragma once
#include <QMatrix4x4>


enum CameraMove
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Camera
{
private:

    QVector3D position;
    QVector3D front;
    QVector3D up;
    QVector3D right;
    QVector3D worldUp;

    float speed = 0.1f;
    float sensivity = 0.001f;
    float pitch;
    float yaw;

public:

    Camera(float yaw, float pitch,
           QVector3D position = QVector3D(0.0f, 0.0f, -3.0f),
           QVector3D up = QVector3D(0.0f, 1.0f, 0.0f));
    ~Camera() {};

    QMatrix4x4 getViewMat();
    void moveView(float xoffset, float yoffset);
    void move(CameraMove direction);

private:
    void update();
};
