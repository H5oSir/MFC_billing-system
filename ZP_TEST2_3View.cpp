
// ZP_TEST2_3View.cpp : CZP_TEST2_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZP_TEST2_3.h"
#endif

#include "ZP_TEST2_3Doc.h"
#include "ZP_TEST2_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include "Page1Dlg.h"
#include "Page2Dlg.h"

// CZP_TEST2_3View

IMPLEMENT_DYNCREATE(CZP_TEST2_3View, CFormView)

BEGIN_MESSAGE_MAP(CZP_TEST2_3View, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, ID_TAB, &CZP_TEST2_3View::OnTcnSelchangeTab)
END_MESSAGE_MAP()

// CZP_TEST2_3View 构造/析构

CZP_TEST2_3View::CZP_TEST2_3View()
	: CFormView(CZP_TEST2_3View::IDD)
{
	// TODO: 在此处添加构造代码
	
	
}

CZP_TEST2_3View::~CZP_TEST2_3View()
{
}

void CZP_TEST2_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, ID_TAB, m_tab);
}

BOOL CZP_TEST2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CZP_TEST2_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_data.m_id=0;
	m_page1.m_data=&m_data;
	m_page2.m_data=&m_data;

	m_tab.InsertItem(0,TEXT("设置"));
	m_tab.InsertItem(1,TEXT("统计信息"));

	m_page1.Create(MAKEINTRESOURCE(IDD_PAGE1),&m_tab);
	m_page2.Create(MAKEINTRESOURCE(IDD_PAGE2),&m_tab);

	CRect rc;
	m_tab.GetClientRect(&rc);
	rc.top+=22;
	m_page1.MoveWindow(rc);
	m_page1.ShowWindow(TRUE);
	m_page2.MoveWindow(rc);
	m_page2.ShowWindow(FALSE);



	

	

	

	

	/*CTime mTime=CTime::GetTickCount();
	CString mDate=mTime.Format("20%y/%m/%d");
	m_page1.m_date=mDate;*/
	//m_page1.m_cmb_type.InsertString(4,mDate);
	/*m_page1.SetDlgItemText(IDC_EDT_TIME,mDate);
	m_data.initTongji();*/
	//UpdateData(FALSE);
	/*
	m_control.m_tab=&m_tab;
	m_control.m_page1=&m_page1;
	m_control.m_page2=&m_page2;
	m_control.showData();
	*/

	//m_page1.m_doc=this->GetDocument();
	m_data.initData();
	m_page1	.initData();
	m_page2.initData();
	

}


// CZP_TEST2_3View 诊断

#ifdef _DEBUG
void CZP_TEST2_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CZP_TEST2_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CZP_TEST2_3Doc* CZP_TEST2_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_TEST2_3Doc)));
	return (CZP_TEST2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZP_TEST2_3View 消息处理程序


void CZP_TEST2_3View::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_tab.GetCurSel())
	{
	case 0:
		m_page1.ShowWindow(TRUE);
		m_page2.ShowWindow(FALSE);
		break;
	case 1:
		m_page1.ShowWindow(FALSE);
		m_page2.ShowWindow(TRUE);
		break;
	default:
		/*m_page1.ShowWindow(FALSE);
		m_page2.ShowWindow(FALSE);*/
		break;
	}
	*pResult = 0;
}
