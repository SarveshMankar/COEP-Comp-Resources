#Write a program to display a menu on the menu bar with more than 5 options.
# When the user clicks on any of the menu items, the name of the menu item should be
# displayed on the status bar.

from tkinter import *

class Assignment5:

    def __init__(self) -> None:
        self.root = Tk()
        self.root.title("Assignment-5")
        self.root.geometry("400x400")
        self.root.configure(bg="white")
        self.root.resizable(0,0)

    def main(self):
        self.menubar = Menu(self.root)

        self.filemenu = Menu(self.menubar, tearoff=0)
        # On click change the text of Status bar
        self.filemenu.add_command(label="New", command=lambda: self.change_status("New"))
        self.filemenu.add_command(label="Open", command=lambda: self.change_status("Open"))
        self.filemenu.add_command(label="Save", command=lambda: self.change_status("Save"))
        self.filemenu.add_command(label="Save as...", command=lambda: self.change_status("Save as..."))
        self.filemenu.add_command(label="Close", command=lambda: self.change_status("Close"))
        self.filemenu.add_separator()
        self.filemenu.add_command(label="Exit", command=self.root.quit)

        self.menubar.add_cascade(label="File", menu=self.filemenu)
        self.editmenu = Menu(self.menubar, tearoff=0)
        # On click change the text of Status bar
        self.editmenu.add_command(label="Undo", command=lambda: self.change_status("Undo"))
        self.editmenu.add_separator()
        self.editmenu.add_command(label="Cut", command=lambda: self.change_status("Cut"))
        self.editmenu.add_command(label="Copy", command=lambda: self.change_status("Copy"))
        self.editmenu.add_command(label="Paste", command=lambda: self.change_status("Paste"))
        self.editmenu.add_command(label="Delete", command=lambda: self.change_status("Delete"))
        self.editmenu.add_command(label="Select All", command=lambda: self.change_status("Select All"))

        self.menubar.add_cascade(label="Edit", menu=self.editmenu)
        self.helpmenu = Menu(self.menubar, tearoff=0)
        # On click change the text of Status bar
        self.helpmenu.add_command(label="Help Index", command=lambda: self.change_status("Help Index"))
        self.helpmenu.add_command(label="About...", command=lambda: self.change_status("About..."))
        self.menubar.add_cascade(label="Help", menu=self.helpmenu)        

        self.root.config(menu=self.menubar)

        self.statusbar = Label(self.root, text="Status Bar", bd=1, relief=SUNKEN, anchor=W)
        self.statusbar.pack(side=BOTTOM, fill=X)

    def change_status(self, text):
        self.statusbar.config(text=text)

if __name__ == "__main__":
    obj = Assignment5()
    obj.main()
    obj.root.mainloop()