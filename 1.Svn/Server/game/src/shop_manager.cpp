//Find
	long distance = DISTANCE_APPROX(pkChr->GetX() - pkChrShopKeeper->GetX(), pkChr->GetY() - pkChrShopKeeper->GetY());

	if (distance >= SHOP_MAX_DISTANCE)
	{
		sys_log(1, "SHOP: TOO_FAR: %s distance %d", pkChr->GetName(), distance);
		return false;
	}
	
///Change
#if !defined(BL_REMOTE_SHOP)
	long distance = DISTANCE_APPROX(pkChr->GetX() - pkChrShopKeeper->GetX(), pkChr->GetY() - pkChrShopKeeper->GetY());

	if (distance >= SHOP_MAX_DISTANCE)
	{
		sys_log(1, "SHOP: TOO_FAR: %s distance %d", pkChr->GetName(), distance);
		return false;
	}
#endif

//Find
	if (DISTANCE_APPROX(ch->GetX() - ch->GetShopOwner()->GetX(), ch->GetY() - ch->GetShopOwner()->GetY()) > 2000)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("»уБЎ°ъАЗ °Её®°Ў іК№« ёЦѕо №°°ЗА» »м јц ѕшЅАґПґЩ."));
		return;
	}
	
///Change
#if !defined(BL_REMOTE_SHOP)
	if (DISTANCE_APPROX(ch->GetX() - ch->GetShopOwner()->GetX(), ch->GetY() - ch->GetShopOwner()->GetY()) > 2000)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("»уБЎ°ъАЗ °Её®°Ў іК№« ёЦѕо №°°ЗА» »м јц ѕшЅАґПґЩ."));
		return;
	}
#endif

//Find
	if (DISTANCE_APPROX(ch->GetX() - ch->GetShopOwner()->GetX(), ch->GetY() - ch->GetShopOwner()->GetY()) > 2000)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("»уБЎ°ъАЗ °Её®°Ў іК№« ёЦѕо №°°ЗА» ЖИ јц ѕшЅАґПґЩ."));
		return;
	}
	
///Change
#if !defined(BL_REMOTE_SHOP)
	if (DISTANCE_APPROX(ch->GetX() - ch->GetShopOwner()->GetX(), ch->GetY() - ch->GetShopOwner()->GetY()) > 2000)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("»уБЎ°ъАЗ °Её®°Ў іК№« ёЦѕо №°°ЗА» ЖИ јц ѕшЅАґПґЩ."));
		return;
	}
#endif