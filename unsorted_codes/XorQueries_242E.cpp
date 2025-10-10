#include <bits/stdc++.h>

using namespace std;

const int logn = 20, maxn = logn << logn;

int root[maxn], to[maxn][2], cnt[maxn];
int sz = 1, rt = 1;

void add(int x)
{
    int cur = root[rt] = sz++;
    memcpy(to[cur], to[root[rt - 1]], sizeof(to[cur]));
    cnt[cur] = cnt[root[rt - 1]];
    rt++;
    cnt[cur]++;
    for(int i = logn - 1; i >= 0; i--)
    {
        bool c = x & (1 << i);
        if(to[cur][c])
        {
            memcpy(to[sz], to[to[cur][c]], sizeof(to[sz]));
            cnt[sz] = cnt[to[cur][c]];
        }
        cur = to[cur][c] = sz++;
        cnt[cur]++;
    }
}

void remove(int k)
{
    rt -= k;
}

int xor_max(int l, int r, int x)
{
    int a = root[l], b = root[r];
    int y = 0;
    for(int i = logn - 1; i >= 0; i--)
    {
        bool c = !(x & (1 << i));
        if(cnt[to[a][c]] < cnt[to[b][c]])
        {
            y |= c << i;
            a = to[a][c];
            b = to[b][c];
        }
        else if(cnt[to[a][!c]] < cnt[to[b][!c]])
        {
            y |= (!c) << i;
            a = to[a][!c];
            b = to[b][!c];
        }
        else break;
    }
    return y;
}

int order(int l, int r, int x)
{
    int a = root[l], b = root[r];
    int ans = 0;
    for(int i = logn - 1; i >= 0; i--)
    {
        bool c = x & (1 << i);
        if(c) ans += cnt[to[b][0]] - cnt[to[a][0]];
        a = to[a][c];
        b = to[b][c];
    }
    ans += cnt[b] - cnt[a];
    return ans;
}

int kth_stat(int l, int r, int k)
{
    int a = root[l], b = root[r];
    int ans = 0;
    for(int i = logn - 1; i >= 0; i--)
    {
        if(k > cnt[to[b][0]] - cnt[to[a][0]])
        {
            k -= cnt[to[b][0]] - cnt[to[a][0]];
            ans |= 1 << i;
            a = to[a][1];
            b = to[b][1];
        }
        else
        {
            a = to[a][0];
            b = to[b][0];
        }
    }
    return ans;
}

 main()
 {
     //freopen("input.txt", "r", stdin);
     ios::sync_with_stdio(0);
     cin.tie(0);
     int m;
     cin >> m;
     while(m--)
     {
         int type;
         cin >> type;
         if(type == 0)
         {
             int x;
             cin >> x;
             add(x);
         }
         else if(type == 1)
         {
             int l, r, x;
             cin >> l >> r >> x;
             cout << xor_max(l - 1, r, x) << "\n";
         }
         else if(type == 2)
         {
             int k;
             cin >> k;
             remove(k);
         }
         else if(type == 3)
         {
             int l, r, x;
             cin >> l >> r >> x;
             cout << order(l - 1, r, x) << "\n";
         }
         else
         {
             int l, r, k;
             cin >> l >> r >> k;
             cout << kth_stat(l - 1, r, k) << "\n";
         }
     }
 }