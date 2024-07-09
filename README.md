//
// Created by SAMSUNG on 7/9/2024.
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
#define fasting ios_base::sync_with_stdio(0);cin.tie(0) cout.tie(0);
using namespace std;

using ll = long long;

int main()
{
 int n;
 cin >> n;
 vector<int>p(n);
 for(int &i : p) cin >> i;
 int ans = 0, t = 0, last = 0;
 for (int i = 0; i < n; i++)
  {
  last += n - 2*p[i] + 1;
  if (last < t)
   {
   t = last;
   ans = i + 1;
   }
  }
 cout << ans << endl;


}
