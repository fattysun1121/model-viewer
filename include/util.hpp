#pragma once
#include <vector>
#include <glad/glad.h>
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"


using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
};

namespace util {

    class Mesh {
        public:
            vector<Vertex> vertices;
            vector<unsigned int> indices;
            vector<Texture> textures;

            Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures):
                vertices(vertices), indices(indices), textures(textures) {
                setUpMesh();
            }

            void draw() {

            }
        private:
            GLuint VAO, VBO, EBO;
            void setUpMesh() {
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                glGenBuffers(1, &EBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

                glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
                glVertexAttribPointer(0, sizeof(float) * 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(1, sizeof(float) * 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(2, sizeof(float) * 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
                glEnableVertexAttribArray(2);
                glBindVertexArray(0);
            }
    };
}