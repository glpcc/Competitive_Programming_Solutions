#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
    string anelid;
    stringstream s;
    int num_stages; cin >> num_stages;
    int stage_size;
    while (num_stages != 0)
    {
        cin >> anelid;
        anelid.erase(anelid.length()-1,1);
        s.str("");
        s << anelid;
        for (int i = 0; i < num_stages; i++)
        {
            for (int j = 0; j < anelid.length(); j++)
            {
                s << ((anelid.at(j) == 'A') ? "N":"A");
            }
            anelid = s.str();
        }
        cout << anelid << "C\n";
        cin >> num_stages;
    }
    
    return 0;
}