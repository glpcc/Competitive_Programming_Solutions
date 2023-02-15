#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;cin >> num;
    string nombre;
    for (int i = 0;i < num;i++){
        cin >> nombre;
        cin >> nombre;
        cout << "Hola, " << nombre << "." << endl;
    }
    return 0;
}