//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(BL_REMOTE_SHOP)
	PyModule_AddIntConstant(poModule, "BL_REMOTE_SHOP", true);
#else
	PyModule_AddIntConstant(poModule, "BL_REMOTE_SHOP", false);
#endif