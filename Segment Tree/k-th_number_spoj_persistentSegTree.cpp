// taken the idea of self pointer to avoid handling null pointer from coach fegla
#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e6;
struct node{
    node* l,* r;
    int sz;
    node(){
      l = r = this;
      sz = 0;
    }
    static node* empty;

};
node nodes[MAX];
int nxt = 0;
node* node::empty = &nodes[0];
node* newNode(int sz = 0,node* l = node::empty,node* r = node::empty){
    nxt++;
    node *ret = &nodes[nxt];
    ret->sz = sz;
    ret->l = l;
    ret->r = r;
    return ret;
}
node* insert(node* prev,int val,int tl = -1e9,int tr = 1e9){
    if(val > tr || val < tl)return prev;
    if(tl == tr)return newNode(prev->sz+1);
    int mid = tl+(tr-tl)/2;
    node* l = insert(prev->l,val,tl,mid);
    node* r = insert(prev->r,val,mid+1,tr);
    return newNode(l->sz+r->sz,l,r);
}
int query(node* st,node* en,int k,int tl = -1e9,int tr = 1e9){
    if(tl == tr)return tl;
    int mid = tl+(tr-tl)/2;
    int lsz = en->l->sz - st->l->sz;
    if(k <= lsz)return query(st->l,en->l,k,tl,mid);
    else        return query(st->r,en->r,k-lsz,mid+1,tr);
}
const int N = 1e5+5;
node* roots[N];
int main(){
    roots[0] = newNode();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; ++i){
        int x;
        scanf("%d",&x);
        roots[i] = insert(roots[i-1],x);
    }
    for (int i = 0;i < m; ++i){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(roots[l-1],roots[r],k));
    }

    return 0;
}
