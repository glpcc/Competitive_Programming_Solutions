#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int m; cin >> m;
    long long int d; cin >> d;
    long long int n; cin >> n;
    while (n != 0)
    {
        cout << n/((m*d)/gcd(m,d)) << '\n';
        cin >> m;
        cin >> d;
        cin >> n;
    }
    
    return 0;
}