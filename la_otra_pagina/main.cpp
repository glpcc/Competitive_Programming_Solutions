#include <iostream>

using namespace std;

int main(){
    int num;cin >> num;
    int num_pagina;
    
    for (int i = 0;i < num;i++){
        cin >> num_pagina;
        if (num_pagina%2 == 0){
            cout << num_pagina + 1 << endl;
        }else{
            cout << num_pagina - 1 << endl;
        }
    }
    return 0;
}