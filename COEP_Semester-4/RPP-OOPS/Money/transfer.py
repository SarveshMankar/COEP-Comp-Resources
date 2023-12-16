import sqlite3
#from pprint import pprint

var=sqlite3.connect('data2.db')
v=var.cursor()

#v.execute('select * from data1 where id<=93')
#v.execute('select * from data1 where id>=95 and id<=96')
v.execute('select * from data1 where id>=98 and id<=106')
a=v.fetchall()

var.commit()
var.close()
print(a)

var=sqlite3.connect('data.db')
v=var.cursor()
'''v.execute("""CREATE table data1(id integer PRIMARY KEY,
        dd text NOT NULL,
        ffrom text NOT NULL,
        tto text NOT NULL,
        dc text NOT NULL,
        amt integer NOT NULL,
        more text,
        mainacc text NOT NULL
        )""")'''

for i in a:
    if i[4]=='Debit':
        ma=i[2]
    else:
        ma=i[3]

    v.execute("INSERT INTO data1 (dd,ffrom,tto,dc,amt,more,mainacc) VALUES(:dd,:f,:ttoo,:dc,:a,:m,:ma)",
    {
        'dd':i[1],
        'f':i[2],
        'ttoo':i[3],
        'dc':i[4],
        'a':i[5],
        'm':i[6],
        'ma':ma
    })

var.commit()
var.close()
