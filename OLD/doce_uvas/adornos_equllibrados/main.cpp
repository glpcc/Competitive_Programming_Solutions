#include <iostream>
#include <deque>
using namespace std;

int main(){
    int num_to_buy;
    int num_in_store;
    deque<int> last_items;
    int item;
    while (cin >> num_in_store >> num_to_buy)
    {
        last_items.clear();
        //cout << num_in_store << ' ' << num_to_buy << '\n';
        int result = 0;
        int max_weight = 0;
        int selected_weight = 0;
        int half_weight = 0;
        int last_sumed = 0;
        for (size_t i = 0; i < num_in_store; i++)
        {
            cin >> item;
            if (i >= num_to_buy){
                selected_weight -= last_items.front();
                half_weight -= last_items.front();
                last_items.pop_front();
                if (last_sumed > 0 && i >= num_to_buy){
                    last_sumed--;
                }
            }
            last_items.push_back(item);
            selected_weight += item;
            half_weight -= item;
            //cout << "item:" << item << '\n';
            //cout << half_weight << '\n';
            if (half_weight <= 0){
                while (half_weight < 0 && last_sumed < num_to_buy)
                {
                    //cout << "To sum: " << last_items[last_sumed]*2 << '\n';
                    half_weight += last_items[last_sumed]*2;
                    last_sumed++;
                }
                if (half_weight == 0){
                    if (selected_weight > max_weight && i+1 >= num_to_buy){
                        result = i - num_to_buy + 2;
                        max_weight = selected_weight;
                    }
                    half_weight += last_items[last_sumed]*2;
                    last_sumed++;
                }
            }
            //cout << half_weight << '\n';
            //cout << "Last Sumed:" << last_sumed << '\n';
        }
        if (result == 0){
            cout << "SIN ADORNOS\n";
        }else{
            cout << result << '\n';
        }
    }
    
    return 0;
}