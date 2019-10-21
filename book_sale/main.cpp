#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
 #include "Sales_data.cpp"

using namespace std;

int main(int argc, const char** argv) 
{
    Sales_data  data;
    ofstream out_file("logs.txt");
    vector<Sales_data> data_v;

    while (data.Read( cin, &data))
    {
        data.Logs(&data, data_v);
    }
    data.Print(out_file, data_v);
    return 0;
}