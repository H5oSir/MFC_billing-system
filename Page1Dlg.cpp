// Page1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST2_3.h"
#include "Page1Dlg.h"
#include "afxdialogex.h"
#include "ZP_TEST2_3Doc.h"
#include "resource.h" 

// CPage1Dlg 对话框

IMPLEMENT_DYNAMIC(CPage1Dlg, CDialogEx)

CPage1Dlg::CPage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1Dlg::IDD, pParent)
	, m_name(_T(""))
	, m_money(_T(""))
	, m_date(_T(""))
	, m_cmb_value(_T(""))
{
	
}

CPage1Dlg::~CPage1Dlg()
{
}

void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_COMBO1, m_cmb_type);
	DDX_Text(pDX, IDC_EDT_NAME, m_name);
	DDX_Text(pDX, IDC_EDT_MONEY, m_money);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDT_TIME, m_date);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_CBString(pDX, IDC_COMBO1, m_cmb_value);
}


BEGIN_MESSAGE_MAP(CPage1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UPDATE, &CPage1Dlg::OnBnClickedBtnUpdate)
	ON_BN_CLICKED(IDC_BTN_DELETE, &CPage1Dlg::OnBnClickedBtnDelete)
	ON_BN_CLICKED(IDC_BTN_ADD, &CPage1Dlg::OnBnClickedBtnAdd)
END_MESSAGE_MAP()


// CPage1Dlg 消息处理程序


void CPage1Dlg::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	shop data;
	/*CString strText;
	GetDlgItemText(IDC_EDT_NAME,strText);
	data.name=strText;
	GetDlgItemText(IDC_EDT_MONEY,strText);
	data.money=strText;*/
	data.name=m_name;
	data.date=m_date;
	data.money=m_money;
	data.type=m_cmb_value;
	//CString cstr;
	//GetDlgItemText(IDC_COMBO1,cstr);
	//data.type=cstr;
	
	CString mstr;
	mstr.Format(TEXT("%d"),m_data->m_id);
	data.id=mstr;
	
	//data.type="aaa";
	//data.date=m_date;
	data.haveData=TRUE;
	m_data->insertData(data);
	
	//更新list
	int nCount=m_list.GetItemCount();
	m_list.InsertItem(nCount,m_data->m_data[m_data->m_id-1].id);
	m_list.SetItemText(nCount,1,m_data->m_data[m_data->m_id-1].type);
	m_list.SetItemText(nCount,2,m_data->m_data[m_data->m_id-1].name);
	m_list.SetItemText(nCount,3,m_data->m_data[m_data->m_id-1].money);
	m_list.SetItemText(nCount,4,m_data->m_data[m_data->m_id-1].date);

	//更新树
	m_data->tongJi();
	showTree();




	/*
	for (int i =0;i< m_data->m_id;i++)
	{
		if (m_data->m_data[i].haveData)
		{
			int nCount=m_list.GetItemCount();
			m_list.InsertItem(nCount,m_data->m_data[i].id);
			m_list.SetItemText(nCount,1,m_data->m_data[i].type);
			m_list.SetItemText(nCount,2,m_data->m_data[i].name);
			m_list.SetItemText(nCount,3,m_data->m_data[i].money);
			
			m_list.InsertColumn(0,m_data->m_data[i].id,LVCFMT_CENTER,50);
			m_list.InsertColumn(1,m_data->m_data[i].type,LVCFMT_CENTER,50);
			m_list.InsertColumn(2,m_data->m_data[i].name,LVCFMT_CENTER,50);
			m_list.InsertColumn(3,m_data->m_data[i].money,LVCFMT_CENTER,50);
		}
	}*/




	/*GetDlgItemText(IDC_EDT_NAME,strText);
	data.name=strText;*/
	
	//CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST,TEXT("*.bmp|*.bmp||"),this);
	//if (dlg.DoModal()==IDOK)
	//{
	//	//HBITMAP phBmp = (HBITMAP)LoadImage(NULL,TEXT(".\\res\\1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//	HBITMAP phBmp = (HBITMAP)LoadImage(NULL,dlg.GetPathName(),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	//	m_pic.SetBitmap(phBmp);
	//}
	//CString strText("111");
	//strText=CString(m_name);
	//GetDlgItemText(IDC_EDT_NAME,strText);
	//m_cmb_type.AddString(strText);
	//m_cmb_type.SetCurSel(m_cmb_type.GetCount()-1);



	/*m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.InsertColumn(0,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(1,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(2,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(3,TEXT("序号"),LVCFMT_CENTER,50);*/
	
	
	//m_tree.EnsureVisible(hNewItem);
	//m_tree.SetItemText(hItem,TEXT("11111"));

	/*
	CString strName;
	GetDlgItemText(IDC_EDT_NAME,strName);
	CString strMoney;
	GetDlgItemText(IDC_EDT_MONEY,strMoney);
	//CString strName;
	//GetDlgItemText(IDC_EDT_NAME,strName);
	CString strDate;
	GetDlgItemText(IDC_EDT_NAME,strDate);
	shop mdata;
	mdata.name=strName;
	mdata.money=strMoney;
	mdata.date=strDate;
	mdata.type="12111";
	m_doc->insertData(mdata);*/
	
}


