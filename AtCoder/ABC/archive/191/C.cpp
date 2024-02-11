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
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  set<int> st;
  int ans = 0;
  rep(i, h) {
    set<int> st2;
    rep(j, w-1) {
      if(S[i][j] != S[i][j+1]) {
        if(!st.count(j)) ans++;
        st2.insert(j);
      }
    }
    st = st2;
  }
  st.clear();
  rep(j, w) {
    set<int> st2;
    rep(i, h-1) {
      if(S[i][j] != S[i+1][j]) {
        if(!st.count(i)) ans++;
        st2.insert(i);
      }
    }
    st = st2;
  }
  cout << ans << endk;
  return 0;
}
