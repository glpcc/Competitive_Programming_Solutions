#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_freq[10] = {0,0,0,0,0,0,0,0,0,0};
    string line;
    while (getline(cin,line)){
        for (auto i: line){
            num_freq[i-'0'] += 1;
        }
        bool all_equal = true;
        int freq_to_compare = num_freq[0];
        for (int i = 0; i < 10; i++)
        {
            if (num_freq[i] != freq_to_compare){
                all_equal = false;
            }
            num_freq[i] = 0;
        }
        if (all_equal){
            cout << "subnormal\n";
        }else{
            cout << "no subnormal\n";
        }
        
    }
    
    
    return 0;
}