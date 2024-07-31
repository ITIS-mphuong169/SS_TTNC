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

int main()
{
    int n, hx = 0, hm = (int)1e9 + 1;
    cin >> n;
    long long sum = 0, ans = 0, t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t > hx)
            hx = t;
        sum += t;
        if (t < hm )
            hm = t;
    }
    if (n == 2 && hm != hx || ((sum&1) && ((n&1) == 0)))
    {
        cout << -1;
    }
    if (n > 2)
    {
        t = (sum - 2*hm + n - 3)/(n- 2);
        if(t < hx)
            t = hx;
        if((t *n - sum) &1)
            t++;
        ans = (t* n - sum)>>1;
    }
    cout << ans;
}