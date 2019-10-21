#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

class Sales_data
{
private:
    string bookno;
    unsigned int unit_sold;
    double income;

public:
    Sales_data();
    ~Sales_data();
    bool Read( istream& is  ,Sales_data* pData);
    void Print(ostream &os, const vector<Sales_data> &pData_v);
    void  Logs(Sales_data *pRec, vector<Sales_data> &);
};
