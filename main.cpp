#include "temperature.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

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
int main()
{
    size_t number_count;
       cerr << "Enter number count: ";
       cin >> number_count;

               cerr << "Enter numbers: ";
       vector<Temperature> numbers(number_count);
        for (size_t i = 0; i < number_count; i++) {
                cin >> numbers[i];
           }

              size_t column_count;
      cerr << "Enter column count: ";
      cin >> column_count;

               double min = numbers[0];
    double max = numbers[0];
       for (double number : numbers) {
              if (number < min) {
            min = number;
        }
             if (number > max) {
                       max = number;
                    }
           }
            vector<size_t> counts(column_count);
       for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
               if (column == column_count) {
                      column--;
                 }
               counts[column]++;
           }

               const size_t screen_width = 80;
      const size_t axis_width = 4;
       const size_t chart_width = screen_width - axis_width;

                // Можно было бы считать в предыдущем цикле, но так более наглядно.
                size_t max_count = 0;
    for (size_t count : counts) {
               if (count > max_count) {
            max_count = count;
        }
            }const bool scaling_needed = max_count > chart_width;

                for (size_t count : counts) {
                if (count < 100) {
                       cout << ' ';
                   }
               if (count < 10) {
                      cout << ' ';
                   }
             cout << count << "|";

                64   +        size_t height = count;
              if (scaling_needed) {
                        // Point: код должен быть в первую очередь понятным.
                                const double scaling_factor = (double)chart_width / max_count;
                       height = (size_t)(count * scaling_factor);
                   }

                       for (size_t i = 0; i < height; i++) {
                        cout << '*';
                   }
                cout << '\n';   }

                return 0;

    test_temperature_input();
}

