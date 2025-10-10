#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()


string s;
int n;
int Open[2], Close[2];
stack<char> st;
int check(){
	while(st.size()) st.pop();
	for(int i = 0;i < n; i++){
		if(s[i] == '('){
			st.push(s[i]);
		}else if(s[i] == '[') st.push(s[i]);
		else{
			if(s[i] == ']'){
				if(st.empty() or st.top() != '['){
					return 0;
				}
				st.pop();
			}else{
				if(st.empty() or st.top() != '('){
					return 0;
				}
				st.pop();
			}
		}
	}
	return (st.size() == 0);
}

void f(){
	if(s.size() == n){
		if(Open[0] != Close[0]) return;
		if(Open[1] != Close[1]) return;
		if(check()) cout << s << '\n';
		return;
	}
	if(Open[0] < n/2){
		s.push_back('(');
		Open[0]++;
		f();
		s.pop_back();
		Open[0]--;	
	}
	if(Open[1] < n / 2){
		s.push_back('[');
		Open[1]++;
		f();
		s.pop_back();
		Open[1]--;
	}
	if(Open[0] > Close[0]){
		s.push_back(')');
		Close[0]++;
		f();
		s.pop_back();
		Close[0]--;	
	}
	if(Open[1] > Close[1]){
		s.push_back(']');
		Close[1]++;
		f();
		s.pop_back();
		Close[1]--;	
	}
}



main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
	  cin >> n;
	  set<string> ans;
	  s = "";	
	f();
	return 0;
}

