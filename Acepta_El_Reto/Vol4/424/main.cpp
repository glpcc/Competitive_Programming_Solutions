#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_c; cin >> num_c;
    int tot_max = 0, tot = 0, temp;
    bool setted_max = false;
    while (num_c != 0)
    {   
        for (int  i = 0; i < num_c; i++)
        {
            cin >> temp;
            tot += temp;
            if (!setted_max){
                setted_max = true;
                tot_max = tot;
            }else{
                if (tot > tot_max){
                    tot_max = tot;
                }
            }
        }
        cout << tot << ' ' << tot_max << '\n';
        setted_max = false;
        tot = 0;
        cin >> num_c;
    }
    
    return 0;
}