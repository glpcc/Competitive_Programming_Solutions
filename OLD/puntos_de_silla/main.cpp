#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_filas; cin >> num_filas;
    int num_columnas; cin >> num_columnas;
    vector<vector<int>> matriz;
    vector<int> min_filas;
    vector<int> max_filas;
    vector<int> max_cols;
    vector<int> min_cols;
    int temp;
    bool punto_de_silla;
    while (num_columnas != 0)
    {   
        punto_de_silla = false;
        matriz.clear();
        min_filas.clear();
        max_filas.clear();
        min_cols.clear();
        max_cols.clear();
        for (size_t i = 0; i < num_filas; i++)
        {
            vector<int> fila;
            for (size_t j = 0; j < num_columnas; j++)
            {
                cin >> temp;
                if (min_filas.size() < i+1){
                    min_filas.push_back(temp);
                    max_filas.push_back(temp);
                }else if (temp < min_filas[i])
                {
                    min_filas[i] = temp;
                }else if (temp > max_filas[i])
                {
                    max_filas[i] = temp;
                }
                if (max_cols.size() < j+1){
                    max_cols.push_back(temp);
                    min_cols.push_back(temp);
                }else if (temp > max_cols[j])
                {
                    max_cols[j] = temp;
                }else if (temp < min_cols[j])
                {
                    min_cols[j] = temp;
                }
                fila.push_back(temp);
            }
            matriz.push_back(fila);
        }
        for (size_t i = 0; i < num_filas; i++)
        {
            for (size_t j = 0; j < num_columnas; j++)
            {
                if ((matriz[i][j] >= max_filas[i] && matriz[i][j] <= min_cols[j]) || (matriz[i][j] <= min_filas[i] && matriz[i][j] >= max_cols[j])){
                    punto_de_silla = true;
                    break;
                }
            }
        }
        if (punto_de_silla){
            cout << "SI\n";
        }else{
            cout << "NO\n";
        }
        cin >> num_filas;
        cin >> num_columnas;
    }
    return 0;
}