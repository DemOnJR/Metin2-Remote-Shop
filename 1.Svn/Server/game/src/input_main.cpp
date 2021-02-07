//Find
void CInputMain::SafeboxItemMove(LPCHARACTER ch, const char* data)
{
	...
}

///Add
#if defined(BL_REMOTE_SHOP)
static bool RemoteShopRestrictedMap(long lMapIndex)
{
	switch (lMapIndex)
	{
	case 113:
		return false;
	}
	return true;
}
void CInputMain::RemoteShop(LPCHARACTER ch, const char* data)
{
	const TPacketCGRemoteShop* p = reinterpret_cast<const TPacketCGRemoteShop*>(data);

	if (RemoteShopRestrictedMap(ch->GetMapIndex()) == false)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "<RemoteShop> You can not open in this map.");
		return;
	}

	//PREVENT_TRADE_WINDOW
	if (ch->IsOpenSafebox() || ch->GetExchange() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("ґЩёҐ °Е·ЎГўАМ ї­ё°»уЕВїЎј­ґВ »уБЎ°Е·Ўё¦ ЗТјц °Ў ѕшЅАґПґЩ."));
		return;
	}
	//END_PREVENT_TRADE_WINDOW

	const DWORD dwCurrentTime = get_dword_time(), dwLimitTime = ch->GetLastRemoteTime() + 15000; // 15 sec.
	if (dwCurrentTime < dwLimitTime) {
		ch->ChatPacket(CHAT_TYPE_INFO, "<RemoteShop> You have to wait %u sec.", MAX(1, (dwLimitTime - dwCurrentTime) / 1000));
		return;
	}

	static const/*expr*/ DWORD _arrShopVnum[] = { 70, 75, 48, 107 };
	if (p->shop_index >= _countof(_arrShopVnum)) {
		sys_err("RemoteShop player(%s) unknown index(%d)", ch->GetName(), p->shop_index);
		return;
	}

	const DWORD dwShopVnum = _arrShopVnum[p->shop_index];
	LPSHOP pkShop = CShopManager::instance().Get(dwShopVnum);
	if (pkShop == NULL)
		return;

	pkShop->AddGuest(ch, NULL, false);
	ch->SetShopOwner(ch);
	ch->SetLastRemoteTime(get_dword_time());
	sys_log(0, "SHOP: START: %s", ch->GetName());
}
#endif

//Find
	case HEADER_CG_SAFEBOX_ITEM_MOVE:
		SafeboxItemMove(ch, c_pData);
		break;
		
///Add
#if defined(BL_REMOTE_SHOP)
	case HEADER_CG_REMOTE_SHOP:
		RemoteShop(ch, c_pData);
		break;
#endif