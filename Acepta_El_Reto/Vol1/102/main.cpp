#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int get_code(char first_letter){
    int left  = (first_letter < 'p')
            ? -((first_letter - 'a') + (123 - 'p'))
            : -(first_letter - 'p');
    int right = (first_letter > 'p')
            ? (('z' - first_letter) + ('p' - 96))
            : ('p' - first_letter);
    //cout << "Left: " << left << " Right: " << right <<endl;
    return (abs(left) <= abs(right)) ? left : right;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char first_char; 
    string line;
    unordered_set<char> vocales {'a','e','i','o','u','A','E','I','O','U'};
    while (getline(cin,line))
    {
        int num_vocales = 0;
        int cesar_code =get_code(tolower(line[0]));
        string decoded_string = "";
        //cout << "Cesar Code:" << cesar_code << endl;
        for (int i = 1; i < line.length(); i++)
        {
            int int_char = tolower(line[i]);
            char new_char = line[i];
            char decodified_char;

            if (isalpha(int_char)){
                int new_value = int_char + cesar_code;
                if (new_value < 97){
                    decodified_char = 123 - (97-new_value);
                }else if (new_value > 122){
                    decodified_char = 96 + (new_value - 122);
                }else{
                    decodified_char = new_value;
                }
            }else{
                decodified_char = new_char;
            }

            if (isupper(new_char)){
                decodified_char = toupper(decodified_char);
            }

            if (vocales.find(decodified_char) != vocales.end()){
                num_vocales += 1;
            }
            decoded_string.push_back(decodified_char);
        }

        if (decoded_string != "FIN"){
            //cout << "Decoded Str: " << decoded_string << endl;
            cout << num_vocales << endl;
            
        }else{
            break;
        }
        //
    }
    

    return 0;
}