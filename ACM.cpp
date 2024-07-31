//
// Created by Macbook on 25/07/2024.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <string>
#include <iomanip>
#include<sstream>
#include <queue>
#include<math.h>
#include<string.h>
#include <fstream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int m, n;
    cin >> m >> n;
    char bg[m][n];
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> bg[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bg[i][j] == 'C')
            {
                int ca = 0, cm = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if (bg[x][y] == 'M')
                        {
                            cm++;
                        }
                        else if (bg[x][y] == 'A')
                        {
                            ca++;
                        }
                    }
                }

                sum += ca * cm;
            }
        }
    }

    cout << sum << endl;
}
