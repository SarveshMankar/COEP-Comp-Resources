class Animals:

    __eyes = 2

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def get_name(self):
        return self.name

    def set_eyes(self):
        self.__eyes = 2

    def get_eyes(self):
        return self.__eyes

    
class Carnivores(Animals):
    def __init__(self, name, age):
        super().__init__(name, age)
        self.set_eyes()


class Herbivores(Animals):
    def __init__(self, name, age):
        super().__init__(name, age)
        self.set_eyes()


c1= Herbivores("Dog", 10)
print(c1.get_eyes())

print(c1._Animals__eyes)
print(c1.__eyes)

