#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
using namespace std;

class Shape {
protected:
    int xcord, ycord;
    string clr;

    sf::Color getSFMLColor() const {
        if (clr == "red") return sf::Color::Red;
        if (clr == "green") return sf::Color::Green;
        if (clr == "blue") return sf::Color::Blue;
        if (clr == "yellow") return sf::Color::Yellow;
        return sf::Color::Black;
    }

public:
    Shape() : xcord(0), ycord(0), clr("black"){}
    Shape(string color) : xcord(0), ycord(0), clr(color){}
    virtual double get_area() const = 0;
    virtual double get_perimeter() const = 0;
    virtual string get_color() const {
        return clr;
    }
    virtual int get_shape() const = 0;
    void translate(int dx, int dy){
        xcord+= dx;
        ycord+= dy;
    }
    pair<int,int> get_coordinates() const{
        return make_pair(xcord,ycord);
    }
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual ~Shape() {}
};


class Rectangle : public Shape {
private:
    int len, bred;

public:
    Rectangle(int x, int y) : len(x) , bred(y), Shape(){}
    Rectangle(int x, int y, string color) : len(x), bred(y), Shape(color){}

    int get_length() const{
        return len;
    }
    int get_breadth() const{
        return bred;
    }
    double get_area() const override{
        return len*bred;
    }
    double get_perimeter() const override{
        return 2*(len+bred);
    }
    bool is_square() const {
        return len == bred;
    }
    int get_shape() const override{
        return 0;
    }

    void draw(sf::RenderWindow& window) const override {
        sf::RectangleShape rect(sf::Vector2f(len, bred));
        rect.setPosition(xcord, ycord);
        rect.setFillColor(getSFMLColor());
        window.draw(rect);
    }
};

class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {}
    Square(int side, string clr) : Rectangle(side, side, clr){}
    int get_shape() const override{
        return 1;
    }
};

class Ellipse : public Shape {
private:
    int a, b;

public:
    Ellipse(int x, int y) : a(x), b(y), Shape(){}
    Ellipse(int x, int y, string color) : a(x), b(y), Shape(color){}

    int get_Xlength() const{
        return a;
    }
    int get_Ylength() const{
        return b;
    }
    double get_area() const override{
        return M_PI*a*b;
    }
    double get_perimeter() const override{
        return M_PI * (3*(a + b) - sqrt((3*a + b)*(a + 3*b)));

    }
    int get_shape() const override{
        return 3;
    }

    void draw(sf::RenderWindow& window) const override {
        sf::CircleShape ellipse(1.f);  
        ellipse.setScale(a, b);        
        ellipse.setPosition(xcord, ycord);
        ellipse.setFillColor(getSFMLColor());
        window.draw(ellipse);
    }
};

class Circle : public Ellipse {
public:
    Circle(int x) : Ellipse(x,x){}
    Circle(int x, string color) : Ellipse(x,x,color){}

    int get_Radii() const {
        return get_Xlength();
    }
    int get_shape() const override{
        return 2;
    }
};
