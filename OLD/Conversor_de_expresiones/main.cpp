#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

struct BinTreeNode{
    int depth;
    struct BinTreeNode* left_node;
    struct BinTreeNode* right_node;
};


int main(){
    std::string current_case; 
    while (std::cin >> current_case)
    {
        std::string result;
        std::vector<BinTreeNode> stack;
        for (int i = 0;i<current_case.length();i++){
            if (std::isdigit(current_case[i])){
            } else
            {}
        std::cout << result << std::endl;
        result = "";
        stack.clear();
    }
    return 0;
}