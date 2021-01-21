//Find
	private:
		bool IsValidItemPosition(TItemPos Pos) const;
		
///Add
#if defined(BL_REMOTE_SHOP)
	public:
		DWORD GetLastRemoteTime() const { return dwLastRemoteTime; }
		void SetLastRemoteTime(DWORD dwTime) { dwLastRemoteTime = dwTime; }
	private:
		DWORD dwLastRemoteTime;
#endif