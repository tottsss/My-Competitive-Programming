#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int M = 1e9 + 7;
const int N = 1e6 + 1;

struct node{
	node *next[2] {};
	int leaf=0;
};
typedef node* pnode;
char type; 
int x, q;

int get_bit(int i){
	return (x&(1LL<<i) ? 1 : 0);
}
int get_inver(int i){
	return (x&(1LL<<i) ? 0 : 1);
}
void add(pnode &cur, int i){
	if(cur == nullptr) cur = new node();
	cur->leaf++;
	if(i == 0) return;
	add(cur->next[get_bit(i-1)], i-1);
}
void del(pnode &cur, int i){
	
	cur->leaf--;
	if(i == 0) return;
	del(cur->next[get_bit(i-1)], i-1);
}
int get_max(pnode cur){
	int sum = 0;
	for(int i = 30; i >= 0; i--){
		if(cur == nullptr){
			assert(false);
		}
		if(cur->next[get_inver(i)] != nullptr and cur->next[get_inver(i)]->leaf > 0){
			sum+= (1<<i);
			cur =cur->next[get_inver(i)];
		}else{
			cur = cur->next[get_bit(i)];
		}
	}
	return sum;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	pnode trie = new node();
	cin >> q;
	x = 0LL;
	add(trie->next[0], 30);
	while(q--){
		cin >> type >> x;
		if(type == '+'){
			add(trie->next[get_bit(30)],30);
		}else if(type == '-'){
			del(trie->next[get_bit(30)],30);
		}else{
			cout << get_max(trie) << '\n';
		}
	}	

	return 0;
}

