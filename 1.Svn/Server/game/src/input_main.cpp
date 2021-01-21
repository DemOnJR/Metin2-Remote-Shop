//Find
void CInputMain::SafeboxItemMove(LPCHARACTER ch, const char* data)
{
	...
}

///Add
#if defined(BL_REMOTE_SHOP)
void CInputMain::RemoteShop(LPCHARACTER ch, const char* data)
{
	const TPacketCGRemoteShop* p = reinterpret_cast<const TPacketCGRemoteShop*>(data);
	static const/*expr*/ DWORD _arrShopNpcVnum[] = { 9001, 9002, 9003, 9004 };

	if (p->shop_index >= _countof(_arrShopNpcVnum)) {
		sys_err("RemoteShop player(%s) unknown index(%d)", ch->GetName(), p->shop_index);
		return;
	}

	const DWORD dwCurrentTime = get_dword_time(), dwLimitTime = ch->GetLastRemoteTime() + 15000; // 15 sec.
	if (dwCurrentTime < dwLimitTime) {
		ch->ChatPacket(CHAT_TYPE_INFO, "<RemoteShop> You have to wait %u sec.", max(1, (dwLimitTime - dwCurrentTime) / 1000));
		return;
	}

	LPSECTREE_MAP pSecMap = SECTREE_MANAGER::instance().GetMap(ch->GetMapIndex());
	if (!pSecMap)
		return;

	struct FindSHOP
	{
		LPCHARACTER npc;
		DWORD vnum;
		FindSHOP(DWORD m_vnum) : npc(NULL), vnum(m_vnum) {};
		void operator()(LPENTITY ent)
		{
			if (ent->IsType(ENTITY_CHARACTER)) {
				LPCHARACTER ch = static_cast<LPCHARACTER>(ent);
				if (ch && ch->IsNPC() && ch->GetRaceNum() == vnum)
					npc = ch;
			}
		}
	};

	FindSHOP func(_arrShopNpcVnum[p->shop_index]);
	pSecMap->for_each(func);

	LPCHARACTER ShopNPC = func.npc;
	if (ShopNPC == NULL) {
		ch->ChatPacket(CHAT_TYPE_INFO, "This shop does not exist on this map.");
		return;
	}

	CShopManager::instance().StartShopping(ch, ShopNPC);
	ch->SetLastRemoteTime(get_dword_time());
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