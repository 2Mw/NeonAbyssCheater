
// NeonAbyssCheaterDlg.h : header file
//

#pragma once

#include "GameEntry.h"


// CNeonAbyssCheaterDlg dialog
class CNeonAbyssCheaterDlg : public CDialogEx
{
	// Construction
public:
	CNeonAbyssCheaterDlg(CWnd* pParent = nullptr);	// standard constructor

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEONABYSSCHEATER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;
	GameEntry game_entry;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	const std::map<std::string, int> basic_label_map = {
		{"money", IDC_STATIC_MONEY}, {"hp", IDC_STATIC_HP}, {"crystal", IDC_STATIC_CRYSTAL}, {"shield", IDC_STATIC_SHIELD}, {"normalBomb", IDC_STATIC_NBOMB},
		{"iceBomb", IDC_STATIC_IBOMB}, {"jumpLevel", IDC_STATIC_JUMP_LEVEL}, {"rainbowKey", IDC_STATIC_RKEY}, {"normalKey", IDC_STATIC_NKEY}, 
		{"alcoholBomb", IDC_STATIC_ABOMB}, {"fireBomb", IDC_STATIC_FBOMB}
	};
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnBnClickedMfcbutton1();
};


// ==== Timer ID ====
#define BASIC_TIMER 1000


// ==== HotKey ID ====
#define HK_SHOW_HIDE_KEY 2000
