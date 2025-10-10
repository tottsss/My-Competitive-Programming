#include "bits/stdc++.h"

using namespace std;

string str[3];
string ans;
char get(string ttr) {
	if(ttr == "     |  |") return '1';
	if(ttr == " _  _||_ ") return '2';
	if(ttr == "   _|_ | ") return '+';
	if(ttr == " _  _| _|") return '3';
	if(ttr == " _ |_  _|") return '5';
	if(ttr == "   ___   ") return '-';
	if(ttr == " _ | ||_|") return '0';
	if(ttr == "   ------") return '=';
	if(ttr == "   |_|  |") return '4';
	if(ttr == " _ |_ |_|") return '6';
	if(ttr == " _   |  |") return '7';
	if(ttr == " _ |_||_|") return '8';
	return '9';
}

void make() {

	for(int i = 0; i < str[0].size()-2; i +=4) {
		string temp;
		temp += str[0][i];
		temp += str[0][i+1];
		temp += str[0][i+2];
		// cout << temp << "\n";
		// temp = "";
		temp += str[1][i];
		temp += str[1][i+1];
		temp += str[1][i+2];
		// cout << temp << "\n";
		// temp = "";
		temp += str[2][i];
		temp += str[2][i+1];
		temp += str[2][i+2];
		ans += get(temp);
		// cout << temp << "\n";
		// temp = "";
	}
	cout << ans;
}

signed main () {
	for(int i = 0; i < 3; i ++) getline(cin,str[i]);
	make();
	int simbol = 1;
	string cur="0";
	int res = 0;
	for(int i = 0; i < ans.size(); i ++) {
		if(ans[i]=='+'||ans[i]=='-') {
			res += simbol*stoi(cur);
			cur="0";
			if(ans[i]=='+')simbol=1;
			else simbol = -1;
			continue;
		}
		if(ans[i]=='=')continue;
		cur += ans[i];
	}
	if(cur.size()>0) {
	
			res += simbol*stoi(cur);}
			cout << res;
	return 0;
}