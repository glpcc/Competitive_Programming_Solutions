#include <stdio.h>
#include <iostream>

using namespace std;

struct interval_node{
    long long int min;
    long long int max;
    bool breaked;
    interval_node *next_node;
    bool has_next_node;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_sobrinos;
    long long int temp;
    while (cin >> num_sobrinos)
    {
        interval_node base_node;
        cin >> base_node.min;
        base_node.max = 0;
        base_node.breaked = false;
        base_node.has_next_node = false;
        interval_node *selected_node = &base_node;
        bool possible = true;
        for (int i = 1; i < num_sobrinos; i++)
        {
            cin >> temp;
            // cout << "First" << selected_node -> min << " " << selected_node -> max << " " << selected_node -> breaked <<endl;
            if (possible){
                selected_node = &base_node;
                while (temp < selected_node -> min && selected_node -> has_next_node)
                {
                    //cout << "sele " << selected_node -> min << " " << selected_node -> max << " " << selected_node -> has_next_node <<endl;
                    selected_node = selected_node -> next_node;
                }
                //cout << selected_node -> min << " " << selected_node -> max << " " << selected_node -> breaked <<endl;
                if (temp < selected_node -> min){
                    if (!(selected_node ->breaked)){
                        selected_node -> min = temp;
                    }else{
                        selected_node -> next_node = new interval_node;
                        selected_node -> next_node -> min = temp;
                        selected_node -> next_node -> has_next_node = false;
                        selected_node -> next_node -> breaked = false;
                        selected_node -> has_next_node = true;
                    }
                }else{
                    if (!(selected_node ->breaked)){
                        //cout << "Ahora" << '\n';
                        selected_node ->breaked = true;
                        selected_node -> max = temp;
                        //cout << selected_node -> max << '\n';
                    }else{
                        if (temp < selected_node -> max){
                            possible = false;
                        }else{
                            selected_node -> max = temp;
                        }
                    }
                }
            }
            
        }
        

        if (possible){
            cout << "SIEMPRE PREMIO" << '\n';
        }else{
            cout << "ELEGIR OTRA" << '\n';
        }
    }
    
    return 0;
}