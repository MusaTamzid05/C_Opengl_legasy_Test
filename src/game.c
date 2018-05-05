#include "game.h"
#include "glut_helper.h"
#include "camera.h"

#include <GL/glut.h>
#include "stats.h"

void run_game(int argc , char** argv , int width , int height , char* title , int update_time , int total_road) {

    stats = create_stats(total_road);

    Camera* camera = create_camera(create_vector(0.0f , 0.0f , -7.0f) , create_vector(0.0f , 1.0f , 0.0f) , 0);
    Window* window = create_window(title , width , height , camera , 25);

    init_glut(argc , argv , window);
    create_glut_window();
    glutDisplayFunc(draw_callback);
    glutReshapeFunc(handle_resize);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(window->update_time, update_callback , 0);
    //glutFullScreen();
    glutMainLoop();

}
