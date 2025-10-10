// https://www.hackerearth.com/practice/data-structures/advanced-
data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/
//https://stackoverflow.com/questions/39787455/is-it-possible-to-query-number-of-distinct-integers-in-a-range-in-olg-n
https://www.quora.com/Is-there-any-way-to-solve-the-dquery-problem-on-SPOJ-using-persistent-segment-trees-an-online-solution
// a[i] <= 5000
// Q <= 1e5
// N <= 1e5

#include<bits/stdc++.h>
using namespace std;
bitset<5001> seg_a[400001],seg_b[400001],rst;
int a[100005],b[100005];
void built_a(int node,int start,int end){
	if(start==end){
		seg_a[node].set(a[start]);
		return;
	}
	int mid=(start+end)/2;
	built_a(2*node,start,mid);
	built_a(2*node+1,mid+1,end);
	seg_a[node]=(seg_a[2*node]|seg_a[2*node+1]);
}
void built_b(int node,int start,int end){
	if(start==end){
		seg_b[node].set(b[start]);
		return;
	}
	int mid=(start+end)/2;
	built_b(2*node,start,mid);
	built_b(2*node+1,mid+1,end);
	seg_b[node]=(seg_b[2*node]|seg_b[2*node+1]);
}
bitset<5001> query_a(int node,int start,int end,int L,int R){
	if(R<start||end<L)return rst;
	if(start>=L && end<=R)return seg_a[node];
	int mid=(start+end)/2;
	return query_a(2*node,start,mid,L,R)|query_a(2*node+1,mid+1,end,L,R);
}
bitset<5001> query_b(int node,int start,int end,int L,int R){
	if(R<start||end<L)return rst;
	if(start>=L && end<=R)return seg_b[node];
	int mid=(start+end)/2;
	return (query_b(2*node,start,mid,L,R)|query_b(2*node+1,mid+1,end,L,R));
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	
	built_a(1,0,n-1);
	built_b(1,0,n-1);
	
	cout<<seg_a[1].
	int q;cin>>q;
	int L1,R1,L2,R2;
	while(q--){
		cin>>L1>>R1>>L2>>R2;
		int ans=(query_a(1,0,n-1,L1-1,R1-1)|query_b(1,0,n-1,L2-1,R2-1)).count();
		cout<<ans<<"\n";
	}
	return 0;
}