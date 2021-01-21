#Add end of file
import app
if app.BL_REMOTE_SHOP:
	window["children"] += (
		{
			"name" : "RemoteShop",
			"type" : "button",

			"x" : SCREEN_WIDTH - 178,
			"y" : 3 + Y_ADD_POSITION,

			"tooltip_text" : uiScriptLocale.REMOTE_SHOP_TITLE,

			"default_image" : ROOT + "TaskBar/RemoteShop_Button_01.tga",
			"over_image" : ROOT + "TaskBar/RemoteShop_Button_02.tga",
			"down_image" : ROOT + "TaskBar/RemoteShop_Button_03.tga",
		},
	)