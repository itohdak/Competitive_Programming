#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  string s, t; cin >> s >> t;
  if(s.size() < t.size()) {
    cout << "NO" << endk;
    return;
  }
  vector<map<char, vector<int>>> mps(2);
  rep(i, s.size()) mps[i&1][s[i]].push_back(i);
  auto test = [&](int begin) -> bool {
    int pos = begin;
    rep(i, t.size()) {
      // cout << pos << endk;
      if(!mps[1-(pos&1)].count(t[i])) return false;
      auto next = lower_bound(all(mps[1-(pos&1)][t[i]]), pos+1);
      if(next == mps[1-(pos&1)][t[i]].end()) return false;
      pos = *next;
    }
    return true;
  };
  if(test(-1) || test(-2)) {
    cout << "YES" << endk;
  } else {
    cout << "NO" << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
