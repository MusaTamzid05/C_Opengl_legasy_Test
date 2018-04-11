#ifndef CAMERA_H
#define CAMERA_H

#include "vertex.h"

typedef struct Camera {

    Vector3* rotation;
    Vector3* translation;
    float angle;
} Camera;

Camera* create_camera( Vector3* translation ,  Vector3* rotation , float angle);

#endif
