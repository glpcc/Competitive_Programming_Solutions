#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;



int calculate_steps(int sep_num[4],int num_steps){
    if (num_steps == 8) return num_steps;

    int temp1 = 0;
    int temp2 = 0 ;
    sort(sep_num,sep_num+4);
    for (int i = 0; i < 4; i++)
    {
        temp2 *= 10;
        temp2 += sep_num[i];
    }
    sort(sep_num,sep_num+4,greater<int>());
    for (int i = 0; i < 4; i++)
    {
        temp1 *= 10;
        temp1 += sep_num[i];
    }
    int result[4];
    int num_result = temp1-temp2;
    if (num_result == 6174) return num_steps+1;
    for (int i = 0; i < 4; i++)
    {
        result[i] = num_result % 10;
        num_result /= 10;
    }
    return calculate_steps(result,num_steps + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_cases; cin >> num_cases;
    int num1;
    int sep_num[4];
    for (int i = 0; i < num_cases; i++)
    {
        cin >> num1;
        if (num1 == 6174) {
            cout << "0\n"; 
            continue;
        }
        
        for (int i = 0; i < 4; i++)
        {
            sep_num[i] = num1 % 10;
            num1 = num1 /10;
        }
        cout << calculate_steps(sep_num,0) << '\n';
    }
    
    return 0;
}