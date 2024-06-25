#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Initial points of the triangle
GLfloat triangle[3][2] = {
    {100.0, 100.0},
    {200.0, 100.0},
    {150.0, 200.0}
};

GLfloat transformedTriangle[3][2];

// Function to set up the OpenGL environment
void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the background color to white
    glColor3f(0.0, 0.0, 0.0);         // Set the drawing color to black
    glPointSize(4.0);                 // Set the point size to 4 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

// Function to display the triangle
void displayTriangle(GLfloat triangle[3][2]) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();
    glFlush();
}

// Function to translate the triangle
void translateTriangle(GLfloat tx, GLfloat ty) {
    for (int i = 0; i < 3; i++) {
        transformedTriangle[i][0] = triangle[i][0] + tx;
        transformedTriangle[i][1] = triangle[i][1] + ty;
    }
}

// Function to scale the triangle
void scaleTriangle(GLfloat sx, GLfloat sy) {
    for (int i = 0; i < 3; i++) {
        transformedTriangle[i][0] = triangle[i][0] * sx;
        transformedTriangle[i][1] = triangle[i][1] * sy;
    }
}

// Function to rotate the triangle
void rotateTriangle(GLfloat angle) {
    GLfloat radian = angle * M_PI / 180.0;
    GLfloat cosTheta = cos(radian);
    GLfloat sinTheta = sin(radian);

    for (int i = 0; i < 3; i++) {
        transformedTriangle[i][0] = triangle[i][0] * cosTheta - triangle[i][1] * sinTheta;
        transformedTriangle[i][1] = triangle[i][0] * sinTheta + triangle[i][1] * cosTheta;
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle
    glColor3f(0.0, 0.0, 0.0);
    displayTriangle(triangle);

    // Translated triangle
    glColor3f(1.0, 0.0, 0.0); // Red color
    translateTriangle(100.0, 50.0);
    displayTriangle(transformedTriangle);

    // Scaled triangle
    glColor3f(0.0, 1.0, 0.0); // Green color
    scaleTriangle(0.5, 0.5);
    displayTriangle(transformedTriangle);

    // Rotated triangle
    glColor3f(0.0, 0.0, 1.0); // Blue color
    rotateTriangle(45.0);
    displayTriangle(transformedTriangle);

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("2D Geometric Transformations");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
