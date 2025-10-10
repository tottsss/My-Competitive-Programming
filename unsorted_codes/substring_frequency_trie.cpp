#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()


struct node{
	node* next[26] {};
	int words = 0, prefix=0;	
};
typedef node* pnode;
pnode trie;
string word;
void add(pnode &cur, int i){
	cur->prefix++;
	if(i >= word.size()){
		cur->words++;
		return;
	}
	int k = word[i]-'a';
	if(cur->next[k] == nullptr){
		cur->next[k] = new node();
	}
	add(cur->next[k], i+1);
}

void del(pnode &cur, int i){
	cur->prefix--;
	if(i >= word.size()){
		cur->words--;
		return;
	}
	int k = word[i]-'a';
	if(cur->next[k] == nullptr){
		assert(false);
	}
	del(cur->next[k], i+1);
}

int find(pnode cur, int i){
	if(i >= word.size()){
		return 1;
	}
	int k = word[i]-'a';
	if(cur->next[k] == nullptr or cur->next[k]->prefix <= 0) return 0;
	find(cur->next[k], i+1);
}

int count_words(pnode cur, int i){
	if(i >= word.size()){
		return cur->words;
	}
	int k = word[i]-'a';
	if(cur->next[k] == nullptr or cur->next[k]->prefix <= 0) return 0;
	return count_words(cur->next[k], i+1);
}

int max_prefix(pnode cur){
	int i = 0;
	while(i < word.size()){
		int k = word[i]-'a';
		if(cur->next[k] == nullptr) return i;
		if(cur->next[k]->prefix <= 1) return i;
		cur = cur->next[k];
		i++;
	}
	return i;
}

main(){
   	ios::sync_with_stdio(0);
   	cin.tie(0); cout.tie(0);
   	trie = new node();
	int len; cin >> len;
	string s; cin >> s;
	vector<string> sub;
	int n = s.size();
	for(int i = 0;i + len-1 < n; i++){
		string sb = s.substr(i, len);
		sub.push_back(sb);
	}
	for(auto &e : sub){
		word = e;
		add(trie, 0);
	}
	int mx = 0;
	string answer = "";
	for(auto &e : sub){
		word = e;
		int cnt = count_words(trie, 0);
		if(cnt > mx){
			mx =cnt;
			answer = e; 
		}
	}
	cout << answer;
	return 0;
}

