#include <stdio.h>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool compare_bases(vector<int> b1,vector<int> b2){
    return b1[0] - b1[1] > b2[0] - b2[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_bases; cin >> num_bases;
    vector<vector<int>> bases;
    while ( num_bases != 0)
    {
        for (int i = 0; i < num_bases; i++)
        {
            vector<int> base;
            int troops_to_conquer; cin >> troops_to_conquer;
            int troops_dead; cin >> troops_dead;
            int troops_to_leave; cin >> troops_to_leave;
            base.push_back(troops_to_conquer);
            base.push_back(troops_dead + troops_to_leave);
            bases.push_back(base);
        }
        sort(bases.begin(), bases.end(), compare_bases); 
        int min_troops = 0;
        int current_troops = 0;
        for (auto i: bases){
            if (i[0] > current_troops){
                min_troops += i[0] - current_troops; 
                current_troops = i[0];
            }
            if (i[1] > current_troops){
                min_troops += i[1] - current_troops; 
                current_troops = 0;
            }else{
                current_troops -= i[1];
            }
        }
        cout << min_troops << endl;
        cin >> num_bases;
        bases.clear();
    }
    
    
    return 0;
}