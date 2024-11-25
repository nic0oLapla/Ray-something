#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Camera.h"
#include "Sphere.h"

double view_window_width = 3.0;
int samples_per_pixel = 1;
double fov = 90.f;
Vec2 window_dim = Vec2(1920, 1080);
Vec3 camera_pos = Vec3(0, 0, 0);
Vec3 camera_dir = Vec3(0, -0.2, 1);
Camera camera(view_window_width, samples_per_pixel, fov, window_dim, camera_pos, camera_dir);
Scene scene;

auto spec = std::make_shared<Specular>();
auto diff = std::make_shared<Diffuse>();
auto lamb = std::make_shared<Lambertian>();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RayBans");

    scene.addEntity(std::make_shared<Sphere>(Vec3(0, -3, 10), 2, Colour(0.8, 0.8, 1), lamb));
    scene.addEntity(std::make_shared<Sphere>(Vec3(5, -3, 6), 2, Colour(1.0, 1.0, 1.0), spec));
    scene.addEntity(std::make_shared<Sphere>(Vec3(-5, -3, 6), 2, Colour(1.0, 1.0, 1.0), spec));
    scene.addEntity(std::make_shared<Sphere>(Vec3(0, -5005, 0), 5000, Colour(0.5, 1, 0.2), lamb));

    //// INITIALISATION
    //if (!glfwInit()) {
    //    std::cout << "GLFW fucky wucky\n";
    //    return 1;
    //}

    //GLFWwindow* window;

    //window = glfwCreateWindow(window_dim.x, window_dim.y, "RayBans", NULL, NULL);

    //if (!window) {
    //    std::cout << "Window fucky wucky\n";
    //    glfwTerminate();
    //    return 1;
    //}

    //glfwMakeContextCurrent(window);

    //if (glewInit() != GLEW_OK) {
    //    std::cout << "GLEW fucky wucky\n";
    //    return 1;
    //}

    //int width, height;
    //glfwGetFramebufferSize(window, &width, &height);
    //glViewport(0, 0, width, height);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);

    //glewExperimental = GL_TRUE;

    ///*BUFFERS*/
    //// Vertex buffer
    //float vertices[12]{
    //    -1.0f,  1.0f, 0.0f,
    //     1.0f,  1.0f, 0.0f,
    //    -1.0f, -1.0f, 0.0f,
    //     1.0f, -1.0f, 0.0f
    //};

    //GLuint vertex_buffer = 0;
    //glGenBuffers(1, &vertex_buffer);
    //glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    //glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertices, GL_STATIC_DRAW);

    //// Index buffer
    //GLuint indices[6]{
    //    0, 2, 1,
    //    1, 2, 3
    //};

    //GLuint index_buffer;
    //glGenBuffers(1, &index_buffer);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), indices, GL_STATIC_DRAW);

    //// Vertex array
    //GLuint vertex_array = 0;
    //glGenVertexArrays(1, &vertex_array);
    //glBindVertexArray(vertex_array);
    //glEnableVertexAttribArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    ///*SHADERS*/
    //// Load shader text from files
    //std::string vertex_shader_string = Utils::fileToCString("VertexShader.vert");
    //const GLchar* vertex_shader_text = vertex_shader_string.c_str();
    //std::string fragment_shader_string = Utils::fileToCString("FragmentShader.frag");
    //const GLchar* fragment_shader_text = fragment_shader_string.c_str();

    //// Create and compile shaders
    //GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    //glCompileShader(vertex_shader);
    //GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    //glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    //glCompileShader(fragment_shader);

    //// Check if shaders have compiled correctly
    //GLint vertex_compiled;
    //glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertex_compiled);
    //if (vertex_compiled == GL_TRUE)
    //    std::cout << "Vertex shader OK\n";
    //else
    //{
    //    GLint infoLogLength;
    //    glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &infoLogLength);
    //    GLchar* message = new GLchar[infoLogLength + 1];
    //    glGetShaderInfoLog(vertex_shader, infoLogLength, NULL, message);
    //    std::cout << "Vertex shader error: " << message << std::endl;
    //    delete[] message;
    //}

    //GLint fragment_compiled;
    //glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &fragment_compiled);
    //if (fragment_compiled == GL_TRUE)
    //    std::cout << "Fragment shader OK\n";
    //else
    //{
    //    GLint infoLogLength;
    //    glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &infoLogLength);
    //    GLchar* message = new GLchar[infoLogLength + 1];
    //    glGetShaderInfoLog(fragment_shader, infoLogLength, NULL, message);
    //    std::cout << "Fragment shader error: " << message << std::endl;
    //    delete[] message;
    //}

    //// Attach shaders and link program
    //GLuint program = glCreateProgram();
    //glAttachShader(program, vertex_shader);
    //glAttachShader(program, fragment_shader);
    //glLinkProgram(program);
    //glUseProgram(program);

    //// Check if program is linked
    //GLint program_linked;
    //glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    //if (program_linked == GL_TRUE)
    //    std::cout << "Program OK\n";
    //else
    //{
    //    GLint infoLogLength;
    //    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
    //    GLchar* message = new GLchar[infoLogLength + 1];
    //    glGetProgramInfoLog(program, infoLogLength, NULL, message);
    //    std::cout << "Program error: " << message << std::endl;
    //    delete[] message;
    //}

    //GLuint dim_location = glGetUniformLocation(program, "dim");
    //glUniform2f(dim_location, window_dim.x, window_dim.y);

    uint16_t frame = 0;
    while (window.isOpen())
    {
        frame++;
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::VertexArray image = camera.render(scene, frame);
        window.clear();
        window.draw(image);
        window.display();
    }

    //while (!glfwWindowShouldClose(window)) {
    //    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //    glUseProgram(program);
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    //    
    //    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

    //    glfwSwapBuffers(window);

    //    glfwPollEvents();
    //}

    //glfwTerminate();
    //return 0;
}