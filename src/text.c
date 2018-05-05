#include "text.h"
#include <GL/glut.h>
#include <string.h>

#include "text.h"
#include <stdio.h>

Text* create_text(char* str ,Vector3* pos , Vector3* scale , Vector3* color) {

    Text* text = (Text*)malloc(sizeof(Text));

    text->str = str;
    text->pos = pos;
    text->scale = scale;
    text->color = color;

    return text;

}


void draw_text(Text* text){

    glPushMatrix();
    glColor3f(text->color->x, text->color->y , text->color->z);
    gluOrtho2D(0 , 2500 , 0 , 2500);
    glTranslatef(text->pos->x , text->pos->y , text->pos->z);
    //glScalef(2.0 , 3.0  , 1);

    glScalef(text->scale->x , text->scale->y , text->scale->z);

    int text_length = strlen(text->str);

    int i = 0;

    for(i = 0 ; i < text_length; i++) 
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text->str[i]);

    glPopMatrix();
}
