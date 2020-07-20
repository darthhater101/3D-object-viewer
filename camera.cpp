#include "camera.h"

Camera::Camera(float yaw, float pitch,
               QVector3D position, QVector3D up) : front(QVector3D(0.0f, 0.0f, -1.0f))
{
    this->position = position;
    this->worldUp = up;
    this->pitch = pitch;
    this->yaw = yaw;

    update();
}

 QMatrix4x4 Camera::getViewMat()
 {
     QMatrix4x4 view;
     view.lookAt(position, position + front, up);
     return view;
 }

 void Camera::moveView(float xoffset, float yoffset)
 {
     xoffset *= sensivity;
     yoffset *= sensivity;

     yaw += xoffset;
     pitch += yoffset;

     if(pitch > 89.0f)
         pitch = 89.0f;
     if(pitch < -89.0f)
         pitch = -89.0f;

     qDebug() << pitch;
     qDebug() << yaw;

     update();
 }

 void Camera::move(CameraMove direction)
 {
     if(direction == FORWARD)
         position += speed * front;
     if(direction == BACKWARD)
         position -= speed * front;
     if(direction == LEFT)
         position -= speed * right;
     if(direction == RIGHT)
         position += speed * right;
     if(direction == UP)
         position += speed * up;
     if(direction == DOWN)
         position -= speed * up;

     qDebug() << position;
 }

 void Camera::update()
 {
     QVector3D front;
     front.setX(cos(yaw) * cos(pitch));
     front.setY(sin(pitch));
     front.setZ(sin(yaw) * cos(pitch));
     this->front = front.normalized();
     this->right = QVector3D::crossProduct(this->front, this->worldUp).normalized();
     this->up = QVector3D::crossProduct(this->right, this->front).normalized();
 }
