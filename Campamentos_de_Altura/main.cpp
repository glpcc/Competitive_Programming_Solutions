#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

vector<int> alturas;
vector<int> costes;
map<int,int> function_memory;

int calculate_coste_total(int indx_altr, int max_jump){
    if (function_memory.find(indx_altr) != function_memory.end()){
        return function_memory[indx_altr];
    }
    if (indx_altr == alturas.size() - 1){
        return 0;
    }
    int num_posible_jumps = 0;
    int i = indx_altr;
    while (alturas[i+1] - alturas[indx_altr] <= max_jump){
        num_posible_jumps++;
        i++;
        if (i == alturas.size()-1){
            break;
        }
    }
    cout << num_posible_jumps << '\n';
    int result = -1;
    int temp_result;
    for (int i = 0; i < num_posible_jumps; i++)
    {
        //cout << calculate_coste_total(indx_altr+1+i,max_jump) << '\n';
        temp_result = costes[indx_altr+i+1]+calculate_coste_total(indx_altr+i+1,max_jump);
        if (temp_result < result || result == -1){
            result = temp_result;
        }
    }
    function_memory[indx_altr] = result;
    return result; 
}

int main(){
    int num_bases;
    int temp;
    int max_jump;
    while (cin >> num_bases)
    {
        for (int i = 0; i < num_bases; i++)
        {
            cin >> temp;
            alturas.push_back(temp);
        }
        for (int i = 0; i < num_bases; i++)
        {
            cin >> temp;
            costes.push_back(temp);
        }
        cin >> max_jump;
        cout << calculate_coste_total(0,max_jump) << '\n';
        alturas.clear();
        costes.clear();
        function_memory.clear();
    }
    
    return 0;
}