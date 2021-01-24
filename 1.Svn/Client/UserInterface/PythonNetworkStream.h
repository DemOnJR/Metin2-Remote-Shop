//Find
		bool SendGuildWithdrawMoneyPacket(DWORD dwMoney);
		
///Add
#if defined(BL_REMOTE_SHOP)
		bool SendRemoteShopPacket(BYTE bIndex);
#endif