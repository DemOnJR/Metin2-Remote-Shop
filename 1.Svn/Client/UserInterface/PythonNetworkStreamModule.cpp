///Add
#if defined(BL_REMOTE_SHOP)
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
		{ "SendRemoteShopPacket",					netSendRemoteShopPacket,					METH_VARARGS },
#endif