screen_helper="""
ScreenManager:
	HOScreen:
		id:his
	HOScreen:
		id:his
    ENScreen:
		id:ens
	UPScreen:
		id:ups
    SOScreen:
        id:sos
    SOCScreen:
        id:socs
	REScreen:
		id:res
	ACScreen:
		id:acs
	CBScreen:
		id:cbs
	STScreen:
		id:sts

<HOScreen>
    name:'ho'
    MDTopAppBar:
	    title:'Manage My Money-> Home Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
        elevation: 4

    MDRectangleFlatButton:
		text:"Entry"
		pos_hint:{'center_x':0.2,'center_y':0.75}
		on_press:app.starten()
		on_release:root.manager.current='en'

	Image:
        source:"my_logo.jpeg"
        size_hint:(0.6,0.9)
        pos_hint:{'center_x':0.7,'center_y':0.45} 

        

<ENScreen>
    name:'en'
    MDTopAppBar:
	    title:'Manage My Money-> Entry Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
        elevation: 4

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.1}
		on_release:root.manager.current='ho'

	MDTextField:
		id:ent
		hint_text:"Transaction Type"
		pos_hint:{'center_x':0.5,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"Credit/Debit"
		helper_text_mode:"on_focus"
		disabled:True
	
	MDIconButton:
		id:drop2
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .75}
		on_release:app.menu2.open()

	MDTextField:
		id:enf
		hint_text:"From"
		pos_hint:{'center_x':0.5,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text:"From"
		helper_text_mode:"on_focus"
		disabled:False
	
	MDIconButton:
		id:drop1
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .65}
		on_release:app.menu1.open()
		disabled:True

	MDTextField:
		id:entt
		hint_text:"To"
		pos_hint:{'center_x':0.5,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text:"To"
		helper_text_mode:"on_focus"
		disabled:False
	
	MDIconButton:
		id:drop3
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .55}
		on_release:app.menu3.open()
		disabled:True

	MDTextField:
		id:end
		hint_text:"Date"
		pos_hint:{'center_x':0.5,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:ena
		hint_text:"Amount"
		pos_hint:{'center_x':0.5,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text:"Digits(In Rs.)"
		helper_text_mode:"on_focus"
		
	MDTextField:
		id:enm
		hint_text:"Narration"
		pos_hint:{'center_x':0.5,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text:"More Info"
		helper_text_mode:"on_focus"

	MDRectangleFlatButton:
		text:"Submit"
		pos_hint:{'center_x':0.5,'center_y':0.20}
		on_release:app.save1()

"""