screen_helper="""
ScreenManager:
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

<HOScreen>
    name:'ho'
    MDToolbar:
	    title:'Manage My Money-> Home Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10
		right_action_items: [["calculator", lambda x: app.calci()]]

	Image:
        source:"my_logo.jpeg"
        size_hint:(0.6,0.9)
        pos_hint:{'center_x':0.7,'center_y':0.45}

    MDRectangleFlatButton:
		text:"Entry"
		pos_hint:{'center_x':0.2,'center_y':0.70}
		on_press:app.starten()
		on_release:root.manager.current='en'

    MDRectangleFlatButton:
		text:"Update & Delete"
		pos_hint:{'center_x':0.2,'center_y':0.60}
		on_press:app.startup()
		on_release:root.manager.current='up'

    MDRectangleFlatButton:
		text:"Manage Account"
		pos_hint:{'center_x':0.2,'center_y':0.50}
		on_press:app.startac()
		on_release:root.manager.current='ac'

    MDRectangleFlatButton:
		text:"Account Info"
		pos_hint:{'center_x':0.2,'center_y':0.40}
		on_press:app.startso()
		on_release:root.manager.current='so'

	MDRectangleFlatButton:
		text:"Category Info"
		pos_hint:{'center_x':0.2,'center_y':0.30}
		on_press:app.startsoc()
		on_release:root.manager.current='soc'

	MDRectangleFlatButton:
		text:"Report"
		pos_hint:{'center_x':0.2,'center_y':0.20}
		on_press:app.startre()
		on_release:root.manager.current='re'

<ENScreen>
    name:'en'
    MDToolbar:
	    title:'Manage My Money-> Entry Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

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

<UPScreen>
    name:'up'
    MDToolbar:
	    title:'Manage My Money-> Update & Delete Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

	MDTextField:
		id:u1
		hint_text:"From Date"
		pos_hint:{'center_x':0.25,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:u2
		hint_text:"To Date"
		pos_hint:{'center_x':0.25,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDRectangleFlatButton:
		text:"Show Date-wise"
		pos_hint:{'center_x':0.25,'center_y':0.55}
		on_release:app.shownormaldatewiseu()

	MDTextField:
		id:u3
		hint_text:"Account Type"
		pos_hint:{'center_x':0.50,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:u4
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .85}
		on_release:app.u44.open()

	MDRectangleFlatButton:
		text:"Show Account-wise"
		pos_hint:{'center_x':0.50,'center_y':0.65}
		on_release:app.shownormaltypewiseu()

	MDTextField:
		id:u5
		hint_text:"From Date"
		pos_hint:{'center_x':0.75,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:u6
		hint_text:"To Date"
		pos_hint:{'center_x':0.75,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:u7
		hint_text:"Account Type"
		pos_hint:{'center_x':0.75,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:u8
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .85, "center_y": .65}
		on_release:app.u88.open()
		disabled:False	

	MDRectangleFlatButton:
		text:"Show All-type-wise"
		pos_hint:{'center_x':0.75,'center_y':0.55}
		on_release:app.showalltypewiseu()

	MDRectangleFlatButton:
		text:"Show All Data"
		pos_hint:{'center_x':0.5,'center_y':0.55}
		on_release:app.showallu()

	MDTextField:
		id:uu1
		hint_text:"Transaction Type"
		pos_hint:{'center_x':0.25,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text:"Credit/Debit"
		helper_text_mode:"on_focus"
		disabled:True
	
	MDIconButton:
		id:uu2
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .35, "center_y": .45}
		on_release:app.menu2.open()
		disabled:True

	MDTextField:
		id:uu3
		hint_text:"From"
		pos_hint:{'center_x':0.5,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text:"From"
		helper_text_mode:"on_focus"
		disabled:False
	
	MDIconButton:
		id:uu4
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .45}
		on_release:app.menu1u.open()
		disabled:True

	MDTextField:
		id:uu5
		hint_text:"To"
		pos_hint:{'center_x':0.75,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text:"Credit/Debit"
		helper_text_mode:"on_focus"
		disabled:False
	
	MDIconButton:
		id:uu6
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .85, "center_y": .45}
		on_release:app.menu3u.open()
		disabled:True

	MDTextField:
		id:uu7
		hint_text:"Date"
		pos_hint:{'center_x':0.25,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:uu8
		hint_text:"Amount"
		pos_hint:{'center_x':0.5,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text:"Digits(In Rs.)"
		helper_text_mode:"on_focus"
		
	MDTextField:
		id:uu9
		hint_text:"Narration"
		pos_hint:{'center_x':0.75,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text:"More Info"
		helper_text_mode:"on_focus"

    MDRectangleFlatButton:
		text:"Update"
		pos_hint:{'center_x':0.40,'center_y':0.25}
		on_release:app.updatee()

    MDRectangleFlatButton:
		text:"Delete"
		pos_hint:{'center_x':0.60,'center_y':0.25}
		on_release:app.deletee()

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.1}
		on_release:root.manager.current='ho'

<DEScreen>
    name:'de'
    MDToolbar:
	    title:'Manage My Money-> Delete Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.2}
		on_release:root.manager.current='ho'

<SOScreen>
    name:'so'
    MDToolbar:
	    title:'Manage My Money-> Account Info Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

	MDTextField:
		id:normalfromdate
		hint_text:"From Date"
		pos_hint:{'center_x':0.25,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:normaltodate
		hint_text:"To Date"
		pos_hint:{'center_x':0.25,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDRectangleFlatButton:
		text:"Show Date-wise"
		pos_hint:{'center_x':0.25,'center_y':0.45}
		on_release:app.shownormaldatewise()

	MDRectangleFlatButton:
		text:"Export Date-wise"
		pos_hint:{'center_x':0.25,'center_y':0.35}
		on_release:app.exportshownormaldatewise()

	MDTextField:
		id:ndd
		pos_hint:{'center_x':0.25,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDTextField:
		id:normaltype
		hint_text:"Account Type"
		pos_hint:{'center_x':0.50,'center_y':0.70}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:drop4
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .6, "center_y": .70}
		on_release:app.namenu.open()

	MDRectangleFlatButton:
		text:"Show Account-wise"
		pos_hint:{'center_x':0.50,'center_y':0.45}
		on_release:app.shownormaltypewise()

	MDRectangleFlatButton:
		text:"Export Account-wise"
		pos_hint:{'center_x':0.50,'center_y':0.35}
		on_release:app.exportshownormaltypewise()

	MDTextField:
		id:ndt
		pos_hint:{'center_x':0.5,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDTextField:
		id:alltypefromdate
		hint_text:"From Date"
		pos_hint:{'center_x':0.75,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:alltypetodate
		hint_text:"To Date"
		pos_hint:{'center_x':0.75,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:alltype
		hint_text:"Account Type"
		pos_hint:{'center_x':0.75,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:drop5
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .85, "center_y": .55}
		on_release:app.alltypemenu.open()		

	MDRectangleFlatButton:
		text:"Show All-Type-wise"
		pos_hint:{'center_x':0.75,'center_y':0.45}
		on_release:app.showalltypewise()

	MDRectangleFlatButton:
		text:"Export All-Type-wise"
		pos_hint:{'center_x':0.75,'center_y':0.35}
		on_release:app.exportshowalltypewise()

	MDTextField:
		id:nda
		pos_hint:{'center_x':0.75,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDRectangleFlatButton:
		text:"Show All Data"
		pos_hint:{'center_x':0.3,'center_y':0.1}
		on_release:app.showall()

	MDRectangleFlatButton:
		text:"Export All Data"
		pos_hint:{'center_x':0.4,'center_y':0.1}
		on_release:app.exportall()

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.6,'center_y':0.1}
		on_release:root.manager.current='ho'

<SOCScreen>
    name:'soc'
	MDToolbar:
	    title:'Manage My Money-> Category Info Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

	MDTextField:
		id:socnormaltype
		hint_text:"Category Type"
		pos_hint:{'center_x':0.25,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:socdrop4
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .35, "center_y": .65}
		on_release:app.socnamenu.open()

	MDRectangleFlatButton:
		text:"Show Account-wise"
		pos_hint:{'center_x':0.25,'center_y':0.45}
		on_release:app.socshownormaltypewise()

	MDRectangleFlatButton:
		text:"Export Account-wise"
		pos_hint:{'center_x':0.25,'center_y':0.35}
		on_release:app.exportsocshownormaltypewise()

	MDTextField:
		id:socndt
		pos_hint:{'center_x':0.25,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDTextField:
		id:socalltypefromdate
		hint_text:"From Date"
		pos_hint:{'center_x':0.75,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:socalltypetodate
		hint_text:"To Date"
		pos_hint:{'center_x':0.75,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text:"yyyy-mm-dd"
		helper_text_mode:"on_focus"

	MDTextField:
		id:socalltype
		hint_text:"Category Type"
		pos_hint:{'center_x':0.75,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True
		
	MDIconButton:
		id:socdrop5
		icon:'gamepad-circle-down'
		pos_hint:{"center_x": .85, "center_y": .55}
		on_release:app.socalltypemenu.open()		

	MDRectangleFlatButton:
		text:"Show All-type-wise"
		pos_hint:{'center_x':0.75,'center_y':0.45}
		on_release:app.socshowalltypewise()

	MDRectangleFlatButton:
		text:"Export Account-wise"
		pos_hint:{'center_x':0.75,'center_y':0.35}
		on_release:app.exportsocshowalltypewisee()

	MDTextField:
		id:socnda
		pos_hint:{'center_x':0.75,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDRectangleFlatButton:
		text:"Show All Data"
		pos_hint:{'center_x':0.5,'center_y':0.2}
		on_release:app.showall()

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.1}
		on_release:root.manager.current='ho'

<REScreen>
    name:'re'
    MDToolbar:
	    title:'Manage My Money-> Report Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

	MDTextField:
		id:m1
		hint_text:"Month"
		pos_hint:{'center_x':0.25,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropm1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .35, "center_y": .85}
		on_release:app.rem1.open()

	MDTextField:
		id:my1
		hint_text:"Year"
		pos_hint:{'center_x':0.25,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropmy1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .35, "center_y": .75}
		on_release:app.remy1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.20,'center_y':0.65}
		on_release:app.remtable1()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.30,'center_y':0.65}
		on_release:app.remgraph1()

	MDTextField:
		id:m2
		hint_text:"Month"
		pos_hint:{'center_x':0.25,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropm2
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .35, "center_y": .55}
		on_release:app.rem2.open()

	MDTextField:
		id:my2
		hint_text:"Year"
		pos_hint:{'center_x':0.25,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropmy2
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .35, "center_y": .45}
		on_release:app.remy2.open()

	MDTextField:
		id:ma1
		hint_text:"Account/Category"
		pos_hint:{'center_x':0.25,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropma1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .35, "center_y": .35}
		on_release:app.rema1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.20,'center_y':0.25}
		on_release:app.remtable2()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.30,'center_y':0.25}
		on_release:app.remgraph2()

	MDTextField:
		id:y1
		hint_text:"Year"
		helper_text:"Year"
		pos_hint:{'center_x':0.5,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropy1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .85}
		on_release:app.rey1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.45,'center_y':0.75}
		on_release:app.retable()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.55,'center_y':0.75}
		on_release:app.graphy1()

	MDTextField:
		id:y2
		hint_text:"Year"
		helper_text:"Year"
		pos_hint:{'center_x':0.5,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropy2
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .65}
		on_release:app.rey2.open()

	MDTextField:
		id:ay2
		hint_text:"Account Name"
		pos_hint:{'center_x':0.5,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropay1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .55}
		on_release:app.reay1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.45,'center_y':0.45}
		on_release:app.retableay()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.55,'center_y':0.45}
		on_release:app.graphay1()

	MDTextField:
		id:y3
		hint_text:"Year"
		helper_text:"Year"
		pos_hint:{'center_x':0.5,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropy3
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .35}
		on_release:app.rey3.open()

	MDTextField:
		id:c3
		hint_text:"Category Name"
		pos_hint:{'center_x':0.5,'center_y':0.25}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropcy1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .25}
		on_release:app.recy1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.45,'center_y':0.15}
		on_release:app.retablecy()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.55,'center_y':0.15}
		on_release:app.graphcy1()

	MDTextField:
		id:yy1
		hint_text:"From Year"
		pos_hint:{'center_x':0.75,'center_y':0.85}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropyy1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .85}
		on_release:app.reyy1.open()

	MDTextField:
		id:yy2
		hint_text:"To Year"
		pos_hint:{'center_x':0.75,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropyy2
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .75}
		on_release:app.reyy2.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.70,'center_y':0.65}
		on_release:app.retableyy1()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.80,'center_y':0.65}
		on_release:app.graphyy1()

	MDTextField:
		id:y2y1
		hint_text:"From Year"
		pos_hint:{'center_x':0.75,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropy2y1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .55}
		on_release:app.rey2y1.open()

	MDTextField:
		id:y2y2
		hint_text:"To Year"
		pos_hint:{'center_x':0.75,'center_y':0.45}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropy2y2
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .45}
		on_release:app.rey2y2.open()

	MDTextField:
		id:ya1
		hint_text:"Account/Category"
		pos_hint:{'center_x':0.75,'center_y':0.35}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropya1
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .35}
		on_release:app.reya1.open()

	MDRectangleFlatButton:
		text:"Show Table"
		pos_hint:{'center_x':0.70,'center_y':0.25}
		on_release:app.reyytable1()

	MDRectangleFlatButton:
		text:"Graph"
		pos_hint:{'center_x':0.80,'center_y':0.25}
		on_release:app.reyygraph1()

    MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.05}
		on_release:root.manager.current='ho'

<ACScreen>
    name:'ac'
    MDToolbar:
	    title:'Manage My Money-> Manage Account Screen'
	    pos_hint:{'center_x':0.5,'center_y':0.95}
	    elevation:10

	MDTextField:
		id:ace
		hint_text:"Account Name"
		helper_text:"Account Name"
		pos_hint:{'center_x':0.25,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
	
	MDRectangleFlatButton:
		text:"Create"
		pos_hint:{'center_x':0.25,'center_y':0.45}
		on_release:app.createacc()

	MDTextField:
		id:acd
		hint_text:"Account Name"
		helper_text:"Account Name"
		pos_hint:{'center_x':0.5,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropdelete
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .6, "center_y": .65}
		on_release:app.deletemenu.open()
		
	MDRectangleFlatButton:
		text:"Delete"
		pos_hint:{'center_x':0.5,'center_y':0.45}
		on_release:app.deleteacc()

	MDTextField:
		id:acu1
		hint_text:"Previous Account Name"
		helper_text:"Account Name"
		pos_hint:{'center_x':0.75,'center_y':0.75}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropupdate
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .75}
		on_release:app.updatemenu.open()

	MDTextField:
		id:acu2
		hint_text:"New Account Name"
		helper_text:"Needed Account Name"
		pos_hint:{'center_x':0.75,'center_y':0.65}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"

	MDTextField:
		id:acus
		hint_text:"Account Status"
		pos_hint:{'center_x':0.75,'center_y':0.55}
		size_hint_x:None
		width:300
		helper_text_mode:"on_focus"
		disabled:True

	MDIconButton:
		id:dropstatus
		icon:"gamepad-circle-down"
		pos_hint:{"center_x": .85, "center_y": .55}
		on_release:app.updatestatusmenu.open()

	MDRectangleFlatButton:
		text:"Update"
		pos_hint:{'center_x':0.75,'center_y':0.45}
		on_release:app.updateacc()

	MDRectangleFlatButton:
		text:"Show Accounts"
		pos_hint:{'center_x':0.5,'center_y':0.30}
		on_release:app.showacc()

	MDRectangleFlatButton:
		text:"Home"
		pos_hint:{'center_x':0.5,'center_y':0.15}
		on_release:root.manager.current='ho'
"""