void CPage1Dlg::OnBnClickedBtnUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	/*HTREEITEM hItem = m_tree.GetSelectedItem();
	CString str;
	GetDlgItemText(IDC_EDT_NAME,str);
	m_tree.SetItemText(hItem,str);*/
	int nCount = m_list.GetItemCount();
	for (int i = nCount; i >= 0 ; i--)
	{
		if (m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			
			UpdateData(TRUE);
			shop data;
			CString mstr;
			mstr.Format(TEXT("%d"),m_data->m_id);
			CString str = m_list.GetItemText(i,0);
			data.id=str;
			data.type=m_cmb_value;
			data.name=m_name;
			data.money=m_money;
			data.date=m_date;
			data.haveData=TRUE;
			m_data->updateData(data,str[0]-'0');

			m_list.SetItemText(i,0,data.id);
			m_list.SetItemText(i,1,data.type);
			m_list.SetItemText(i,2,data.name);
			m_list.SetItemText(i,3,data.money);
			m_list.SetItemText(i,4,data.date);
		}
	}
	m_data->tongJi();
	showTree();

}

void CPage1Dlg::OnBnClickedBtnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	/*HTREEITEM hItem = m_tree.GetSelectedItem();
	HTREEITEM hParent = m_tree.GetParentItem(hItem);
	m_tree.DeleteItem(hItem);
	m_tree.SelectItem(hParent);*/
	int nCount = m_list.GetItemCount();
	for (int i = nCount; i >= 0 ; i--)
	{
		if (m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str = m_list.GetItemText(i,0);
			m_data->deleteData(str[0]-'0');
			m_list.DeleteItem(i);
		}
	}
	m_data->tongJi();
	showTree();

}

bool CPage1Dlg::showData(shop sData)
{
	return TRUE;
}

bool CPage1Dlg::showTree()
{
	m_tree.DeleteItem(TVI_ROOT);
	for (int i = 0; i < m_data->m_tongji.top; i++)
	{
		
		//插入根节点
		HTREEITEM hItem = TVI_ROOT;
		TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		ts.item.pszText=m_data->m_tongji.date[i].GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		HTREEITEM hNewItem = m_tree.InsertItem(&ts);//插入
		m_tree.SelectItem(hNewItem);
		ts.hParent=hNewItem;

		//总消费
		//TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		float allMoney=m_data->m_tongji.money_licai[i]+m_data->m_tongji.money_qita[i]+m_data->m_tongji.money_shiping[i]+m_data->m_tongji.money_shuma[i];
		CString str;
		str.Format(TEXT("总消费:%.2f"),allMoney);
		ts.item.pszText=str.GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		m_tree.InsertItem(&ts);//插入

		//TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		//CString str;
		str.Format(TEXT("食品:%.2f"),m_data->m_tongji.money_shiping[i]);
		ts.item.pszText=str.GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		m_tree.InsertItem(&ts);//插入

		//TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		//CString str;
		str.Format(TEXT("数码:%.2f"),m_data->m_tongji.money_shuma[i]);
		ts.item.pszText=str.GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		m_tree.InsertItem(&ts);//插入


		//TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		//CString str;
		str.Format(TEXT("理财:%.2f"),m_data->m_tongji.money_licai[i]);
		ts.item.pszText=str.GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		m_tree.InsertItem(&ts);//插入

		//TVINSERTSTRUCT ts={0};
		ts.hInsertAfter=TVI_LAST;
		//CString str;
		str.Format(TEXT("其它:%.2f"),m_data->m_tongji.money_qita[i]);
		ts.item.pszText=str.GetBuffer();//显示的文本内容
		ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
		m_tree.InsertItem(&ts);//插入
		
	}

	/*

	//CString treeData[60];
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem==NULL)
		hItem = TVI_ROOT;//没有选中则为根
	TVINSERTSTRUCT ts={0};
	ts.hParent=hItem;
	ts.hInsertAfter=TVI_LAST;//插到这一层最后
	CString str;
	GetDlgItemText(IDC_EDT_NAME,str);//
	ts.item.pszText=str.GetBuffer();//显示的文本内容
	ts.item.mask=TVIF_TEXT;//设置掩码，文本成员有效
	HTREEITEM hNewItem = m_tree.InsertItem(&ts);//插入
	m_tree.SelectItem(hNewItem);
	*/
	return TRUE;
}
bool CPage1Dlg::showList(shop sData)
{

	/*
	m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.InsertColumn(0,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(1,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(2,TEXT("序号"),LVCFMT_CENTER,50);
	m_list.InsertColumn(3,TEXT("序号"),LVCFMT_CENTER,50);*/
	return TRUE;

}

void CPage1Dlg::initData()
{
	CTime mTime=CTime::GetTickCount();
	CString mDate=mTime.Format("20%y/%m/%d");
	m_date=mDate;
	m_name="苹果";
	m_money="10";
	UpdateData(FALSE);
	//SetDlgItemText(IDC_EDT_TIME,mDate);

	m_list.ModifyStyle(LVS_TYPEMASK,LVS_REPORT);
	m_list.InsertColumn(0,TEXT("序号"),LVCFMT_CENTER,90);
	m_list.InsertColumn(1,TEXT("类型"),LVCFMT_CENTER,90);
	m_list.InsertColumn(2,TEXT("名称"),LVCFMT_CENTER,90);
	m_list.InsertColumn(3,TEXT("钱数"),LVCFMT_CENTER,90);
	m_list.InsertColumn(4,TEXT("时间"),LVCFMT_CENTER,90);

	m_cmb_type.InsertString(0,TEXT("食品"));
	m_cmb_type.InsertString(1,TEXT("数码"));
	m_cmb_type.InsertString(2,TEXT("理财"));
	m_cmb_type.InsertString(3,TEXT("其它"));
	m_cmb_type.SetCurSel(0);


	

	//m_page1.m_cmb_type.SetCurSel(m_page1.m_cmb_type.GetCount()-1);
}