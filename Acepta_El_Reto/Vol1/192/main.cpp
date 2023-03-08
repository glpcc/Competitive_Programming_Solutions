#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> mem(20010,-1);

bool is_valid(int num){
    if (mem[num] != -1){ return mem[num];}
    if (num % 3 == 0){
        if (is_valid(num/3) == 1){
            mem[num] = 1;
            return 1;
        }
    }
    if (num > 5){
        if (is_valid(num-5) == 1){
            mem[num] = 1;
            return 1;
        }
    }
    mem[num] = 0;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mem[1] = 1;
    int num;cin >> num;
    int valid;
    while (num != 0)
    {
        valid = is_valid(num);
        if (valid == 1){
            cout << "SI\n";
        }else if (valid == 0){
            cout << "NO\n";
        }
        cin >> num;
    }
    
    return 0;
}