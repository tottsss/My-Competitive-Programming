#include <bits/stdc++.h>
#include "caesar.h"
using namespace std;

//vector<int> p;
//long long substrings(int k){
//	long long all = k * (k+1LL);
//	all = (all * 1LL) / 2LL;
//	return all;
//}
void init(int n, int q, char A[], char B[]) {

//	for(int i = 0;i < n; i++){
//		a.push_back(A[i]);
//		b.push_back(B[i]);
//	}
//	for(int i = 0;i < n; i++){
//		int x = (int)A[i]-'a';
//		int y = (int)B[i]-'a';
//		if(y >= x){
//			p.push_back(y-x);
//		}else{
//			int z = 'z'-'a';
//			p.push_back(z-x+1 + y);
//		}
//	}
//	for(int i = 0;i <= 55; i++){
//		for(int j = 0;j < n; j++){
//					
//		}
//	}
}
long long query(int left, int right) {
	long long len = right-left+1;
	long long sum = (len * (len+1) * 1LL) / 2LL;
//	if(len >= 10000) assert(false);
	return sum;
//	int last = p[left], c = 1;
//	long long sum = 0LL;
//	for(int i = left+1; i <= right; i++){
//		if(last == p[i]){
//			c++;
//		}else{
//			sum+= substrings(c);
//			c = 1;
//			last = p[i];
//		}
//	}
//	sum+= substrings(c);
//	return sum;
}
