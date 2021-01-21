//Find
bool CPythonNetworkStream::SendExchangeExitPacket()
{
	...
}

///Add
#if defined(BL_REMOTE_SHOP)
bool CPythonNetworkStream::SendRemoteShopPacket(BYTE bIndex)
{
	auto vShopNames = GetRemoteShopNames();
	if (bIndex >= vShopNames->size())
		return false;

	TPacketCGRemoteShop p;
	p.header = HEADER_CG_REMOTE_SHOP;
	p.shop_index = bIndex;

	if (!Send(sizeof(p), &p))
		return false;

	return SendSequence();
}
#endif