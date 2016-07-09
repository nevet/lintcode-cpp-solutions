/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class Triangle: public Shape {
    void draw() const {
        cout << "  /\\  " << endl;
        cout << " /  \\ " << endl;
        cout << "/____\\" << endl;
    }
};

class Square: public Shape {
    void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if (shapeType == "Square") return new Square();
        if (shapeType == "Triangle") return new Triangle();
        if (shapeType == "Rectangle") return new Rectangle();
    }
};




