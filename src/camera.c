#include "camera.h"
#include <stdlib.h>


Camera* create_camera(Vector3* translation ,  Vector3* rotation , float angle) {


    Camera* camera = (Camera*)malloc(sizeof(Camera));
    camera->rotation = rotation;
    camera->translation = translation;
    camera->angle = angle;

    return camera;

}
