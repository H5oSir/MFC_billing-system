#pragma once
#include<vector>
using namespace std;
typedef struct shop
{
	CString id;
	CString type;
	CString name;
	CString money;
	CString date;
	bool haveData;
}shop; 
typedef struct tongji
{
	int top;
	CString date[50];
	float money_shiping[50];
	float money_qita[50];
	float money_licai[50];
	float money_shuma[50];

	//float money_shiping[50];
}tj;
class CData
{
public:
	CData(void);
	~CData(void);
	bool insertData(shop iData);
	bool deleteData(int id);
	bool updateData(shop nData,int id);
	bool tongJi();
	bool initTongji();
	void initData();
	int m_id;
	tj m_tongji;
public:
	shop m_data[1000];
};

