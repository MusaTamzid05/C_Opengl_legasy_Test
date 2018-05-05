#ifndef TEXT_H
#define TEXT_H

#include "vertex.h"

typedef struct Text {

    char* str;

    Vector3* pos;
    Vector3* scale;
    Vector3* color;


} Text;

void draw_text(Text* text);
Text* create_text(char* str , Vector3* pos , Vector3* scale, Vector3* color);

#endif
