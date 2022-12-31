#include <iostream>

using namespace std;

int main(){
    int num_cases; cin >> num_cases;
    int num_lanes;
    int min_height = -1;
    int max_bridge_height = 0;
    int temp;
    while (num_cases != 0)
    {
        for (size_t i = 0; i < num_cases; i++){
            max_bridge_height = 0;
            cin >> num_lanes;
            for (size_t j = 0; j < num_lanes; j++){
                cin >> temp;
                if (temp > max_bridge_height){
                    max_bridge_height = temp;
                }
            }
            if (min_height != -1 && min_height > max_bridge_height){
                min_height = max_bridge_height;
            }else if (min_height == -1)
            {
                min_height = max_bridge_height;
            }
        }
        cout << min_height << "\n";
        cin >> num_cases;
        min_height = -1;
    }
    return 0;
}