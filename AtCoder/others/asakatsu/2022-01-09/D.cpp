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
  string ans;
  rep(i, s.size()) {
    string tmp = s;
    if(i+t.size() > s.size()) continue;
    bool ok = true;
    rep(j, t.size()) {
      if(s[i+j] != '?' && s[i+j] != t[j]) ok = false;
    }
    if(!ok) continue;
    rep(j, t.size()) {
      tmp[i+j] = t[j];
    }
    rep(j, s.size()) {
      if(tmp[j] == '?') tmp[j] = 'a';
    }
    if(ans == "") ans = tmp;
    else chmin(ans, tmp);
  }
  if(ans.size() > 0) cout << ans << endk;
  else cout << "UNRESTORABLE" << endk;
  return 0;
}
