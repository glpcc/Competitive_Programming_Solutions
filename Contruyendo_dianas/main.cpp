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
    //printf("Points: %d, num_sections: %d, num_darts: %d,prev_memory: %d,num_min_darts: %d, Dart_sequence:",points,num_sections,num_darts,mem[points],num_min_darts);
    if (mem[points] != -1) return mem[points];
    if (points == 0) return 0;
    if (num_darts > num_min_darts) {
        mem[points] = INF;
        return INF;
    }
    
    int result = INF;
    int temp;
    for (int i = num_sections; i >= 0 ; i--)
    {
        if (sections[i] > points) continue;
        darts_sequence[num_darts] = sections[i];
        temp = calculate_min_dart_sequence(points-sections[i],num_sections,num_darts+1);
        if (temp < result) {
            result = temp;
            if (num_darts+result+1 < num_min_darts){
                num_min_darts = num_darts+result+1;
            }
        }
    }
    //cout << points <<" " << result +1 << endl;
    mem[points] = result + 1;
    return result+1;
    
}

void print_series(int points, int num_sections, int min_darts){

    for (int i = num_sections; i >= 0; i--)
    {
        if (sections[i] > points) continue;
        if (sections[i] == points){
            cout << " " << sections[i];
            break;
        }
        if (mem[points-sections[i]] == min_darts-1){
            cout << " " << sections[i];
            print_series(points-sections[i],num_sections,min_darts-1);   
            break;
        }
    }
    return;
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
        if (mem[num_points] == INF || num_min_darts == INF){
            cout << "Imposible\n";
            continue;
        }
        cout << num_min_darts << ':';
        print_series(num_points,num_sections-1,num_min_darts);
        cout << '\n';
    }
    return 0;
}