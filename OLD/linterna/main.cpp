#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void add_element(vector<long long int> &vec,int size,long long el){
    if (size >= vec.size()){
        vec.push_back(el);
    }else{
        vec[size] = el;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_sobrinos;
    long long int temp;
    while (cin >> num_sobrinos)
    {
        vector<long long int> maximos,minimos;
        int num_intervalos = 0;
        long long int max = 0,min = -1,new_min = -1;
        bool posible = true;
        for (int i = 0; i < num_sobrinos; i++)
        {
            cin >> temp;
            if (!posible){
                continue;
            }
            // cout << "Min: " << min << " Max: " << max << " Temp: " << temp << " New Min: " << new_min;
            // cout << " Num Intervalos: " << num_intervalos << "\n";
            // cout << "Minimos: " << "\n";
            // for (int k = 0; k < minimos.size(); k++)
            // {
            //     cout << minimos[k] << " ";
            // }
            // cout << "\n" ;
            // cout << "Maximos: " << "\n";
            // for (int k = 0; k < maximos.size(); k++)
            // {
            //     cout << maximos[k] << " ";
            // }
            // cout << "\n" ;
            
            if (temp < min || min == -1){
                // cout << "Hay" << "\n";
                if (temp < new_min || new_min == -1){
                    new_min = temp;
                }else{
                    // Add interval if the new_min has been breaked and it is less than the actual min
                    num_intervalos++;
                    add_element(minimos,num_intervalos,new_min);
                    min = new_min;
                    add_element(maximos,num_intervalos,temp);
                    max = temp > max ? temp : max;
                    new_min = -1;
                }
                continue;
            }
            // If temp > min, the number of intervals cant be 0
            // Check if it is bigger than the first one
            if (temp > max){
                // cout << "Hey" << "\n";
                num_intervalos = 0;                   
                add_element(minimos,num_intervalos,new_min == -1 ? min : new_min);
                min = new_min == -1 ? min : new_min;
                add_element(maximos,num_intervalos,temp);
                num_intervalos++;
                max = temp;
                new_min = -1;
                continue;
            }
            // Detect the first max so that the next max is <temp or 0 if there isnt more
            int indx = 0;
            for (int j = 0; j < num_intervalos; j++)
            {
                if (j == num_intervalos-1){
                    indx = j;
                    break;
                }
                if (maximos[j+1] < temp){
                    indx = j;
                    break;
                }
            }
            // If the number is inside the interval
            if (temp > minimos[indx]){
                posible = false;
                continue;
            }
            // If the maximums must be updated by a new one
            // The indx cant be the last one because it would either be > last_min or wouldnt be here (it would be <min)
            num_intervalos = indx + 1;
            add_element(minimos,num_intervalos,new_min == -1 ? min : new_min);
            min = new_min == -1 ? min : new_min;
            add_element(maximos,num_intervalos,temp);
            num_intervalos++;
            new_min = -1;
            max = temp > max ? temp : max;
        }
        if (posible){
            cout << "SIEMPRE PREMIO" << "\n";
        }else{
            cout << "ELEGIR OTRA" << "\n";
        }
        maximos.clear();
        minimos.clear();
    }
    
    return 0;
}