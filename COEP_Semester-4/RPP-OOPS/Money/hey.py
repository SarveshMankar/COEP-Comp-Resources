d1=[]
            for i in z:
                ii=i[0].split('-')
                if float(ii[1])==mn and float(ii[0])==float(y):
                    d1.append(i)
                else:
                    pass

            dates=[]
            for i in d1:
                s=datetime.strptime(i[0],"%Y-%m-%d")
                if s not in dates:
                    dates.append(s)
                else:
                    pass

            fdates=[]
            for i in dates:
                dd=str(i).split(" ")
                fdates.append(dd[0])

            c=[]
            d=[]
            for i in fdates:
                nc=0
                nd=0
                for j in d1:
                    if datetime.strptime(j[0],"%Y-%m-%d")==datetime.strptime(i,"%Y-%m-%d"):
                        if float(j[1])<0:
                            nd=nd+float(float(j[1]*-1))
                        else:
                            nc=nc+float(j[1])
                c.append(nc)
                d.append(nd)

            var.commit()
            var.close()

            daa=zip(fdates,c,d)
            data=list(daa)
            

ddata1+cdata1
[('2021-6-2', -240, 96), ('2021-6-2', 1, 97), 
('2021-6-2', -1, 98), ('2021-6-5', -149, 99), 
('2021-6-7', -17.7, 100), ('2021-6-7', -30, 101), 
('2021-6-7', -149, 103), ('2021-6-17', -96, 108), 
('2021-6-20', -400, 110), ('2021-6-21', -251, 111), 
('2021-6-21', -340, 112), ('2021-6-21', -96, 114), 
('2021-6-26', -96, 115), ('2021-6-27', -151, 116), 
('2021-6-2', 500, 95), ('2021-6-7', 500, 102), 
('2021-6-13', 3, 104), ('2021-6-13', 19, 105), 
('2021-6-14', 6, 106), ('2021-6-15', 6, 107), 
('2021-6-20', 1000, 109), ('2021-6-21', 5, 113)]

i1
[95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 
106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116]

iddd
['2021-6-2', '2021-6-2', '2021-6-2', '2021-6-2', 
'2021-6-5', '2021-6-7', '2021-6-7', '2021-6-7', 
'2021-6-7', '2021-6-13', '2021-6-13', '2021-6-14', 
'2021-6-15', '2021-6-17', '2021-6-20', '2021-6-20', 
'2021-6-21', '2021-6-21', 
'2021-6-21', '2021-6-21', '2021-6-26', '2021-6-27']

dates
[datetime.datetime(2021, 6, 2, 0, 0), 
datetime.datetime(2021, 6, 5, 0, 0), 
datetime.datetime(2021, 6, 7, 0, 0), 
datetime.datetime(2021, 6, 13, 0, 0), 
datetime.datetime(2021, 6, 14, 0, 0), 
datetime.datetime(2021, 6, 15, 0, 0), 
datetime.datetime(2021, 6, 17, 0, 0), 
datetime.datetime(2021, 6, 20, 0, 0), 
datetime.datetime(2021, 6, 21, 0, 0), 
datetime.datetime(2021, 6, 26, 0, 0), 
datetime.datetime(2021, 6, 27, 0, 0)]

fdates
['2021-06-02', '2021-06-05', '2021-06-07', '2021-06-13', 
'2021-06-14', '2021-06-15', '2021-06-17', 
'2021-06-20', '2021-06-21', '2021-06-26', '2021-06-27']



            '''if itype=="Debit":
                if lst2[0][1]==lst1[0] and lst2[0][2]==lst1[1] and lst2[0][3]==lst1[2] and lst2[0][4]=='Credit' and float(lst2[0][5])==float((lst1[4])*-1) and lst2[0][6]==lst1[5] and lst2[0][7]==lst1[2]:
                    idtodo=tid1
                elif lst3[0][1]==lst1[0] and lst3[0][2]==lst1[1] and lst3[0][3]==lst1[2] and lst3[0][4]=='Credit' and float(lst3[0][5])==float(lst1[4]) and lst3[0][6]==lst1[5] and lst3[0][7]==lst1[3]:
                    idtodo=tid2
            elif itype=="Credit":
                if lst3[0][1]==lst1[0] and lst3[0][2]==lst1[1] and lst3[0][3]==lst1[2] and lst3[0][4]=='Debit' and float(lst3[0][5])==float(float(lst1[4])*-1) and lst3[0][6]==lst1[5] and lst3[0][7]==lst1[3]:
                    idtodo=tid2
                elif lst2[0][1]==lst1[0] and lst2[0][2]==lst1[1] and lst2[0][3]==lst1[2] and lst2[0][4]=='Debit' and float(lst2[0][5])==float((lst1[4])*-1) and lst2[0][6]==lst1[5] and lst2[0][7]==lst1[2]:
                    idtodo=tid1'''