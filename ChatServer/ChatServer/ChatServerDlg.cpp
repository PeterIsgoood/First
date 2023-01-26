
// ChatServerDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ChatServerDlg.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChatServerDlg 대화 상자




CChatServerDlg::CChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_List, m_List);

	DDX_Control(pDX, IDC_StaticTime, StaticTime);
	DDX_Control(pDX, IDC_Traffic_Port1_Tx, m_P1_Tx);
	DDX_Control(pDX, IDC_Traffic_Port2_Tx, m_P2_Tx);
	DDX_Control(pDX, IDC_Traffic_Port3_Tx, m_P3_Tx);
	DDX_Control(pDX, IDC_Traffic_Port4_Tx, m_P4_Tx);
	DDX_Control(pDX, IDC_Traffic_Port5_Tx, m_P5_Tx);
	DDX_Control(pDX, IDC_Traffic_Port6_Tx, m_P6_Tx);
	DDX_Control(pDX, IDC_Traffic_Port1_Rx, m_P1_Rx);
	DDX_Control(pDX, IDC_Traffic_Port2_Rx, m_P2_Rx);
	DDX_Control(pDX, IDC_Traffic_Port3_Rx, m_P3_Rx);
	DDX_Control(pDX, IDC_Traffic_Port4_Rx, m_P4_Rx);
	DDX_Control(pDX, IDC_Traffic_Port5_Rx, m_P5_Rx);
	DDX_Control(pDX, IDC_Traffic_Port6_Rx, m_P6_Rx);
	DDX_Control(pDX, IDC_IP1, m_IP1);
	DDX_Control(pDX, IDC_IP1_NUM, m_IP1_NUM);
	DDX_Control(pDX, IDC_IP1_TX, m_IP1_TX);
	DDX_Control(pDX, IDC_IP1_RX, m_IP1_RX);
	DDX_Control(pDX, IDC_IP2, m_IP2);
	DDX_Control(pDX, IDC_IP2_NUM, m_IP2_num);
	DDX_Control(pDX, IDC_IP2_TX, m_IP2_tx);
	DDX_Control(pDX, IDC_IP2_RX, m_IP2_rx);
	DDX_Control(pDX, IDC_IP3, m_IP3_);
	DDX_Control(pDX, IDC_IP3_NUM, m_IP3_num);
	DDX_Control(pDX, IDC_IP3_TX, m_IP3_tx);
	DDX_Control(pDX, IDC_IP3_RX, m_IP3_rx);
	DDX_Control(pDX, IDC_IP4, m_IP4);
	DDX_Control(pDX, IDC_IP4_NUM, m_IP4_num);
	DDX_Control(pDX, IDC_IP4_TX, m_IP4_tx);
	DDX_Control(pDX, IDC_IP4_RX, m_IP4_rx);
	DDX_Control(pDX, IDC_IP5, m_IP5);
	DDX_Control(pDX, IDC_IP5_NUM, m_IP5_num);
	DDX_Control(pDX, IDC_IP5_TX, m_IP5_tx);
	DDX_Control(pDX, IDC_IP5_RX, m_IP5_rx);
	DDX_Control(pDX, IDC_IP6, m_IP6);
	DDX_Control(pDX, IDC_IP6_NUM, m_IP6_num);
	DDX_Control(pDX, IDC_IP6_TX, m_IP6_tx);
	DDX_Control(pDX, IDC_IP6_RX, m_IP6_rx);
	DDX_Control(pDX, IDC_IP7, m_IP7);
	DDX_Control(pDX, IDC_IP7_NUM, m_IP7_num);
	DDX_Control(pDX, IDC_IP7_TX, m_IP7_tx);
	DDX_Control(pDX, IDC_IP7_RX, m_IP7_rx);
	DDX_Control(pDX, IDC_IP8, m_IP8);
	DDX_Control(pDX, IDC_IP8_NUM, m_IP8_num);
	DDX_Control(pDX, IDC_IP8_TX, m_IP8_tx);
	DDX_Control(pDX, IDC_IP8_RX, m_IP8_rx);
	DDX_Control(pDX, IDC_List2, m_List2);

	DDX_Control(pDX, IDC_time1, m_time1);
	DDX_Control(pDX, IDC_time2, m_time2);
	DDX_Control(pDX, IDC_time3, m_time3);
	DDX_Control(pDX, IDC_time4, m_time4);
	DDX_Control(pDX, IDC_time5, m_time5);

	DDX_Control(pDX, IDC_situ1, m_situ1);
	DDX_Control(pDX, IDC_situ2, m_situ2);
	DDX_Control(pDX, IDC_situ3, m_situ3);
	DDX_Control(pDX, IDC_situ4, m_situ4);
	DDX_Control(pDX, IDC_situ5, m_situ5);

	DDX_Control(pDX, IDC_avr1, m_avr1);
	DDX_Control(pDX, IDC_avr2, m_avr2);
	DDX_Control(pDX, IDC_avr3, m_avr3);
	DDX_Control(pDX, IDC_avr4, m_avr4);
	DDX_Control(pDX, IDC_avr5, m_avr5);

	DDX_Control(pDX, IDC_exAvr1, m_exavr1);
	DDX_Control(pDX, IDC_exAvr2, m_exavr2);
	DDX_Control(pDX, IDC_exAvr3, m_exavr3);
	DDX_Control(pDX, IDC_exAvr4, m_exavr4);
	DDX_Control(pDX, IDC_exAvr5, m_exavr5);

	DDX_Control(pDX, IDC_interval1, m_interval1);
	DDX_Control(pDX, IDC_interval2, m_interval2);
	DDX_Control(pDX, IDC_interval3, m_interval3);
	DDX_Control(pDX, IDC_interval4, m_interval4);
	DDX_Control(pDX, IDC_interval5, m_interval5);

	DDX_Control(pDX, IDC_List3, m_EventList);
	DDX_Control(pDX, IDC_LIST3_1, m_List3_1);
	DDX_Control(pDX, IDC_LIST3_2, m_List3_2);
	DDX_Control(pDX, IDC_LIST3_3, m_List3_3);
	DDX_Control(pDX, IDC_LIST3_4, m_List3_4);
	DDX_Control(pDX, IDC_LIST3_5, m_List3_5);
	DDX_Control(pDX, IDC_LIST5, m_List5);
	DDX_Control(pDX, IDC_LIST_max1, m_ListMax1);
	DDX_Control(pDX, IDC_LIST_max2, m_ListMax2);
	DDX_Control(pDX, IDC_LIST_max3, m_ListMax3);
	DDX_Control(pDX, IDC_LIST_max4, m_ListMax4);
	DDX_Control(pDX, IDC_LIST_max5, m_ListMax5);
}

