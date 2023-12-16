class Boss:
    def __init__(self):
        print("Boss constructor")
        
class B1(Boss):
    def __init__(self):
        #super().__init__()
        print("B1 constructor")
        
class B2(Boss):
    def __init__(self):
        #super().__init__()
        print("B2 constructor")
        
class Child(B1,B2):
    def __init__(self):
        super().__init__()
        print("Child constructor")
        
b = Child()