#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int countOlivos(int x, int y, vector<string>& mat, int F, int C)
{
    int answer = 0;
    if (x >= 0 && x < F && y >= 0 && y < C)
    {
        if (mat[x][y] == '#')
        {
            mat[x][y] = '.';
            answer = 1 + countOlivos(x-1, y, mat, F, C) + countOlivos(x+1, y, mat, F, C) +
                        countOlivos(x, y-1, mat, F, C) + countOlivos(x, y+1, mat, F, C);
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int F, C;
    string line;
    while (cin >> F >> C)
    {
        vector<string> matriz(F);
        getline(cin, line);
        for (int i = 0; i < F; i++)
        {
            getline(cin, line);
            matriz[i] = line;
        }
        int maximo = 0;
        for (int i = 0; i < F; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (matriz[i][j] == '#')
                {
                    int num = countOlivos(i, j, matriz, F, C);
                    maximo = max(maximo, num);
                }
            }
        }
        cout << maximo << '\n';
    }
}