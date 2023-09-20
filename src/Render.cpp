#include "Render.h"
#include "ResourceManager.h"

Render::Render(Shader& shader)
{
    this->shader = shader;
    init();
}

void Render::init()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLfloat vertices[] = {
        // Pos     
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
 
    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);
    shader.use();
    shader.setMat4("perspective", perspective);

    count = 0;
}

void Render::draw(glm::vec3& position, glm::vec4& tex, glm::vec3& wayLine, glm::vec3& direction) {
    if (count >= MAXNUM_OF_OBJS) {
        return;
    }


    this->position[count] = position;
    this->tex[count] = tex;
    this->wayLine[count] = wayLine;
    this->direction[count] = direction;
    
    count++;
}

void Render::handleCamera(glm::mat4& trans) {
    shader.use();

    glm::mat4 camera = glm::mat4(1.0f);

    shader.setMat4("camera", trans);
}

void Render::draw()
{
    shader.use();
    
    //shader.setMat4("model", model);
    unsigned int VBO2;
    glGenBuffers(1, &VBO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec3), position, GL_STREAM_DRAW);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glVertexAttribDivisor(1, 1);
    glBindVertexArray(0);

    unsigned int VBO3;
    glGenBuffers(1, &VBO3);
    glBindBuffer(GL_ARRAY_BUFFER, VBO3);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec4), tex, GL_STREAM_DRAW);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)0);
    glVertexAttribDivisor(2, 1);
    glBindVertexArray(0);

    unsigned int VBO4;
    glGenBuffers(1, &VBO4);
    glBindBuffer(GL_ARRAY_BUFFER, VBO4);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec3), wayLine, GL_STREAM_DRAW);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glVertexAttribDivisor(3, 1);
    glBindVertexArray(0);

    unsigned int VBO5;
    glGenBuffers(1, &VBO5);
    glBindBuffer(GL_ARRAY_BUFFER, VBO5);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(glm::vec3), direction, GL_STREAM_DRAW);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glVertexAttribDivisor(4, 1);
    glBindVertexArray(0);
    

    ResourceManager::getTexture("texture").bind();
    glBindVertexArray(VAO);
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, count);

    glBindVertexArray(0);

    glDeleteBuffers(1, &VBO2);
    glDeleteBuffers(1, &VBO3);
    glDeleteBuffers(1, &VBO4);
    glDeleteBuffers(1, &VBO5);

    count = 0;
}



