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
    vector<int> frigs_x;
    vector<int> frigs_y;
    int temp_y;
    int temp_x;
    while (num_frig != 0)
    {
        for (int i = 0; i < num_frig; i++)
        {
            cin >> temp_x;
            frigs_x.push_back(temp_x);
            cin >> temp_y;
            frigs_y.push_back(temp_y);
        }
        sort(frigs_x.begin(),frigs_x.end());
        sort(frigs_y.begin(),frigs_y.end());
        cout << frigs_x[round((float) num_frig/2)-1] << ' ' << frigs_y[round((float) num_frig/2)-1] << '\n';
        cin >> y_max;
        cin >> x_max;
        cin >> num_frig;
        frigs_x.clear();
        frigs_y.clear();
    }
    

    return 0;
}