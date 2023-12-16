import tkinter as tk

root = tk.Tk()
root.title("Tkinter Demo")

"""# Create a label
label = tk.Label(root, text="Hello World")
label.pack()

# Create a button
button = tk.Button(root, text="Click Me")
button.pack()

# Create a text box
text = tk.Text(root, width=40, height=10)
text.pack()"""

Hello = tk.Label(root, text="Hello World")
Hello.grid(row=0, column=0)
Name = tk.Label(root, text="Name")
Name.grid(row=1, column=0)
Age = tk.Label(root, text="Age")
Age.grid(row=2, column=0)


root.mainloop()
