// Proyecto segundo parcial

// Toatzin Padilla 
// Diego Zamora 

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

// Tamaño de la ventana
GLint width = 800;
GLint height = 600;

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

int r = 0, g = 0, b = 0;

int slices = 10, stacks = 10;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}
void createMenu(void) {
	//Esfera, Cono, Cubo, Caja, Toroide, Tetrahedro, Octahedro, Dodecahedro, Icosahedro, Tetera
	
	submenu_id = glutCreateMenu(menu);

	glutAddMenuEntry("Esfera", 2);
	glutAddMenuEntry("Cono", 3);
	glutAddMenuEntry("Cubo", 4);
	glutAddMenuEntry("Caja", 5);
	glutAddMenuEntry("Toroide", 6);
	glutAddMenuEntry("Tetrahedro", 7);
	glutAddMenuEntry("Octahedro", 8);
	glutAddMenuEntry("Dodecahedro", 9);
	glutAddMenuEntry("Icosahedro", 10);
	glutAddMenuEntry("Tetera", 11);
	
	menu_id = glutCreateMenu(menu);
	
	glutAddMenuEntry("Limpiar último", 1);
	glutAddSubMenu("Dibujar figura", submenu_id);
	glutAddMenuEntry("Salir", 0);     glutAttachMenu(GLUT_LEFT_BUTTON);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);   if (value == 1) {
		return; //glutPostRedisplay();
	}
	else if (value == 2) {
		glPushMatrix();
		glColor3d(1.0, 0.0, 0.0);
		glutWireSphere(0.5, 50, 50);
		glPopMatrix();
	}
	else if (value == 3) {
		glPushMatrix();
		glColor3d(0.0, 1.0, 0.0);
		glRotated(65, -1.0, 0.0, 0.0);
		glutWireCone(0.5, 1.0, 50, 50);
		glPopMatrix();
	}
	else if (value == 4) {
		glPushMatrix();
		glColor3d(0.0, 0.0, 1.0);
		glutWireTorus(0.3, 0.6, 100, 100);
		glPopMatrix();
	}
	else if (value == 5) {
		glPushMatrix();
		glColor3d(1.0, 0.0, 1.0);
		glutSolidTeapot(0.5);
		glPopMatrix();
	}
	glFlush();
}


// Funcin que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
	width = w;
	height = h;
}

// Funcin que se invoca cada vez que se dibuja
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Se limpian los buffers con el color activo definido por glClearColor



	/*
	glViewport(0, 0, width, height);// Se fija el rea de dibujo en la ventana (viewport)
									// Se dibuja un tringulo con el color activo definido por glColor
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, -0.5f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.f);
	glVertex3f(0.f, 0.5f, 0.f);
	glEnd();
	*/
	glutSwapBuffers();// Se intercambian buffers
}

// Función que se invoca cada vez que ocurre un evento de click del Mouse (botón derecho y al terminar)
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		cout << "GLUT_RIGHT & GLUT_UP, x= " << x << ", y= " << y << endl;
	}
}

// Función que se invoca cada vez que ocurre un evento de movimiento y dragging del Mouse
void motionMouse(int x, int y)
{
	//cout << "x= " << x << ", y= " << y << endl;
}



int main(GLint argc, GLchar **argv)
{
	// 1. Se crea una ventana y un contexto OpenGL usando GLUT
	glutInit(&argc, argv);// Se inicializa GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Se inicializan Buffers
	glutInitWindowSize(width, height);  // Se define el teamaño de la ventana
	glutCreateWindow("Proyecto de segundo parcial"); // Se crea la ventana
	glDrawArrays(1, 1, 10);

	glutMouseFunc(mouse);			// La función mouse se invocará cada vez que ocurra un click del mouse (botón derecho y terminar)
	glutPassiveMotionFunc(motionMouse); // La función motionMouse se invocará cada vez que ocurra un movimiento del mouse
	createMenu(); // se agrega el menu cada que ocurra un click izquierdo

													   // 1.2 Se definen las funciones callback para el manejo de eventos
	glutReshapeFunc(resize);// La funcin resize se invocar cada vez que se redimensione la ventana
	glutDisplayFunc(render);// La funcin render se invocar cada vez que se tenga que dibujar

							// 2. Se direcciona a las funciones correctas del API de OpenGL
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW Error");
		return false;
	}

	// 3. Se inicializa el contexto de OpenGL
	glClearColor(0.f, 0.f, 0.f, 0.f);// Fija el color RGBA (Negro) usado para limpiar los Buffers inicializados
	glColor3f(1.f, 1.f, 1.f);// Fija el color RGB (Blanco) usado para dibujar la escena

							 // 4. Se inicia el ciclo de escucha de eventos
	glutMainLoop();
	return 0;
}
