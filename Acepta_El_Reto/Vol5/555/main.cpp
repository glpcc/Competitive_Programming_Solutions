#include <stdio.h>
#include <iostream>
#include <array> 
#include <set>
#include <vector>
#include <math.h>
using namespace std;


set<array<int,2>> non_searched_pos;
vector<array<int,2>> pos_vigilantes;

float  calculate_distance(array<int,2> &p1,array<int,2> &p2){
    return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2));
}

bool check_if_horizontal_cut(array<int,2> &p, int max_x){
    non_searched_pos.erase(p);
    if (p[0] >= max_x-10){ 
        return true;
    }
    bool posible = false;
    for (array<int,2> pos: pos_vigilantes){
        if (non_searched_pos.find(pos) == non_searched_pos.end()){
            continue;
        }
        if (calculate_distance(p,pos) <= 20){
            posible = check_if_horizontal_cut(pos,max_x);
        }
        if (posible){
            return true;
        }
    }
    return posible;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max_x; cin >> max_x;
    int max_y;
    int num_vig;
    while (max_x != 0)
    {
        cin >> max_y; cin >> num_vig;
        for (int i = 0; i < num_vig; i++)
        {
            array<int,2> vig_pos;
            cin >> vig_pos[0];cin >> vig_pos[1];
            pos_vigilantes.push_back(vig_pos);
            non_searched_pos.insert(vig_pos);
        }
        bool imposible = false;
        for (array<int,2> pos: pos_vigilantes){
            if (non_searched_pos.find(pos) != non_searched_pos.end() && pos[0] <= 10){ 
                imposible = check_if_horizontal_cut(pos,max_x);
            }
            if (imposible){
                break;
            }
        }
        if (imposible){
            cout << "NO\n";
        }else{
            cout << "SI\n";
        }
        cin >> max_x;
        pos_vigilantes.clear();
        non_searched_pos.clear();
    }
    return 0;
    
}