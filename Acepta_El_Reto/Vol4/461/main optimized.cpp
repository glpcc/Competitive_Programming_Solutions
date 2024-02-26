#include <iostream>
#include<algorithm>

using namespace std;

struct base{
    int conquistan;
    int mueren;
};
static bool compare_bases(base b1,base b2){
    return b1.conquistan - b1.mueren > b2.conquistan - b2.mueren;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_bases; cin >> num_bases;
    base bases[1000];
    while ( num_bases != 0)
    {
        for (int i = 0; i < num_bases; i++)
        {
            int troops_to_conquer; cin >> troops_to_conquer;
            int troops_dead; cin >> troops_dead;
            int troops_to_leave; cin >> troops_to_leave;
            bases[i].conquistan = troops_to_conquer;
            bases[i].mueren = troops_dead + troops_to_leave;
        }
        sort(bases, bases + num_bases, compare_bases); 
        int min_troops = 0;
        int current_troops = 0;
        for (int j = 0; j < num_bases; j++){
            if (bases[j].conquistan > current_troops){
                min_troops += bases[j].conquistan - current_troops; 
                current_troops = bases[j].conquistan;
            }
            if (bases[j].mueren > current_troops){
                min_troops += bases[j].mueren - current_troops; 
                current_troops = 0;
            }else{
                current_troops -= bases[j].mueren;
            }
        }
        cout << min_troops << '\n';
        cin >> num_bases;
    }
    
    
    return 0;
}