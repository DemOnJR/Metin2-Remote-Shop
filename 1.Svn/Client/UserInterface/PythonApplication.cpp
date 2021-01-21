//Find
	if (!rkItemMgr.LoadItemTable(szItemProto))
	{
		TraceError("LoadLocaleData - LoadItemProto(%s) Error", szItemProto);
		return false;
	}
	
///Add above
#if defined(BL_REMOTE_SHOP)
	char szRemoteShop[256];
	snprintf(szRemoteShop, sizeof(szRemoteShop), "%s/remote_shop_names.txt", localePath);
	if (!rkNetStream.LoadRemoteShop(szRemoteShop)) {
		TraceError("LoadRemoteShop - (%s) Error", szRemoteShop);
		return false;
	}
#endif