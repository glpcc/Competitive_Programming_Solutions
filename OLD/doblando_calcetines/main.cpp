#include <string>
#include <iostream>

int main(){
    std::string input; 
    std::cin >> input;
    bool hash_map[100] = {0};
    int sock_number;
    std::string temp;
    int num_socks;
    int lonely_socks;
    int max_lonely_socks;
    num_socks = std::stoi(input);
    while (num_socks)
    {
        lonely_socks = 0;
        max_lonely_socks = 0;
        for (int i = 0; i < num_socks;i++){
            std::cin >> temp;
            sock_number = std::stoi(temp) - 1;
            lonely_socks = lonely_socks - (2*hash_map[sock_number] - 1);
            hash_map[sock_number] = !hash_map[sock_number];
            if (lonely_socks>max_lonely_socks) {
                max_lonely_socks = lonely_socks;
            }
            // READEABLE CODE
            // if (hash_map[sock_number]){
            //     hash_map[sock_number] = false;
            //     lonely_socks--;
            // }else{
            //     hash_map[sock_number] = true;
            //     lonely_socks++;
            //     if (lonely_socks > max_lonely_socks){
            //         max_lonely_socks = lonely_socks;
            //     }
            // }
        }   
        std::fill(hash_map + 0,hash_map + 100,0);
        std::cout << max_lonely_socks << std::endl;
        std::cin >> input; 
        num_socks = std::stoi(input);
    };
    return 0;
}