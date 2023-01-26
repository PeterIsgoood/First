// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ClientSocket.h"
#include "ListenSocket.h"
#include "ChatServerDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	m_pListenSocket = NULL;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket member functions

void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
	TimeCount = 0;
	FirstAVR = 0;
	Event_Count = 0;
	E_Count = 0;
	Number_list3 = 0;     // �ѹ���		
	str_Max1 = 0;
	str_Max2 = 0;
	str_Max3 = 0;
	str_Max4 = 0;
	str_Max5 = 0;
	
	str_Min1 = 0;
	str_Min2 = 0;
	str_Min3 = 0;
	str_Min4 = 0;
	str_Min5 = 0;

}

void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}

void CClientSocket::OnReceive(int nErrorCode)
{
	CString strTmp = _T(""), strIPAddress = _T(""), strIPTraffic =_T(""), strIP_Sum =_T(""), strIP_Dump = _T(""), strIP_Dump2 = _T(""), strIP_Dump3 = _T(""), strIP_Dump_bbegi = _T(""), strIP_Dump4 = _T("");
	
	int Trans_Szbuffer = 0; // a0 �����÷η� �ȴ°� ���
	CString strTime=0; //�ð�
	CString strPort = 0; // ��Ʈ�� ��ŷ�
	unsigned char char_szBuffer[500] = { 0 };
	int Trafficint, IP_Num = 0; // ��Ʈ �� ��ŷ� ���
	int exTrafficint = 0;

	CString strIP = 0; // ip ��ŷ� �Է½�

	UINT uPortNumber = 0;
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	GetPeerName(strIPAddress, uPortNumber);
	if(Receive(szBuffer, sizeof(szBuffer)) > 0)
	{
		/* �����÷η� �Ǵ� a0�� fffffa0�� �Ǵ� ó�� ���
		Trans_Szbuffer = szBuffer[0];
		if (Trans_Szbuffer >= 0xffffffa0) Trans_Szbuffer = Trans_Szbuffer - 0xffffff00;
		if (Trans_Szbuffer = 0xa0) AfxMessageBox(_T("a0 found"));
		*/
		
		for (int i = 0; i < 300; i++)
		{
			Trans_Szbuffer = 0;
			Trans_Szbuffer = szBuffer[i];
			char_szBuffer[i] = szBuffer[i];
			if (Trans_Szbuffer > 0xffffff00)
			{
				Trans_Szbuffer = Trans_Szbuffer - 0xffffff00;
				char_szBuffer[i] = Trans_Szbuffer;
			}			
		}		

		CChatServerDlg* pMain = (CChatServerDlg*)AfxGetMainWnd();		
	 
		//�ð��̱�	
		strTime.Format(_T("%02d�� %02d�� %02d��"), char_szBuffer[11], char_szBuffer[12], char_szBuffer[13]);
		pMain->StaticTime.SetWindowTextA(strTime);	

		//��Ʈ ��ŷ� �̱�		
		//TX

		for (int i = 0; i < 6; i++)
		{
			Trafficint = 0;
			Trafficint =
				(char_szBuffer[(i * 10 )+ 14] * 256 * 256 * 256 * 256) +
				(char_szBuffer[(i * 10) + 15] * 256 * 256 * 256) +
				(char_szBuffer[(i * 10) + 16] * 256 * 256) +
				(char_szBuffer[(i * 10) + 17] * 256) +
				(char_szBuffer[(i * 10) + 18]);

			strPort.Format(_T("%d"), Trafficint);
			if (i == 0) pMain->m_P1_Tx.SetWindowTextA(strPort);
			if (i == 1) pMain->m_P2_Tx.SetWindowTextA(strPort);
			if (i == 2) pMain->m_P3_Tx.SetWindowTextA(strPort);
			if (i == 3) pMain->m_P4_Tx.SetWindowTextA(strPort);
			if (i == 4) pMain->m_P5_Tx.SetWindowTextA(strPort);
			if (i == 5) pMain->m_P6_Tx.SetWindowTextA(strPort);

			//RX
			Trafficint = 0;
			Trafficint =
				(char_szBuffer[(i * 10) + 19] * 256 * 256 * 256 * 256) +
				(char_szBuffer[(i * 10) + 20] * 256 * 256 * 256) +
				(char_szBuffer[(i * 10) + 21] * 256 * 256) +
				(char_szBuffer[(i * 10) + 22] * 256) +
				(char_szBuffer[(i * 10) + 23]);
			strPort.Format(_T("%d"), Trafficint);			
			if (i == 0) pMain->m_P1_Rx.SetWindowTextA(strPort);
			if (i == 1) pMain->m_P2_Rx.SetWindowTextA(strPort);
			if (i == 2) pMain->m_P3_Rx.SetWindowTextA(strPort);
			if (i == 3) pMain->m_P4_Rx.SetWindowTextA(strPort);
			if (i == 4) pMain->m_P5_Rx.SetWindowTextA(strPort);
			if (i == 5) pMain->m_P6_Rx.SetWindowTextA(strPort);
		}

		//ip �ֱ�
		for(int i =0 ;i< 8 ; i++)
		{
			//ip
			int sangsu = 15;
			strIP.Format(_T(""));
			strIP.Format(_T("%d,%d,%d,%d"), char_szBuffer[(i * sangsu) + 75], char_szBuffer[ (i * sangsu) + 76], char_szBuffer[(i * sangsu) + 77], 
				        char_szBuffer[(i * sangsu) +78]);
			if (i == 0) pMain->m_IP1.SetWindowTextA(strIP);
			if (i == 1) pMain->m_IP2.SetWindowTextA(strIP);
			if (i == 2) pMain->m_IP3_.SetWindowTextA(strIP);
			if (i == 3) pMain->m_IP4.SetWindowTextA(strIP);
			if (i == 4) pMain->m_IP5.SetWindowTextA(strIP);
			if (i == 5) pMain->m_IP6.SetWindowTextA(strIP);
			if (i == 6) pMain->m_IP7.SetWindowTextA(strIP);
			if (i == 7) pMain->m_IP8.SetWindowTextA(strIP);

			//port ��Ʈ���� �׳� strip ����
			strIP.Format(_T(""));
			strIP.Format(_T("%d"), char_szBuffer[(i * sangsu) + 74]);
			if (i == 0) pMain->m_IP1_NUM.SetWindowTextA(strIP);	
			if (i == 1) pMain->m_IP2_num.SetWindowTextA(strIP);
			if (i == 2) pMain->m_IP3_num.SetWindowTextA(strIP);
			if (i == 3) pMain->m_IP4_num.SetWindowTextA(strIP);
			if (i == 4) pMain->m_IP5_num.SetWindowTextA(strIP);
			if (i == 5) pMain->m_IP6_num.SetWindowTextA(strIP);
			if (i == 6) pMain->m_IP7_num.SetWindowTextA(strIP);
			if (i == 7) pMain->m_IP8_num.SetWindowTextA(strIP);					

			// tx 
			Trafficint = 0;		
			Trafficint =
				(char_szBuffer[(i * sangsu) + 79] * 256 * 256 * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 80] * 256 * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 81] * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 82] * 256) +
				(char_szBuffer[(i * sangsu) + 83]);

			strPort.Format(_T("%d"), Trafficint);
			if (i == 0) pMain->m_IP1_TX.SetWindowTextA(strPort);
			if (i == 1) pMain->m_IP2_tx.SetWindowTextA(strPort);
			if (i == 2) pMain->m_IP3_tx.SetWindowTextA(strPort);
			if (i == 3) pMain->m_IP4_tx.SetWindowTextA(strPort);
			if (i == 4) pMain->m_IP5_tx.SetWindowTextA(strPort);
			if (i == 5) pMain->m_IP6_tx.SetWindowTextA(strPort);
			if (i == 6) pMain->m_IP7_tx.SetWindowTextA(strPort);
			if (i == 7) pMain->m_IP8_tx.SetWindowTextA(strPort);
		
		//RX
			Trafficint = 0;
			Trafficint =
				(char_szBuffer[(i * sangsu) + 84] * 256 * 256 * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 85] * 256 * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 86] * 256 * 256) +
				(char_szBuffer[(i * sangsu) + 87] * 256) +
				(char_szBuffer[(i * sangsu) + 88]);
			strPort.Format(_T("%d"), Trafficint);
			if (i == 0) pMain->m_IP1_RX.SetWindowTextA(strPort);
			if (i == 1) pMain->m_IP2_rx.SetWindowTextA(strPort);
			if (i == 2) pMain->m_IP3_rx.SetWindowTextA(strPort);
			if (i == 3) pMain->m_IP4_rx.SetWindowTextA(strPort);
			if (i == 4) pMain->m_IP5_rx.SetWindowTextA(strPort);
			if (i == 5) pMain->m_IP6_rx.SetWindowTextA(strPort);
			if (i == 6) pMain->m_IP7_rx.SetWindowTextA(strPort);
			if (i == 7) pMain->m_IP8_rx.SetWindowTextA(strPort);

			if (char_szBuffer[(i * sangsu) + 91] == 0xfe)
			{				
				for (int j = i+1; j < 8 ; j++)
				{
					strIP.Format(_T("0.0.0.0"));
					if (j == 0) pMain->m_IP1.SetWindowTextA(strIP);
					if (j == 1) pMain->m_IP2.SetWindowTextA(strIP);
					if (j == 2) pMain->m_IP3_.SetWindowTextA(strIP);
					if (j == 3) pMain->m_IP4.SetWindowTextA(strIP);
					if (j == 4) pMain->m_IP5.SetWindowTextA(strIP);
					if (j == 5) pMain->m_IP6.SetWindowTextA(strIP);
					if (j == 6) pMain->m_IP7.SetWindowTextA(strIP);
					if (j == 7) pMain->m_IP8.SetWindowTextA(strIP);					

					strPort.Format(_T("0"));
					if (j == 0) pMain->m_IP1_TX.SetWindowTextA(strPort);
					if (j == 1) pMain->m_IP2_tx.SetWindowTextA(strPort);
					if (j == 2) pMain->m_IP3_tx.SetWindowTextA(strPort);
					if (j == 3) pMain->m_IP4_tx.SetWindowTextA(strPort);
					if (j == 4) pMain->m_IP5_tx.SetWindowTextA(strPort);
					if (j == 5) pMain->m_IP6_tx.SetWindowTextA(strPort);
					if (j == 6) pMain->m_IP7_tx.SetWindowTextA(strPort);
					if (j == 7) pMain->m_IP8_tx.SetWindowTextA(strPort);

					if (j == 0) pMain->m_IP1_RX.SetWindowTextA(strPort);
					if (j == 1) pMain->m_IP2_rx.SetWindowTextA(strPort);
					if (j == 2) pMain->m_IP3_rx.SetWindowTextA(strPort);
					if (j == 3) pMain->m_IP4_rx.SetWindowTextA(strPort);
					if (j == 4) pMain->m_IP5_rx.SetWindowTextA(strPort);
					if (j == 5) pMain->m_IP6_rx.SetWindowTextA(strPort);
					if (j == 6) pMain->m_IP7_rx.SetWindowTextA(strPort);
					if (j == 7) pMain->m_IP8_rx.SetWindowTextA(strPort);

					strIP.Format(_T("0"));					
					if (j == 0) pMain->m_IP1_NUM.SetWindowTextA(strIP);
					if (j == 1) pMain->m_IP2_num.SetWindowTextA(strIP);
					if (j == 2) pMain->m_IP3_num.SetWindowTextA(strIP);
					if (j == 3) pMain->m_IP4_num.SetWindowTextA(strIP);
					if (j == 4) pMain->m_IP5_num.SetWindowTextA(strIP);
					if (j == 5) pMain->m_IP6_num.SetWindowTextA(strIP);
					if (j == 6) pMain->m_IP7_num.SetWindowTextA(strIP);
					if (j == 7) pMain->m_IP8_num.SetWindowTextA(strIP);

					
				}
				break;
			}		

		}

		strTmp.Format(_T("[%s:%d] : %s"), strIPAddress, uPortNumber, szBuffer);
		pMain->m_List.AddString(strTmp);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() -1);


				
		//�ð��̱�
		strTime.Format(_T("%02d�� %02d�� %02d��  ||  "), char_szBuffer[11], char_szBuffer[12], char_szBuffer[13]);		
		

		int sangsu_Jari = 0;
		strIPTraffic.Format(_T("%d,%d,%d,%d     ||  "), char_szBuffer[(sangsu_Jari) + 75], char_szBuffer[(sangsu_Jari) + 76], char_szBuffer[(sangsu_Jari) + 77],
			char_szBuffer[(sangsu_Jari) + 78]);

		Trafficint =
			(char_szBuffer[79] * 256 * 256 * 256 * 256) +
			(char_szBuffer[80] * 256 * 256 * 256) +
			(char_szBuffer[81] * 256 * 256) +
			(char_szBuffer[82] * 256) +
			(char_szBuffer[83]);

		strPort.Format(_T("%d     ||    "), Trafficint);
		strIP_Dump.Format(_T("TimeCount = %d    ||   "), TimeCount);		
				
		if (FirstAVR == 0)    //��ŷ� ���
		{
			FirstAVR = Trafficint;
		}
		else {
			FirstAVR = (FirstAVR + Trafficint) / 2;
		}
		Event_Count_AVR[TimeCount] = Trafficint;

		if(TimeCount == 3) // �ʱ� ������ ������ 3���� ������ 
		{
			MinAVR = Trafficint;    // ���� ����
			exMinAVR = Trafficint;  //���� 
			MaxAVR = Trafficint;
			exMaxAVR = Trafficint;
			FirstAVR = 0;				
		
		}
		if (TimeCount % 3 == 0) //Ʈ�� �ʱ�ȭ
		{
			exMinAVR = MinAVR;  //�ּҰ� Ʈ�� �ʱ�ȭ
		//	exMaxAVR = MaxAVR;
		}
		
		if (TimeCount >= 3) // �ּҰ��� �ִ밪�� �˾Ƴ���. 
		{
			if (MinAVR > Trafficint)
			{
				exTrafficint = MinAVR;
				MinAVR = Trafficint;			

				// Ʈ�� ����� min �����ΰ�?
				if ((MinAVR - exMinAVR) > 0) //minavr�� ũ�ٸ�
				{
					MinAVR = MinAVR;
					exMinAVR = exMinAVR;

				}
				if ((MinAVR - exMinAVR) < 0) //minAVR�� �۴ٸ�, ���ϰ� ũ��.
				{
					exMinAVR = Trafficint;
					MinAVR = exTrafficint;
				}				
			}
			if (MaxAVR < Trafficint)
			{
				exTrafficint = MaxAVR;
				MaxAVR = Trafficint;
				//��⿡ �ִ밪�� ���� Ʈ���� �־�� �Ѵ�. 
				
				if ((MaxAVR - exMaxAVR) > 0) //maxavr�� ũ�ٸ�  ���� ū�Ŵ� ����.
				{
					exMaxAVR = Trafficint;
					MaxAVR = exTrafficint;
				}
				if ((MinAVR - exMinAVR) < 0) //MaxAVR�� �۴ٸ�
				{
					MaxAVR = MaxAVR;
					exMaxAVR = exMaxAVR;
				}
				
			}
		}


		////////////////////////// 2th AI str //////////////////////////////
		// pMain->StaticTime.SetWindowTextA(strTime);		

		str_list3[Number_list3].Format(_T("%d"), Trafficint);


		/*
		if (Number_list3 % 5 == 0)
		{
			pMain->m_List3_1.AddString(str_list3[Number_list3]);			
		//	pMain->m_List3_1.SetTopIndex(pMain->m_List3_1.GetCount() - 1);
		}
		if (Number_list3 % 5 == 1)
		{
			pMain->m_List3_2.AddString(str_list3[Number_list3]);			
		//	pMain->m_List3_2.SetTopIndex(pMain->m_List3_2.GetCount() - 1);
			
		}
		if (Number_list3 % 5 == 2)
		{
			pMain->m_List3_3.AddString(str_list3[Number_list3]);
		//	pMain->m_List3_3.SetTopIndex(pMain->m_List3_3.GetCount() - 1);
						
		}
		if (Number_list3 % 5 == 3)
		{
			pMain->m_List3_4.AddString(str_list3[Number_list3]);
		//	pMain->m_List3_4.SetTopIndex(pMain->m_List3_4.GetCount() - 1);

		}
		if (Number_list3 % 5 == 4)
		{
			pMain->m_List3_5.AddString(str_list3[Number_list3]);
		//	pMain->m_List3_5.SetTopIndex(pMain->m_List3_5.GetCount() - 1);

		}
		*/
				
		if (Number_list3 >= 10) // 5���� ���� �ʱⰪ - ó�� ������ ������ �����Ƿ� 10���� ����
		{
			int CHAI_Traffic;
			CHAI_Traffic = _ttoi(str_list3[Number_list3 - 5]) - Trafficint;

			str_list3_Value[Number_list3].Format(_T(" -%d-"), CHAI_Traffic);    //�񱳰��� �ִ´�.		


			if (CHAI_Traffic > 50000)
			{
				str_test100.Format(_T(""));

				str_test100.Format(_T("%d  "), Number_list3);

				str_test100 = str_test100 + str_list3_Value[Number_list3];

			//	pMain->m_List5.AddString(str_list3[Number_list3]);
				pMain->m_List5.AddString(str_test100);
			}
	//		pMain->m_List3_1.AddString(str_list3_Value[Number_list3]);
		}

		str_test100.Format(_T(""));
		str_test100.Format(_T("N= %d; "), Number_list3);
		str_test100 = str_test100 + str_list3[Number_list3] + str_list3_Value[Number_list3];

		///////////////////////////
		if (Number_list3 % 5 == 0)
		{
			m_distribution(Trafficint);
		//	pMain->m_List3_1.AddString(str_list3_Value[Number_list3]);
			pMain->m_List3_1.AddString(str_test100);		 
			//	pMain->m_List3_1.SetTopIndex(pMain->m_List3_1.GetCount() - 1);
			if (Number_list3 == 0)
			{
				str_Max1 = str_Min1 = Trafficint;
			}

			if (str_Max1 > Trafficint)
			{
				str_Max1 = str_Max1;
			}
			else
			{
				str_Max1 = Trafficint;
			}

			if (str_Min1 < Trafficint)
			{
				str_Min1 = str_Min1;
			}
			else
			{
				str_Min1 = Trafficint;
			}

			str_test100.Format(_T(""));
			str_test100.Format(_T("%d,%d, %d"), str_Max1,str_Min1, (str_Max1-str_Min1) );
			pMain->m_ListMax1.AddString(str_test100);

			str_test100.Format(_T(""));

			
			
		}
		if (Number_list3 % 5 == 1)
		{
		//	pMain->m_List3_2.AddString(str_list3_Value[Number_list3]);
			pMain->m_List3_2.AddString(str_test100);
			//	pMain->m_List3_2.SetTopIndex(pMain->m_List3_2.GetCount() - 1);

			if (Number_list3 == 1)
			{
				str_Max2 = str_Min2 = Trafficint;
			}

			if (str_Max2 > Trafficint)
			{
				str_Max2 = str_Max2;
			}
			else
			{
				str_Max2 = Trafficint;
			}

			if (str_Min2 < Trafficint)
			{
				str_Min2 = str_Min2;
			}
			else
			{
				str_Min2 = Trafficint;
			}

			str_test100.Format(_T(""));
			str_test100.Format(_T("%d,%d, %d"), str_Max2, str_Min2, (str_Max2 - str_Min2));
			pMain->m_ListMax2.AddString(str_test100);

			str_test100.Format(_T(""));

		}
		if (Number_list3 % 5 == 2)
		{
		//	pMain->m_List3_3.AddString(str_list3_Value[Number_list3]);
			pMain->m_List3_3.AddString(str_test100);
			//	pMain->m_List3_3.SetTopIndex(pMain->m_List3_3.GetCount() - 1);

			if (Number_list3 == 2)
			{
				str_Max3 = str_Min3 = Trafficint;
			}

			if (str_Max3 > Trafficint)
			{
				str_Max3 = str_Max3;
			}
			else
			{
				str_Max3 = Trafficint;
			}

			if (str_Min3 < Trafficint)
			{
				str_Min3 = str_Min3;
			}
			else
			{
				str_Min3 = Trafficint;
			}

			str_test100.Format(_T(""));
			str_test100.Format(_T("%d,%d, %d"), str_Max3, str_Min3, (str_Max3 - str_Min3));
			pMain->m_ListMax3.AddString(str_test100);

			str_test100.Format(_T(""));

		}
		if (Number_list3 % 5 == 3)
		{
		//	pMain->m_List3_4.AddString(str_list3_Value[Number_list3]);
			pMain->m_List3_4.AddString(str_test100);
			//	pMain->m_List3_4.SetTopIndex(pMain->m_List3_4.GetCount() - 1);

			if (Number_list3 == 3)
			{
				str_Max4 = str_Min4 = Trafficint;
			}

			if (str_Max4 > Trafficint)
			{
				str_Max4 = str_Max4;
			}
			else
			{
				str_Max4 = Trafficint;
			}

			if (str_Min4 < Trafficint)
			{
				str_Min4 = str_Min4;
			}
			else
			{
				str_Min4 = Trafficint;
			}

			str_test100.Format(_T(""));
			str_test100.Format(_T("%d,%d, %d"), str_Max4, str_Min4, (str_Max4 - str_Min4));
			pMain->m_ListMax4.AddString(str_test100);

			str_test100.Format(_T(""));

		}
		if (Number_list3 % 5 == 4)
		{
		//	pMain->m_List3_5.AddString(str_list3_Value[Number_list3]);
			pMain->m_List3_5.AddString(str_test100);
			//	pMain->m_List3_5.SetTopIndex(pMain->m_List3_5.GetCount() - 1);

			if (Number_list3 == 4)
			{
				str_Max5 = str_Min5 = Trafficint;
			}

			if (str_Max5 > Trafficint)
			{
				str_Max5 = str_Max5;
			}
			else
			{
				str_Max5 = Trafficint;
			}

			if (str_Min5 < Trafficint)
			{
				str_Min5 = str_Min5;
			}
			else
			{
				str_Min5 = Trafficint;
			}

			str_test100.Format(_T(""));
			str_test100.Format(_T("%d,%d, %d"), str_Max5, str_Min5, (str_Max5 - str_Min5));
			pMain->m_ListMax5.AddString(str_test100);

			str_test100.Format(_T(""));

		}

		//������ �ִ밪 �ּҰ� ���ϱ�
		





		if (Number_list3 == 9999)Number_list3 = 0;
		Number_list3++;

		
		//////////////////////////////////// �̺�Ʈ ó�� ///////////////////////////////////////////////
		
		if ((MaxAVR - MinAVR) >= 30000)
		{	
			//�̺�Ʈ ó�� ��ü�̵� ��Ȳ��ȭ  
			// ����
			//�̺�Ʈ�� �߻��ϸ� ������ ��ü�̵��� �Ͼ��.
			//��ü�̵��� �Ͼ�� �� timecount = 13�϶�(10�ʰ�)���ӵɶ� �����ŷ� ���Ͽ� ��Ȳ��ȭ ��		
			
			//�̺�Ʈ �߻���		
			
			strIP_Dump4.Format(_T("%s      -- �� ü �� �� (�� �� Ʈ �� �� )  --  "), strTime);

			
			//�̺�Ʈ �߻� ��ŷ�
			Event_AVR[Event_Count] = FirstAVR; 
			strIP_Dump4.Format(_T("%d"),Event_AVR[Event_Count]);
			pMain->m_avr1.SetWindowTextA(strIP_Dump4);

			//�̺�Ʈ �߻� �ٷ� ���� ��ŷ�			
			strIP_Dump4.Format(_T("%d"), Event_Count_AVR[TimeCount - 1]);
			pMain->m_exavr1.SetWindowTextA(strIP_Dump4);

			//�̺�Ʈ ����
			strIP_Dump4.Format(_T("%d"), (FirstAVR - Event_Count_AVR[TimeCount - 1]));
			pMain->m_interval1.SetWindowTextA(strIP_Dump4);

			strIP_Dump4.Format(_T("%s    ��ü�̵�(�̺�Ʈ)    || Recent = %d, Before = %d, Interval = %d"), strTime, Event_AVR[Event_Count], Event_Count_AVR[TimeCount - 1], (FirstAVR - Event_Count_AVR[TimeCount - 1]));			
	//		pMain->m_EventList.AddString(strIP_Dump4);


			Event_Count++;
			if (Event_Count == 4) Event_Count = 0;

			TimeCount = 2;
			strIPTraffic.Format(_T("----------- �̺�Ʈ -------------"));			

		}
		if ((MaxAVR - MinAVR) > 10000 && (MaxAVR - MinAVR) < 30000)
		{
			TimeCount = 2;
			strIPTraffic.Format(_T("----------- ��ü ���� -------------"));

			//��ü ���µ� �̺�Ʈ�̹Ƿ� ��հ��� ���� 
			/*
			Event_AVR[Event_Count] = FirstAVR; //������ ������ ����
			Event_Count++;
			if (Event_Count == 4) Event_Count = 0;
			*/
		}

	//	if (TimeCount == 13 || TimeCount == 23 || TimeCount == 33 || TimeCount == 43 || TimeCount == 53 || TimeCount == 63 || TimeCount == 73 || TimeCount == 83 || TimeCount == 93)  // 10�ʰ��� ���ӽð��� ���϶�
		if (TimeCount == 13 || TimeCount == 23 )  // 10�ʰ��� ���ӽð��� ���϶�
		{
			//��Ȳ��ȭ �ν� �ϱ� 
			// �̺�Ʈ ������ �־��� ������ �־��� ��Ȳ�� ���ϱ�
			// �̺�Ʈ �� 10�ʰ��� ���ӽð��� ���϶� ���ϰ� ������� ���ư���
			if (E_Count == 0)
			{
				E_AVR[0] = FirstAVR;



				strIP_Dump4.Format(_T("%s    ��Ȳ��ȭüũ����    ||   ���� = 0,  Ecount = %d " ), strTime, E_Count);		
				pMain->m_EventList.AddString(strIP_Dump4);
			}
			else {
				//���� ��Ȳ�� ������ ���ϱ�
				E_AVR[E_Count] = FirstAVR;
				ochar = E_AVR[E_Count] - E_AVR[E_Count-1];

				if (ochar > 10000 || ochar < -10000)
				{				
					strIP_Dump4.Format(_T("%s    -- �� Ȳ �� ȭ --     ||   ���� = %d,  Ecount = %d, T = %d"), strTime, ochar, E_Count, FirstAVR);
					pMain->m_EventList.AddString(strIP_Dump4);
				}
				if (ochar <= 10000 && ochar >= -10000 )
				{
					strIP_Dump4.Format(_T("%s    - ��Ȳ��ȭ�̺� -     ||   ���� = %d,  Ecount = %d, T = %d "), strTime, ochar, E_Count, FirstAVR);
					pMain->m_EventList.AddString(strIP_Dump4);
				}
			}			
			E_Count++;
		}
	//	strIP_Dump4.Format(_T("%s      ��Ȳ��ȭüũ����      ||   ���� = %d, Ecount = %d "), strTime, E_AVR[0], E_Count);
	//	strIP_Dump4.Format(_T("%s      -- �� Ȳ�� ȭ --      ||   ���� = %d, Ecount = %d "), strTime, ochar, E_Count);
	//	strIP_Dump4.Format(_T("%s      - ��Ȳ��ȭ�̺� -      ||   ���� = %d, Ecount = %d "), strTime, ochar, E_Count);

		TimeCount++;
	//	strIP_Dump_bbegi.Format(_T("%d"), (MaxAVR - MinAVR));
		strIP_Dump2.Format(_T("MinAVR = %d, exMinAVR = %d,  Max = %d, exMaxAVR = %d, BBegi = %d, AVR = %d "), MinAVR, exMinAVR, MaxAVR, exMaxAVR, (MaxAVR-MinAVR), FirstAVR);

		strIP_Sum = strTime + strIPTraffic + strPort + strIP_Dump + strIP_Dump2 ;
		pMain->m_List2.AddString(strIP_Sum);
		pMain->m_List2.SetTopIndex(pMain->m_List2.GetCount()-1);

		pMain->m_EventList.SetTopIndex(pMain->m_EventList.GetCount() - 1);
		
		CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
		pServerSocket->SendChatDataAll(szBuffer);		

//		TimeCount++;

	}

	CSocket::OnReceive(nErrorCode);
}




void CClientSocket::m_distribution(int m_TrafficInt)
{	
	//10������ Ŭ��
	if (m_TrafficInt > 100000)
	{

	}
	//9��~10��
	//8��~9��
	//7��~8��
	//6��~7��
	//5��~6��
	//4��~5��
	//3��~4��
	//2��~3��
	//1��~2��
	
	//�� ����
	if (m_TrafficInt < 10000)
	{
		//����
	}


	//�̷���ĵ� �ְ� Ʈ������ 100,000 ���� 10,000�� ������ ���
	//�ڿ� ��4�� õ�ڸ����� ���ְ� ������ 10000 ���� �ѵ� ������ �������� �����Ű�� ���!


}
