#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool check_intersection(array<int,2> ed1,array<int,2> ed2){
    return (ed2[1] > ed1[0] && ed2[1] <= ed1[1]) || (ed1[1] > ed2[0] && ed1[1] <= ed2[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n_edificios; cin >> n_edificios;
    vector<array<int,2>> edificios;
    while (n_edificios != 0)
    {
        for (int i = 0; i < n_edificios; i++)
        {
            array<int,2> coords;
            cin >> coords[0]; cin >> coords[1];
            edificios.push_back(coords);
        }
        sort(edificios.begin(),edificios.end(),[](array<int,2> ed1, array<int,2> ed2) { return ed1[1] < ed2[1];});
        int last_independent_indx = 0;
        int num_independent = 1;
        int i = 0;
        for (array<int,2> edif: edificios){
            bool independent = !check_intersection(edificios[last_independent_indx],edif);
            if (independent){
                last_independent_indx = i;
                num_independent++;
            }
            i++;
        }
        cout << num_independent << '\n';
        edificios.clear();
        cin >> n_edificios;
    }
    
    return 0;
}