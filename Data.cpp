#include "stdafx.h"
#include "Data.h"


CData::CData(void)
{
	m_id=0;
}


CData::~CData(void)
{
}
bool CData::insertData(shop iData)
{
	
	m_data[m_id]=iData;
	m_data[m_id].haveData=TRUE;
	m_id++;
	return TRUE;
}
bool CData::deleteData(int id)
{
	m_data[id].haveData=FALSE;
	return TRUE;
}
bool CData::updateData(shop nData,int id)
{
	m_data[id]=nData;
	return TRUE;
}
bool CData::tongJi()
{
	initTongji();
	for (int i = 0; i < m_id; i++)
	{
		if (m_data[i].haveData)
		{
			bool flag=TRUE;
			for (int j = 0; j < m_tongji.top; j++)
			{
				if (m_data[i].date==m_tongji.date[j])
				{
					if (m_data[i].type=="其它")
					{
						
						m_tongji.money_qita[j]+=_ttol(m_data[i].money);
					}
					else if (m_data[i].type=="食品")
					{
						m_tongji.money_shiping[j]+=_ttol(m_data[i].money);
					}
					else if (m_data[i].type=="数码")
					{
						m_tongji.money_shuma[j]+=_ttol(m_data[i].money);
					}
					else if (m_data[i].type=="理财")
					{
						m_tongji.money_licai[j]+=_ttol(m_data[i].money);
					}
					flag=FALSE;
					break;
					
				}
			}
			if (flag)
			{
				m_tongji.date[m_tongji.top]=m_data[i].date;
				/*m_tongji.money_shuma[m_tongji.top]=0;
				m_tongji.money_qita[m_tongji.top]=0;
				m_tongji.money_licai[m_tongji.top]=0;
				m_tongji.money_shiping[m_tongji.top]=0;*/
				if (m_data[i].type=="其它")
				{
				
					m_tongji.money_qita[m_tongji.top]+=_ttol(m_data[i].money);
				}
				else if (m_data[i].type=="食品")
				{
					m_tongji.money_shiping[m_tongji.top]+=_ttol(m_data[i].money);
				}
				else if (m_data[i].type=="数码")
				{
						m_tongji.money_shuma[m_tongji.top]+=_ttol(m_data[i].money);
				}
				else if (m_data[i].type=="理财")
				{
					m_tongji.money_licai[m_tongji.top]+=_ttol(m_data[i].money);
				}
				m_tongji.top++;
			}
			
		}
	}
	return TRUE;
}
bool CData::initTongji()
{
	m_tongji.top=0;
	for (int i = 0; i < 50; i++)
	{
		m_tongji.money_licai[i]=0;
		m_tongji.money_qita[i]=0;
		m_tongji.money_shiping[i]=0;
		m_tongji.money_shuma[i]=0;
		m_tongji.date[i]="";
	}
	return TRUE;
}

void CData::initData()
{
	tongJi();
}