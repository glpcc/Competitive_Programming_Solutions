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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        long long int up_bound = num_desired_zeros*5;
        long long int low_bound = 0;
        bool done = false;
        long long int temp;
        long long int num_ceros;
        if (calculate_num_ceros(up_bound) == num_desired_zeros){
            done = true;
            temp = up_bound;
        }
        while (!done || low_bound >= up_bound){
            temp = (up_bound+low_bound)/2;
            num_ceros = calculate_num_ceros(temp);
            if (num_ceros == num_desired_zeros){
                done = true;
            }else if (num_ceros > num_desired_zeros){
                up_bound = temp-1;
            }else{
                low_bound = temp+1;
            }
        }
        long long int final_num = temp - temp%5;
        //cout << five_mult << '\n';
        for (size_t i = 0; i < 5; i++)  
        {
            if ((final_num + i) % div_num == 0 && !founded){
                cout << final_num + i << '\n';
                //cout << final_num % 3<< '\n';
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