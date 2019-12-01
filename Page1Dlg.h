#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ZP_TEST2_3Doc.h"
#include "resource.h" 
#include "Data.h"

// CPage1Dlg �Ի���

class CPage1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPage1Dlg)

public:
	CPage1Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage1Dlg();

// �Ի�������
	enum { IDD = IDD_PAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	CComboBox m_cmb_type;
	CString m_name;
	CString m_money;
	CListCtrl m_list;
	CString m_date;
	CTreeCtrl m_tree;
	CData *m_data;
	HTREEITEM* m_tRoot;
	afx_msg void OnBnClickedBtnUpdate();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnBnClickedBtnAdd();
public:
	bool showData(shop sData);
	bool showTree();
	bool showList(shop sData);
	void initData();
	CString m_cmb_value;
};
