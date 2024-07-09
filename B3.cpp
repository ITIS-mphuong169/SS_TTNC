
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
#include<bits/stdc++.h>
#define fasting ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using ll = long long;

int main()
{
	string s;
	cin >> s;
	unoder_map<char, int> mp;
	for (char c : s)
	{
		mp[c]++;
	}
	if(mp.size() == 1)
	{
		cout << "First\n";
	}
	int tong = 0;
	for (auto  &pair : mp)
	{
		tong += pair.second - 1;
	}
	
	// m le va m > 1 => second
	if (tong % 2 == 0)
	{
		cout << "Second\n";
	}
	else
	{
		cout << "First\n";
	}
}