#Add
if app.BL_REMOTE_SHOP:
	import uiRemoteShop
	
#Find
		self.wndTaskBar = None
		
#Add
		if app.BL_REMOTE_SHOP:
			self.wndRemoteShop = None
			
#Find
		import app
		if app.ENABLE_ENERGY_SYSTEM:
			wndEnergyBar = uiTaskBar.EnergyBar()
			wndEnergyBar.LoadWindow()
			self.wndEnergyBar = wndEnergyBar
			
#Add
		if app.BL_REMOTE_SHOP:
			self.wndTaskBar.SetToggleButtonEvent(uiTaskBar.TaskBar.BUTTON_REMOTE_SHOP, ui.__mem_func__(self.OpenRemoteShop))
			
#Find
		wndChatLog.BindInterface(self)
		
#Add
		if app.BL_REMOTE_SHOP:
			self.wndRemoteShop = uiRemoteShop.RemoteShopDialog()
			
#Find
		if self.wndDragonSoul:
			del self.wndDragonSoul
			
#Add
		if app.BL_REMOTE_SHOP:
			if self.wndRemoteShop:
				del self.wndRemoteShop
				
#Find
	def MakeWhisperButton(self, name):
		self.__MakeWhisperButton(name)
		
#Add
	if app.BL_REMOTE_SHOP:
		def OpenRemoteShop(self):
			if self.wndRemoteShop:
				self.wndRemoteShop.Show()