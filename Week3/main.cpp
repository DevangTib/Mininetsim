#include "Canvas.cpp"

int main() {
    Canvas canvas;

    Rectangle* r = new Rectangle(100, 50, "red");
    r->translate(50, 50);
    canvas.addShape(r);

    Square* s = new Square(60, "blue");
    s->translate(200, 100);
    canvas.addShape(s);

    Circle* c = new Circle(40, "green");
    c->translate(400, 200);
    canvas.addShape(c);

    Ellipse* e = new Ellipse(80, 40, "yellow");
    e->translate(600, 100);
    canvas.addShape(e);

    canvas.displayCanvas();

    return 0;
}
