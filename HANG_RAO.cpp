//
// Created by Macbook on 30/07/2024.
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

using ll = long long;

#define pdd pair<double, double>
#define mp make_pair

int n, d;
vector<pdd> a;
vector<pdd> up, down;
int area(pdd a, pdd b, pdd c)
{
    return a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);
}
void graham()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        a.push_back(mp(a[i].first + d, a[i].second));
        a.push_back(mp(a[i].first, a[i].second + d));
        a.push_back(mp(a[i].first - d, a[i].second));
        a.push_back(mp(a[i].first, a[i].second - d));
    }
    sort(a.begin(), a.end());
    int k = unique(a.begin(), a.end()) - a.begin();
    a.resize(k);
    pdd p1 = a[0], p2 = a[k - 1];
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i <= a.size() - 1; i++)
    {
        if (i == a.size() - 1 || area(p1, a[i], p2) < 0)
        {
            while (up.size() >= 2 && area(up[up.size() - 2], up[up.size() - 1], a[i]) >= 0)
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || area(p1, a[i], p2) > 0)
        {
            while (down.size() >= 2 && area(down[down.size() - 2], down[down.size() - 1], a[i]) <= 0)
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

}

void lengh()
{
    double res = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        res += sqrt((a[i].first - a[i + 1].first)*(a[i].first - a[i + 1].first) + (a[i].second - a[i + 1].second)*(a[i].second - a[i + 1].second));
    }
    cout << fixed << setprecision(10) << res;
}
int main()
{
    graham();
    lengh();
}