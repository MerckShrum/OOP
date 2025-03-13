//
// Created by merckshrum on 09.03.25.
//

#ifndef ACTION_H
#define ACTION_H

#include <stddef.h>
#include "errors.h"
#include "canvas.h"

typedef struct {
    enum {
        OPEN_FILE = 0
    } type;
    union {
        char *filename;
    } var_field;
    canvas_t *canvas;
} action_t;

returncode_t action_set_file(action_t *action, char *filename);
returncode_t action_set_canvas(action_t *action, canvas_t *canvas);

#endif //ACTION_H
