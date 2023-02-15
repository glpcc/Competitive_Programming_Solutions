#include <iostream>

using namespace std;


int main(){
    int a; cin >> a;
    int b; cin >> b;
    int n; cin >> n;
    int c;
    int modul;
    while (!(a==0 && b == 0 && n== 0)){
        c = b - a;
        modul = n%3;
        if (modul == 0){
            if ((n/3) % 2 == 0){
                cout << -(c-b) << "\n";
            }else{
                cout << c-b << "\n";
            }
        }else if (modul == 1){
            if ((n/3) % 2 == 0){
                cout << b << "\n";
            }else{
                cout << -b << "\n";
            }
        }else if (modul == 2){
            if ((n/3) % 2 == 0){
                cout << c << "\n";
            }else{
                cout << -c << "\n";
            }
        }
        cin >> a;
        cin >> b;
        cin >> n;
    }
    return 0;
}

