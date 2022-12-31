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
        // cout << div_num << " " << num_desired_zeros << "\n";
        if (num_desired_zeros%5 == 0 && num_desired_zeros != 0){
            cout << "NINGUNO\n";
            cin >> div_num;
            cin >> num_desired_zeros;
            continue;
        }
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
        while (!done){
            temp = temp*5 + 1;
            if (num_desired_zeros/temp < 1){
                done = true;
            }else{
                five_mult -= num_desired_zeros/temp;
            }
        }
        
        for (size_t i = 0; i < 1000; i++)  
        {
            if ((five_mult*5 + i) % div_num == 0 && !founded){
                cout << five_mult*5 + i << '\n';
                founded = true;
            } 
        }
        if (!founded){
            cout << "NINGUNO\n";
        }
        cin >> div_num;
        cin >> num_desired_zeros;
    }
    //cout << calculate_num_ceros(72) << '\n';
    return 0;
    
}