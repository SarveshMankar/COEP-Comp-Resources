#Tkinter Program to diplay 4 labels in 4 egdes of the window with different colors

from tkinter import *

class Assignment4:
    def __init__(self) -> None:
        self.root = Tk()
        self.root.title("Assignment-4")
        self.root.geometry("400x400")
        self.root.configure(bg="black")
        self.root.resizable(0,0)


    def change_color(self):
        import random
        colors = ["red", "blue", "green", "yellow", "pink", "orange", "purple", "brown", "white", "grey"]
        self.top.configure(bg=random.choice(colors))
        self.bottom.configure(bg=random.choice(colors))
        self.left.configure(bg=random.choice(colors))
        self.right.configure(bg=random.choice(colors))

    def main(self):
        self.top = Label(self.root, text="Top", bg="red", fg="black")
        self.top.pack(side=TOP, fill=X)

        self.bottom = Label(self.root, text="Bottom", bg="blue", fg="black")
        self.bottom.pack(side=BOTTOM, fill=X)

        self.left = Label(self.root, text="Left", bg="green", fg="black")
        self.left.pack(side=LEFT, fill=Y)

        self.right = Label(self.root, text="Right", bg="yellow", fg="black")
        self.right.pack(side=RIGHT, fill=Y)

        #Adding a button in Center to call change_color function
        self.btn = Button(self.root, text="Change Color", command=self.change_color)
        self.btn.place(relx=0.5, rely=0.5, anchor=CENTER)


if __name__ == "__main__":
    obj = Assignment4()
    obj.main()
    obj.root.mainloop()
