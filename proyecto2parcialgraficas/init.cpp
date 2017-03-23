// HelloWorld OpenGL using GLUT

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

// Tamaño de la ventana
GLint width = 800;
GLint height = 600;

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

int main(GLint argc, GLchar **argv)
{
// 1. Se crea una ventana y un contexto OpenGL usando GLUT
glutInit(&argc, argv);// Se inicializa GLUT
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Se inicializan Buffers
glutInitWindowSize(width, height);  // Se define el teamaño de la ventana
glutCreateWindow("Hello World OpenGL using GLUT"); // Se crea la ventana

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
