#include <GL/glut.h>
#include <cmath>
#include <cstdio> 

#define M_PI 3.14159265358979323846

// Variáveis para controle das transformações
float translateX = 0.0f, translateY = 0.0f, translateZ = -7.0f;
float rotateX = 0.0f, rotateY = 0.0f, rotateZ = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;

// Vértices do cubo (centrado na origem)
GLfloat vertices[8][3] = {
    {-1.0f, -1.0f,  1.0f}, // 0
    { 1.0f, -1.0f,  1.0f}, // 1
    { 1.0f,  1.0f,  1.0f}, // 2
    {-1.0f,  1.0f,  1.0f}, // 3
    {-1.0f, -1.0f, -1.0f}, // 4
    { 1.0f, -1.0f, -1.0f}, // 5
    { 1.0f,  1.0f, -1.0f}, // 6
    {-1.0f,  1.0f, -1.0f}  // 7
};

// Arestas do cubo (pares de índices de vértices)
int edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Face frontal
    {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Face traseira
    {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Conexões entre faces
};

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

// Aplica as transformações atuais a um vértice
void transformVertex(GLfloat* vertex) {
    GLfloat x = vertex[0];
    GLfloat y = vertex[1];
    GLfloat z = vertex[2];

    // Aplica escala
    x *= scaleX;
    y *= scaleY;
    z *= scaleZ;

    // Aplica rotação em X (I/K)
    if (rotateX != 0) {
        float rad = rotateX * M_PI / 180.0f;
        float newY = y * cos(rad) - z * sin(rad);
        float newZ = y * sin(rad) + z * cos(rad);
        y = newY;
        z = newZ;
    }

    // Aplica rotação em Y (J/L)
    if (rotateY != 0) {
        float rad = rotateY * M_PI / 180.0f;
        float newX = x * cos(rad) + z * sin(rad);
        float newZ = -x * sin(rad) + z * cos(rad);
        x = newX;
        z = newZ;
    }

    // Aplica rotação em Z (U/O)
    if (rotateZ != 0) {
        float rad = rotateZ * M_PI / 180.0f;
        float newX = x * cos(rad) - y * sin(rad);
        float newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    // Aplica translação
    x += translateX;
    y += translateY;
    z += translateZ;

    vertex[0] = x;
    vertex[1] = y;
    vertex[2] = z;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha o cubo como wireframe
    glColor3f(0.0f, 1.0f, 1.0f); // Cor ciano para as arestas
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        // Transforma os vértices da aresta
        GLfloat v1[3] = { vertices[edges[i][0]][0], vertices[edges[i][0]][1], vertices[edges[i][0]][2] };
        GLfloat v2[3] = { vertices[edges[i][1]][0], vertices[edges[i][1]][1], vertices[edges[i][1]][2] };

        transformVertex(v1);
        transformVertex(v2);

        // Desenha a aresta
        glVertex3fv(v1);
        glVertex3fv(v2);
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y) {
    float step = 0.1f;
    float angleStep = 5.0f;
    float scaleStep = 0.1f;

    switch (key) {
        // Translação
    case 'w': translateY += step; break;
    case 's': translateY -= step; break;
    case 'a': translateX -= step; break;
    case 'd': translateX += step; break;
    case 'q': translateZ -= step; break;
    case 'e': translateZ += step; break;

        // Rotação (corrigido)
    case 'i': rotateX += angleStep; break;  // Rotação +X
    case 'k': rotateX -= angleStep; break;  // Rotação -X
    case 'j': rotateY -= angleStep; break;  // Rotação -Y (sentido horário)
    case 'l': rotateY += angleStep; break;  // Rotação +Y (sentido anti-horário)
    case 'u': rotateZ += angleStep; break;  // Rotação +Z
    case 'o': rotateZ -= angleStep; break;  // Rotação -Z

        // Escala
    case '1': scaleX += scaleStep; break;
    case '2': scaleX -= scaleStep; break;
    case '3': scaleY += scaleStep; break;
    case '4': scaleY -= scaleStep; break;
    case '5': scaleZ += scaleStep; break;
    case '6': scaleZ -= scaleStep; break;

        // Reset
    case 'r':
        translateX = translateY = 0.0f;
        translateZ = -7.0f;
        rotateX = rotateY = rotateZ = 0.0f;
        scaleX = scaleY = scaleZ = 1.0f;
        break;

    case 27: // ESC key
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Cubo 3D com Transformacoes Corrigidas");

    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    // Instruções atualizadas
    printf("Controles CORRETOS:\n");
    printf("Translação: W (cima), S (baixo), A (esquerda), D (direita), Q (afastar), E (aproximar)\n");
    printf("Rotação:\n");
    printf("  I/K: Rotação em X (I=para frente, K=para trás)\n");
    printf("  J/L: Rotação em Y (J=esquerda, L=direita) - como um pião\n");
    printf("  U/O: Rotação em Z (U=inclina esquerda, O=inclina direita)\n");
    printf("Escala: 1/2 (X), 3/4 (Y), 5/6 (Z)\n");
    printf("Reset: R\n");

    glutMainLoop();
    return 0;
}