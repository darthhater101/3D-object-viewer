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

    float zoomCoef = 1.0f;

public:

    Camera(float yaw, float pitch,
           QVector3D position = QVector3D(6.5f, 5.5f, -7.0f),
           QVector3D up = QVector3D(0.0f, 1.0f, 0.0f));
    ~Camera() {};

    QMatrix4x4 getViewMat();

    void moveView(float xoffset, float yoffset);
    void move(CameraMove direction);

    QVector3D getPosition() { return position; }

    void zoom();
    void unzoom();

    QVector3D getScaleVec() { return QVector3D(zoomCoef, zoomCoef, zoomCoef); }

private:
    void update();
};

