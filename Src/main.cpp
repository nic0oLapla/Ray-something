//#define FPL_IMPLEMENTATION
//#include "final_platform_layer.h"
#include "Camera.h"
#include "Sphere.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(3840, 2160), "RayBans");

    double view_window_width = 3.0;
    int samples_per_pixel = 1;
    double fov = 90.f;
    Vec2 window_dim = window.getSize();
    Vec3 camera_pos = Vec3(0, 2, -3);
    Vec3 camera_dir = Vec3(0, -0.2, 1);
    Camera camera(view_window_width, samples_per_pixel, fov, window_dim, camera_pos, camera_dir);
    
    Specular spec = Specular();
    Specular* specPtr = &spec;
    Diffuse diff = Diffuse();
    Diffuse* diffPtr = &diff;
    Glow glow = Glow();
    Glow* glowPtr = &glow;

    Scene scene;
    scene.addEntity(std::make_shared<Sphere>(Vec3(0, 0, 5), 2, Colour(0.8, 0.8, 1), diffPtr));
    scene.addEntity(std::make_shared<Sphere>(Vec3(5, 0, 3), 2, Colour(1.0, 1.0, 1.0), specPtr));
    scene.addEntity(std::make_shared<Sphere>(Vec3(-5, 0, 3), 2, Colour(1.0, 1.0, 1.0), specPtr));
    scene.addEntity(std::make_shared<Sphere>(Vec3(0, -502, 0), 500, Colour(0.5, 1, 0.2), diffPtr));
    scene.addEntity(std::make_shared<Sphere>(Vec3(0, 5000, 0), 500, Colour(1, 1, 0.95), glowPtr));

    int frame = 0;

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
    return 0;
}