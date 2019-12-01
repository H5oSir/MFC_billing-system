// Page2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST2_3.h"
#include "Page2Dlg.h"
#include "afxdialogex.h"


// CPage2Dlg 对话框

IMPLEMENT_DYNAMIC(CPage2Dlg, CDialogEx)

CPage2Dlg::CPage2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2Dlg::IDD, pParent)
	, m_startTime(_T(""))
	, m_stopTime(_T(""))
	, m_cmb_value(_T(""))
{

}

CPage2Dlg::~CPage2Dlg()
{
}

void CPage2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Text(pDX, IDC_EDI_TIME1, m_startTime);
	DDX_Text(pDX, IDC_EDI_TIME2, m_stopTime);
	DDX_Control(pDX, IDC_CMB_TYPE, m_list_type);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_CBString(pDX, IDC_CMB_TYPE, m_cmb_value);
}


BEGIN_MESSAGE_MAP(CPage2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_TONGJI, &CPage2Dlg::OnBnClickedBtnTongji)
	ON_BN_CLICKED(IDC_BTN_MINGXI, &CPage2Dlg::OnBnClickedBtnMingxi)
	ON_BN_CLICKED(IDC_BTN_QUXIAO, &CPage2Dlg::OnBnClickedBtnQuxiao)
END_MESSAGE_MAP()


// CPage2Dlg 消息处理程序


void CPage2Dlg::OnBnClickedBtnTongji()
{
	// TODO: 在此添加控件通知处理程序代码
	selectData();
}


void CPage2Dlg::OnBnClickedBtnMingxi()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CPage2Dlg::OnBnClickedBtnQuxiao()
{
	// TODO: 在此添加控件通知处理程序代码
}
void CPage2Dlg::initData()
{
	CString str;
	str="2019/01/01";
	m_startTime=str;
	str="2019/02/01";
	m_stopTime=str;
	UpdateData(FALSE);
	m_list_type.InsertString(0,TEXT("食品"));
	m_list_type.InsertString(1,TEXT("数码"));
	m_list_type.InsertString(2,TEXT("理财"));
	m_list_type.InsertString(3,TEXT("其它"));
	m_list_type.InsertString(4,TEXT("所有"));
	m_list_type.SetCurSel(0);
	//m_page2.m_cmb_type.SetCurSel(m_page1.m_cmb_type.GetCount()-1);


	m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.InsertColumn(0,TEXT("序号"),LVCFMT_CENTER,90);
	m_list.InsertColumn(1,TEXT("类型"),LVCFMT_CENTER,90);
	m_list.InsertColumn(2,TEXT("名称"),LVCFMT_CENTER,90);
	m_list.InsertColumn(3,TEXT("钱数"),LVCFMT_CENTER,90);
	m_list.InsertColumn(4,TEXT("时间"),LVCFMT_CENTER,90);

	
}
void CPage2Dlg::showAllData()
{
	deleteData();
	for (int i = 0; i < m_data->m_id; i++)
	{
		if (m_data->m_data[i].haveData)
		{
			showRowData(m_data->m_data[i]);
			/*int nCount=m_list.GetItemCount();
			m_list.InsertItem(nCount,m_data->m_data[i].id);
			m_list.SetItemText(nCount,1,m_data->m_data[i].type);
			m_list.SetItemText(nCount,2,m_data->m_data[i].name);
			m_list.SetItemText(nCount,3,m_data->m_data[i].money);
			m_list.SetItemText(nCount,4,m_data->m_data[i].date);*/
		}
	}
}

void CPage2Dlg::deleteData()
{
	for (int i = m_list.GetItemCount()-1; i >=0; i--)
	{
		/*m_list.DeleteItem(i,m_data->m_data[i].id);
		m_list.DeleteItem(i,1,m_data->m_data[i].type);
		m_list.DeleteItem(i,2,m_data->m_data[i].name);
		m_list.DeleteItem(i,3,m_data->m_data[i].money);*/
		m_list.DeleteItem(i);
	}
}

void CPage2Dlg::selectData()
{
	deleteData();
	UpdateData(TRUE);
	for (int i = 0; i < m_data->m_id; i++)
	{
		if (m_data->m_data[i].haveData)
		{
			if ( m_cmb_value == "所有")
			{
				if (m_data->m_data[i].date>=m_startTime&&m_data->m_data[i].date<=m_stopTime)
				{
					showRowData(m_data->m_data[i]);
				}
			}
			else
			{
				if (m_data->m_data[i].type==m_cmb_value&&m_data->m_data[i].date>=m_startTime&&m_data->m_data[i].date<=m_stopTime)
				{
					showRowData(m_data->m_data[i]);
				}
			}
		}
		//if ( m_cmb_value == "所有")
		//{
		//	for (int i = 0; i < m_data->m_id; i++)
		//	{
		//		if (m_data->m_data[i].haveData)
		//		{
		//			if (m_data->m_data[i].date>=m_startTime&&m_data->m_data[i].date<=m_stopTime)
		//			{
		//				showRowData(m_data->m_data[i]);
		//				/*int nCount=m_list.GetItemCount();
		//				m_list.InsertItem(nCount,m_data->m_data[i].id);
		//				m_list.SetItemText(nCount,1,m_data->m_data[i].type);
		//				m_list.SetItemText(nCount,2,m_data->m_data[i].name);
		//				m_list.SetItemText(nCount,3,m_data->m_data[i].money);
		//				m_list.SetItemText(nCount,4,m_data->m_data[i].date);*/
		//			}
		//		}
		//	}
		//}
		//else
		//{
		//}
	}
}

void CPage2Dlg::showRowData(shop data)
{
	int nCount=m_list.GetItemCount();
	m_list.InsertItem(nCount,data.id);
	m_list.SetItemText(nCount,1,data.type);
	m_list.SetItemText(nCount,2,data.name);
	m_list.SetItemText(nCount,3,data.money);
	m_list.SetItemText(nCount,4,data.date);
}