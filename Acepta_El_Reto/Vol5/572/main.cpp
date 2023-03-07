#include <stdio.h>
#include <string>
#include <iostream>

int main(){
    int num_cases; 
    std::cin >> num_cases;
    float temp;
    for (int i = 0;i < num_cases;i++){
        bool hacer_media = true;
        bool aparecion_nueve = false;
        for (int j = 0;j < 5;j++){
            std::cin >> temp;
            if (temp == 0. && !aparecion_nueve)
            {
                hacer_media = false;
            }
            else if (temp >= 9.0)
            {
                hacer_media = true;
                aparecion_nueve = true;
            }
        }
        if (hacer_media){
            std::cout << "MEDIA" << std::endl;
        }else{
            std::cout << "SUSPENSO DIRECTO" << std::endl;
        }
    }

    return 0;
}