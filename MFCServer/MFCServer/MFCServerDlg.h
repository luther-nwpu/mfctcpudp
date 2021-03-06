
// MFCServerDlg.h: 头文件
//

#pragma once
#include "afxwin.h"
#include <WinSock2.h>

#define MAX_SOCKET 56	// 定义此服务器所能接受的最大客户量

// CMFCServerDlg 对话框
class CMFCServerDlg : public CDialog
{
// 构造
public:
	CMFCServerDlg(CWnd* pParent = NULL);	// 标准构造函数
	sockaddr_in m_clientAddr;
	// 若为true则终止线程  
	bool m_bTerminateThread;
	// Socket 要处理的Socket
	SOCKET recieveSocket;
	// 客户连接列表
	SOCKET client[MAX_SOCKET];	// 套节字数组
	int clientcount;			// 上述数组的大小
	CWinThread* currentThread;
	// udpSocket
	SOCKET udpSocket;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG *pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 当前记录的Port
	CString portString;
	// 记录所有人的message
	CString messageString;
	// 记录当前状态
	CString clueString;
	// 记录当前udp的端口
	CString udpPortString;
	// 展示当前message
	CListBox messagesBox;
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedClear();
	afx_msg void OnEnChangeMessages();
	afx_msg void OnEnChangePort();
	afx_msg void OnEnChangeClue();
	afx_msg void OnLbnSelchangeMessageslist();
	BOOL CreateAndListen(int nPort);
	long OnSocket(WPARAM wParam, LPARAM lParam);
	BOOL AddClient(SOCKET s);
	void RemoveClient(SOCKET s);
	BOOL CloseAllSocket();
};
