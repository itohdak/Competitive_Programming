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
  string s; cin >> s;
  ll k; cin >> k;
  int a = 0, b = 0;
  set<pair<int, int>> st;
  st.insert({a, b});
  for(char c: s) {
    if(c == 'U') b--;
    else if(c == 'D') b++;
    else if(c == 'R') a++;
    else a--;
    st.insert({a, b});
  }
  if(a == 0 && b == 0) {
    cout << st.size() << endk;
    return 0;
  }
  if(a == 0) {
    set<pair<int, int>> st2;
    for(auto [x, y]: st) st2.insert({y, x});
    st = st2;
    swap(a, b);
  }
  if(a < 0) {
    set<pair<int, int>> st2;
    for(auto [x, y]: st) st2.insert({-x, y});
    st = st2;
    a = -a;
  }
  map<pair<int, int>, set<pair<int, int>>> mp;
  vector<int> next(st.size(), inf);
  for(auto [x, y]: st) {
    int p = x/a;
    int x_ = x-p*a, y_ = y-p*b;
    if(x_ < 0) {
      x_ += a;
      y_ += b;
    }
    mp[{x_, y_}].insert({x, y});
  }
  ll ans = 0;
  for(auto [_, st]: mp) {
    bool first = true;
    int xprev = 0;
    for(auto [x, y]: st) {
      if(!first) {
        ans += min(k, (ll)(x-xprev)/a);
      } else {
        first = false;
      }
      xprev = x;
    }
    ans += k;
  }
  cout << ans << endk;
  return 0;
}
