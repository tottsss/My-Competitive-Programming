#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(a) a.begin(), a.end()
const int N = 1e7;
const int K = 30;
struct node{
	int next[2];
	int leaf;
};
node trie[N];
int vertex=0;
int get_bit(int x, int i){
	if(x&(1<<i)) return 1;
	return 0;
}
int get_inver(int x, int i){
	return (get_bit(x, i)^1);
}
void add(int x){
	int cur = 0;
	for(int i = K;i >= 0; i--){
		if(trie[cur].next[get_bit(x, i)] != -1){
			cur = trie[cur].next[get_bit(x, i)];
			trie[cur].leaf++;
		}else{
			trie[cur].next[get_bit(x, i)] = ++vertex;
			cur = trie[cur].next[get_bit(x, i)];
			trie[cur].leaf = 1;
			trie[cur].next[0] = -1, trie[cur].next[1] = -1;
		}
	}
}
void del(int x){
	int cur = 0;  
	for(int i = K;i >= 0; i--){
		cur = trie[cur].next[get_bit(x, i)];
		trie[cur].leaf--;
	}
}
int get_max(int x){
	int cur = 0, sum = 0;
	for(int i = K; i >= 0; i--){
		if(trie[cur].next[get_inver(x, i)] != -1 and trie[trie[cur].next[get_inver(x, i)]].leaf > 0){
			cur = trie[cur].next[get_inver(x, i)];
			sum+= (1<<i);
		}else{
			cur = trie[cur].next[get_bit(x, i)];
		}
	}
	return sum;
}

// codeforces problem 706D
main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   	trie[0].next[0] = -1, trie[0].next[1] = -1;
   	trie[0].leaf = 0;
	int q; cin >> q;
	add(0);
	while(q--){
		char type; cin >> type;
		int x; cin >> x;
		if(type == '+'){
			add(x);
		}else if(type == '-'){
			del(x);
		}else{
			cout << get_max(x) << '\n';
		}
	}
	return 0;
}

