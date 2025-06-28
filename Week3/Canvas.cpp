#include <SFML/Graphics.hpp>
#include <vector>
#include "Shapes.cpp" 
using namespace std;

class Canvas {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void displayCanvas() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Canvas");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);

            for (auto shape : shapes) {
                shape->draw(window);
            }

            window.display();
        }
    }
};
