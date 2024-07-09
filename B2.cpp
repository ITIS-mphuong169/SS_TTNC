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
#define fasting ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using ll = long long;
int n;

auto modetify_fw = [](int j)
{
 while(j <= n)
  {
  fw[j]++;
  j += j &(-j);
  }
};

auto modetify_calcfw = [&](int j)
{
 int rf = 0;
 while(j > 0) {
  rf += fw[j];
  j &= (j - 1);
 }
 return rf;
};
int main()
{	
 string s;
 int t, tm, r, m;
 int ans = 1;
 int m0;
 cin >> n;
 vector<int> a(n + 1), fw(n + 1, 0), v(n + 1, 0);
 m = n + 1;
 for (int i = 1; i < n; i++)
 {
 	t = v[i];
 	if (t <= m)
 	{
 		tm = calcfw(m - 1) - calcfw(t);
 		if (m == 1)
 			ans++;
 		else
 			ans += m - t - tm;
 		fw(t);
 		m = t;
		
	 }
	 else
	 {
	 	tm = calcfw(t - 1) - calcfw(m);
	 	if (m >= n || t == n)
	 		ans++;
	 	else
	 		ans += t - m - tm;
	 	fw(t);
	 	m = t;
	 }
 }
 cout << ans << endl;
}