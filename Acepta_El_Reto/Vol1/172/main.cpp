#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_seats; cin >> num_seats;
    char option;
    bool d_appeared = false;
    bool i_appeared = false;
    bool done = false;
    while (num_seats != 0)
    {
        for (int i = 0; i < num_seats; i++)
        {
            cin >> option;
            //cout << option << ' ' << d_appeared << '\n';
            if (done) { continue;}
            if (option == 'D'){
                if (i_appeared){done = true; continue;}
                d_appeared = true;
            }else if (option == 'I'){
                if (d_appeared){done = true; continue;}
                i_appeared = true;
            }
        }
        cout << (done ? "ALGUNO NO COME\n" : "TODOS COMEN\n");
        d_appeared = false;
        i_appeared = false;
        done = false;
        cin >> num_seats;
    }
    
    return 0;
}