#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
char Scale[] = "CKF";
struct Temperature{
    double temp;
    char scale;
};
istream & operator >> (istream & in,Temperature & Temp);
istream & operator >> (istream & in,Temperature & Temp) {
    in >> Temp.temp;
    in >> Temp.scale;
}

void test_temperature_input()
{
    Temperature Temp;
    string inp = "10C";
    istringstream iss(inp);
    iss >> Temp;
    assert(Temp.temp==10);
    assert(Temp.scale=='C');
    string inp1 = "0K";
    istringstream iss1(inp1);
    iss1 >> Temp;
    assert (Temp.temp == 0);
    assert (Temp.scale =='K');
    string inp2 = "-400F";
    istringstream iss2 (inp2);
    iss2 >> Temp;
    assert (Temp.temp == -400);
    assert (Temp.scale == 'F');
}
 double convert (const Temperature & Temp,char scale_to)
 {
     double Kelvins;
     switch (Temperature.scale)
     {
     case 'K': {
           Kelvins = ((9.0/5)(-273)+32);
         break;
     }
     case 'K1'






     }
 }
int main()
{
        test_temperature_input();
}

