///Add
#if defined(BL_REMOTE_SHOP)
PyObject* netGetRemoteShopData(PyObject* poSelf, PyObject* poArgs)
{
	auto vShopNames = CPythonNetworkStream::Instance().GetRemoteShopNames();
	PyObject* _RemoteShop = PyTuple_New(vShopNames->size());

	for (size_t i = 0; i < vShopNames->size(); i++)
		PyTuple_SetItem(_RemoteShop, i, Py_BuildValue("s", vShopNames->at(i).c_str()));

	return _RemoteShop;
}
PyObject* netSendRemoteShopPacket(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bIdx;
	if (!PyTuple_GetByte(poArgs, 0, &bIdx))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendRemoteShopPacket(bIdx);
	return Py_BuildNone();
}
#endif

//Find
		{ NULL,										NULL,										NULL },
		
///Add above
#if defined(BL_REMOTE_SHOP)
		{ "GetRemoteShopData",						netGetRemoteShopData,						METH_VARARGS },
		{ "SendRemoteShopPacket",					netSendRemoteShopPacket,					METH_VARARGS },
#endif