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
  string s, t; cin >> s >> t;
  vector<pair<char, int>> v, u;
  for(char c: s) {
    if(v.empty()) {
      v.push_back({c, 1});
    } else if(v.back().first == c) {
      v.back().second++;
    } else {
      v.push_back({c, 1});
    }
  }
  for(char c: t) {
    if(u.empty()) {
      u.push_back({c, 1});
    } else if(u.back().first == c) {
      u.back().second++;
    } else {
      u.push_back({c, 1});
    }
  }
  if(v.size() != u.size()) {
    cout << "No" << endk;
  } else {
    bool ok = true;
    rep(i, v.size()) {
      if(v[i].first != u[i].first) {
        ok = false;
      } else if(v[i].second > u[i].second) {
        ok = false;
      } else if(v[i].second == 1 && u[i].second > 1) {
        ok = false;
      }
    }
    cout << (ok ? "Yes" : "No") << endk;
  }
  return 0;
}
