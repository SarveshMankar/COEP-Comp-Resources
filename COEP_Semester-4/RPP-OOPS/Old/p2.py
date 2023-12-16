#Examples of Inheritance

#Single Inheritance
class parent:
    def __init__(self):
        print("Calling parent constructor")

    def parentMethod(self):
        print("Calling parent method")

class child1(parent):
    def __init__(self):
        print("Calling child1 constructor")

    def childMethod(self):
        print("Calling child1 method")

    def child1ParentMethod(self):
        print("Calling child1 method")

#Heirarchical Inheritance
class child2(parent):
    def __init__(self):
        print("Calling child2 constructor")

    def childMethod(self):
        print("Calling child2 method")
        
#Multiple Inheritance
class parent2:
    def __init__(self):
        print("Calling parent2 constructor")

    def parentMethod(self):
        print("Calling parent2 method")

class child3(parent, parent2):
    def __init__(self):
        print("Calling child3 constructor")

    def childMethod(self):
        print("Calling child3 method")

#Multilevel Inheritance
class child4(child1):
    def __init__(self):
        print("Calling child4 constructor")

    def childMethod(self):
        print("Calling child4 method")




print("Single Inheritance")
print("Child 1:")
c1 = child1()
c1.childMethod()
c1.parentMethod()

print("")

print("Heirarchical Inheritance")
print("Child 2:")
c2 = child2()
c2.childMethod()
c2.parentMethod()

print("")

print("Multiple Inheritance")
print("Child 3:")
c3 = child3()
c3.childMethod()
c3.parentMethod()

print("")

print("Multilevel Inheritance")
print("Child 4:")
c4 = child4()
c4.childMethod()
c4.child1ParentMethod()
c4.parentMethod()
