#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main(){
    int num_sticks; cin >> num_sticks;
    map<int,int> sticks;
    int stick_length;
    int four_groups;
    int two_groups;
    while (num_sticks != 0)
    {
        four_groups = 0;
        two_groups = 0;
        sticks.clear();
        for (size_t i = 0; i < num_sticks; i++)
        {
            cin >> stick_length;
            if (sticks.find(stick_length) != sticks.end()){
                sticks[stick_length] += 1;
            }else{
                sticks[stick_length] = 1;
            }
        }
        std::map<int, int>::iterator it = sticks.begin();
        while(it != sticks.end())
        {
            four_groups += it->second / 4 ;
            two_groups += (it->second % 4)/2;
            it++;
        }
        if (two_groups < four_groups){
            while (two_groups < four_groups){
                four_groups -= 1;
                two_groups += 2;
            }
            cout << four_groups << "\n";
        }else{
            cout << four_groups << "\n";
        }
        cin >> num_sticks;
    }
    
}