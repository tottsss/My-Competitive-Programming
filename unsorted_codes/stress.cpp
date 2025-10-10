#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

// to compile: g++ grader.cpp solution.cpp -o test.exe
string find_next(string str){
	vector<string> answer;
	map<int, char> mp;
	mp[0] = 'A', mp[1] = 'C', mp[2] = 'G', mp[3] = 'T';
	vector<char> a = {'A', 'A', 'A', 'A', 'C', 'C', 'C', 'C', 'G', 'G', 'G', 'G', 'T', 'T', 'T', 'T'};
	set<string> all;
	for(int mask = 0; mask < (1<<16); mask++){
		if(__builtin_popcount(mask) != 4) continue;
		string s = "";
		for(int i = 0;i < 16; i++){
			if(mask & (1<<i)){
				s.push_back(a[i]);
			}
		}
		string ss = s;
		do{
			pair<string, string> p = get_min_max(ss);
			if(!p.first.empty() and s >= str) all.insert(s);
		}while(next_permuation(ss.begin(), ss.end()));
		
	}
	if(all.empty()){
		return "";
	}
	return *all.begin();
}