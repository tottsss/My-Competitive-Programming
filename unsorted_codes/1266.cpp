#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


int answer;
void equality(vector< pair<char, char> > &A,  map<char, char> &mp){
	for(int i = 0;i < A.size(); i++){
		if(A[i].ff == A[i].ss) continue;
		if(mp.count(A[i].ff) == false){
			A[i].ff = A[i-1].ff;
			continue;
		}
		if(mp.count(A[i].ss) == false or mp[A[i].ss] == A[i].ss){
			answer++;
			mp.erase(A[i].ff);
			A[i].ff = A[i].ss;
			mp[A[i].ff] = A[i].ff;
		}
	}
}
int is_equal(vector< pair<char, char> > &A){
	for(auto x : A){
		if(x.ff != x.ss) return 0;
	}
	return 1;
}
void solve(){
	string a, b; cin >> a >> b;
	vector< pair<char, char> > A;
	int n = a.size();
	map<char, char> mp;
	if(a.size() != b.size()){
		cout << "-1";
		return;
	}
	for(int i = 0;i < n; i++){
		A.push_back({a[i], b[i]});
		if(mp.count(a[i]) == false or mp[a[i]] == b[i]){
			mp[a[i]] = b[i];
		}else{
			cout << "-1";
			return;
		}
	}
	sort(all(A));
	 answer = 0;
	 int RT = 50;
	 while(RT--){
	 	equality(A, mp);
	 	sort(all(A));
	 }
	 RT = 50;
	 while(RT--){
		equality(A, mp);
		sort(all(A));
		for(int i = 0;i < n; i++){
			if(A[i].ff == A[i].ss) continue;
			if(mp.count(A[i].ff) == false){
				A[i].ff = A[i-1].ff;
				continue;
			}
			char fd = '#';
			if(mp.count(A[i].ss)==false or mp[A[i].ss] == A[i].ss){
		 		fd = A[i].ff;
			}
			 for(char ch = 'A'; ch <= 'z'; ch++){
			 	if(fd != '#') break;
			 	if(!(ch >= 'A' and ch <= 'Z') && !(ch >= 'a' and ch <= 'z')){
			 		continue;
				 }
				 if(ch == A[i].ff){	
				 	continue;
				 }
				 if(mp.count(ch) == false or mp[ch] == A[i].ss){
				 	fd = ch;
				 	break;
				 }
			 }
			 if(fd == '#'){
			 	cout << -1;
			 	return;
			 }
			 if(fd == A[i].ff) continue;
			 answer++;
			 mp.erase(A[i].ff);
			 A[i].ff = fd;
			 mp[fd] = A[i].ss;
		}
		if(is_equal(A)){
			break;
		}
	}
	if(!is_equal(A)) answer = -1;
	cout << answer;
}


main(){
	int t; cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}

	return 0;
}

