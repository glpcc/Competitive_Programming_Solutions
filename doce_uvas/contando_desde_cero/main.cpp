#include <iostream>

using namespace std;

int main(){
    int num_cases; cin >> num_cases;
    int year;
    for (int i = 0;i< num_cases;i++){
        cin >> year;
        if (year > 0){
            cout << year-1 << "\n";
        }else{
            cout << year << "\n";
        }
    }
    return 0;
}