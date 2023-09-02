#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> row_sums;
    vector<int> colum_sums;
    int diag_left;
    int diag_right;
    int corner_sum;
    int center_sum;
    int sidecenter_sum;
    int x;
    int y;
    unordered_set<int> numbers_appeared;
    while (n != 0)
    {
        row_sums.resize(n);
        colum_sums.resize(n);
        fill(row_sums.begin(),row_sums.end(),0);
        fill(colum_sums.begin(),colum_sums.end(),0);
        diag_left = 0;
        diag_right = 0;
        corner_sum = 0;
        center_sum = 0;
        sidecenter_sum = 0;
        bool all_numbers_apeared = true;

        for (int i = 0; i < n*n; i++)
        {
            int num; cin >> num;
            x = i%n;
            y = i/n;
            row_sums[y] += num;
            colum_sums[x] += num;
            // Sum the corners
            if ((x ==  0 || x ==  n-1) && (y == 0 || y == n-1)){
                corner_sum += num;
            }
            // Diag left
            if (x == y){
                diag_left += num;
            }
            // Diag right
            if (n-x-1 == y){
                diag_right += num;
            }
            // Sum the side centers
            if (n%2 == 0){
                if ((x ==  0 || x ==  n-1) && ( y == n/2 || y == n/2 - 1)){
                    sidecenter_sum += num;
                }
                if ((y ==  0 || y ==  n-1) && ( x == n/2 || x == n/2 - 1)){
                    sidecenter_sum += num;
                }
                if (( x == n/2 || x == n/2 - 1) && ( y == n/2 || y == n/2 - 1)){
                    center_sum += num;
                }
            }else{
                if ((x ==  0 || x ==  n-1) && ( y == n/2 )){
                    sidecenter_sum += num;
                }
                if ((y ==  0 || y ==  n-1) && ( x == n/2)){
                    sidecenter_sum += num;
                }
                if (( y == n/2 ) && ( x == n/2)){
                    center_sum += num;
                }
            }
            if (numbers_appeared.find(num) != numbers_appeared.end() || num > n*n || num < 1){
                all_numbers_apeared = false;
            }
            if (all_numbers_apeared){
                numbers_appeared.insert(num);
            }
        }
        // For squares side 2 
        if (n == 2){
            sidecenter_sum -= corner_sum;

        }
        int cm = row_sums[0];
        int cm2 = (4*cm)/n;
        if (n%2 == 0){
            sidecenter_sum = sidecenter_sum/2;
        }else{
            center_sum = 4*center_sum;
        }

        bool diab_square = true;
        for (int i = 0; i < n; i++)
        {
            if (cm != row_sums[i] || cm != colum_sums[i]){
                diab_square = false;
                break;
            }
        }
        if (cm != diag_left || cm != diag_right){
            diab_square = false;
        }
        if (diab_square && cm2 == center_sum && cm2 == sidecenter_sum && cm2 == corner_sum && all_numbers_apeared){
            cout << "ESOTERICO\n";
        }else if (diab_square){
            cout << "DIABOLICO\n";
        }else{
            cout << "NO\n";
        }
        //cout << diag_right << ' ' << diag_left << endl;
        cin >> n;
        numbers_appeared.clear();
    }
    

    return 0;
}