//Find
	HEADER_CG_STATE_CHECKER					= 206,
	
///Add
#if defined(BL_REMOTE_SHOP)
	HEADER_CG_REMOTE_SHOP						= 215,
#endif

//Find
typedef struct command_item_use
{
	...
} TPacketCGItemUse;

///Add
#if defined(BL_REMOTE_SHOP)
typedef struct command_remote_shop
{
	BYTE	header;
	BYTE	shop_index;
} TPacketCGRemoteShop;
#endif