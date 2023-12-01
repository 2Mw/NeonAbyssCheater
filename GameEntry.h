#pragma once
#include "ProcessUtil.h"
#include "pch.h"
// Learn from: https://github.com/Geedium/pvz-trainer

class GameEntry
{
private:
	CString process_name = "Neon Abyss";
	CString process_class = "UnityWndClass";
	CString unity_player_dll = "UnityPlayer.dll";

	DWORD proccessID = 0;
	// unity_player_dll's base address
	QWORD upd_base = 0;
	// the HANDLE of process
	HANDLE pHandle = 0;

	// ===== Basic info part ======
	const std::vector<QWORD> BASIC_INFO_OFFSET = { 0x01542940, 0, 0x10, 0x28, 0x40, 0x18, 0x18, 0x10, 0x18 };
	const std::map<std::string, QWORD> basic_map = {
		{"money", 0x210}, {"hp", 0x258}, {"crystal", 0x270}, {"shield", 0x288}, {"normalBomb", 0x2a0}, {"iceBomb", 0x450}, {"jumpLevel", 0x3f0}, {"rainbowKey", 0x468}, {"normalKey", 0x510}, {"alcoholBomb", 0x558}, {"fireBomb", 0xc30}
	};

public:
	/**
	Get the name of neon abyss process
	*/
	CString getGameName() const;

	// Return the class name of game window
	CString getGameMainClass() const;

	DWORD getGameProcessID();
	/*
	Return if the game is running
	*/
	BOOL isGameRunning();
	/*
	Get the player's hero basic infomation when in battle mode.
	*/
	std::map<std::string, double> getHeroBasicInfo();


};

