import ui, net, localeInfo

class RemoteShopDialog(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__LoadDialog()		
		self.IsShow = False
		
	def __del__(self):
		ui.ScriptWindow.__del__(self)
		
	def __LoadDialog(self) :	
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "UIScript/RemoteShopDialog.py")
		except:
			import exception
			exception.Abort("RemoteShopDialog.__LoadDialog")
		
		self.ParentBoard = self.GetChild("RemoteShopBoard")
		self.ChildBoard = self.GetChild("BlackBoard")
		self.GetChild("RemoteShopTitle").SetCloseEvent(ui.__mem_func__(self.Close))
		
		self.ShopList = []
		ShopData = net.GetRemoteShopData()
		cnt = len(ShopData)
		
		self.DlgWidht = 190
		self.BlackBoardHeight = 23*cnt + 5*(cnt-1) + 13
		self.DlgHeight = self.BlackBoardHeight + 75
		
		self.AcceptBtn = ui.MakeButton(self.ParentBoard, 13, self.DlgHeight - 33, "", "d:/ymir work/ui/public/", "middle_button_01.sub", "middle_button_02.sub", "middle_button_03.sub")
		self.AcceptBtn.SetText( localeInfo.UI_ACCEPT )
		self.AcceptBtn.SetEvent(ui.__mem_func__(self.AcceptButton))
		self.CloseBtn = ui.MakeButton(self.ParentBoard, self.DlgWidht - 73, self.DlgHeight - 33, "", "d:/ymir work/ui/public/", "middle_button_01.sub", "middle_button_02.sub", "middle_button_03.sub")
		self.CloseBtn.SetText( localeInfo.UI_CLOSE )
		self.CloseBtn.SetEvent(ui.__mem_func__(self.Close))

		for i in xrange(cnt):
			btn = ui.MakeButton(self.ChildBoard, 8, 6 + i*28, "", "d:/ymir work/ui/game/myshop_deco/", "select_btn_01.sub", "select_btn_02.sub", "select_btn_03.sub")
			btn.SetText(ShopData[i])
			btn.SetEvent(ui.__mem_func__(self.__SelectShop), i)
			self.ShopList.append(btn)
		
		self.ParentBoard.SetSize(self.DlgWidht, self.DlgHeight)
		self.ChildBoard.SetSize(self.DlgWidht - 26, self.BlackBoardHeight)
		self.SetSize(self.DlgWidht, self.DlgHeight)
		
		self.UpdateRect()
		
	def __SelectShop(self, idx):
		if idx >= len(self.ShopList):
			return
			
		self.SelectedShopIndex = idx
		
		for btn in self.ShopList:
			btn.SetUp()
			btn.Enable()
			
		self.ShopList[idx].Down()
		self.ShopList[idx].Disable()
		
	def AcceptButton(self):
		net.SendRemoteShopPacket(self.SelectedShopIndex)
		self.Close()

	def Show(self) :
		if self.IsShowWindow():
			return	
		ui.ScriptWindow.Show(self)
		self.__SelectShop(0)
		self.SetCenterPosition()
		self.SetTop()		
		self.IsShow = True
	
	def Close(self):
		self.Hide()		
		self.IsShow = False
		
	def OnPressEscapeKey(self):
		self.Close()
		return True
		
	def IsShowWindow(self):
		return self.IsShow