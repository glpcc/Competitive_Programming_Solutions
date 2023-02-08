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
                num_questions++;
                questions_pos_mods[j] = pows_mods[8-j];
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
            for (int i = 0; i < 4; i++)
            {
                temp += questions_pos_mods[i]*vals[i];
            }
            
            vals[3]++;
            for (int i = 3; i > 0; i--)
            {
                if (vals[i] == 10){
                    vals[i-1]++;
                    vals[i] = 0;
                }
            }
            
        }
                      
    }
    
    return 0;
}