
// ZP_TEST2_3.h : ZP_TEST2_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CZP_TEST2_3App:
// �йش����ʵ�֣������ ZP_TEST2_3.cpp
//

class CZP_TEST2_3App : public CWinApp
{
public:
	CZP_TEST2_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZP_TEST2_3App theApp;
