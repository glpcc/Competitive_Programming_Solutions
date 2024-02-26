#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool mapa[100][100];
int filas;
int columnas;
int explore_position(int y, int x){
    int result = 0;
    if (y >= filas || y < 0 || x < 0 || x >= columnas){
        return 0;
    }
    if (mapa[y][x]){
        result += 1;
        mapa[y][x] = false;
    } else{
        return result;
    }
    result += explore_position(y+1,x) + explore_position(y-1,x) + explore_position(y,x+1) + explore_position(y,x-1);
    return result;
}
int main(){
    string linea;
    while (cin >> filas >> columnas)
    {
        char caracter;
        for (int i = 0; i < filas; i++){
            char caracter;
            cin.get(caracter);
            //cout << linea.size() << ' ' << columnas << endl;
            for (int j = 0; j < columnas;j++)
            {
                cin.get(caracter);
                mapa[i][j] = (caracter == '#');
            }
        }
        int max_patch_size = 0;
        for (int y = 0; y < filas;y++){
            for (int x = 0; x < columnas; x++){
                max_patch_size = max(max_patch_size,explore_position(y,x));
            }
        }
        cout << max_patch_size << '\n';
    }
    
    return 0;
}