BEGIN_MESSAGE_MAP(CChatServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_List, &CChatServerDlg::OnLbnSelchangeList)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Tx2, &CChatServerDlg::OnStnClickedTrafficPort6Tx2)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Rx2, &CChatServerDlg::OnStnClickedTrafficPort6Rx2)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Tx3, &CChatServerDlg::OnStnClickedTrafficPort6Tx3)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Tx4, &CChatServerDlg::OnStnClickedTrafficPort6Tx4)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Tx5, &CChatServerDlg::OnStnClickedTrafficPort6Tx5)
//	ON_STN_CLICKED(IDC_Traffic_Port6_Tx8, &CChatServerDlg::OnStnClickedTrafficPort6Tx8)
ON_BN_CLICKED(IDC_Save_Btn, &CChatServerDlg::OnBnClickedSaveBtn)
ON_BN_CLICKED(IDC_BUTTON2, &CChatServerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CChatServerDlg 메시지 처리기

BOOL CChatServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	if(m_ListenSocket.Create(51153, SOCK_STREAM))
	{
		if(!m_ListenSocket.Listen())
		{
			AfxMessageBox(_T("ERROR: Listen() return FALSE"));
		}
	}
	else
	{
		AfxMessageBox(_T("ERROR: Failed to create server socket!"));
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChatServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChatServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChatServerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	POSITION pos;
	pos = m_ListenSocket.m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while(pos != NULL)
	{
		pClient = (CClientSocket*)
				m_ListenSocket.m_ptrClientSocketList.GetNext(pos);
		if(pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();

			delete pClient;
		}
	}

	m_ListenSocket.ShutDown();
	m_ListenSocket.Close();
}


void CChatServerDlg::OnLbnSelchangeList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Tx2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Rx2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Tx3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Tx4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Tx5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnStnClickedTrafficPort6Tx8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChatServerDlg::OnBnClickedSaveBtn()
{
	LPCTSTR lpszFilter = _T("txt파일(*.txt)");
	CFileDialog FileDlg( FALSE, _T( ".txt" ), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, NULL );

	if (FileDlg.DoModal() == IDOK) 
	{
		CString sPath(FileDlg.GetPathName());
		CFile File(sPath, CFile::modeWrite | CFile::modeCreate);

		CString sData = NULL;
		for (int i = 0; i < m_List2.GetCount(); ++i) 
		{ 
			m_List2.GetText(i, sData);
			sData += _T("\r\n");
			File.Write((LPCTSTR)sData, sData.GetLength() * sizeof(TCHAR)); 
		}
		
		File.Flush(); File.Close();	
	}
}	


void CChatServerDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LPCTSTR lpszFilter = _T("txt파일(*.txt)");
	CFileDialog FileDlg(FALSE, _T(".txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, NULL);

	if (FileDlg.DoModal() == IDOK)
	{
		CString sPath(FileDlg.GetPathName());
		CFile File(sPath, CFile::modeWrite | CFile::modeCreate);

		CString sData = NULL;
		for (int i = 0; i < m_EventList.GetCount(); ++i)
		{
			m_EventList.GetText(i, sData);
			sData += _T("\r\n");
			File.Write((LPCTSTR)sData, sData.GetLength() * sizeof(TCHAR));
		}

		File.Flush(); File.Close();
	}
	
}
