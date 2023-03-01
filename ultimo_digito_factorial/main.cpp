#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casos_de_prueba; cin >> casos_de_prueba;
    int numero;
    int ultimo_digito = 1;
    for (int i = 0; i < casos_de_prueba; i++)
    {
        cin >> numero;
        switch (numero)
        {
        case 4:
            ultimo_digito = 4;
            break;
        case 3:
            ultimo_digito = 6;
            break;
        case 2:
            ultimo_digito = 2;
            break;
        case 1:
            ultimo_digito = 1;
            break;
        case 0:
            ultimo_digito = 1;
            break;
        default:
            ultimo_digito = 0;
            break;
        }
        cout << ultimo_digito << '\n';
    }
    return 0;
}