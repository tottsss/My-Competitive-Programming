#include <stdio.h>
#include <iostream>
#include <algorithm> 
using namespace std;

// Test generation section:
const int maxn=(1e5)+10;
int n,q,m,a[maxn];
unsigned long long seed; 
int INF;

struct node 
{
	int op,x,y;
} Q[maxn*50];

unsigned long long gen_num() 
{
	seed^=seed<<17;
	seed^=seed>>3;
	seed^=seed<<11;
	return seed;
}

void ReadAndGenerateData()
{
	int i,id,x;
	cin >> n >> q >> m >> seed >> INF;
	for (i=1;i<=n;i++) 
		cin >> a[i];
	for (i=1;i<=q;i++) 
	{
		Q[i].op=1;
		Q[i].x=gen_num()%n+1;
		Q[i].y=gen_num()%INF+1;
	}
	for (i=1;i<=m;i++) 
	{
		cin >> id >> x;
		Q[id].op=2;
		Q[id].x=x;
	}
}
// End of Test generation section.

const int block=555;
int b[maxn],c[maxn];

int main() 
{
	// https://official.contest.yandex.ru/contest/50291/problems/2/
	ReadAndGenerateData();
	for (int I=1;I<=q;I++) 
	{
		int op=Q[I].op,x=Q[I].x,y=Q[I].y;
//		cout << op << ' ' << x << ' ' << y << '\n';
		if (op==1) 
		{
			b[x/block]=max(b[x/block],y);
			c[x]=max(c[x],y);
		} 
		else 
		{
			int ans=a[x];
			for (int i=x/block + 1;i<=n/block;i++)
				ans=max(ans,b[i]);
			for (int i=x;i<(x/block+1)*block;i++)
				ans=max(ans,c[i]);
			cout << ans << endl;
		}
	}
	return 0;
}
