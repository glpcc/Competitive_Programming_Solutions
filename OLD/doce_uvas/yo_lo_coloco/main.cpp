#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(){
    int num_cases; cin >> num_cases;
    string f1;
    string f2;
    string final_f1;
    string final_f2;
    getline(cin,f1);
    for (int i = 0;i< num_cases;i++){
        final_f1 = "";
        final_f2 = "";
        getline(cin,f1);
        getline(cin,f2);
        transform(f1.begin(), f1.end(), f1.begin(), ::tolower);
        transform(f2.begin(), f2.end(), f2.begin(), ::tolower);
        for (int i =0; i < f1.length();i++){
            if (isalpha(f1[i])){
                final_f1.push_back(f1[i]);
            }
        }
        for (int i =0; i < f2.length();i++){
            if (isalpha(f2[i])){
                final_f2.push_back(f2[i]);
            }
        }
        if (final_f1 == final_f2){
            cout << "SI\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}