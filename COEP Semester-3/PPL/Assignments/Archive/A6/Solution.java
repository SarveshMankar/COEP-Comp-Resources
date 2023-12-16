interface Shape {
    public void draw();
}

class Circle implements Shape {
    int radius;

    Circle(int radius) {
        this.radius = radius;
    }

    int area() {
        return (int) (Math.PI * radius * radius);
    }

    int perimeter() {
        return (int) (2 * Math.PI * radius);
    }

    public void draw() {
        System.out.println("Drawing a circle");
    }

}

class Polygon implements Shape {
    int edges;

    public void draw() {
        System.out.println("Drawing a polygon");
    }

}

class Triangle extends Polygon {
    int base;
    int height;

    Triangle(int base, int height) {
        this.base = base;
        this.height = height;
    }

    int area() {
        return (base * height) / 2;
    }

    int perimeter() {
        return 3 * base;
    }

}

class Square extends Polygon {

    Square(int edges) {
        this.edges = edges;
    }

    int area() {
        return edges * edges;
    }

    int perimeter() {
        return 4 * edges;
    }

}

class Rhombus extends Polygon {

    Rhombus(int edges) {
        this.edges = edges;
    }

    int area() {
        return edges * edges;
    }

    int perimeter() {
        return 4 * edges;
    }

}

class Rectangle extends Polygon {
    int length;
    int breadth;

    Rectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    int area() {
        return length * breadth;
    }

    int perimeter() {
        return 2 * (length + breadth);
    }

}

class Octagon extends Polygon {

    Octagon(int edges) {
        this.edges = edges;
    }

    int area() {
        return (int) (2 * (1 + Math.sqrt(2)) * edges * edges);
    }

    int perimeter() {
        return 8 * edges;
    }

    public void draw() {
        System.out.println("Drawing an octagon");
    }

}

public class Solution {
    public static void main(String[] args) {
        Square square = new Square(5);
        System.out.println(square.area());
        System.out.println(square.perimeter());

        Triangle triangle = new Triangle(5, 10);
        System.out.println(triangle.area());
        System.out.println(triangle.perimeter());

        Rectangle rectangle = new Rectangle(5, 10);
        System.out.println(rectangle.area());
        System.out.println(rectangle.perimeter());

        Rhombus rhombus = new Rhombus(5);
        System.out.println(rhombus.area());
        System.out.println(rhombus.perimeter());

        Octagon octagon = new Octagon(5);
        System.out.println(octagon.area());
        System.out.println(octagon.perimeter());
    }
}
