#include <stdio.h>
#include <iostream>
#include <map>
#include <math.h>
#include <string>

using namespace std;
char types[5] = {'D','A','M','I','C'};
map<char,string> abreviations = {
    {'D' ,"DESAYUNOS"},
    {'A', "COMIDAS"},
    {'M', "MERIENDAS"},
    {'I',"CENAS"},
    {'C',"COPAS"}
};
map<char,double> values;



void print_day(int num_presented,int num_a){
    double avrg = 0;
    double max = -1;
    char max_char;
    bool repeated_max = false;
    double min = INFINITY;
    char min_char;
    bool repeated_min = false;
    for (int i = 0; i < 5; i++)
    {
        if (values[types[i]] < min ){
            min = values[types[i]];
            min_char = types[i];
            repeated_min = false;
        }else if (values[types[i]] == min){
            repeated_min = true;
        }
        if (values[types[i]] > max ){
            max = values[types[i]];
            max_char = types[i];
            repeated_max = false;
        }else if (values[types[i]] == max){
            repeated_max = true;
        }
        if (values[types[i]] != 0){
            avrg += values[types[i]];
        }

    }
    cout << (repeated_max ? "EMPATE": abreviations[max_char]) << '#';
    cout << (repeated_min ? "EMPATE": abreviations[min_char]) << '#';
    cout << ((values['A']/num_a > avrg/num_presented) ? "SI\n" : "NO\n");
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 5; i++){ values[types[i]] = 0;}
    char type;
    int num_presented = 0;
    int num_a = 0;
    double gains;
    while (cin >> type >> gains){
        if (type == 'N'){
            print_day(num_presented,num_a);
            num_presented = 0;
            num_a = 0;
            for (int i = 0; i < 5; i++){ values[types[i]] = 0;}
        }else{
            num_presented++;
            values[type] += gains;
            if (type == 'A'){
                num_a++;
            }
        }
    }
    
    return 0;
}