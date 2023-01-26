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
	
	int Number_list3;   // 5개씩 나눠서 넣는것에 대한 넘버링		
	CString str_list3[10000];  // nuber_list3 에 넣을 value 값
	CString str_list3_Value[10000]; // nuber_list3 에 넣을 비교값

	CString str_test100;  //테스값 넣기

	int str_Max1, str_Max2, str_Max3, str_Max4, str_Max5;
	int str_Min1, str_Min2, str_Min3, str_Min4, str_Min5;


	


	int Event_AVR[10] = { 0 };  // 이벤트에 따라 평균통신량 저장 
	int Event_Count;
	int Event_Count_AVR[20000] = { 0 };
	
	
	int E_AVR[10000];	
	int E_Count;
	int ochar;
	void m_distribution(int m_TrafficInt);
};


