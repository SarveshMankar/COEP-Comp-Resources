class shapes:
    def __init__(self, name):
        self.name = name
    
    def area(self):
        pass
    
    def perimeter(self):
        pass

    def dimensions(self):
        pass


class circle(shapes):
    def __init__(self, name, radius):
        super().__init__(name)
        self.radius = radius
    
    def area(self):
        return 3.14 * self.radius * self.radius
    
    """def area(self, radius):
        return 3.14 * radius * radius"""
    
    def perimeter(self):
        return 2 * 3.14 * self.radius
    
    def dimensions(self, radius):
        print(f"Radius: {self.radius:.2f}")

class rectangle(shapes):
    def __init__(self, name, length, breadth):
        super().__init__(name)
        self.length = length
        self.breadth = breadth
    
    def area(self):
        return self.length * self.breadth
    
    def perimeter(self):
        return 2 * (self.length + self.breadth)
    
    def dimensions(self, length, breadth):
        print("Length: ", self.length)
        print("Breadth: ", self.breadth)

class square(shapes):
    def __init__(self, name, side):
        super().__init__(name)
        self.side = side

    def area(self):
        return self.side * self.side
    
    def perimeter(self):
        return 4 * self.side
    
    def dimensions(self, side):
        print("Side: ", self.side)

class pentagon(shapes):
    def __init__(self, name, side):
        super().__init__(name)
        self.side = side

    def area(self):
        return (5/2) * (self.side * self.side)
    
    def perimeter(self):
        return 5 * self.side
    
    def dimensions(self, side):
        print("Side: ", self.side)

class hexagon(shapes):
    def __init__(self, name, side):
        super().__init__(name)
        self.side = side

    def area(self):
        return (3 * (3**0.5) * (self.side * self.side)) / 2
    
    def perimeter(self):
        return 6 * self.side
    
    def dimensions(self, side):
        print("Side: ", self.side)
    

circle1 = circle("My 1st Circle", 5.34543543)
print("Circle: ", circle1.name)
circle1.dimensions(5.34543543)
print("Area",circle1.area())
print("Perimeter",circle1.perimeter())

print()

rectangle1 = rectangle("My 1st Rectangle", 5, 10)
print("Rectangle: ", rectangle1.name)
rectangle1.dimensions(5, 10)
print("Area",rectangle1.area())
print("Perimeter",rectangle1.perimeter())

print()

square1 = square("My 1st Square", 5)
print("Square: ", square1.name)
square1.dimensions(5)
print("Area",square1.area())
print("Perimeter",square1.perimeter())

print()

pentagon1 = pentagon("My 1st Pentagon", 5)
print("Pentagon: ", pentagon1.name)
pentagon1.dimensions(5)
print("Area",pentagon1.area())
print("Perimeter",pentagon1.perimeter())

print()

