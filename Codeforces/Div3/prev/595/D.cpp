#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, K;
  cin >> N >> K;
  multiset<pair<int, int> > S; // (end, SegIdx)
  vector<pair<int, int> > Seg(N); // (begin, end)
  vector<pair<int, pair<int, int> > > mp; // (x, (begin/end, SegIdx))
  rep(i, N) {
    cin >> Seg[i].first >> Seg[i].second;
    mp.push_back(make_pair(Seg[i].first, make_pair(1, i)));
    mp.push_back(make_pair(Seg[i].second+1, make_pair(-1, i)));
  }
  sort(all(mp));
  vector<int> ans;
  rep(i, mp.size()) {
    auto m = mp[i];
    int x = m.first;
    while(mp[i].first == x) {
      int flag = mp[i].second.first;
      int idx = mp[i].second.second;
      if(flag == 1) {
        S.insert(make_pair(Seg[idx].second, idx));
      } else {
        if(S.count(make_pair(Seg[idx].second, idx)))
          S.erase(make_pair(Seg[idx].second, idx));
      }
      i++;
    }
    i--;
    while(S.size() > K) {
      auto itr = S.end();
      itr--;
      ans.push_back(itr->second);
      S.erase(itr);
    }
  }
  sort(all(ans));
  cout << ans.size() << endl;
  for(int a: ans) cout << a+1 << ' ';
  cout << endl;
  return 0;
}

