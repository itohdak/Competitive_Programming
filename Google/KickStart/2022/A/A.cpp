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

void solve() {
  string s, t; cin >> s >> t;
  map<char, vector<int>> pos;
  rep(i, t.size()) {
    pos[t[i]].push_back(i);
  }
  for(auto& [_, v]: pos) {
    v.push_back(t.size());
  }
  int p = -1;
  rep(i, s.size()) {
    if(p == t.size() || !pos.count(s[i])) {
      cout << "IMPOSSIBLE" << endk;
      return;
    }
    p = *lower_bound(all(pos[s[i]]), p+1);
  }
  if(p == t.size()) {
      cout << "IMPOSSIBLE" << endk;
  } else {
    cout << t.size()-s.size() << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}