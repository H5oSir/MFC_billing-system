
// ZP_TEST2_3View.h : CZP_TEST2_3View 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"

#include "Page1Dlg.h"
#include "Page2Dlg.h"
#include "Data.h"


class CZP_TEST2_3View : public CFormView
{
protected: // 仅从序列化创建
	CZP_TEST2_3View();
	DECLARE_DYNCREATE(CZP_TEST2_3View)

public:
	enum{ IDD = IDD_ZP_TEST2_3_FORM };

// 特性
public:
	CZP_TEST2_3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CZP_TEST2_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CPage1Dlg m_page1;
	CPage2Dlg m_page2;
	CData m_data;
//	CControl m_control;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // ZP_TEST2_3View.cpp 中的调试版本
inline CZP_TEST2_3Doc* CZP_TEST2_3View::GetDocument() const
   { return reinterpret_cast<CZP_TEST2_3Doc*>(m_pDocument); }
#endif

