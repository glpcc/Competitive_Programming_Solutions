#include <iostream>
#include <string>

using namespace std;

int main(){
    int num_cases; cin >> num_cases;
    string version;
    string temp;
    int num11;
    int num12;
    int num13;
    int num21;
    int num22;
    int num23;
    for (int i = 0;i< num_cases;i++){
        cin >> version;
        temp = version.substr(0,version.find('.'));
        num11 = stoi(temp);
        version = version.substr(version.find('.')+1,version.length());
        temp = version.substr(0,version.find('.'));
        num12 = stoi(temp);
        version = version.substr(version.find('.')+1,version.length());
        num13 = stoi(version);
        cin >> version;
        temp = version.substr(0,version.find('.'));
        num21 = stoi(temp);
        version = version.substr(version.find('.')+1,version.length());
        temp = version.substr(0,version.find('.'));
        num22 = stoi(temp);
        version = version.substr(version.find('.')+1,version.length());
        num23 = stoi(version);
        if (num11 == num21){
            if (num22 == num12){
                if (num13 == num23){
                    cout << "NO\n";
                }else if (num23 - num13 == 1){
                    cout << "SI\n";
                }else{
                    cout << "NO\n";
                }
            }else if (num22 - num12 == 1){
                if (num23 == 0){
                    cout << "SI\n";
                }else{
                    cout << "NO\n";
                }
            }else{
                cout << "NO\n";
            }
        }else if (num21 - num11 == 1){
            if (num22 == 0 && num23 == 0){
                cout << "SI\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}