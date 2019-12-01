#pragma once
#include "stdafx.h"
#include "ZP_TEST2_3.h"
#include "Page2Dlg.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "Data.h"

// CPage2Dlg �Ի���

class CPage2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPage2Dlg)

public:
	CPage2Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage2Dlg();

// �Ի�������
	enum { IDD = IDD_PAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	CString m_startTime;
	CString m_stopTime;
	CComboBox m_list_type;
	CListCtrl m_list;
	CData *m_data;
	void initData();
	void showAllData();
	void deleteData();
	void selectData();
	void showRowData(shop data);
	afx_msg void OnBnClickedBtnTongji();
	afx_msg void OnBnClickedBtnMingxi();
	afx_msg void OnBnClickedBtnQuxiao();
	CString m_cmb_value;
};
