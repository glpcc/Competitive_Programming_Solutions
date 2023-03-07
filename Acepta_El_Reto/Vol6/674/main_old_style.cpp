#include <iostream>
#include <cmath>
using namespace std;

long long int calculate_num_ceros(long long int n){
    long long int temp = n;
    long long int num_ceros = 0;
    while (temp >= 5){
        num_ceros += temp/5;
        temp /= 5;
    }
    return num_ceros;
}

int main(){
    int div_num; cin >> div_num;
    long long int num_desired_zeros; cin >> num_desired_zeros;
    bool founded;
    while (!(div_num == 0 && num_desired_zeros == 0))
    {
        if (num_desired_zeros==0){
            if (div_num == 5){
                cout << "NINGUNO\n";
            }else{
                cout << div_num << '\n';
            }
            cin >> div_num;
            cin >> num_desired_zeros;
            continue;
        }
        founded = false;
        long long int five_mult = num_desired_zeros;
        bool done = false;
        long long int temp = 1;
        long long int total_to_rest = 0;
        while (!done){
            temp = temp*5 + 1;
            //cout << total_to_rest << '\n';
            if (num_desired_zeros/temp < 1){
                done = true;
            }else{
                total_to_rest += num_desired_zeros/temp;
            }
        }
        five_mult -= total_to_rest;
        //cout << five_mult << '\n';
        for (size_t i = 0; i < 5; i++)  
        {
            if ((five_mult*5 + i) % div_num == 0 && !founded){
                cout << five_mult*5 + i << '\n';
                cout << calculate_num_ceros(five_mult*5 + i) << '\n';
                founded = true;
            } 
        }
        if (!founded){
            cout << "NINGUNO\n";
        }
        cin >> div_num;
        cin >> num_desired_zeros;
    }
    return 0;
    
}