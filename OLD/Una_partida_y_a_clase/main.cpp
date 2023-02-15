#include <string>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numcases; cin >> numcases;
    for (int i = 0; i<numcases;i++){
        int play_time = 0;
        int current_hour = 8;
        int current_minute = 0;
        int game_time; cin >> game_time;
        int num_clases; cin >> num_clases;
        int time_diference;
        string current_time;
        for (int j = 0; j<num_clases; j++){
            cin >> current_time;    
            int class_hour = stoi(current_time.substr(0,2));
            int class_minute = stoi(current_time.substr(3));
            time_diference = (class_hour-current_hour)*60 + (class_minute-current_minute);
            play_time += time_diference*(time_diference>=game_time);
            int class_duration; cin >> class_duration;
            current_hour = class_hour + (class_minute + class_duration)/60;
            current_minute = (class_minute + class_duration)%60;
        }
        time_diference = (14-current_hour)*60 - current_minute;
        play_time += time_diference*(time_diference>=game_time);
        cout << play_time << '\n';
    }
}