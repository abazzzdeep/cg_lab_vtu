#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

// Function to set up the OpenGL environment
void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the background color to white
    glColor3f(0.0, 0.0, 0.0);         // Set the drawing color to black
    glPointSize(1.0);                 // Set the point size to 1 pixel
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

// Function to draw a pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Bresenham's line drawing algorithm
void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        drawPixel(x1, y1);

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    bresenham(x1, y1, x2, y2);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenham's Line Drawing");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
