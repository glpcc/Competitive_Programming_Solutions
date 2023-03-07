#include <iostream>
#include <cmath>

using namespace std;

float calculate_distance(int x, int y, int c_x, int c_y){
    return sqrt(pow(x-c_x,2) + pow(y-c_y,2));
}

float calculate_max_distance(int initial_rad){
    int total = initial_rad;
    int new_rad = initial_rad;
    while (new_rad >= 1)
    {
        new_rad = new_rad/2;
        total += new_rad;
    }
    return total;
}

int calculate_num_circ(int rad,int px,int py,int cx, int cy,int max_dist){
    float distance = calculate_distance(px,py,cx,cy);
    int num_circ = 0;
    int new_max_dist = max_dist - rad;
    if (rad >= distance){
        num_circ++;
    }
    if (rad <= 1){ return num_circ; }
    if (abs(px-cx) <= max_dist && abs(py-cy) <= new_max_dist){
        if (px-cx > 0){
            num_circ += calculate_num_circ(rad/2,px,py,cx+rad,cy,new_max_dist);
        }else{
            num_circ += calculate_num_circ(rad/2,px,py,cx-rad,cy,new_max_dist);
        }
    }
    if (abs(px-cx) <= new_max_dist && abs(py-cy) <= max_dist){
        if (py-cy > 0){
            num_circ += calculate_num_circ(rad/2,px,py,cx,cy+rad,new_max_dist);
        }else{
            num_circ += calculate_num_circ(rad/2,px,py,cx,cy-rad,new_max_dist);
        }
    }
    return num_circ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rad;
    int px;
    int py;
    while (cin >> rad)
    {
        cin >> px;
        cin >> py;
        cout << calculate_num_circ(rad,px,py,0,0,calculate_max_distance(rad)) << '\n';
    }
}
