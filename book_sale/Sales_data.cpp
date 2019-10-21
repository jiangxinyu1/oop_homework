#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace  std;

Sales_data::Sales_data()
{
    unit_sold = 0 ;
    income = 0;
}
Sales_data::~Sales_data()
{
    
}

/* 
    用户通过is对象输入书号，数量和价钱
    输入成功就返回0，并更新pData对象的值
    输入失败就返回0，并在终端打印
*/
bool Sales_data::Read(istream& is ,Sales_data* pData)
{
    double price = 0.0;
    is >> pData->bookno >> pData->unit_sold >> price;

    if( is )
    {
        if (pData->unit_sold == 0 || pData->unit_sold < 0)
        {
            cerr << "Report: Invalid inputing" << endl;
            return false;
        }
        if (price == 0 || price <0 )
        {
            cerr << "Report: Invalid inputing" << endl;
            return false;
        }
        
        pData->income = price * pData->unit_sold;
        return true;
    }
    else
    {
        cerr << "Report:  OVER! " << endl;
        return false;
    }
    

}
/* 
    把pData_v里面的容器元素输出
*/
void Sales_data::Print(ostream &os, const vector<Sales_data>  &pData_v)
{
    int tmp = 0;
    for( int i = 0; i<pData_v.size(); ++i)
    {
        tmp = tmp + pData_v[i].unit_sold;
        os << "bookno: " << pData_v[i].bookno << '\t'
             << "unit_sold: " << pData_v[i].unit_sold << '\t'
             << "income: " << pData_v[i].income << endl;
    }
    os << "total: " << tmp << endl;
    cout << pData_v.size() << endl;
}

/*  
    将单条记录保存到容器的函数
    如果储存区里有书号相同的对象，累加
    如果没有，就pushback
*/
void  Sales_data::Logs(Sales_data *pData, vector<Sales_data> &v_logs)
{
    static int tmp = 0;
    if (v_logs.size() == 0)
    {
        v_logs.push_back(*pData);
    }
    else
    {
        for (int i = 0; i < v_logs.size(); ++i)
        {
            if (v_logs[i].bookno == pData->bookno )
            {
                v_logs[i].income = v_logs[i].income + pData->income;
                v_logs[i].unit_sold = v_logs[i].unit_sold + pData->unit_sold;
                return ;
            }
        }
        v_logs.push_back(*pData);
    }
}