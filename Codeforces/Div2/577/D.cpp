#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<set<int>> treasure(n);
  rep(i, k) {
    int r, c; cin >> r >> c;
    r--; c--;
    treasure[r].insert(c);
  }
  while(treasure.back().empty()) {
    treasure.pop_back();
    n--;
  }
  set<int> safe;
  rep(i, q) {
    int b; cin >> b;
    b--;
    safe.insert(b);
  }
  vector<pair<int, ll>> tmp;
  tmp.push_back({0, 0});
  rep(i, n) {
    if(treasure[i].empty()) {
      if(i == 0) {
        tmp.clear();
        tmp.push_back({*safe.begin(), *safe.begin()});
      }
      for(auto& ele: tmp) ele.second++;
      continue;
    }
    int first = *treasure[i].begin();
    int last = *treasure[i].rbegin();
    vector<int> nextPos;
    if(i == n-1) {
      nextPos.push_back(first);
      nextPos.push_back(last);
    } else {
      if(safe.upper_bound(first) != safe.begin()) nextPos.push_back(*(--safe.upper_bound(first)));
      if(safe.lower_bound(first) != safe.end()) nextPos.push_back(*safe.lower_bound(first));
      if(safe.upper_bound(last) != safe.begin()) nextPos.push_back(*(--safe.upper_bound(last)));
      if(safe.lower_bound(last) != safe.end()) nextPos.push_back(*safe.lower_bound(last));
    }
    sort(all(nextPos));
    nextPos.erase(unique(all(nextPos)), end(nextPos));
    vector<pair<int, ll>> next;
    for(auto p: nextPos) next.push_back({p, longinf});
    for(auto [from, cost]: tmp) {
      rep(j, next.size()) {
        int to = nextPos[j];
        chmin(next[j].second, cost + min({
              abs(from-first)+abs(first-last)+abs(to-last),
              abs(from-last)+abs(first-last)+abs(to-first)
            }));
      }
    }
    if(i != n-1) for(auto& ele: next) ele.second++;
    tmp = next;
  }
  ll ans = longinf;
  for(auto [_, cost]: tmp) chmin(ans, cost);
  cout << ans << endk;
  return 0;
}
