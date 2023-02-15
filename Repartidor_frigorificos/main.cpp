#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y_max;cin >> y_max;
    int x_max;cin >> x_max;
    int num_frig;cin >> num_frig;
    int frigs_x_avg = 0;
    int frigs_y_avg = 0;
    int temp_y;
    int temp_x;
    while (num_frig != 0)
    {
        for (int i = 0; i < num_frig; i++)
        {
            cin >> temp_x;
            frigs_x_avg += temp_x;
            cin >> temp_y;
            frigs_y_avg += temp_y;
        }
        cout << floor((float) frigs_x_avg/ (float) num_frig) << ' ' << floor((float) frigs_y_avg/ (float) num_frig) << '\n';
        cin >> y_max;
        cin >> x_max;
        cin >> num_frig;
        frigs_x_avg = 0;
        frigs_y_avg = 0;
    }
    

    return 0;
}