#include <stdio.h>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int INF = 0xffffff;
array<int,505> mem;
array<int,505> solution;
array<int,505> darts_sequence;
array<int,55> sections;
int num_min_darts = INF;



int calculate_min_dart_sequence(int points,int num_sections,int num_darts){
    if (mem[points] != -1) return mem[points];
    if (num_darts > num_min_darts) {
        mem[points] = num_darts;
        return num_darts;
    }
    if (points == 0){
        if (num_darts < num_min_darts){
            num_min_darts = num_darts;
            for (int i = 0; i < num_darts; i++)
            {
                solution[i] = darts_sequence[i];
            }
        }
        return num_darts;
    }
    
    int result = INF;
    int temp;
    for (int i = num_sections; i >= 0 ; i--)
    {
        if (sections[i] > points) continue;
        darts_sequence[num_darts] = sections[i];
        temp = calculate_min_dart_sequence(points-sections[i],i,num_darts+1);
        if (temp < result) result = temp;
    }
    mem[points] = result;
    return result;
    
}

int main(){
    int num_points;
    int num_sections;
    while (cin >> num_points)
    {
        num_min_darts = INF;
        mem.fill(-1);      
        cin >> num_sections;
        for (int i = 0; i < num_sections; i++)
        {
            cin >> sections[i];
        }
        calculate_min_dart_sequence(num_points,num_sections-1,0);
        if (mem[num_points] == INF){
            cout << "Imposible\n";
            continue;
        }
        cout << num_min_darts << ':';
        for (int i = 0; i < num_min_darts; i++)
        {   
            cout << ' ' << solution[i];
        }
        cout << '\n';
    }
    return 0;
}