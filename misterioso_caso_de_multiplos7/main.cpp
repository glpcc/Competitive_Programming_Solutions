#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_cases; cin >> num_cases;
    for (int i = 0;i < num_cases; i++){
        int power;cin >> power;
        cout << power/3 << '\n';
    }
    return 0;
}