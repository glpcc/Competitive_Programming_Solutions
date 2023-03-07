#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map<int,int> function_memory;

long long int calculate_num_possibilities(int peldanos_left, int (&tipos_salto)[10], int num_tipos_salto){
    if (function_memory.find(peldanos_left) != function_memory.end()){
        return function_memory[peldanos_left];
    }
    long long int result = 0;
    for (int i = num_tipos_salto-1; i >= 0; i--)
    {
        if (tipos_salto[i] == peldanos_left){
            result++;
        }else if (tipos_salto[i] < peldanos_left){
            result += calculate_num_possibilities(peldanos_left-tipos_salto[i],tipos_salto,num_tipos_salto);
        }
    }
    result = result%1000000007;
    function_memory[peldanos_left] = result;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_peldanos; cin >> num_peldanos;
    int num_tipos_salto;
    int tipos_salto[10];
    while (num_peldanos != 0)
    {
        cin >> num_tipos_salto;
        for (int i = 0; i < num_tipos_salto; i++)
        {
            cin >> tipos_salto[i];
        }
        cout << calculate_num_possibilities(num_peldanos,tipos_salto,num_tipos_salto)%1000000007 << '\n';
        function_memory.clear();
        cin >> num_peldanos;
    }
    
}