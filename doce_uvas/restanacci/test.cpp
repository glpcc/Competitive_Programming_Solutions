#include <iostream>

using namespace std;


int main(){
    int a; cin >> a;
    int b; cin >> b;
    int n; cin >> n;
    int temp;
    while (!(a==0 && b == 0 && n== 0)){
        for (size_t i = 0; i < n; i++){
            temp = b - a;
            a = b;
            b = temp;
        }
        cout << a << "\n";
        cin >> a;
        cin >> b;
        cin >> n;
    }
    return 0;
}