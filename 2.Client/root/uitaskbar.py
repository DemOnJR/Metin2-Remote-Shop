#Find
	BUTTON_EXPAND = 4

#Add
	if app.BL_REMOTE_SHOP:
		BUTTON_REMOTE_SHOP = 5
		
#Find
		toggleButtonDict[TaskBar.BUTTON_SYSTEM]=self.GetChild("SystemButton")
		
#Add
		if app.BL_REMOTE_SHOP:
			toggleButtonDict[TaskBar.BUTTON_REMOTE_SHOP]=self.GetChild("RemoteShop")