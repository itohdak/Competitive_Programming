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
  string t; cin >> t;
  map<char, vector<int>> pos;
  rep(i, t.size()) {
    pos[t[i]].push_back(i);
  }
  vector<pair<char, vector<int>>> pos2;
  for(auto [c, p]: pos) pos2.push_back({c, p});
  sort(all(pos2), [&](pair<char, vector<int>>& p1, pair<char, vector<int>>& p2) {
    return p1.second.back() < p2.second.back();
  });
  string ord;
  for(auto [c, _]: pos2) {
    ord += c;
  }
  int nchar = pos2.size();
  vector<vector<pair<int, int>>> from_to(nchar);
  rep(i, nchar) {
    if(pos2[i].second.size() % (i+1)) {
      cout << -1 << endk;
      return;
    }
    int step = pos2[i].second.size() / (i+1);
    rep(j, i+1) {
      from_to[i].push_back({pos2[i].second[step*j], pos2[i].second[step*(j+1)-1]});
    }
  }
  int prev_end = -1;
  string s;
  string s_next, s_tmp;
  rep(i, nchar) {
    int from = inf, to = 0;
    for(int j=i; j<nchar; j++) {
      chmin(from, from_to[j][i].first);
      chmax(to, from_to[j][i].second);
    }
    if(prev_end >= from) {
      cout << -1 << endk;
      return;
    }
    s_tmp = t.substr(from, to-from+1);
    if(i == 0) {
      s = s_next = s_tmp;
    }
    if(s_tmp != s_next) {
      // cout << s_tmp << ' ' << s_next << endk;
      cout << -1 << endk;
      return;
    }
    s_next = "";
    for(auto c: s_tmp) {
      if(c != pos2[i].first) s_next += c;
    }
    prev_end = to;
  }
  int to = 0;
  rep(i, nchar) chmax(to, from_to[i][0].second);
  cout << s << ' ' << ord << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
