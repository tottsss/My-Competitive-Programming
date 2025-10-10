/*
This is the code for bzoj4552
(http://www.lydsy.com:808/JudgeOnline/problem.php?id=4552)
The problem is maintaing a permutation of 1~n,
supporting range sorting (increasing or decreasing),
query the value of **one** position **after all sortings**.
This problem can also be solved offline by using binary
search and naive segment tree which is O(nlog^2n).
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define SZ 666666 //length of sequence
#define SG 9999999 //number of segment tree nodes
//merge-split seg begin
int ss[SG],sn=0,ch[SG][2],s[SG];
#define er(x) ss[++sn]=x //erase x for further usage
inline int alc_() //allocate a clean new node
{
    int x=ss[sn--];
    ch[x][0]=ch[x][1]=s[x]=0;
    return x;
}
#define alc alc_()
//make a seg with only node p
void build(int& x,int l,int r,int p)
{
    x=alc; s[x]=1;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) build(ch[x][0],l,m,p);
    else build(ch[x][1],m+1,r,p);
}
//merge seg t1&t2
int merge(int t1,int t2)
{
    if(t1&&t2);else return t1^t2;
    ch[t1][0]=merge(ch[t1][0],ch[t2][0]);
    ch[t1][1]=merge(ch[t1][1],ch[t2][1]);
    s[t1]+=s[t2]; er(t2); return t1;
}
//split t1 to t1&t2 so that s[t1]=k
void split(int t1,int&t2,int k)
{
    t2=alc;
    int ls=s[ch[t1][0]];
    if(k>ls) split(ch[t1][1],ch[t2][1],k-ls);
    else swap(ch[t1][1],ch[t2][1]);
    if(k<ls) split(ch[t1][0],ch[t2][0],k);
    s[t2]=s[t1]-k; s[t1]=k;
}
//query k-th
int ask(int x,int l,int r,int k)
{
    if(l==r) return l;
    int ls=s[ch[x][0]];
    int m=(l+r)>>1;
    if(k>ls) return ask(ch[x][1],m+1,r,k-ls);
    return ask(ch[x][0],l,m,k);
}
//seg end
bool typ[SZ]; //0 inc   1 dec
//i-th pos store a substr which l=i (if exists)
//rots[] stores the root, rs[] stores the right border
int rots[SZ],rs[SZ];
set<int> sol; //maintain the left borders of ordered substrs
int n,q,a[SZ];
//split x so that rs[x]=s
void sp(int x,int s)
{
    if(s>=rs[x]||s<x) return;
    if(!typ[x]) split(rots[x],rots[s+1],s-x+1);
    else
    {
        rots[s+1]=rots[x];
        split(rots[s+1],rots[x],rs[x]-s);
    }
    rs[s+1]=rs[x]; rs[x]=s;
    sol.insert(s+1); typ[s+1]=typ[x];
}
//merge adjacent substr a&b to a (typ[a] should be edited manually)
void mg(int a,int b)
{
    if(a==b) return;
    sol.erase(b);
    rots[a]=merge(rots[a],rots[b]);
    rs[a]=rs[b];
}
//query the value of k in substr begin with x
int qpos(int x,int k)
{
    k-=x-1;
    if(!typ[x]) return ask(rots[x],1,n,k);
    else return ask(rots[x],1,n,rs[x]-x+2-k);
}
int main()
{
    for(int i=SG-1;i>=1;i--) ss[++sn]=i; //initialize memory pool
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i); //original sequence
        build(rots[i],1,n,a[i]);
        sol.insert(i); rs[i]=i;
    }
    static int tmp[SZ],tn=0;
    while(q--)
    {
        int o,l,r;
        scanf("%d%d%d",&o,&l,&r);
        //sort range [l,r]
		//o: 0 inc  1 dec
        //split out l&r
        set<int>::iterator w=sol.upper_bound(l); sp(*(--w),l-1);
        w=sol.upper_bound(r); sp(*(--w),r);
        //get the range
        set<int>::iterator p1=sol.lower_bound(l),
        p2=sol.upper_bound(r); --p2;
        int tg=*p1;
        if(p1!=p2) //merge them
        {
        	for(set<int>::iterator i=++p1;;++i)
        	{tmp[++tn]=*i; if(i==p2) break;}
        	for(int i=1;i<=tn;i++) mg(tg,tmp[i]); tn=0;
        }
        typ[tg]=o;
    }
    int r; scanf("%d",&r); //query the r-th position of the sequence
    set<int>::iterator w=sol.upper_bound(r);
    int x=*(--w); printf("%d\n",qpos(x,r));
}
