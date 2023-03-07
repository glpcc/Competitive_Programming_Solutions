#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
    int num_secs;
    int num_persons_left;
    bool still_claping;
};


int main(){
    int num_cases;cin >> num_cases;
    vector<Person> list_ordered_secs;
    vector<Person*> list_ordered_num_persons;
    Person temp_person;
    while (num_cases != 0)
    {
        //cout << num_cases << endl;
        for (int i = 0;i < num_cases;i++){
            cin >> temp_person.num_secs;
            cin >> temp_person.num_persons_left;
            temp_person.still_claping = true;
            list_ordered_secs.push_back(temp_person);
        }
        // Ordeno el vector por el numero de segundos.
        sort(list_ordered_secs.begin(),list_ordered_secs.end(),[](Person p1,Person p2){ return p1.num_secs < p2.num_secs; });
        // Creo el vector de punteros que ordenare por numero de personas;
        for (int i = 0;i < num_cases;i++){
            list_ordered_num_persons.push_back(&list_ordered_secs[i]);
        }
        // Ordeno el vector por el numero de personas.
        sort(list_ordered_num_persons.begin(),list_ordered_num_persons.end(),[](Person *p1,Person *p2){ return p1->num_persons_left > p2->num_persons_left; });

        // Calculo el numero de segundos
        int list_secs_indx = 0;
        int list_per_indx = 0;
        int sec = 0;
        int num_persons_left = num_cases;
        while (true)
        {
            while (!list_ordered_secs[list_secs_indx].still_claping){
                list_secs_indx++;
                if (list_secs_indx == num_cases){
                    list_secs_indx--;
                    break;
                }
            }
            if (list_secs_indx+1 == num_cases && !list_ordered_secs[list_secs_indx].still_claping){
                break;
            }
            sec = list_ordered_secs[list_secs_indx].num_secs;
            while (list_ordered_secs[list_secs_indx].num_secs <= sec){
                if (list_ordered_secs[list_secs_indx].still_claping){
                    list_ordered_secs[list_secs_indx].still_claping = false;
                    num_persons_left--;
                }
                list_secs_indx++;
                if (list_secs_indx == num_cases){
                    list_secs_indx--;
                    break;
                }
            }
            if (list_secs_indx+1 == num_cases && !list_ordered_secs[list_secs_indx].still_claping){
                break;
            }
            while (list_ordered_num_persons[list_per_indx] -> num_persons_left > num_persons_left){
                if (list_ordered_num_persons[list_per_indx] -> still_claping){
                    num_persons_left--;
                    list_ordered_num_persons[list_per_indx] -> still_claping = false;
                }
                list_per_indx++;
                if (list_per_indx == num_cases){
                    list_per_indx--;
                    break;
                }
            }
            if (list_per_indx+1 == num_cases && !list_ordered_num_persons[list_per_indx] -> still_claping){
                break;
            }
        }
        cout << sec << endl;
        cin >> num_cases;
        list_ordered_secs.clear();
        list_ordered_num_persons.clear();
    }
    
    return 0;
}