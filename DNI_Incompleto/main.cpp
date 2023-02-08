#include <stdio.h>
#include <iostream>
#include <cmath>
#include <map>



using namespace std;

map<char,int> char_mods = {
    {'T',0},
    {'R',1},
    {'W',2},
    {'A',3},
    {'G',4},
    {'M',5},
    {'Y',6},
    {'F',7},
    {'P',8},
    {'D',9},
    {'X',10},
    {'B',11},
    {'N',12},
    {'J',13},
    {'Z',14},
    {'S',15},
    {'Q',16},
    {'V',17},
    {'H',18},
    {'L',19},
    {'C',20},
    {'K',21},
    {'E',22}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pows_mods[9];
    for (int i = 0; i < 9; i++)
    {
        pows_mods[i] = ((int) pow(10,i))%23;
    }
    
    int num_dnis; cin >> num_dnis;
    for (int i = 0; i < num_dnis; i++){
        int dni = 0;
        int num_questions = 0;
        int questions_pos_mods[4]; 
        int vals[4] = {0,0,0,0};
        char digit;
        for (int j = 0; j < 8; j++)
        {
            cin >> digit;
            if (digit == '?'){
                questions_pos_mods[num_questions] = pows_mods[7-j];
                num_questions++;
                dni = dni*10;
            }else{
                dni += (int) (digit-'0');
                dni *= 10;
            }
        }
        cin >> digit; 
        int mod = char_mods[digit];
        dni = (dni/10)%23;
        int count = 0;
        while (vals[0] != 10)
        {
            int temp = dni;
            for (int k = 0; k < num_questions; k++)
            {
                temp += questions_pos_mods[k]*vals[k];
            }
            if (temp%23 == mod){
                count++;
            }
            vals[num_questions-1]++;
            for (int k = num_questions-1; k > 0; k--)
            {
                if (vals[k] == 10){
                    vals[k-1]++;
                    vals[k] = 0;
                }
            }
            
        }
        cout << count << '\n';            
    }

    
    return 0;
}