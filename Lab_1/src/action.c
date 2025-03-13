//
// Created by merckshrum on 09.03.25.
//

#include "../inc/action.h"


returncode_t action_set_file(action_t *action, char *filename) {
    returncode_t returncode = RETURN_SUCESS;
    if (action == NULL || filename == NULL)
        returncode |= ERROR_NULL_POINTER;
    else {
        action->type = OPEN_FILE;
        action->var_field.filename = filename;
    }
    return returncode;
}

returncode_t action_set_canvas(action_t *action, canvas_t *canvas) {
    returncode_t returncode = RETURN_SUCESS;
    if (action == NULL || canvas == NULL)
        returncode |= ERROR_NULL_POINTER;
    else {
        action->canvas = canvas;
    }
    return returncode;
}
