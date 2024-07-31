//
// Created by Macbook on 13/07/2024.
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
#include <
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0;
    sort(a.begin(), a.end());
    // (i + 1) * ai
    // chon max
    int m = -1;
    for (int i = 0; i < n; i++)
    {
        m = max((n - i)*a[i], m);
    }


}