#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glEnable(GL_DEPTH_TEST);         
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f); 
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); 
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); 
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); 

    
    glBegin(GL_QUADS);

    // frente
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Red
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // Green
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Blue
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Yellow

    // costas
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Magenta
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Cyan
    glColor3f(0.0f, 0.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f); // Black
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // White

    // cima
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Green
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Cyan
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Yellow
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f); // Blue

    // baixo
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Red
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Magenta
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // White
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // Yellow

    // esquerda
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Red
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); // Magenta
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // Yellow
    glColor3f(1.0f, 0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // Magenta

    // direita
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // Green
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f); // Cyan
    glColor3f(0.0f, 0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // Blue
    glColor3f(1.0f, 1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // White

    glEnd();

    glutSwapBuffers(); // melhora a execução, não remova
}

void reshape(int width, int height) {
    if (height == 0) height = 1; 
    float aspect = (float)width / (float)height;

    glViewport(0, 0, width, height); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    
    gluPerspective(45.0, aspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: 
            angleX -= 5.0f;
            break;
        case GLUT_KEY_DOWN: 
            angleX += 5.0f;
            break;
        case GLUT_KEY_LEFT: 
            angleY -= 5.0f;
            break;
        case GLUT_KEY_RIGHT: 
            angleY += 5.0f;
            break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("RGB Gradient Cube");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
