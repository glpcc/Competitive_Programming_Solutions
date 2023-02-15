#include <iostream>

using namespace std;

int main(){
    int num_cases; cin >> num_cases;
    for (int i= 0; i< num_cases;i++){
        int num_hours; cin >> num_hours;
        int num_onoff; cin >> num_onoff;
        int num_hours_per_onoff; cin >> num_hours_per_onoff;
        int hours_on = num_onoff*num_hours_per_onoff;
        if (hours_on > num_hours){
            cout << "HORAS\n";
        }else if (hours_on == num_hours){
            cout << "AMBAS\n";
        }else{
            cout << "ENCENDIDOS\n";
        }
    }
    return 0;
}