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
  int n; cin >> n;
  set<char> st;
  rep(i, 26) st.insert(char('a'+i));
  int ans = 0;
  vector<char> C(n);
  vector<string> S(n);
  rep(i, n) cin >> C[i] >> S[i];
  char selected = S[n-1][0];
  rep(i, n) {
    if(C[i] == '!') {
      if(st.size() == 1) {
        ans++;
        continue;
      }
      set<char> ne;
      for(char cc: S[i]) {
        if(st.count(cc)) ne.insert(cc);
      }
      st = ne;
    } else if(C[i] == '.') {
      for(char cc: S[i]) {
        if(st.count(cc)) st.erase(cc);
      }
    } else {
      if(st.size() == 1) {
        if(S[i][0] != selected) ans++;
      } else {
        if(S[i][0] != selected) st.erase(S[i][0]);
      }
    }
  }
  cout << ans << endk;
  return 0;
}
