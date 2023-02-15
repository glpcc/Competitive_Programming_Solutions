#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

struct operation_element
{
    int value;
    bool original;
};


int main(){
    std::string current_case; 
    while (std::cin >> current_case)
    {
        std::string result;
        std::vector<operation_element> stack;
        for (int i = 0;i<current_case.length();i++){
            if (std::isdigit(current_case[i])){
                operation_element new_element;
                new_element.value = current_case[i] - '0';
                new_element.original = true;
                stack.push_back(new_element);
            } else
            {
                operation_element e1 = stack[stack.size()-1];
                stack.pop_back();
                operation_element e2 = stack[stack.size()-1];
                stack.pop_back();
                if (e1.original){
                    result.append(std::to_string(e1.value));
                }
                if (e2.original){
                    result.append(std::to_string(e2.value));
                }
                operation_element new_element;
                switch (current_case[i])
                {
                case '+':
                    result.append("+");
                    new_element.value = e1.value + e2.value;
                    break;
                case '-':
                    result.append("-");
                    new_element.value = e1.value - e2.value;
                    break;
                case '/':
                    result.append("/");
                    if (e2.value == 0){
                        new_element.value = 1;
                    }else{
                        new_element.value = e1.value / e2.value;
                    }
                    break;
                case '*':
                    result.append("*");
                    new_element.value = e1.value * e2.value;
                    break;
                case '%':
                    result.append("%");
                    if (e2.value == 0){
                        new_element.value = 1;
                    }else{
                        new_element.value = e1.value % e2.value;
                    }
                    break;
                }
                new_element.original = false;
                stack.push_back(new_element);
            }
        }
        if (stack.size() != 0){
            operation_element last_element = stack[stack.size()-1];
            if (last_element.original){
                result.append(std::to_string(last_element.value));
            }
            stack.pop_back();
        }
        std::cout << result << std::endl;
        result = "";
        stack.clear();
    }
    return 0;
}