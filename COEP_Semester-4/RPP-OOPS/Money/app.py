from kivy.lang import Builder
from kivymd.app import MDApp
from kivymd.uix.screen import MDScreen
from kivymd.uix.button import MDRectangleFlatButton
from kivymd.uix.menu import MDDropdownMenu

import sqlite3


from screen import screen_helper

class HOScreen(MDScreen):
    pass

class HOScreen(MDScreen):
    pass

class UPScreen(MDScreen):
    pass

class ENScreen(MDScreen):
    pass

class SOScreen(MDScreen):
    pass

class SOCScreen(MDScreen):
    pass

class REScreen(MDScreen):
    pass

class ACScreen(MDScreen):
    pass

class CBScreen(MDScreen):
    pass

class STScreen(MDScreen):
    pass

class MainApp(MDApp):
    def build(self):
        self.theme_cls.theme_style = "Dark"
        self.theme_cls.primary_palette = "Orange"
        self.text_hint_color="White"

        self.screen=Builder.load_string(screen_helper)

        return self.screen

    def starten(self):
        l=["Debit","Credit"]
        self.lst2 = [{
                "text": f"{i}",
                "viewclass": "OneLineListItem",
                "on_release": lambda x=f"{i}": self.show_text2(x),
            } for i in l]

        self.menu2=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop2,
            items=self.lst2,
            width_mult=4,)

    def show_text2(self,word):
        var=sqlite3.connect('data.db')
        v=var.cursor()
        self.screen.ids.ens.ids.ent.text=word
        self.screen.ids.ens.ids.enf.text=""
        if word=="Debit":
            v.execute("Select a from accounts where s=\"Open\"")
            a=v.fetchall()
            aa=[i[0] for i in a]
            aa.sort()
            # print(aa)

            self.lst1 = [{
                "text": f"{i}",
                "viewclass": "OneLineListItem",
                "on_release": lambda x=f"{i}": self.show_text1(x),
            } for i in aa]
            # print(self.lst1)
            self.screen.ids.ens.ids.entt.text=""


            v.execute("select distinct(tto) from data1 where dc=\"Debit\"")
            abc=v.fetchall()
            abc11=[i[0] for i in abc]
            abc11.sort()

            v.execute("Select a from accounts where s=\"Open\"")
            abc=v.fetchall()
            abc12=[i[0] for i in abc]
            abc12.sort()

            abc1=abc12+abc11
            self.lst3=[]

            self.lst3 = [{
                "text": f"{i}",
                "viewclass": "OneLineListItem",
                "on_release": lambda x=f"{i}": self.show_text3(x),
            } for i in abc1]

            self.screen.ids.ens.ids.drop3.disabled=False
        else:
            v.execute("Select a from accounts where s=\"Open\"")
            a=v.fetchall()
            aa=[i[0] for i in a]
            aa.sort()
            self.lst3=[{
                "text": f"{i}",
                "viewclass": "OneLineListItem",
                "on_release": lambda x=f"{i}": self.show_text3(x),
            } for i in aa]
            self.lst1=[]
            self.screen.ids.ens.ids.drop3.disabled=False
            self.screen.ids.ens.ids.entt.text=""

            v.execute("SELECT distinct(ffrom) from data1 where dc=\"Credit\"")
            q=v.fetchall()
            qq1=[i[0] for i in q]
            qq1.sort()

            v.execute("Select a from accounts where s=\"Open\"")
            abc=v.fetchall()
            abc12=[i[0] for i in abc]
            abc12.sort()

            qq=abc12+qq1
            self.lst1=[{
                "text": f"{i}",
                "viewclass": "OneLineListItem",
                "on_release": lambda x=f"{i}": self.show_text1(x),
            } for i in qq]

        
        var.commit()
        var.close()

        #print("HEY",self.lst1)
        self.screen.ids.ens.ids.drop1.disabled=False
        self.menu1=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop1,
            items=self.lst1,
            width_mult=5,)

        self.menu3=MDDropdownMenu(
            caller=self.screen.ids.ens.ids.drop3,
            items=self.lst3,
            width_mult=5,)


MainApp().run()