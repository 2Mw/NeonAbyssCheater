
// NeonAbyssCheaterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "NeonAbyssCheater.h"
#include "NeonAbyssCheaterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNeonAbyssCheaterDlg dialog

CNeonAbyssCheaterDlg::CNeonAbyssCheaterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEONABYSSCHEATER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNeonAbyssCheaterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNeonAbyssCheaterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_HOTKEY()
END_MESSAGE_MAP()


// CNeonAbyssCheaterDlg message handlers

BOOL CNeonAbyssCheaterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Initialize Basic Timer
	SetTimer(BASIC_TIMER, 1000, NULL);

	// Register HotKey
	RegisterHotKey(m_hWnd, HK_SHOW_HIDE_KEY, 0, VK_F9);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNeonAbyssCheaterDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNeonAbyssCheaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Timer Handler
void CNeonAbyssCheaterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == BASIC_TIMER) {	
		CString showText;
		auto id = game_entry.getGameProcessID();
		if (game_entry.isGameRunning()) showText = "Game not running...";
		else showText.Format("PID:%lld", id);
		SetDlgItemText(IDC_STATIC_GAME_STATUS, showText);
		auto basic_info = game_entry.getHeroBasicInfo();
		for (auto item : basic_info) {
			CString s;
			s.Format("%.3lf", item.second);
			int id = basic_label_map.at(item.first);
			SetDlgItemTextA(id, s);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CNeonAbyssCheaterDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: Add your message handler code here and/or call default
	if (nHotKeyId == HK_SHOW_HIDE_KEY) {
		if (IsWindowVisible()) this->ShowWindow(SW_HIDE);
		else this->ShowWindow(SW_SHOW);
	}
	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CNeonAbyssCheaterDlg::OnBnClickedMfcbutton1()
{
	
}
