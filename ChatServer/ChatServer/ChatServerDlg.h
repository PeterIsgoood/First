
// ChatServerDlg.h : 헤더 파일
//

#pragma once

#include "afxwin.h"
#include "ListenSocket.h"

// CChatServerDlg 대화 상자
class CChatServerDlg : public CDialog
{
// 생성입니다.
public:
	CChatServerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CListenSocket		m_ListenSocket;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHATSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_List;
	afx_msg void OnDestroy();
	afx_msg void OnLbnSelchangeList();
	CStatic StaticTime;
	CStatic m_P1_Tx;
	CStatic m_P2_Tx;
	CStatic m_P3_Tx;
	CStatic m_P4_Tx;
	CStatic m_P5_Tx;
	CStatic m_P6_Tx;
	CStatic m_P1_Rx;
	CStatic m_P2_Rx;
	CStatic m_P3_Rx;
	CStatic m_P4_Rx;
	CStatic m_P5_Rx;
	CStatic m_P6_Rx;
	afx_msg void OnStnClickedTrafficPort6Tx2();
	afx_msg void OnStnClickedTrafficPort6Rx2();
	afx_msg void OnStnClickedTrafficPort6Tx3();
	afx_msg void OnStnClickedTrafficPort6Tx4();
	afx_msg void OnStnClickedTrafficPort6Tx5();
	afx_msg void OnStnClickedTrafficPort6Tx8();
	CStatic m_IP1;
	CStatic m_IP1_NUM;
	CStatic m_IP1_TX;
	CStatic m_IP1_RX;
	CStatic m_IP2;
	CStatic m_IP2_num;
	CStatic m_IP2_tx;
	CStatic m_IP2_rx;
	CStatic m_IP3_;
	CStatic m_IP3_num;
	CStatic m_IP3_tx;
	CStatic m_IP3_rx;
	CStatic m_IP4;
	CStatic m_IP4_num;
	CStatic m_IP4_tx;
	CStatic m_IP4_rx;
	CStatic m_IP5;
	CStatic m_IP5_num;
	CStatic m_IP5_tx;
	CStatic m_IP5_rx;
	CStatic m_IP6;
	CStatic m_IP6_num;
	CStatic m_IP6_tx;
	CStatic m_IP6_rx;
	CStatic m_IP7;
	CStatic m_IP7_num;
	CStatic m_IP7_tx;
	CStatic m_IP7_rx;
	CStatic m_IP8;
	CStatic m_IP8_num;
	CStatic m_IP8_tx;
	CStatic m_IP8_rx;
	// ip 시간 tx 축적
	CListBox m_List2;
	afx_msg void OnBnClickedSaveBtn();


	CStatic m_time1;
	CStatic m_time2;
	CStatic m_time3;
	CStatic m_time4;
	CStatic m_time5;
	
	CStatic m_situ1;
	CStatic m_situ2;
	CStatic m_situ3;
	CStatic m_situ4;
	CStatic m_situ5;
	
	CStatic m_avr1;
	CStatic m_avr2;
	CStatic m_avr3;
	CStatic m_avr4;
	CStatic m_avr5;
	
	CStatic m_exavr1;
	CStatic m_exavr2;
	CStatic m_exavr3;
	CStatic m_exavr4;
	CStatic m_exavr5;	
	
	CStatic m_interval1;
	CStatic m_interval2;
	CStatic m_interval3;
	CStatic m_interval4;
	CStatic m_interval5;
	
	CListBox m_EventList;
	afx_msg void OnBnClickedButton2();
	CListBox m_List3_1;
	CListBox m_List3_2;
	CListBox m_List3_3;
	CListBox m_List3_4;
	CListBox m_List3_5;
	CListBox m_List5;
	CListBox m_ListMax1;
	CListBox m_ListMax2;
	CListBox m_ListMax3;
	CListBox m_ListMax4;
	CListBox m_ListMax5;
};
