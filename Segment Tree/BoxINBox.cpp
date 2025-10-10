#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int main(){
  int N;
  cin >> N;
  vector<int> h(N), w(N), d(N);
  for (int i = 0; i < N; i++){
    cin >> h[i] >> w[i] >> d[i];
  }
  map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < N; i++){
    mp[h[i]].push_back(make_pair(w[i], d[i]));
    mp[h[i]].push_back(make_pair(d[i], w[i]));
    mp[w[i]].push_back(make_pair(h[i], d[i]));
    mp[w[i]].push_back(make_pair(d[i], h[i]));
    mp[d[i]].push_back(make_pair(h[i], w[i]));
    mp[d[i]].push_back(make_pair(w[i], h[i]));
  }
  map<int, int> mp2;
  mp2[0] = INF;
  mp2[INF] = 0;
  bool ok = false;
  for (auto P : mp){
    int cnt = P.second.size();
    for (int i = 0; i < cnt; i++){
      int x = P.second[i].first;
      int y = P.second[i].second;
      auto itr = mp2.lower_bound(x);
      itr--;
      if ((*itr).second < y){
        ok = true;
      }
    }
    for (int i = 0; i < cnt; i++){
      int x = P.second[i].first;
      int y = P.second[i].second;
      if (mp2.count(x) == 0){
        auto itr = prev(mp2.lower_bound(x));
        int a = (*itr).second;
        mp2[x] = a;
      }
      while (true){
        auto itr = mp2.lower_bound(x);
        if ((*itr).second > y){
          mp2.erase(itr);
        } else {
          break;
        }
      }
      mp2[x] = y;
      auto itr = prev(mp2.lower_bound(x));
      if ((*itr).second <= y){
        mp2.erase(x);
      }
    }
  }
  if (ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}