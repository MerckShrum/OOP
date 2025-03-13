//
// Created by merckshrum on 12.03.25.
//

#ifndef SCENE_H
#define SCENE_H

#include "wire-frame_model.h"
#include "camera.h"

typedef struct {
    wire_frame_model_t model;
    camera_t camera;
} scene_t;

#endif //SCENE_H
