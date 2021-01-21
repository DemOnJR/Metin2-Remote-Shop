//Find
	Set(HEADER_CG_SAFEBOX_ITEM_MOVE, sizeof(TPacketCGItemMove), "SafeboxItemMove", true);
	
///Add
#if defined(BL_REMOTE_SHOP)
	Set(HEADER_CG_REMOTE_SHOP, sizeof(TPacketCGRemoteShop), "RemoteShop", true);
#endif