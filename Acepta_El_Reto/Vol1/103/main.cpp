#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

float evaluar_polinomio(float x,int num_coef,int coef[20]){
    float y = 0;
    for (int i = 0; i <= num_coef; i++)
    {
        y += coef[i]* pow(x,num_coef-i);

    }
    return y;
    
}

double calcular_suma_rieman(int n, int num_coef, int coef[20]){
    double suma = 0;
    double n_inverso = 1./((float) n);
    for (int i = 0; i < n; i++)
    {   
        double y = evaluar_polinomio(i*n_inverso,num_coef,coef);
        suma += n_inverso*max(0.,min(y,1.));
    }
    return suma;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int coeficientes[20];
    int num_coeficientes; cin >> num_coeficientes;
    while (num_coeficientes != 20)
    {
        for (int i = 0; i <= num_coeficientes; i++)
        {
            cin >> coeficientes[i];
        }
        int num_rectangulos; cin >> num_rectangulos;
        double area_cain = calcular_suma_rieman(num_rectangulos,num_coeficientes,coeficientes);
        if (abs(area_cain - (1-area_cain)) <= 0.001){
            cout << "JUSTO\n";
        }else if( area_cain < 0.5){
            cout << "ABEL\n";
        }else{
            cout << "CAIN\n";
        }
        cin >> num_coeficientes;
    }

    return 0;
}
