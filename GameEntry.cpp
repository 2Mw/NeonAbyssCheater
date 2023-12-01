#include "pch.h"
#include "GameEntry.h"
#include "ProcessUtil.h"

CString GameEntry::getGameName() const
{
	return process_name;
}

CString GameEntry::getGameMainClass() const
{
	return process_class;
}

DWORD GameEntry::getGameProcessID()
{
	DWORD tmpProcessID = ProcessUtil::GetProcessIDByTitle(getGameName(), getGameMainClass());
	if (tmpProcessID != proccessID) {	// ¸üÐÂ
		proccessID = tmpProcessID;
		pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, proccessID);
		auto p = ProcessUtil::GetModule(proccessID, unity_player_dll.GetBuffer());
		upd_base = p.first;
	}

	return proccessID;
}

BOOL GameEntry::isGameRunning()
{
	return getGameProcessID() == 0;
}

std::map<std::string, double> GameEntry::getHeroBasicInfo()
{
	QWORD roleBase = ProcessUtil::ReadMultiLevelPointer(pHandle, upd_base, BASIC_INFO_OFFSET);
	std::map<std::string, double> ans;
	
	for (auto i : basic_map) {
		QWORD eAddr = ProcessUtil::ReadMultiLevelPointer(pHandle, roleBase, { 0, i.second });
		// ProcessUtil::GetProcessIDByTitle("Neon Abyss");
		ans[i.first] = ProcessUtil::Read<double>(pHandle, eAddr);
	}
	return ans;
}
