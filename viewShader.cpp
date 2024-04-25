#include <SFML/Graphics.hpp>


class viewShader {
public:
    sf::Vector2u dim;
    

    viewShader(sf::RenderWindow* window) {
        dim = (*window).getSize();
    }

    void shade(sf::Vertex* v) {
        (*v).color = sf::Color(
            255 * ((dim.x - (*v).position.x) * (dim.y - (*v).position.y)) / (dim.x * dim.y),
            255 * (((*v).position.x) * (dim.y - (*v).position.y)) / (dim.x * dim.y),
            255 * ((dim.x - (*v).position.x) * ((*v).position.y)) / (dim.x * dim.y),
            255);
    }
};



