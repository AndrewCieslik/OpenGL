#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>
#include <DevGL\glaux.h>

float angle = 1.0;
void my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, 1.0, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   
	//Slonce 
    glTranslatef(0.0, 0.0, -300.0);  
    glPushMatrix();
    	glRotatef(angle, 0.0, 1.0, 0.0); 
		glColor3f(1.0, 1.0, 0.0);
    	glutWireSphere(60, 15, 15);
    glPopMatrix();
    
    //Czerwona planeta
    glPushMatrix();
		glRotatef(angle, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 100.0, 0.0);
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(20, 15, 15);
	glPopMatrix();

	//Ziemia 
    glPushMatrix();
	    glRotatef(angle, 0.0, 1.0, 0.0);
	    glTranslatef(0.0, 0.0, 150); 
	    glColor3f(0.0, 1.0, 0.0);
	    glutWireSphere(20, 10, 10);
    glPopMatrix();

    angle += 0.01;

    glutSwapBuffers();
}

void my_keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL. Transformacje 3D");

    glutKeyboardFunc(my_keyboard);
    glutDisplayFunc(my_display);
    glutIdleFunc(my_display);

    glutMainLoop();
}

