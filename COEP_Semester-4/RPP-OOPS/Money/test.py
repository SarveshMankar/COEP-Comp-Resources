from kivymd.app import MDApp
from kivymd.uix.screen import Screen
from kivy.lang import Builder
from kivy.uix.screenmanager import Screen,ScreenManager
from kivymd.uix.menu import MDDropdownMenu
from kivy.metrics import dp
from kivymd.uix.datatables import MDDataTable
from kivymd.uix.dialog import MDDialog
from kivymd.uix.button import MDRectangleFlatButton,MDFlatButton
import sqlite3
from datetime import datetime
from kivy.core.window import Window
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from pprint import pprint
from extras import *
#from kivy.config import Config

from test_screen import screen_helper

class HOScreen(Screen):
    pass

class UPScreen(Screen):
    pass

class ENScreen(Screen):
    pass

class SOScreen(Screen):
    pass

class SOCScreen(Screen):
    pass

class REScreen(Screen):
    pass

class ACScreen(Screen):
    pass

class MoneyApp(MDApp):

    def build(self):
        #Window.fullscreen = 'auto'
        self.theme_cls.theme_style="Dark"
        self.theme_cls.primary_palette="Cyan"
        self.theme_cls.primary_hue="A700"
        Window.fullscreen = False
        self.screen=Builder.load_string(screen_helper)
        return self.screen

    def show_textnamenuu44(self,a):
        self.screen.ids.ups.ids.u3.text=a.text

    def show_textnamenuu88(self,a):
        self.screen.ids.ups.ids.u7.text=a.text

    def save1(self):
        #self.screen.ids.ens.ids.enf.text
        var=sqlite3.connect('data.db')
        v=var.cursor()
        ffrom=self.screen.ids.ens.ids.enf.text
        ttype=self.screen.ids.ens.ids.ent.text
        ddate=self.screen.ids.ens.ids.end.text
        aamount=self.screen.ids.ens.ids.ena.text
        mmore=self.screen.ids.ens.ids.enm.text
        ttoo=self.screen.ids.ens.ids.entt.text
        bamount=aamount


        '''v.execute("""CREATE table data1(id integer PRIMARY KEY,
            dd text NOT NULL,
            ddate integer NOT NULL,
            dmonth integer NOT NULL,
            dyear Integer NOT NULL,
            ffrom text NOT NULL,
            tto text NOT NULL,
            dc text NOT NULL,
            amt integer NOT NULL,
            more text	
            )""")'''
        try:
            if ffrom!='' and ttype!='' and ddate!='' and aamount!='' and ttoo!='' and float(aamount)>0:
                try:
                    format = "%Y-%m-%d"
                    datetime.strptime(ddate,format)
                    if ttype=="Debit":
                        bamount=float(str('-') + str(aamount))
                    v.execute("INSERT INTO data1 (dd,ffrom,tto,dc,amt,more) VALUES(:dd,:f,:ttooo,:dc,:a,:m)",{
                        'dd':ddate,
                        'f':ffrom,
                        'ttooo':ttoo,
                        'dc':ttype,
                        'a':bamount,
                        'm':mmore
                    })
                    bcloses=MDFlatButton(text="Close",on_release=self.closes)
                    self.dialogs=MDDialog(title="Money App",text="Record Saved!",buttons=[bcloses])
                    self.dialogs.open()
                    self.screen.ids.ens.ids.enf.text=''
                    self.screen.ids.ens.ids.ent.text=''
                    self.screen.ids.ens.ids.ena.text=''
                    self.screen.ids.ens.ids.enm.text=''
                    self.screen.ids.ens.ids.entt.text=''
                except:
                    bclosee=MDFlatButton(text="Close",on_release=self.closee)
                    self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                    self.dialogee.open()
                    #print("Error!   1")
            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
                #print("Error!   2")
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()
            #print("Error!   3")

        var.commit()
        var.close()
        
    def show_text2(self,word):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        self.screen.ids.ens.ids.ent.text=word.text
        self.screen.ids.ens.ids.enf.text=""
        if word.text=="Debit":
            v.execute("Select a from accounts where s=\"Open\"")
            a=v.fetchall()
            aa=[i[0] for i in a]
            aa.sort()
            self.lst1=[{'text':f'{i}'} for i in aa]
            self.screen.ids.ens.ids.entt.text=""
            v.execute("select distinct(tto) from data1 where dc=\"Debit\"")
            abc=v.fetchall()
            abc1=[i[0] for i in abc]
            abc1.sort()
            self.lst3=[]
            for i in abc1:
                abcabc={'text':str(i)}
                self.lst3.append(abcabc)
            self.screen.ids.ens.ids.drop3.disabled=False
        else:
            v.execute("Select a from accounts where s=\"Open\"")
            a=v.fetchall()
            aa=[i[0] for i in a]
            aa.sort()
            self.lst3=[{'text':f'{i}'} for i in aa]
            self.lst1=[]
            self.screen.ids.ens.ids.drop3.disabled=False
            self.screen.ids.ens.ids.entt.text=""
            v.execute("SELECT distinct(ffrom) from data1 where dc=\"Credit\"")
            q=v.fetchall()
            #print(q)
            qq=[i[0] for i in q]
            qq.sort()
            for i in qq:
                j={'text':i}
                self.lst1.append(j)
        #self.menu2.close()
        var.commit()
        var.close()

        #print("HEY",self.lst1)
        self.screen.ids.ens.ids.drop1.disabled=False
        self.menu1=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop1,
            items=self.lst1,
            width_mult=4,
            callback=self.show_text1,)

        self.menu3=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop3,
            items=self.lst3,
            width_mult=5,
            callback=self.show_text3,)

    def shownormaldatewise(self):
        try:
            self.screen.ids.sos.ids.nda.hint_text=""
            self.screen.ids.sos.ids.ndt.hint_text=""
            self.screen.ids.sos.ids.ndd.hint_text=""
            d1=self.screen.ids.sos.ids.normalfromdate.text
            d2=self.screen.ids.sos.ids.normaltodate.text
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute("select * from data1")
            data=v.fetchall()
            data1=[]
            for i in data:
                if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                    data1.append(i)

            mainndlist=[]
            for i in data1:
                b=list(i)
                if b[5]<0:
                    b[5]=b[5]*(-1)
                    mainndlist.append(b)
                else:
                    mainndlist.append(b)

            #print(mainndlist)
            self.columnofnormaldatewise=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(35)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
            self.tableofnormaldate=MDDataTable(
                            size_hint_y=None,
                            size_hint_x=None,
                            width=1100,
                            height=400,
                            pos_hint={'center_x':0.5,'center_y':0.62},
                            use_pagination=True,
                            column_data=self.columnofnormaldatewise,
                            row_data=mainndlist)
            a=0
            b=0

            for i in mainndlist:
                if i[4]=="Debit":
                    a=a+(float(i[5]))
                else:
                    #print(i[5])
                    b=b+i[5]

            #print("a:",a," b:",b)
            self.screen.ids.sos.ids.ndd.hint_text=str("Credit:")+str(float(b))+str("        Debit:")+str(float(a*(1)))

            self.tableofnormaldate.open()
            var.commit()
            var.close()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def exportshownormaldatewise(self):
        d1=self.screen.ids.sos.ids.normalfromdate.text
        d2=self.screen.ids.sos.ids.normaltodate.text
        if d1!="" and d2!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute("select * from data1")
            data=v.fetchall()
            data1=[]
            for i in data:
                if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                    data1.append(i)

            mainndlist=[]
            for i in data1:
                b=list(i)
                if b[5]<0:
                    b[5]=b[5]*(-1)
                    mainndlist.append(b)
                else:
                    mainndlist.append(b)
            var.commit()
            var.close()
            c=['Id','Date','From','To','D/C','Amount','Narration']
            df=pd.DataFrame(mainndlist,columns=c)
            df.style.set_caption('All Data-> Money App')
            df.to_csv('Exports/Date_Wise.csv',index=False)
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out Date_Wise.csv file in the Exports Folder!",buttons=[bclosee])
            self.dialogee.open()
        else:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def shownormaltypewise(self):
        try:
            self.screen.ids.sos.ids.nda.hint_text=""
            self.screen.ids.sos.ids.ndt.hint_text=""
            self.screen.ids.sos.ids.ndd.hint_text=""
            ntype=self.screen.ids.sos.ids.normaltype.text

            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute(f"select * from data1 where ffrom=\"{ntype}\" or tto=\"{ntype}\"")
            ntdata=v.fetchall()

            mainntlist=[]
            m=0
            for i in ntdata:
                b=list(i)
                m+=float(b[5])
                s="{:.2f}".format(m)
                b.append(s)
                if b[5]<0:
                    aa=b[5]
                    aab=aa*2
                    b[5]=aa-aab
                mainntlist.append(b)

            self.columnoftype=[("Id",dp(13)),("Date",dp(25)),("From",dp(30)),("To",dp(40)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40)),("Balance",dp(30))]
            self.tableoftype=MDDataTable(
                            size_hint_y=None,
                            height=400,
                            size_hint_x=None,
                            width=1250,
                            pos_hint={'center_x':0.5,'center_y':0.62},
                            use_pagination=True,
                            column_data=self.columnoftype,
                            row_data=mainntlist)

            v.execute(f"select sum(amt) from data1 where ffrom=\"{ntype}\" and dc=\"Debit\"")
            a=v.fetchall()
            v.execute(f"select sum(amt) from data1 where tto=\"{ntype}\" and dc=\"Credit\"")
            b=v.fetchall()
            self.screen.ids.sos.ids.ndt.hint_text=str("Credit:")+str(float(b[0][0]))+str("        Debit:")+str(float(a[0][0]*(-1)))
            var.commit()
            var.close()
            self.tableoftype.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()
            
    def exportshownormaltypewise(self):
        ntype=self.screen.ids.sos.ids.normaltype.text
        if ntype!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute(f"select * from data1 where ffrom=\"{ntype}\" or tto=\"{ntype}\"")
            ntdata=v.fetchall()
            var.commit()
            var.close()

            mainntlist=[]
            m=0
            for i in ntdata:
                b=list(i)
                m+=float(b[5])
                s="{:.2f}".format(m)
                b.append(s)
                if b[5]<0:
                    b[5]=float(b[5])*-1
                mainntlist.append(b)

            c=['Id','Date','From','To','D/C','Amount','Narration','Balance']
            df=pd.DataFrame(mainntlist,columns=c)
            df.style.set_caption('All Data-> Money App')
            df.to_csv('Exports/Account_Wise.csv',index=False)
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out Account_Wise.csv file in the Exports Folder!",buttons=[bclosee])
            self.dialogee.open()
        else:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()
            

    def showalltypewise(self):
        self.screen.ids.sos.ids.nda.hint_text=""
        self.screen.ids.sos.ids.ndt.hint_text=""
        self.screen.ids.sos.ids.ndd.hint_text=""
        d1=self.screen.ids.sos.ids.alltypefromdate.text
        d2=self.screen.ids.sos.ids.alltypetodate.text
        attype=self.screen.ids.sos.ids.alltype.text

        try:
            b=datetime.strptime(d1,"%Y-%m-%d")
            c=datetime.strptime(d2,"%Y-%m-%d")
            if attype!="":
                var=sqlite3.connect('data.db')
                v=var.cursor()
                v.execute(f"select * from data1 where ffrom=\"{attype}\" or tto=\"{attype}\"")
                ntdata=v.fetchall()

                mainntlist0=[]
                m=0
                for i in ntdata:
                    b=list(i)
                    m+=float(b[5])
                    s="{:.2f}".format(m)
                    b.append(s)
                    if b[5]<0:
                        aa=b[5]
                        aab=aa*2
                        b[5]=aa-aab
                    mainntlist0.append(b)

                var.commit()
                var.close()
                mainatlist=[]
                for i in mainntlist0:
                    if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                        mainatlist.append(i)

                self.columnofalltype=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(50)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40)),("Balance",dp(30))]
                self.tableofalltype=MDDataTable(
                                size_hint_y=None,
                                height=400,
                                size_hint_x=None,
                                width=1300,
                                pos_hint={'center_x':0.5,'center_y':0.62},
                                use_pagination=True,
                                column_data=self.columnofalltype,
                                row_data=mainatlist)

                self.tableofalltype.open()
                a=0
                b=0
                for i in mainatlist:
                    if i[4]=="Debit":
                        a=a+i[5]
                    else:
                        b=b+i[5]

                self.screen.ids.sos.ids.nda.hint_text=str("Credit:")+str(float(b))+str("        Debit:")+str(float(a*(1)))
            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def exportshowalltypewise(self):
        d1=self.screen.ids.sos.ids.alltypefromdate.text
        d2=self.screen.ids.sos.ids.alltypetodate.text
        attype=self.screen.ids.sos.ids.alltype.text
        try:
            b=datetime.strptime(d1,"%Y-%m-%d")
            c=datetime.strptime(d2,"%Y-%m-%d")
            if attype!="":
                var=sqlite3.connect('data.db')
                v=var.cursor()
                v.execute(f"select * from data1 where ffrom=\"{attype}\" or tto=\"{attype}\"")
                ntdata=v.fetchall()

                mainntlist0=[]
                m=0
                for i in ntdata:
                    b=list(i)
                    m+=float(b[5])
                    s="{:.2f}".format(m)
                    b.append(s)
                    if b[5]<0:
                        aa=b[5]
                        aab=aa*2
                        b[5]=aa-aab
                    mainntlist0.append(b)

                var.commit()
                var.close()
                mainatlist=[]
                for i in mainntlist0:
                    if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                        mainatlist.append(i)

                c=['Id','Date','From','To','D/C','Amount','Narration','Balance']
                df=pd.DataFrame(mainatlist,columns=c)
                df.style.set_caption('All Data-> Money App')
                df.to_csv('Exports/Account_and_Date_Wise.csv',index=False)
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out Account_and_Date_Wise.csv file in the Exports Folder!",buttons=[bclosee])
                self.dialogee.open()

            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def showall(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()

        v.execute("select * from data1")
        data=v.fetchall()
        mainndlist=[]
        for i in data:
            b=list(i)
            if b[5]<0:
                aa=b[5]
                aab=aa*2
                b[5]=aa-aab
            mainndlist.append(b)

        self.columnofall=[("Id",dp(20)),("Date",dp(25)),("From",dp(30)),("To",dp(40)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
        self.tableofall=MDDataTable(
						size_hint_y=None,
						height=450,
                        size_hint_x=None,
                        width=1200,
                        use_pagination=True,
						column_data=self.columnofall,
						row_data=mainndlist)

        self.tableofall.open()
        
        var.commit()
        var.close()

    def exportall(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        v.execute("select * from data1")
        data=v.fetchall()
        var.commit()
        var.close()

        mainndlist=[]
        for i in data:
            b=list(i)
            if b[5]<0:
                aa=b[5]
                aab=aa*2
                b[5]=aa-aab
            mainndlist.append(b)

        c=['Id','Date','From','Tp','D/C','Amount','Narration']
        df=pd.DataFrame(mainndlist,columns=c)
        df.to_csv('Exports/All_Data.csv',index=False)
        bclosee=MDFlatButton(text="Close",on_release=self.closee)
        self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out All_Data.csv file in the Exports Folder!",buttons=[bclosee])
        self.dialogee.open()

    def shownormaltypewiseu(self):
        ntype=self.screen.ids.ups.ids.u3.text
        if ntype=="":
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()
        else:
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select * from data1 where ffrom=\"{ntype}\" or tto=\"{ntype}\"")
            ntdata=v.fetchall()
            #print(ntdata)
            mainntlist=[]
            m=0
            for i in ntdata:
                b=list(i)
                m+=float(b[5])
                s="{:.2f}".format(m)
                b.append(s)
                if b[5]<0:
                    aa=b[5]
                    aab=aa*2
                    b[5]=aa-aab
                mainntlist.append(b)
            #print(mainntlist)
            self.columnoftypeu=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(45)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40)),("Balance",dp(30))]
            self.tableoftypeu=MDDataTable(
                            size_hint_y=None,
                            height=450,
                            size_hint_x=None,
                            width=1250,
                            use_pagination=True,
                            column_data=self.columnoftypeu,
                            row_data=mainntlist)
            self.tableoftypeu.bind(on_row_press=self.tableoftype_press)
            
            self.tableoftypeu.open()
            #print(mainntlist)

            var.commit()
            var.close()

    def shownormaldatewiseu(self):
        try:
            d1=self.screen.ids.ups.ids.u1.text
            d2=self.screen.ids.ups.ids.u2.text
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute("select * from data1")
            data=v.fetchall()
            data1=[]
            for i in data:
                if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                    data1.append(i)
            data2=[]

            for i in data1:
                c=list(i)
                if c[5]<0:
                    c[5]=float(c[5])*(-1)
                else:
                    pass
                data2.append(c)

            self.columnofnormaldatewiseu=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(45)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
            self.tableofnormaldateu=MDDataTable(
                            size_hint_y=None,
                            size_hint_x=None,
                            width=1100,
                            height=450,
                            pos_hint={'center_x':.5,'center_y':.5},
                            use_pagination=True,
                            column_data=self.columnofnormaldatewiseu,
                            row_data=data2)
            self.tableofnormaldateu.bind(on_row_press=self.tableoftype_press)
            
            self.tableofnormaldateu.open()
            var.commit()
            var.close()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def showalltypewiseu(self):
        d1=self.screen.ids.ups.ids.u5.text
        d2=self.screen.ids.ups.ids.u6.text
        attype=self.screen.ids.ups.ids.u7.text

        try:
            b=datetime.strptime(d1,"%Y-%m-%d")
            c=datetime.strptime(d2,"%Y-%m-%d")
            if attype!="":
                var=sqlite3.connect('data.db')
                v=var.cursor()
                v.execute(f"select * from data1 where ffrom=\"{attype}\" or tto=\"{attype}\"")
                ntdata=v.fetchall()
                #print(ntdata)
                mainntlist0=[]
                m=0
                for i in ntdata:
                    b=list(i)
                    m+=float(b[5])
                    s="{:.2f}".format(m)
                    b.append(s)
                    if b[5]<0:
                        aa=b[5]
                        aab=aa*2
                        b[5]=aa-aab
                    mainntlist0.append(b)

                var.commit()
                var.close()
                mainatlist=[]
                for i in mainntlist0:
                    if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                        mainatlist.append(i)
                #print(mainatlist)
                self.columnofalltypeu=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(45)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40)),("Balance",dp(30))]
                self.tableofalltypeu=MDDataTable(
                                size_hint_y=None,
                                height=450,
                                size_hint_x=None,
                                width=1250,
                                use_pagination=True,
                                column_data=self.columnofalltypeu,
                                row_data=mainatlist)
                self.tableofalltypeu.bind(on_row_press=self.tableoftype_press)
                
                self.tableofalltypeu.open()
            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def showallu(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()

        v.execute("select * from data1")
        data=v.fetchall()
        mainndlist=[]
        for i in data:
            b=list(i)
            if b[5]<0:
                aa=b[5]
                aab=aa*2
                b[5]=aa-aab
            mainndlist.append(b)

        self.columnofallu=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(40)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
        self.tableofallu=MDDataTable(
						size_hint_y=None,
						height=450,
                        size_hint_x=None,
                        width=1100,
                        use_pagination=True,
						column_data=self.columnofallu,
						row_data=mainndlist)
        self.tableofallu.bind(on_row_press=self.tableoftype_press)

        self.tableofallu.open()
        
        var.commit()
        var.close()

    def tableoftype_press(self,a,b):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        try:
            v.execute(f"select id,dd,ffrom,tto,dc,amt,more from data1 where id={int(b.text)}")
            self.d=v.fetchall()
        except:
            pass

        try:
            if self.d[0][4]=='Debit':
                self.screen.ids.ups.ids.uu3.disabled=True
                self.screen.ids.ups.ids.uu5.disabled=False
                self.lsstfrom=[{'text':'Bank of Baroda'},{'text':'Cash'},{'text':'PhonePe Wallet'}]
                self.lsstto=[]
                v.execute('select distinct(tto) from data1 where dc=\"Debit\"')
                s=v.fetchall()
                for i in s:
                    z={'text':i[0]}
                    self.lsstto.append(z)
                #print("From;-",self.lsstfrom,"\nTo:-",self.lsstto)
                b=float(self.d[0][5])*2
                a=float(self.d[0][5])-b
            else:
                self.screen.ids.ups.ids.uu3.disabled=False
                self.screen.ids.ups.ids.uu5.disabled=True
                a=float(self.d[0][5])
                self.lsstto=[{'text':'Bank of Baroda'},{'text':'Cash'},{'text':'PhonePe Wallet'}]
                self.lsstfrom=[]
                v.execute('select distinct(ffrom) from data1 where dc=\"Credit\"')
                s=v.fetchall()
                for i in s:
                    z={'text':i[0]}
                    self.lsstfrom.append(z)
                #print("From;-",self.lsstfrom,"\nTo:-",self.lsstto)
        except:
            pass
        self.screen.ids.ups.ids.uu4.disabled=False
        self.screen.ids.ups.ids.uu6.disabled=False
        try:
            self.screen.ids.ups.ids.uu1.text=self.d[0][4]
            self.screen.ids.ups.ids.uu3.text=self.d[0][2]
            self.screen.ids.ups.ids.uu5.text=self.d[0][3]
            self.screen.ids.ups.ids.uu7.text=self.d[0][1]
            self.screen.ids.ups.ids.uu8.text=str(a)
            self.screen.ids.ups.ids.uu9.text=self.d[0][6]
        except:
            pass

        try:
            self.menu1u=MDDropdownMenu(
                caller=self.screen.ids.ups.ids.uu4,
                items=self.lsstfrom,
                width_mult=4,
                callback=self.show_textnamenuu4,)

            self.menu3u=MDDropdownMenu(
                caller=self.screen.ids.ups.ids.uu6,
                items=self.lsstto,
                width_mult=4,
                callback=self.show_textnamenuu6,)
        except:
            pass

        var.commit()
        var.close()

    def show_textnamenuu4(self,a):
        self.screen.ids.ups.ids.uu3.text=a.text

    def show_textnamenuu6(self,a):
        self.screen.ids.ups.ids.uu5.text=a.text

    def updatee(self):
        try:
            var=sqlite3.connect('data.db')
            v=var.cursor()
            z=float(self.screen.ids.ups.ids.uu8.text)
            if self.d[0][4]=='Debit':
                a=str('-')+str(z)
                z=float(a)


            v.execute(f"UPDATE data1 SET id=:iddd,dd=:ddd,ffrom=:ffromf,tto=:ttot,amt=:amta,more=:morem where id={self.d[0][0]}",{
                'iddd':self.d[0][0],
                'ddd':self.screen.ids.ups.ids.uu7.text,
                'ffromf':self.screen.ids.ups.ids.uu3.text,
                'ttot':self.screen.ids.ups.ids.uu5.text,
                'amta':z,
                'morem':self.screen.ids.ups.ids.uu9.text
            })
            var.commit()
            var.close()
            bclosesu=MDFlatButton(text="Close",on_release=self.closesu)
            self.dialogsu=MDDialog(title="Money App",text="Record Updated!",buttons=[bclosesu])
            self.dialogsu.open()

            self.screen.ids.ups.ids.uu8.text=''
            self.screen.ids.ups.ids.uu1.text='' 
            self.screen.ids.ups.ids.uu7.text=''
            self.screen.ids.ups.ids.uu3.text=''
            self.screen.ids.ups.ids.uu5.text=''
            self.screen.ids.ups.ids.uu9.text=''
            self.d=[]
            #print(self.d[0][0])
            self.screen.ids.ups.ids.uu4.disabled=True
            self.screen.ids.ups.ids.uu6.disabled=True
        except:
            bcloseeu=MDFlatButton(text="Close",on_release=self.closeeu)
            self.dialogeeu=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseeu])
            self.dialogeeu.open()
     

    def deletee(self):
        try:
            var=sqlite3.connect('data.db')
            v=var.cursor()
            i=self.d[0][0]
            v.execute(f"DELETE from data1 where id={i}")
            var.commit()
            var.close()
            self.screen.ids.ups.ids.uu1.text=''
            self.screen.ids.ups.ids.uu3.text=''
            self.screen.ids.ups.ids.uu5.text=''
            self.screen.ids.ups.ids.uu7.text=''
            self.screen.ids.ups.ids.uu8.text=''
            self.screen.ids.ups.ids.uu9.text=''
            bclosesd=MDFlatButton(text="Close",on_release=self.closesd)
            self.dialogsd=MDDialog(title="Money App",text="Entry Deleted!",buttons=[bclosesd])
            self.dialogsd.open()
            self.d=[]
            self.screen.ids.ups.ids.uu4.disabled=True
            self.screen.ids.ups.ids.uu6.disabled=True
        except:
            bcloseed=MDFlatButton(text="Close",on_release=self.closeed)
            self.dialogeed=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseed])
            self.dialogeed.open()


    def socshownormaltypewise(self):
        self.screen.ids.socs.ids.socnda.hint_text=""
        self.screen.ids.socs.ids.socndt.hint_text=""
        ntype=self.screen.ids.socs.ids.socnormaltype.text
        if ntype!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select * from data1 where ffrom=\"{ntype}\" or tto=\"{ntype}\"")
            ntdata=v.fetchall()

            mainntlist=[]
            for i in ntdata:
                b=list(i)
                if b[5]<0:
                    b[5]=float(b[5])*(-1)
                mainntlist.append(b)

            self.soccolumnoftype=[("Id",dp(13)),("Date",dp(25)),("From",dp(30)),("To",dp(40)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
            self.soctableoftype=MDDataTable(
                            size_hint_y=None,
                            height=400,
                            size_hint_x=None,
                            width=1110,
                            pos_hint={'center_x':0.5,'center_y':0.62},
                            use_pagination=True,
                            column_data=self.soccolumnoftype,
                            row_data=mainntlist)

            self.soctableoftype.open()
            d=0
            c=0
            for i in mainntlist:
                if i[4]=="Debit":
                    d+=i[5]
                else:
                    c+=i[5]

            self.screen.ids.socs.ids.socndt.hint_text=str("Debit:")+str(d)+str("   Credit:")+str(c)
            var.commit()
            var.close()
        else:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()
       
    def exportsocshownormaltypewise(self):
        self.screen.ids.socs.ids.socnda.hint_text=""
        self.screen.ids.socs.ids.socndt.hint_text=""
        ntype=self.screen.ids.socs.ids.socnormaltype.text
        if ntype!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select * from data1 where ffrom=\"{ntype}\" or tto=\"{ntype}\"")
            ntdata=v.fetchall()

            mainntlist=[]
            for i in ntdata:
                b=list(i)
                if b[5]<0:
                    b[5]=float(b[5])*(-1)
                mainntlist.append(b)
            var.commit()
            var.close()
            
            c=['Id','Date','From','To','D/C','Amount','Narration']
            df=pd.DataFrame(mainntlist,columns=c)
            df.to_csv('Exports/Category_Wise.csv',index=False)
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out Category_Wise.csv file in the Exports Folder!",buttons=[bclosee])
            self.dialogee.open()
        else:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()


    def socshowalltypewise(self):
        self.screen.ids.socs.ids.socnda.hint_text=""
        self.screen.ids.socs.ids.socndt.hint_text=""
        d1=self.screen.ids.socs.ids.socalltypefromdate.text
        d2=self.screen.ids.socs.ids.socalltypetodate.text
        attype=self.screen.ids.socs.ids.socalltype.text
        try:
            b=datetime.strptime(d1,"%Y-%m-%d")
            c=datetime.strptime(d2,"%Y-%m-%d")
            if attype!="":

                var=sqlite3.connect('data.db')
                v=var.cursor()
                v.execute(f"select * from data1 where ffrom=\"{attype}\" or tto=\"{attype}\"")
                ntdata=v.fetchall()

                mainntlist0=[]
                for i in ntdata:
                    b=list(i)
                    if b[5]<0:
                        b[5]=float(b[5])*(-1)
                    mainntlist0.append(b)

                var.commit()
                var.close()
                mainatlist=[]
                for i in mainntlist0:
                    if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                        mainatlist.append(i)

                self.soccolumnofalltype=[("Id",dp(5)),("Date",dp(25)),("From",dp(30)),("To",dp(50)),("D/C",dp(35)),("Amount",dp(30)),("Narration",dp(40))]
                self.soctableofalltype=MDDataTable(
                                size_hint_y=None,
                                height=400,
                                size_hint_x=None,
                                width=1117,
                                pos_hint={'center_x':0.5,'center_y':0.62},
                                use_pagination=True,
                                column_data=self.soccolumnofalltype,
                                row_data=mainatlist)
                self.soctableofalltype.open()
                d=0
                c=0
                for i in mainatlist:
                    if i[4]=="Debit":
                        d+=i[5]
                    else:
                        c+=i[5]

                self.screen.ids.socs.ids.socnda.hint_text=str("Debit:")+str(d)+str("   Credit:")+str(c)
            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def exportsocshowalltypewisee(self):
        d1=self.screen.ids.socs.ids.socalltypefromdate.text
        d2=self.screen.ids.socs.ids.socalltypetodate.text
        attype=self.screen.ids.socs.ids.socalltype.text
        try:
            b=datetime.strptime(d1,"%Y-%m-%d")
            c=datetime.strptime(d2,"%Y-%m-%d")
            if attype!="":

                var=sqlite3.connect('data.db')
                v=var.cursor()
                v.execute(f"select * from data1 where ffrom=\"{attype}\" or tto=\"{attype}\"")
                ntdata=v.fetchall()

                mainntlist0=[]
                for i in ntdata:
                    b=list(i)
                    if b[5]<0:
                        b[5]=float(b[5])*(-1)
                    mainntlist0.append(b)

                var.commit()
                var.close()
                mainatlist=[]
                for i in mainntlist0:
                    if datetime.strptime(d1,"%Y-%m-%d")<=datetime.strptime(i[1],"%Y-%m-%d") and datetime.strptime(d2,"%Y-%m-%d")>=datetime.strptime(i[1],"%Y-%m-%d"):
                        mainatlist.append(i)

                c=['Id','Date','From','To','D/C','Amount','Narration']
                df=pd.DataFrame(mainatlist,columns=c)
                df.to_csv('Exports/Category_and_Date_Wise.csv',index=False)
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="The Data has been Exported Successfully!\nCheck Out Category_and_Date_Wise.csv file in the Exports Folder!",buttons=[bclosee])
                self.dialogee.open()
            else:
                bclosee=MDFlatButton(text="Close",on_release=self.closee)
                self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
                self.dialogee.open()
        except:
            bclosee=MDFlatButton(text="Close",on_release=self.closee)
            self.dialogee=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bclosee])
            self.dialogee.open()

    def startsoc(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        v.execute("select distinct(ffrom) from data1")
        first=v.fetchall()
        v.execute("select distinct(tto) from data1")
        second=v.fetchall()
        tp=['Bank of Baroda','Cash','PhonePe Wallet']
        data=[]
        for i in first:
            if i[0] not in tp and i[0] not in data:
                data.append(i[0])
        for i in second:
            if i[0] not in tp and i[0] not in data:
                data.append(i[0])

        maindata=[]
        data.sort()
        for i in data:
            a={'text':i}
            maindata.append(a)
        #print(maindata)

        self.socnamenu=MDDropdownMenu(
            caller=self.screen.ids.socs.ids.socdrop4,
            items=maindata,
            width_mult=5,
            callback=self.socshow_textnamenu,)

        self.socalltypemenu=MDDropdownMenu(
            caller=self.screen.ids.socs.ids.socdrop5,
            items=maindata,
            width_mult=5,
            callback=self.socshow_textalltypemenu,)
        var.commit()
        var.close()

    def starten(self):
        self.lst2 = [{"text": "Debit"},{"text":"Credit"}]
        self.menu2=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop2,
            items=self.lst2,
            width_mult=4,
            callback=self.show_text2,)

    def startup(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        
        v.execute("Select a from accounts")
        a=v.fetchall()
        aa=[i[0] for i in a]
        lst=[{'text':f'{i}'} for i in aa]
        self.u44=MDDropdownMenu(
            caller=self.screen.ids.ups.ids.u4,
            items=lst,
            width_mult=4,
            callback=self.show_textnamenuu44,)

        self.u88=MDDropdownMenu(
            caller=self.screen.ids.ups.ids.u8,
            items=lst,
            width_mult=4,
            callback=self.show_textnamenuu88,)

        var.commit()
        var.close()

    def startso(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        v.execute("Select a from accounts")
        a=v.fetchall()
        aa=[i[0] for i in a]
        lst=[{'text':f'{i}'} for i in aa]
        
        self.namenu=MDDropdownMenu(
            caller=self.screen.ids.sos.ids.drop4,
            items=lst,
            width_mult=4,
            callback=self.show_textnamenu,)

        self.alltypemenu=MDDropdownMenu(
            caller=self.screen.ids.sos.ids.drop5,
            items=lst,
            width_mult=4,
            callback=self.show_textalltypemenu,)

        var.commit()
        var.close()

    def startac(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()

        v.execute("Select a from accounts")
        a=v.fetchall()
        aa=[i[0] for i in a]
        aa.sort()
        lst=[{'text':f'{i}'} for i in aa]

        v.execute("Select a from accounts where s=\"Open\"")
        a1=v.fetchall()
        aa1=[i[0] for i in a1]
        aa1.sort()
        lst1=[{'text':f'{i}'} for i in aa1]

        self.deletemenu=MDDropdownMenu(
            caller=self.screen.ids.acs.ids.dropdelete,
            items=lst1,
            width_mult=4,
            callback=self.deletemenushow,)

        self.updatemenu=MDDropdownMenu(
            caller=self.screen.ids.acs.ids.dropupdate,
            items=lst,
            width_mult=4,
            callback=self.updatemenushow,)

        self.updatestatusmenu=MDDropdownMenu(
            caller=self.screen.ids.acs.ids.dropstatus,
            items=[{'text':'Open'},{'text':'Closed'}],
            width_mult=4,
            callback=self.updatestatusmenushow,)

        var.commit()
        var.close()

    def startre(self):
        var=sqlite3.connect('data.db')
        v=var.cursor()

        v.execute("select dd from data1")
        a=v.fetchall()
        yrs=[]
        for i in a:
            b=i[0].split('-')
            c={'text':f'{b[0]}'}
            if c not in yrs:
                yrs.append(c)

        v.execute("Select a from accounts")
        aa=v.fetchall()
        aa1=[i[0] for i in aa]
        aa1.sort()
        lsta=[{'text':f'{i}'} for i in aa1]

        self.rey1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropy1,
            items=yrs,
            width_mult=4,
            callback=self.showrey1,)

        self.rey2=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropy2,
            items=yrs,
            width_mult=4,
            callback=self.showrey2,)

        self.rey3=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropy3,
            items=yrs,
            width_mult=4,
            callback=self.showrey3,)

        self.reay1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropay1,
            items=lsta,
            width_mult=4,
            callback=self.showreay1,)

        m=[{'text':'January'}, {'text':'February'}, {'text':'March'}, {'text':'April'}, {'text':'May'},
            {'text':'June'},{'text':'July'},{'text':'August'},{'text':'September'},{'text':'October'},
            {'text':'November'},{'text':'December'}]
        
        self.rem1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropm1,
            items=m,
            width_mult=4,
            callback=self.showrem1,)

        self.rem2=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropm2,
            items=m,
            width_mult=4,
            callback=self.showrem2,)

        v.execute("select distinct(ffrom) from data1")
        first=v.fetchall()
        v.execute("select distinct(tto) from data1")
        second=v.fetchall()
        tp=['Bank of Baroda','Cash','PhonePe Wallet']
        data=[]
        for i in first:
            if i[0] not in tp and i[0] not in data:
                data.append(i[0])
            else:
                pass
        for i in second:
            if i[0] not in tp and i[0] not in data:
                data.append(i[0])
            else:
                pass

        maindata=[]
        data.sort()
        for i in data:
            a={'text':i}
            maindata.append(a)


        self.recy1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropcy1,
            items=maindata,
            width_mult=5,
            callback=self.showrecy1,)

        self.remy1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropmy1,
            items=yrs,
            width_mult=4,
            callback=self.showremy1,)

        self.remy2=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropmy2,
            items=yrs,
            width_mult=4,
            callback=self.showremy2,)
        
        mad=aa1+data
        madata=[]
        for i in mad:
            a={'text':i}
            madata.append(a)

        self.needed1=aa1

        self.rema1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropma1,
            items=madata,
            width_mult=5,
            callback=self.showrema1,)

        self.reyy1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropyy1,
            items=yrs,
            width_mult=4,
            callback=self.showreyy1,)
        
        self.reyy2=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropyy2,
            items=yrs,
            width_mult=4,
            callback=self.showreyy2,)

        self.rey2y1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropy2y1,
            items=yrs,
            width_mult=4,
            callback=self.showrey2y1,)

        self.rey2y2=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropy2y2,
            items=yrs,
            width_mult=4,
            callback=self.showrey2y2,)

        self.reya1=MDDropdownMenu(
            caller=self.screen.ids.res.ids.dropya1,
            items=madata,
            width_mult=5,
            callback=self.showreya1,)


        var.commit()
        var.close()

    def createacc(self):
        #print("Entered createacc")
        name=self.screen.ids.acs.ids.ace.text
        if name!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()
            '''v.execute("""CREATE table accounts(id integer PRIMARY KEY,
                        a text NOT NULL,
                        s text NOT NULL)
                        """)'''
            v.execute("SELECT a from accounts")
            lst=v.fetchall()
            mlst=[]
            for i in lst:
                mlst.append(i[0])
            
            if name not in mlst:
                v.execute("INSERT INTO accounts (a,s) VALUES(:a,:s)",{
                        'a':name,
                        's':"Open",
                    })
                bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
                self.dialogeeac=MDDialog(title="Money App",text="Account Created Successfully!",buttons=[bcloseeac])
                self.dialogeeac.open()
                self.screen.ids.acs.ids.ace.text=""
            else:
                bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
                self.dialogeeac=MDDialog(title="Money App",text="The Account already Exist for changes use Update part!",buttons=[bcloseeac])
                self.dialogeeac.open()

            var.commit()
            var.close()
        else:
            bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeeac=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseeac])
            self.dialogeeac.open()

    def deleteacc(self):
        #print("Entered deleteacc")
        names=str(self.screen.ids.acs.ids.acd.text)
        if names!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()

            '''v.execute(f"UPDATE accounts SET s=:ss where acc={str(names)}",{
                'ss':"Closed",
            })'''
            v.execute(f"Delete from accounts where a=\"{names}\"")
            v.execute("INSERT INTO accounts (a,s) VALUES(:a,:s)",{
                        'a':names,
                        's':"Closed",
                    })
            var.commit()
            var.close()
            bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeeac=MDDialog(title="Money App",text="Account Deleted!",buttons=[bcloseeac])
            self.dialogeeac.open()
            self.screen.ids.acs.ids.acd.text=""
        else:
            bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeeac=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseeac])
            self.dialogeeac.open()

    def updateacc(self):
        #print("Entered updateacc")
        pn=self.screen.ids.acs.ids.acu1.text
        nn=self.screen.ids.acs.ids.acu2.text
        ns=self.screen.ids.acs.ids.acus.text

        if pn!="" and nn!="" and ns!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute(f"Delete from accounts where a=\"{pn}\"")
            v.execute("INSERT INTO accounts (a,s) VALUES(:a,:s)",{
                        'a':nn,
                        's':ns,
                    })
            var.commit()
            var.close()
            self.screen.ids.acs.ids.acu1.text=""
            self.screen.ids.acs.ids.acu2.text=""
            self.screen.ids.acs.ids.acus.text=""
            bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeeac=MDDialog(title="Money App",text="Account is Updated Successfully!",buttons=[bcloseeac])
            self.dialogeeac.open()
            MoneyApp.startac(self)
        else:
            bcloseeac=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeeac=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseeac])
            self.dialogeeac.open()

    def showacc(self):
        #print("Entered showacc")
        var=sqlite3.connect('data.db')
        v=var.cursor()
        v.execute("Select * from accounts")
        a=v.fetchall()
        #pprint(a)
        c=[("Id",dp(10)),("Account Name",dp(45)),("Status",dp(25))]
        self.tableshowacc=MDDataTable(
                        size_hint_y=None,
                        size_hint_x=None,
                        width=450,
                        height=350,
                        pos_hint={'center_x':0.5,'center_y':0.62},
                        use_pagination=True,
                        column_data=c,
                        row_data=a)
        self.tableshowacc.open()
        var.commit()
        var.close()

    def graphy1(self):
        y=self.screen.ids.res.ids.y1.text
        if y!='':
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
                if a==str(y):
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

            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            x = np.arange(len(labels))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, c, width, label='Credit')
            g2 = ax.bar(x + width/2, d, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Monthly Report of Year {y}')
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
            plt.tight_layout()
            return plt.show()
        
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeere)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def retable(self):
        y=self.screen.ids.res.ids.y1.text
        if y!='':
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
                if a==str(y):
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
                            nd=nd+float(j[1])*(-1)
                        else:
                            nc=nc+float(j[1])
                d.append(nd)
                c.append(nc)

            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            lst=zip(labels,c,d)
            mlst=list(lst)
            #print(mlst)
            c=[("Month",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.tablere1=MDDataTable(
                        size_hint_y=None,
                        size_hint_x=None,
                        width=500,
                        height=400,
                        pos_hint={'center_x':0.5,'center_y':0.62},
                        use_pagination=True,
                        column_data=c,
                        row_data=mlst)
            self.tablere1.open()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def graphay1(self):
        y=self.screen.ids.res.ids.y2.text
        ac=self.screen.ids.res.ids.ay2.text
        if y!='' and ac!='':
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select dd,amt from data1 where ffrom=\'{ac}\'")
            data=v.fetchall()

            data1=[]

            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            d=[]
            for i in range(1,13):
                nd=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nd=nd+float(j[1])*(-1)
                    else:
                        pass   
                        
                d.append(nd)

            v.execute(f"select dd,amt from data1 where tto=\'{ac}\'")
            data=v.fetchall()

            data1=[]
            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            c=[]
            for i in range(1,13):
                nc=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nc=nc+float(j[1])
                    else:
                        pass    
                c.append(nc)


            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            x = np.arange(len(labels))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, c, width, label='Credit')
            g2 = ax.bar(x + width/2, d, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Monthly Report of {ac} in Year {y}')
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
            plt.tight_layout()
            return plt.show()
        
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeere)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def retableay(self):
        y=self.screen.ids.res.ids.y2.text
        ac=self.screen.ids.res.ids.ay2.text
        if y!='' and ac!='':
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select dd,amt from data1 where ffrom=\'{ac}\'")
            data=v.fetchall()

            data1=[]

            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            d=[]
            for i in range(1,13):
                nd=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nd=nd+float(j[1])*(-1)
                    else:
                        pass   
                        
                d.append(nd)

            v.execute(f"select dd,amt from data1 where tto=\'{ac}\'")
            data=v.fetchall()

            data1=[]
            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            c=[]
            for i in range(1,13):
                nc=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nc=nc+float(j[1])
                    else:
                        pass    
                c.append(nc)


            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            lst=zip(labels,c,d)
            mlst=list(lst)
            #print(mlst)

            var.commit()
            var.close()

            c=[("Month",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.tablere1=MDDataTable(
                        size_hint_y=None,
                        size_hint_x=None,
                        width=500,
                        height=400,
                        pos_hint={'center_x':0.5,'center_y':0.62},
                        use_pagination=True,
                        column_data=c,
                        row_data=mlst)
            self.tablere1.open()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def graphcy1(self):
        y=self.screen.ids.res.ids.y3.text
        ac=self.screen.ids.res.ids.c3.text
        if y!='' and ac!='':
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select dd,amt from data1 where tto=\'{ac}\'")
            data=v.fetchall()

            data1=[]

            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            d=[]
            for i in range(1,13):
                nd=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nd=nd+float(j[1])*(-1)
                    else:
                        pass   
                        
                d.append(nd)

            v.execute(f"select dd,amt from data1 where ffrom=\'{ac}\'")
            data=v.fetchall()

            data1=[]
            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            c=[]
            for i in range(1,13):
                nc=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nc=nc+float(j[1])
                    else:
                        pass    
                c.append(nc)


            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            x = np.arange(len(labels))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, c, width, label='Credit')
            g2 = ax.bar(x + width/2, d, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Monthly Report of {ac} in Year {y}')
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
            plt.tight_layout()
            return plt.show()
        
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeere)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def retablecy(self):
        y=self.screen.ids.res.ids.y3.text
        ac=self.screen.ids.res.ids.c3.text
        if y!='' and ac!='':
            var=sqlite3.connect('data.db')
            v=var.cursor()

            v.execute(f"select dd,amt from data1 where tto=\'{ac}\'")
            data=v.fetchall()

            data1=[]

            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            d=[]
            for i in range(1,13):
                nd=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nd=nd+float(j[1])*(-1)
                    else:
                        pass   
                        
                d.append(nd)

            v.execute(f"select dd,amt from data1 where ffrom=\'{ac}\'")
            data=v.fetchall()

            data1=[]
            for i in data:
                a=i[0].split('-')
                a=a[0]
                if a==str(y):
                    data1.append(i)

            c=[]
            for i in range(1,13):
                nc=0
                for j in data1:
                    a=j[0].split('-')
                    if float(a[1])==float(i):    
                        nc=nc+float(j[1])
                    else:
                        pass    
                c.append(nc)


            labels = ['January', 'February', 'March', 'April', 'May','June','July','August','September','October',
            'November','December']

            lst=zip(labels,c,d)
            mlst=list(lst)
            #print(mlst)

            var.commit()
            var.close()

            c=[("Month",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.tablerec=MDDataTable(
                        size_hint_y=None,
                        size_hint_x=None,
                        width=500,
                        height=400,
                        pos_hint={'center_x':0.5,'center_y':0.62},
                        use_pagination=True,
                        column_data=c,
                        row_data=mlst)
            self.tablerec.open()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select the Year!",buttons=[bcloseere])
            self.dialogeere.open()

    def remtable1(self):
        m=self.screen.ids.res.ids.m1.text
        y=self.screen.ids.res.ids.my1.text
        if m!="" and y!="":
            mo=[{'January':1}, {'February':2}, {'March':3}, {'April':4}, {'May':5}, {'June':6},
            {'July':7},{'August':8},{'September':9},{'October':10},{'November':11},{'December':12}]
            for i in mo:
                a=i.get(m)
                if a!=None:
                    mn=a
            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute("select dd,amt from data1")
            z=v.fetchall()

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
            
            c=[("Date",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.remtable11=MDDataTable(
                        size_hint_y=None,
                        size_hint_x=None,
                        width=500,
                        height=400,
                        pos_hint={'center_x':0.5,'center_y':0.62},
                        use_pagination=True,
                        column_data=c,
                        row_data=data)
            self.remtable11.open()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select Both the Fields",buttons=[bcloseere])
            self.dialogeere.open()


    def remgraph1(self):
        m=self.screen.ids.res.ids.m1.text
        y=self.screen.ids.res.ids.my1.text
        if m!="" and y!="":
            mo=[{'January':1}, {'February':2}, {'March':3}, {'April':4}, {'May':5}, {'June':6},
            {'July':7},{'August':8},{'September':9},{'October':10},{'November':11},{'December':12}]
            for i in mo:
                a=i.get(m)
                if a!=None:
                    mn=a

            var=sqlite3.connect('data.db')
            v=var.cursor()
            v.execute("select dd,amt from data1")
            z=v.fetchall()

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

            x = np.arange(len(fdates))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, c, width, label='Credit')
            g2 = ax.bar(x + width/2, d, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Daily Report of {m} in Year {y}')
            ax.set_xticks(x)
            ax.set_xticklabels(fdates)

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
            plt.tight_layout()
            return plt.show()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select Both the Fields",buttons=[bcloseere])
            self.dialogeere.open()

    def remtable2(self):
        m=self.screen.ids.res.ids.m2.text
        y=self.screen.ids.res.ids.my2.text
        aa=self.screen.ids.res.ids.ma1.text

        if m!="" and y!="" and aa!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()

            mo=[{'January':1}, {'February':2}, {'March':3}, {'April':4}, {'May':5}, {'June':6},
            {'July':7},{'August':8},{'September':9},{'October':10},{'November':11},{'December':12}]
            for i in mo:
                a=i.get(m)
                if a!=None:
                    mn=a

            if aa in self.needed1:
                v.execute(f"select dd,amt,id from data1 where ffrom=\"{aa}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt,id from data1 where tto=\"{aa}\"")
                c1=v.fetchall()
            else:
                v.execute(f"select dd,amt,id from data1 where tto=\"{aa}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt,id from data1 where ffrom=\"{aa}\"")
                c1=v.fetchall()

            ddata1=[]
            cdata1=[]

            for i in d1:
                a=i[0].split('-')
                if int(a[0])==int(y) and int(a[1])==int(mn):
                    ddata1.append(i)

            for i in c1:
                a=i[0].split('-')
                if int(a[0])==int(y) and int(a[1])==int(mn):
                    cdata1.append(i)

            i1=[]
            for i in cdata1:
                i1.append(i[2])
            for i in ddata1:
                i1.append(i[2])
            i1.sort()
            iddd=[]
            demo=cdata1+ddata1
            for i in i1:
                for j in demo:
                    if int(i)==j[2]:
                        iddd.append(j[0])
                
            dates=[]
            for i in iddd:
                s=datetime.strptime(i,"%Y-%m-%d")
                if s not in dates:
                    dates.append(s)
                else:
                    pass

            fdates=[]
            for i in dates:
                dd=str(i).split(" ")
                fdates.append(dd[0])
            fd1=[]
            for i in fdates:
                nd=0
                for j in ddata1:
                    if datetime.strptime(j[0],"%Y-%m-%d")==datetime.strptime(i,"%Y-%m-%d"):
                        nd=nd+float(float(j[1]*-1))
                fd1.append(nd)

            fc1=[]
            for i in fdates:
                nc=0
                for j in cdata1:
                    if datetime.strptime(j[0],"%Y-%m-%d")==datetime.strptime(i,"%Y-%m-%d"):
                        nc=nc+float(j[1])
                fc1.append(nc)

            sd1=zip(iddd,fc1,fd1)
            sd2=list(sd1)

            c=[("Date",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.remtable12=MDDataTable(
                    size_hint_y=None,
                    size_hint_x=None,
                    width=500,
                    height=400,
                    pos_hint={'center_x':0.5,'center_y':0.62},
                    use_pagination=True,
                    column_data=c,
                    row_data=sd2)
            self.remtable12.open()
            var.commit()
            var.close()
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select All the Fields!",buttons=[bcloseere])
            self.dialogeere.open()

    def remgraph2(self):
        m=self.screen.ids.res.ids.m2.text
        y=self.screen.ids.res.ids.my2.text
        aa=self.screen.ids.res.ids.ma1.text

        if m!="" and y!="" and aa!="":
            var=sqlite3.connect('data.db')
            v=var.cursor()

            mo=[{'January':1}, {'February':2}, {'March':3}, {'April':4}, {'May':5}, {'June':6},
            {'July':7},{'August':8},{'September':9},{'October':10},{'November':11},{'December':12}]
            for i in mo:
                a=i.get(m)
                if a!=None:
                    mn=a

            if aa in self.needed1:
                v.execute(f"select dd,amt,id from data1 where ffrom=\"{aa}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt,id from data1 where tto=\"{aa}\"")
                c1=v.fetchall()
            else:
                v.execute(f"select dd,amt,id from data1 where tto=\"{aa}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt,id from data1 where ffrom=\"{aa}\"")
                c1=v.fetchall()

            ddata1=[]
            cdata1=[]

            for i in d1:
                a=i[0].split('-')
                if int(a[0])==int(y) and int(a[1])==int(mn):
                    ddata1.append(i)

            for i in c1:
                a=i[0].split('-')
                if int(a[0])==int(y) and int(a[1])==int(mn):
                    cdata1.append(i)

            i1=[]
            for i in cdata1:
                i1.append(i[2])
            for i in ddata1:
                i1.append(i[2])
            i1.sort()
            iddd=[]
            demo=cdata1+ddata1
            for i in i1:
                for j in demo:
                    if int(i)==j[2]:
                        iddd.append(j[0])
                
            dates=[]
            for i in iddd:
                s=datetime.strptime(i,"%Y-%m-%d")
                if s not in dates:
                    dates.append(s)
                else:
                    pass

            fdates=[]
            for i in dates:
                dd=str(i).split(" ")
                fdates.append(dd[0])
            fd1=[]
            for i in fdates:
                nd=0
                for j in ddata1:
                    if datetime.strptime(j[0],"%Y-%m-%d")==datetime.strptime(i,"%Y-%m-%d"):
                        nd=nd+float(float(j[1]*-1))
                fd1.append(nd)

            fc1=[]
            for i in fdates:
                nc=0
                for j in cdata1:
                    if datetime.strptime(j[0],"%Y-%m-%d")==datetime.strptime(i,"%Y-%m-%d"):
                        nc=nc+float(j[1])
                fc1.append(nc)

            var.commit()
            var.close()

            x = np.arange(len(fdates))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, fc1, width, label='Credit')
            g2 = ax.bar(x + width/2, fd1, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Daily Report of {aa} in {m} of Year {y}')
            ax.set_xticks(x)
            ax.set_xticklabels(fdates)

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
            plt.tight_layout()
            return plt.show()
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Select All the Fields!",buttons=[bcloseere])
            self.dialogeere.open()

    def retableyy1(self):
        y1=self.screen.ids.res.ids.yy1.text
        y2=self.screen.ids.res.ids.yy2.text

        if y1!="" and y2!="" and int(y2)>=int(y1):
            var=sqlite3.connect("data.db")
            v=var.cursor()

            v.execute("select dd,amt from data1")
            data1=v.fetchall()

            data2=[]
            for i in data1:
                a=i[0].split('-')
                if int(a[0])>=int(y1) and int(a[0])<=int(y2):
                    data2.append(i)

            y3=int(y2)+1
            lst=[i for i in range(int(y1),int(y3))]

            dc=[]
            dd=[]

            for i in lst:
                c=0
                d=0
                for j in data2:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        if float(j[1])>0:
                            c=c+float(j[1])
                        else:
                            d=d+float(float(j[1])*-1)
                dc.append(c)
                dd.append(d)

            show=zip(lst,dc,dd)
            showdata=list(show)

            c=[("Year",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.reytable1=MDDataTable(
                    size_hint_y=None,
                    size_hint_x=None,
                    width=500,
                    height=400,
                    pos_hint={'center_x':0.5,'center_y':0.62},
                    use_pagination=True,
                    column_data=c,
                    row_data=showdata)
            self.reytable1.open()

            var.commit()
            var.close()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseere])
            self.dialogeere.open()

    def graphyy1(self):
        y1=self.screen.ids.res.ids.yy1.text
        y2=self.screen.ids.res.ids.yy2.text

        if y1!="" and y2!="" and int(y2)>=int(y1):
            var=sqlite3.connect("data.db")
            v=var.cursor()

            v.execute("select dd,amt from data1")
            data1=v.fetchall()

            data2=[]
            for i in data1:
                a=i[0].split('-')
                if int(a[0])>=int(y1) and int(a[0])<=int(y2):
                    data2.append(i)

            y3=int(y2)+1
            lst=[i for i in range(int(y1),int(y3))]

            dc=[]
            dd=[]

            for i in lst:
                c=0
                d=0
                for j in data2:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        if float(j[1])>0:
                            c=c+float(j[1])
                        else:
                            d=d+float(float(j[1])*-1)
                dc.append(c)
                dd.append(d)

            var.commit()
            var.close()

            x = np.arange(len(lst))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, dc, width, label='Credit')
            g2 = ax.bar(x + width/2, dd, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Year Report from {y1} to {y2}')
            ax.set_xticks(x)
            ax.set_xticklabels(lst)

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
            plt.tight_layout()
            return plt.show()
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseere])
            self.dialogeere.open()

    ####################################################DEVELOP####################################################

    def reyytable1(self):
        y1=self.screen.ids.res.ids.y2y1.text
        y2=self.screen.ids.res.ids.y2y2.text
        acc=self.screen.ids.res.ids.ya1.text

        if y1!="" and y2!="" and acc!="" and int(y2)>=int(y1):
            var=sqlite3.connect("data.db")
            v=var.cursor()

            if acc in self.needed1:
                v.execute(f"select dd,amt from data1 where ffrom=\"{acc}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt from data1 where tto=\"{acc}\"")
                c1=v.fetchall()
            else:
                v.execute(f"select dd,amt from data1 where tto=\"{acc}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt from data1 where ffrom=\"{acc}\"")
                c1=v.fetchall()

            var.commit()
            var.close()

            y3=int(y2)+1
            lst=[i for i in range(int(y1),int(y3))]

            d11=[]
            for i in lst:
                n=0
                for j in d1:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        n=n+float(float(j[1]*-1))
                d11.append(n)


            c11=[]
            for i in lst:
                n=0
                for j in c1:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        n=n+float(j[1])
                c11.append(n)

            show=zip(lst,c11,d11)
            showdata=list(show)

            c=[("Year",dp(30)),("Credit",dp(30)),("Debit",dp(30))]
            self.reytable2=MDDataTable(
                    size_hint_y=None,
                    size_hint_x=None,
                    width=500,
                    height=400,
                    pos_hint={'center_x':0.5,'center_y':0.62},
                    use_pagination=True,
                    column_data=c,
                    row_data=showdata)
            self.reytable2.open()
        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseere])
            self.dialogeere.open()

    def reyygraph1(self):
        y1=self.screen.ids.res.ids.y2y1.text
        y2=self.screen.ids.res.ids.y2y2.text
        acc=self.screen.ids.res.ids.ya1.text

        if y1!="" and y2!="" and acc!="" and int(y2)>=int(y1):
            var=sqlite3.connect("data.db")
            v=var.cursor()

            if acc in self.needed1:
                v.execute(f"select dd,amt from data1 where ffrom=\"{acc}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt from data1 where tto=\"{acc}\"")
                c1=v.fetchall()
            else:
                v.execute(f"select dd,amt from data1 where tto=\"{acc}\"")
                d1=v.fetchall()
                v.execute(f"select dd,amt from data1 where ffrom=\"{acc}\"")
                c1=v.fetchall()

            var.commit()
            var.close()

            y3=int(y2)+1
            lst=[i for i in range(int(y1),int(y3))]

            d11=[]
            for i in lst:
                n=0
                for j in d1:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        n=n+float(float(j[1]*-1))
                d11.append(n)


            c11=[]
            for i in lst:
                n=0
                for j in c1:
                    a=j[0].split('-')
                    if int(a[0])==int(i):
                        n=n+float(j[1])
                c11.append(n)

            x = np.arange(len(lst))  # the label locations
            width = 0.45  # the width of the bars

            fig, ax = plt.subplots()
            g1 = ax.bar(x - width/2, c11, width, label='Credit')
            g2 = ax.bar(x + width/2, d11, width, label='Debit')
            ax.set_ylabel('Rupees')
            ax.set_title(f'Year Report of {acc} from {y1} to {y2}')
            ax.set_xticks(x)
            ax.set_xticklabels(lst)

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
            plt.tight_layout()
            return plt.show()

        else:
            bcloseere=MDFlatButton(text="Close",on_release=self.closeeac)
            self.dialogeere=MDDialog(title="Money App",text="Invalid Inputs!",buttons=[bcloseere])
            self.dialogeere.open()

    def closeeac(self,obj):
        try:
            self.dialoge.dismiss()
        except:
            pass

    def closee(self,obj):
        try:
            self.dialogeeac.dismiss()
        except:
            pass

    def closes(self,obj):
        try:
            self.dialogs.dismiss()
        except:
            pass

    def closeed(self,obj):
        try:
            self.dialogeed.dismiss()
        except:
            pass

    def closesd(self,obj):
        try:
            self.dialogsd.dismiss()
        except:
            pass

    def closeeu(self,obj):
        try:
            self.dialogsu.dismiss()
        except:
            pass

    def closesu(self,obj):
        try:
            self.dialogsu.dismiss()
        except:
            pass

    def closeere(self,obj):
        try:
            self.dialogeere.dismiss()
        except:
            pass

    def show_text3(self,word):
        self.screen.ids.ens.ids.entt.text=word.text

    def show_textnamenu(self,a):
        #print(a)
        self.screen.ids.sos.ids.normaltype.text=a.text

    def socshow_textnamenu(self,a):
        #print(a)
        self.screen.ids.socs.ids.socnormaltype.text=a.text

    def show_textalltypemenu(self,b):
        self.screen.ids.sos.ids.alltype.text=b.text

    def show_text1(self,word):
        self.screen.ids.ens.ids.enf.text=word.text

    def socshow_textalltypemenu(self,b):
        self.screen.ids.socs.ids.socalltype.text=b.text

    def deletemenushow(self,b):
        self.screen.ids.acs.ids.acd.text=b.text

    def updatemenushow(self,b):
        self.screen.ids.acs.ids.acu1.text=b.text
        self.screen.ids.acs.ids.acu2.text=b.text

    def updatestatusmenushow(self,b):
        self.screen.ids.acs.ids.acus.text=b.text

    def showrey1(self,a):
        self.screen.ids.res.ids.y1.text=a.text
        
    def showrey2(self,a):
        self.screen.ids.res.ids.y2.text=a.text

    def showreay1(self,a):
        self.screen.ids.res.ids.ay2.text=a.text

    def showrey3(self,a):
        self.screen.ids.res.ids.y3.text=a.text

    def showrecy1(self,a):
        self.screen.ids.res.ids.c3.text=a.text

    def showrem1(self,a):
        self.screen.ids.res.ids.m1.text=a.text

    def showremy1(self,a):
        self.screen.ids.res.ids.my1.text=a.text

    def showrem2(self,a):
        self.screen.ids.res.ids.m2.text=a.text

    def showremy2(self,a):
        self.screen.ids.res.ids.my2.text=a.text

    def showrema1(self,a):
        self.screen.ids.res.ids.ma1.text=a.text

    def showreyy1(self,a):
        self.screen.ids.res.ids.yy1.text=a.text

    def showreyy2(self,a):
        self.screen.ids.res.ids.yy2.text=a.text

    def showrey2y1(self,a):
        self.screen.ids.res.ids.y2y1.text=a.text

    def showrey2y2(self,a):
        self.screen.ids.res.ids.y2y2.text=a.text

    def showreya1(self,a):
        self.screen.ids.res.ids.ya1.text=a.text

    def calci(self):
        print('hi1')
        root.mainloop()
        print('hi2')

MoneyApp().run()
#elevator-down
#gamepad-circle-down
#menu-down
#menu-down-outline
#gamepad-down
#calculator
#calculator-variant
#calculator-variant-outline