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
  set<char> st; for(char c: s) st.insert(c);
  bool hasAsta = false;
  for(char c: t) if(c == '*') hasAsta = true;
  int q; cin >> q;
  while(q--) {
    string u; cin >> u;
    if(hasAsta) {
      int szAsta = u.size()-t.size()+1;
      if(szAsta < 0) {
        cout << "NO" << endk;
      } else {
        int pos = 0;
        bool ok = true;
        rep(i, t.size()) {
          if(t[i] == '*') {
            rep(_, szAsta) if(st.count(u[pos++])) ok = false;
          } else if(t[i] == '?') {
            if(!st.count(u[pos++])) ok = false;
          } else {
            if(t[i] != u[pos++]) ok = false;
          }
        }
        if(ok) cout << "YES" << endk;
        else cout << "NO" << endk;
      }
    } else {
      if(t.size() != u.size()) {
        cout << "NO" << endk;
      } else {
        bool ok = true;
        rep(i, t.size()) {
          if(t[i] == '?') {
            if(!st.count(u[i])) ok = false;
          } else {
            if(t[i] != u[i]) ok = false;
          }
        }
        if(ok) cout << "YES" << endk;
        else cout << "NO" << endk;
      }
    }
  }
  return 0;
}
