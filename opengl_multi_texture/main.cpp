// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Image loader
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Shader Class
#include "Shader.hpp"

// ETC
#include <iostream>
#include <string>

// Call back for changing window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// Receive input, currently only receive ESC
void processInput(GLFWwindow *window);
// Texture loader
enum image_types
{
    JPG = 0,
    PNG = 1
};
unsigned int texture_loader(const char* name, int& width, int& height, int& channel, int type);

int main()
{
    // GLFW Initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // GLFW Window Creation
    GLFWwindow* window = glfwCreateWindow(800, 600, "Opengl Hello World", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD initialize
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // view port, resolution setup
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // Triangle vertic
    float vertices[] = 
    {
        // positions          // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // top left 
    };
    unsigned int indices[] = 
    {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    // Vertex Buffer Object, reference(handle) of created vertex buffer
    // It will be used to contain vertex position
    // Creation
    unsigned int VBO;
    glGenBuffers(1, &VBO); 
    // Binding, Change state
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Set reference, Maybe they copy CPU buffer to GPU.
    //GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
    //GL_DYNAMIC_DRAW: the data is likely to change a lot.
    //GL_STREAM_DRAW: the data will change every time it is drawn.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // indics of triangles
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    // Load Texture
    struct image
    {
        int width;
        int height;
        int channel;
        int type;
        std::string name;
    };
    struct image image1, image2;
    image1.name = "container.jpg";
    image1.type = JPG;
    image2.name = "awesomeface.png";
    image2.type = PNG;
    unsigned int texture1 = texture_loader(image1.name.c_str(), image1.width, image1.height, image1.channel, image1.type);
    unsigned int texture2 = texture_loader(image2.name.c_str(), image2.width, image2.height, image2.channel, image2.type);

    // Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO); 

    // Shader
    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

    // Let's draw
    shader.use();

    // Texture activate
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    shader.set_int("texture1", 0);
    shader.set_int("texture2", 1);

    // Show
    while(!glfwWindowShouldClose(window))
    {
        // check input
        processInput(window);

        // rendering
        // clear buffer color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // register vertex position
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // register color
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Double buffering
        glfwSwapBuffers(window);
        // check event in every polling
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

unsigned int texture_loader(const char* name, int& width, int& height, int& channel, int type)
{
    //fliping option
    stbi_set_flip_vertically_on_load(true);  

    // Create texture object
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // load image
    unsigned char *data = stbi_load(name, &width, &height, &channel, 0);

    if (data)
    {
        switch(type)
        {
            case JPG:
            // copy texture to GPU
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            // MIPMAP
            glGenerateMipmap(GL_TEXTURE_2D);
            break;

            case PNG:
            // copy texture to GPU
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            // MIPMAP
            glGenerateMipmap(GL_TEXTURE_2D);
            break;

            default:
            std::cout << "Can not support this type" << std::endl;
            break;
        }

    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    // un-load image
    stbi_image_free(data);

    return texture;
}