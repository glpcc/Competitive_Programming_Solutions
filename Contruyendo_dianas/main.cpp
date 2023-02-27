#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> calculated_points;

vector<int> calculate_min_darts(int points_left,vector<int> darts_list, const vector<int> &sectores,int min_darts, int max_sector_indx){
    if (darts_list.size() >= min_darts && min_darts != -1){
        calculated_points.insert(points_left);
        return darts_list;
    }
    vector<int> solution = {};
    vector<int> posible_solution = {};
    if (calculated_points.find(points_left) != calculated_points.end()){
        return solution;
    }
    // cout << "Call: " << points_left << " Min_D: " <<min_darts << endl;
    // cout << "Darts List: ";
    // for (int i = 0; i < darts_list.size(); i++)
    // {
    //     cout << darts_list[i] << ' ';
    // }
    // cout << endl;
    for (int i = max_sector_indx; i >= 0; i--)
    {
        if (sectores[i] > points_left){
            continue;
        }else if (sectores[i] == points_left){
            darts_list.push_back(sectores[i]);
            return darts_list;
        }
        darts_list.push_back(sectores[i]);
        posible_solution = calculate_min_darts(points_left-sectores[i],darts_list,sectores,min_darts,i);
        darts_list.pop_back();
        if (posible_solution.size() != 0 && (posible_solution.size() < min_darts || min_darts == -1) ){
            min_darts = posible_solution.size();
            solution = posible_solution;
        }
    }
    calculated_points.insert(points_left);
    return solution;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_puntos;
    int num_sectores;
    vector<int> sectores;
    vector<int> solution;
    while (cin >> num_puntos)
    {
        cin >> num_sectores;
        for (int i = 0; i < num_sectores; i++)
        {
            int temp; cin >> temp;
            sectores.push_back(temp);
        }
        solution = calculate_min_darts(num_puntos,solution,sectores,-1,sectores.size()-1);
        if (solution.size() == 0){
            cout << "Imposible\n"; 
        }else{
            cout << solution.size() << ": " ;
            for (int i = 0; i < solution.size()-1; i++)
            {
                cout << solution[i] << " ";
            }
            cout << solution[solution.size()-1] << '\n';
        }
        solution.clear();
        sectores.clear();
        calculated_points.clear();
    }
    return 0;
}



