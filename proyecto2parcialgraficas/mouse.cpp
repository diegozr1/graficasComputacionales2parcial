// HelloWorld OpenGL using GLUT

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

// Tamaño de la ventana
GLint width = 800;
GLint height = 600;

// Funcin que inicializa el Contexto OpenGL y la geometra de la escena
void init()
{
glClearColor(0.f, 0.f, 0.f, 0.f);// Fija el color RGBA (Negro) inicial usado para limpiar los Buffers inicializados
glColor3f(1.f, 1.f, 1.f);// Fija el color RGB (Blanco) inicial usado para dibujar la escena
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

glViewport(0, 0, width, height);// Se fija el rea de dibujo en la ventana (viewport)
// Se dibuja un tringulo con el color activo definido por glColor
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_TRIANGLES);
glVertex3f(-0.5f, -0.5f, 0.f);
glVertex3f(0.5f, -0.5f, 0.f);
glVertex3f(0.f, 0.5f, 0.f);
glEnd();

glutSwapBuffers();// Se intercambian buffers
}

// Funcin que se invoca cada vez que ocurre un evento de click del Mouse (botn derecho y al terminar)
void mouse(int button, int state, int x, int y)
{
if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
{
cout << "GLUT_RIGHT & GLUT_UP, x= " << x << ", y= " << y << endl;
}
}

// Funcin que se invoca cada vez que ocurre un evento de movimiento y dragging del Mouse
void motionMouse(int x, int y)
{
cout << "x= " << x << ", y= " << y << endl;
}


int main(GLint argc, GLchar **argv)
{
// 1. Se crea una ventana y un contexto OpenGL usando GLUT
glutInit(&argc, argv);// Se inicializa GLUT
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Se inicializan Buffers
glutInitWindowSize(width, height);  // Se define el teamaño de la ventana
glutCreateWindow("GLUT Mouse Events"); // Se crea la ventana

// 1.2 Se definen las funciones callback para el manejo de eventos
glutReshapeFunc(resize);// La funcin resize se invocar cada vez que se redimensione la ventana
glutDisplayFunc(render);// La funcin render se invocar cada vez que se tenga que dibujar
glutMouseFunc(mouse);// La funcin mouse se invocar cada vez que ocurra un click del mouse (botn derecho y terminar)
glutPassiveMotionFunc(motionMouse); // La funcin motionMouse se invocar cada vez que ocurra un movimiento del mouse

// 2. Se direcciona a las funciones correctas del API de OpenGL
GLenum err = glewInit();
if (GLEW_OK != err)
{
fprintf(stderr, "GLEW Error");
return false;
}

// 3. Se inicializa el contexto de OpenGL y la geometra de la escena
init();

// 4. Se inicia el ciclo de escucha de eventos
glutMainLoop();
return 0;
}
