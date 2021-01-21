//Find
bool CPythonNetworkStream::IsInsultIn(const char* c_szMsg)
{
	...
}

///Add
#if defined(BL_REMOTE_SHOP)
bool CPythonNetworkStream::LoadRemoteShop(const char* FileName)
{
	CMappedFile file;
	const VOID* pvData;
	if (!CEterPackManager::Instance().Get(file, FileName, &pvData))
		return false;

	CMemoryTextFileLoader kMemTextFileLoader;
	kMemTextFileLoader.Bind(file.Size(), pvData);

	auto TotalLineCount = kMemTextFileLoader.GetLineCount();
	vRemoteShopNames.clear();
	vRemoteShopNames.reserve(TotalLineCount);

	for (decltype(TotalLineCount) dwLineIndex = 0; dwLineIndex < TotalLineCount; ++dwLineIndex)
	{
		const std::string& sShopName = kMemTextFileLoader.GetLineString(dwLineIndex);
		vRemoteShopNames.push_back(sShopName);
	}

	return true;
}
#endif