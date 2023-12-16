'''import sqlite3
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

var=sqlite3.connect('data.db')
v=var.cursor()

v.execute("select dd,amt from data1")
data=v.fetchall()

var.commit()
var.close()

#print(data)

data1=[]

for i in data:
    a=i[0].split('-')
    a=a[0]
    if a==str(2021):
        data1.append(i)

#print("\nNew:-",data1)

d=[]
c=[]
for i in range(1,13):
    nd=0
    nc=0
    for j in data1:
        a=j[0].split('-')
        if float(a[1])==float(i):
            #print(float(a[1]))
            if float(j[1])<0:
                nd=nd+float(j[1])
            else:
                nc=nc+float(j[1])
    nd=float(nd)*(-1)
    d.append(nd)
    c.append(nc)

print("Debit=",d)
print("Credit=",c)

labels = ['January', 'February', 'March', 'April', 'May','June','July','Aug','Sept','Oct','Nov','Dec']

x = np.arange(len(labels))  # the label locations
width = 0.45  # the width of the bars

fig, ax = plt.subplots()
g1 = ax.bar(x - width/2, c, width, label='Credit')
g2 = ax.bar(x + width/2, d, width, label='Debit')
ax.set_ylabel('Rupees')
ax.set_title('Monthly Report of Year ')
ax.set_xticks(x)
ax.set_xticklabels(labels)

def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height+2),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')

autolabel(g1)
autolabel(g2)

ax.legend()
plt.show()
plt.tight_layout()

"""import sqlite3
var=sqlite3.connect('data.db')
v=var.cursor()

v.execute("select dd,amt from data1")
data=v.fetchall()

var.commit()
var.close()

data1=[]

for i in data:
    a=i[0].split('-')
    a=a[0]
    if a==str(2021):
        data1.append(i)

d=[]
c=[]
for i in range(1,13):
    nd=0
    nc=0
    for j in data1:
        a=j[0].split('-')
        if float(a[1])==float(i):
            if float(j[1])<0:
                nd=nd+float(j[1])
            else:
                nc=nc+float(j[1])
    nd=float(nd)*(-1)
    d.append(nd)
    c.append(nc)

months = ['January', 'February', 'March', 'April', 'May','June','July','Aug','Sept','Oct','Nov','Dec']
print("Debit=",d)
print("Credit=",c)"""

'''
from tkinter import *

root=Tk()

root.title("Calculator ~by Sam Tech")

global lst
lst=[]

def calculate(lst):
    b=lst

    print(b)

    for i in b:
        if i=="/":
            o=b.index('/')
            n2=b.pop(o+1)
            n1=b.pop(o-1)
            ans=float(n1)/float(n2)
            extra=[str(ans)]
            b=b[:o-1]+extra+b[o:]

    for i in b:
        if i=="*":
            o=b.index('*')
            n2=b.pop(o+1)
            n1=b.pop(o-1)
            ans=float(n1)*float(n2)
            extra=[str(ans)]
            b=b[:o-1]+extra+b[o:]

    for i in b:
        if i=="+":
            o=b.index('+')
            n2=b.pop(o+1)
            n1=b.pop(o-1)
            ans=float(n1)+float(n2)
            extra=[str(ans)]
            b=b[:o-1]+extra+b[o:]

    while '-' in b:
        for i in b:
            if i=="-":
                o=b.index('-')
                n2=b.pop(o+1)
                n1=b.pop(o-1)
                ans=float(n1)-float(n2)
                extra=[str(ans)]
                b=b[:o-1]+extra+b[o:]

    return float(b[0])

def click(num):
    cur=e.get()
    e.delete(0,END)
    e.insert(0,str(cur) + str(num))

def clear():
    e.delete(0,END)
    lst=[]

def add():
    first=e.get()
    e.delete(0,END)
    lst.append(str(first))
    lst.append('+')

def sub():
    first=e.get()
    e.delete(0,END)
    lst.append(str(first))
    lst.append('-')    

def mul():
    first=e.get()
    e.delete(0,END)
    lst.append(str(first))
    lst.append('*')

def div():
    first=e.get()
    e.delete(0,END)
    lst.append(str(first))
    lst.append('/')

def equal():
    second=e.get()
    e.delete(0,END)
    global lst
    lst.append(second)
    print(lst)
    ans=calculate(lst)
    e.insert(0,str(ans))
    lst=[]

def backspace():
    h=e.get()
    h=str(h[:-1])
    e.delete(0,END)
    e.insert(0,str(h))

e=Entry(root,width=56,borderwidth=5,bg="Silver")

button1=Button(root,text="1",width=8,padx=10,pady=10,bg="Dark Gray",command=lambda: click(1))
button2=Button(root,text="2",width=9,padx=10,pady=10,bg="Dark Gray",command=lambda: click(2))
button3=Button(root,text="3",width=8,padx=10,pady=10,bg="Dark Gray",command=lambda: click(3))
button4=Button(root,text="4",width=9,padx=10,pady=10,bg="Dark Gray",command=lambda: click(4))
button5=Button(root,text="5",width=8,padx=10,pady=10,bg="Dark Gray",command=lambda: click(5))
button6=Button(root,text="6",width=9,padx=10,pady=10,bg="Dark Gray",command=lambda: click(6))
button7=Button(root,text="7",width=8,padx=10,pady=10,bg="Dark Gray",command=lambda: click(7))
button8=Button(root,text="8",width=9,padx=10,pady=10,bg="Dark Gray",command=lambda: click(8))
button9=Button(root,text="9",width=8,padx=10,pady=10,bg="Dark Gray",command=lambda: click(9))
button0=Button(root,text="0",width=9,padx=10,pady=10,bg="Dark Gray",command=lambda: click(0))

button_eq=Button(root,text="=",width=21,padx=10,pady=10,bg="Dark Gray",command= equal)
button_clr=Button(root,text="Clear",width=21,padx=10,pady=10,bg="Dark Gray",command=clear)
button_exit=Button(root,text="Backspace",width=8,padx=10,pady=10,command=backspace,bg="Dark Gray")
button_add=Button(root,text="+",width=9,padx=10,pady=10,bg="Dark Gray",command=add)
button_sub=Button(root,text="-",width=8,padx=10,pady=10,bg="Dark Gray",command=sub)
button_mul=Button(root,text="*",width=9,padx=10,pady=10,bg="Dark Gray",command=mul)
button_div=Button(root,text="/",width=8,padx=10,pady=10,bg="Dark Gray",command=div)
button_dot=Button(root,text=".",width=9,padx=10,pady=10,bg="Dark Gray",command= lambda:click("."))

e.grid(row=0,column=0,columnspan=5)


button_eq.grid(row=1,column=0,columnspan=2)
button_clr.grid(row=1,column=2,columnspan=2)
button_exit.grid(row=5,column=3)

button_add.grid(row=2,column=0)
button_sub.grid(row=2,column=1)
button_mul.grid(row=2,column=2)
button_div.grid(row=2,column=3)
button_dot.grid(row=5,column=2)

button0.grid(row=3,column=0)
button1.grid(row=3,column=1)
button2.grid(row=3,column=2)
button3.grid(row=3,column=3)
button4.grid(row=4,column=0)
button5.grid(row=4,column=1)
button6.grid(row=4,column=2)
button7.grid(row=4,column=3)
button8.grid(row=5,column=0)
button9.grid(row=5,column=1)

#root.mainloop()
