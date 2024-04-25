#include <iostream>
#include <SFML/Graphics.hpp>
#include "viewShader.cpp"

int main()
{
    sf::Vector2u dim;


    sf::RenderWindow window(sf::VideoMode(1200, 800), "RayBans");
    dim = window.getSize();

    sf::VertexArray vertices(sf::Points, dim.x * dim.y);
    for (float i = 0; i < dim.x; i++) {
        for (float j = 0; j < dim.y; j++) {
            vertices.append(sf::Vertex(sf::Vector2f(i, j)));
        }
    }

    sf::Shader fShader;
    fShader.loadFromFile("viewShader.frag", sf::Shader::Fragment);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        dim = window.getSize();
        fShader.setUniform("dim", sf::Glsl::Vec2(dim.x, dim.y));

        window.clear();
        window.draw(vertices, &fShader);
        window.display();
    }

    return 0;
}