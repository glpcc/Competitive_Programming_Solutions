#include <iostream>
#include <string>

using namespace std;

int main(){
    int digits[10] = {0};
    string year;cin >> year;
    int grapes[10];
    int num_persons;
    int temp;
    while (year != "0")
    {
        for (size_t i = 0; i < 10; i++)
        {
            digits[i] = 0;
        }
        num_persons = -1;
        for (size_t i = 0; i < 4; i++)
        {
            digits[year[i] - '0'] += 1;
        }
        for (size_t i = 0; i < 10; i++)
        {
            cin >> grapes[i];
        }
        for (size_t i = 0; i < 10; i++)
        {
            if (digits[i] > 0){
                temp = grapes[i]/(3*digits[i]);
                if (num_persons != -1){
                    if (temp < num_persons){
                        num_persons = temp;
                    }
                }else{
                    num_persons = temp;
                }

            }
        }
        cin >> year;
        cout << num_persons << '\n';
    }
    
    return 0;
}