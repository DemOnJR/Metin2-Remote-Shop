//Find
		bool SendGuildWithdrawMoneyPacket(DWORD dwMoney);
		
///Add
#if defined(BL_REMOTE_SHOP)
		bool SendRemoteShopPacket(BYTE bIndex);
#endif

//Find
		DWORD EXPORT_GetBettingGuildWarValue(const char* c_szValueName);
		
///Add
#if defined(BL_REMOTE_SHOP)
		bool LoadRemoteShop(const char* FileName);
		std::vector<std::string> * GetRemoteShopNames() { return &vRemoteShopNames; }
#endif

//Find
		CInstanceBase * m_pInstTarget;
		
///Add
#if defined(BL_REMOTE_SHOP)
		std::vector<std::string> vRemoteShopNames;
#endif