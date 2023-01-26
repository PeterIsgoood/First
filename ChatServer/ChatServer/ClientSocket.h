#pragma once

// CClientSocket command target

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	CAsyncSocket*	m_pListenSocket;

	void SetListenSocket(CAsyncSocket* pSocket);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);

	int FirstAVR, LaterAVR;
	int MinAVR, MaxAVR;
	int exMinAVR, exMaxAVR;
	int TimeCount;	
	
	int Number_list3;   // 5���� ������ �ִ°Ϳ� ���� �ѹ���		
	CString str_list3[10000];  // nuber_list3 �� ���� value ��
	CString str_list3_Value[10000]; // nuber_list3 �� ���� �񱳰�

	CString str_test100;  //�׽��� �ֱ�

	int str_Max1, str_Max2, str_Max3, str_Max4, str_Max5;
	int str_Min1, str_Min2, str_Min3, str_Min4, str_Min5;


	


	int Event_AVR[10] = { 0 };  // �̺�Ʈ�� ���� �����ŷ� ���� 
	int Event_Count;
	int Event_Count_AVR[20000] = { 0 };
	
	
	int E_AVR[10000];	
	int E_Count;
	int ochar;
	void m_distribution(int m_TrafficInt);
};


