#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "Sphere.h"
#include <fstream>
#include <sstream>

double view_window_width = 3.0;
int samples_per_pixel = 1;
double fov = 90.f;
Vec2 window_dim = Vec2(1920, 1080);
Vec3 camera_pos = Vec3(0, 1, -3);
Vec3 camera_dir = Vec3(0, -0.2, 1);
Camera camera(view_window_width, samples_per_pixel, fov, window_dim, camera_pos, camera_dir);
Scene scene;

auto spec = std::make_shared<Specular>();
auto diff = std::make_shared<Diffuse>();
auto lamb = std::make_shared<Lambertian>();

Vec2 vertices[4]{
    {0, 0}, {1, 0},
    {0, 1}, {1, 1}
};

int main()
{
    //sf::RenderWindow window(sf::VideoMode(1920, 1080), "RayBans");

    scene.addEntity(std::make_shared<Sphere>(Vec3(0, 0, 5), 2, Colour(0.8, 0.8, 1), lamb));
    scene.addEntity(std::make_shared<Sphere>(Vec3(5, 0, 3), 2, Colour(1.0, 1.0, 1.0), spec));
    scene.addEntity(std::make_shared<Sphere>(Vec3(-5, 0, 3), 2, Colour(1.0, 1.0, 1.0), spec));
    scene.addEntity(std::make_shared<Sphere>(Vec3(0, -5002, 0), 5000, Colour(0.5, 1, 0.2), lamb));

    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "GLFW fucky wucky\n";
        return -1;
    }

    window = glfwCreateWindow(window_dim.x, window_dim.y, "RayBans", NULL, NULL);
    if (!window) {
        glfwTerminate;
        std::cout << "Window fucky wucky\n";
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW fucky wucky\n";
        return -1;
    }

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const GLchar* vertex_shader_text = fileToCString("VertexShader.vert");
        
    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    const GLchar* fragment_shader_text = fileToCString("FragmentShader.frag");

    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    const GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    const GLint mvp_location = glGetUniformLocation(program, "MVP");
    const GLint vpos_location = glGetAttribLocation(program, "vPos");

    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_DOUBLE, GL_FALSE,
        0, vertices);

    uint16_t frame = 1;

    //while (window.isOpen())
    //{
    //    frame++;

    //    sf::Event event;
    //    while (window.pollEvent(event)){
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    sf::VertexArray image = camera.render(scene, frame);

    //    window.clear();
    //    window.draw(image);
    //    window.display();
    //}

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        std::cout << "Frame" << std::endl;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

static const char* fileToCString(std::string filepath) {
    std::ifstream f(filepath);
    std::string str;
    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf();
        str = ss.str();
    }

    const char* c_str = str.c_str();
    return c_str;
}