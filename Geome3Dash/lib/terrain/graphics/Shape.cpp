#include <vector>
#include <array>
#include <iostream>

#include <GL/glew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "graphics/Shape.h"

Shape::Shape() {    
    this->vertexCount = 0;
}

void Shape::DrawShape() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
    glBindVertexArray(0);
}

void Shape::AddVertex(float px, float py, float pz,
            float nx, float ny, float nz,
            float tx, float ty) {
    vertices.push_back(px);
    vertices.push_back(py);
    vertices.push_back(pz);
    vertices.push_back(nx);
    vertices.push_back(ny);
    vertices.push_back(nz);
    vertices.push_back(tx);
    vertices.push_back(1-ty);
    this->vertexCount++;
}

void Shape::SetVertices() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Set vertex attribute Postion
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(GLfloat) * 8, &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));

    // Set vertex attribute Normal
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    // Set vertex attribute Texture Coordinates
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 6));

    // Un-bind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
