#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Shape{
private:
    int xcord, ycord;
    string clr;
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
    virtual ~Shape() {}
};

class Rectangle : public Shape{
private:
    int len, bred;
    // string clr;

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
};

class Square : public Rectangle{
public:
    Square(int side) : Rectangle(side, side) {}
    Square(int side, string clr) : Rectangle(side, side, clr){}
    int get_shape() const override{
        return 1;
    }
};

class Ellipse : public Shape{
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
};

class Circle : public Ellipse{
private:
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

int main() {
    try {
        Shape* s1 = new Rectangle(4, 5, "Red");
        cout<<"Shape Type: "<<s1->get_shape()<<endl;
        cout<<"Coordinates: ("<<s1->get_coordinates().first<<", "<<s1->get_coordinates().second<<")"<<endl;
        s1->translate(5, 7);
        cout<<"Coordinates: ("<<s1->get_coordinates().first<<", "<< s1->get_coordinates().second<<")"<<endl;
        cout<<endl;
        Rectangle* r1 = dynamic_cast<Rectangle*>(s1);
        cout << "Length: " << r1->get_length() << endl;
        cout << "Breadth: " << r1->get_breadth() << endl;
        cout << "Area: " << r1->get_area() << endl;
        cout << "Perimeter: " << r1->get_perimeter() << endl;
        cout << "Color: " << r1->get_color() << endl;
        cout << "Is Square: " << (r1->is_square() ? "Yes" : "No") << endl;
        cout<<endl;
        Shape* s2 = new Rectangle(10, 10);
        cout << "Shape Type: " << s2->get_shape() << endl;
        cout << "Color: " << s2->get_color() << endl;
        Rectangle* r2 = dynamic_cast<Rectangle*>(s2);
        cout << "Is Square: " << (r2->is_square() ? "Yes" : "No") << endl;
        cout<<endl;
        Shape* s3 = new Square(5, "Blue");
        cout << "Shape Type: " << s3->get_shape() << endl;
        s3->translate(-3, 4);
        cout << "Coordinates: (" << s3->get_coordinates().first << ", " << s3->get_coordinates().second << ")" << endl;
        Square* sq = dynamic_cast<Square*>(s3);
        cout << "Length: " << sq->get_length() << endl;
        cout << "Area: " << sq->get_area() << endl;
        cout << "Perimeter: " << sq->get_perimeter() << endl;
        cout << "Color: " << sq->get_color() << endl;
        cout<<endl;
        Shape* s4 = new Circle(3, "Green");
        cout << "Shape Type: " << s4->get_shape() << endl;
        Circle* c1 = dynamic_cast<Circle*>(s4);
        cout << "Color: " << c1->get_color() << endl;
        cout << "Radius: " << c1->get_Radii() << endl;
        cout << "Area: " << c1->get_area() << endl;
        cout << "Perimeter: " << c1->get_perimeter() << endl;
        cout<<endl;
        Shape* s5 = new Ellipse(4, 5);
        cout << "Shape Type: " << s5->get_shape() << endl;
        s5->translate(2, 2);
        s5->translate(5, 4);
        cout << "Coordinates: (" << s5->get_coordinates().first << ", " << s5->get_coordinates().second << ")" << endl;
        Ellipse* e1 = dynamic_cast<Ellipse*>(s5);
        cout << "Color: " << e1->get_color() << endl;
        cout << "X Length: " << e1->get_Xlength() << endl;
        cout << "Y Length: " << e1->get_Ylength() << endl;
        cout << "Area: " << e1->get_area() << endl;
        cout << "Perimeter " << e1->get_perimeter() << endl;

        delete s1;
        delete s2;
        delete s3;
        delete s4;
        delete s5;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
