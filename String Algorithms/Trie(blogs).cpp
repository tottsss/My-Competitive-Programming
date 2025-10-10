/*Tries

Tries are some kind of rooted trees in which each edge has a character on it.
 Actually, trie is some kind of DFA (Determining Finite Automata). 
 For a bunch of strings, their trie is the smallest rooted tree with a character 
 on each edge and each of these strings can be build by writing down the 
 characters in the path from the root to some node.

It's advantage is, LCP (Longest Common Prefix) of two of these strings is the 
LCA (Lowest Common Ancestor) of their nodes in the trie(a node that we can build the 
string by writing down the characters in the path from the root to that node).

Generating the trie :

Root is vertex number 0 (C++)
*/
int x[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE], next = 1; //initially all numbers in x are -1
void build(string s){
	int i = 0, v = 0;
	while(i < s.size()){
		if(x[v][s[i]] == -1)
			v = x[v][s[i++]] = next ++;
		else
			v = x[v][s[i++]];
	}
}
//https://threadsiiithyderabad.quora.com/Tutorial-on-Trie-and-example-problems
//Problem : A lot of games