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
  string x; cin >> x;
  ll m; cin >> m;
  if(x.size() == 1) {
    cout << (x[0]-'0' <= m ? 1 : 0) << endk;
    return 0;
  }
  set<char> st;
  for(char c: x) st.insert(c);
  int mx = (*st.rbegin() - '0');
  reverse(all(x));
  auto test = [&](ll mid) {
    ll tmp = 0;
    ll pw = 1;
    rep(i, x.size()) {
      if(i) {
        if(LONG_LONG_MAX / pw < mid) return false;
        pw *= mid;
      }
      char c = x[i];
      if(LONG_LONG_MAX / pw < (c-'0')) return false;
      if(LONG_LONG_MAX - tmp < (c-'0') * pw) return false;
      tmp += (c-'0') * pw;
      if(tmp > m) return false;
    }
    return true;
  };
  auto bsearch = [&]() {
    ll ok = mx, ng = longinf;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch()-mx << endk;
  return 0;
}
