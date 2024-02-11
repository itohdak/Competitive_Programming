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
  int n, m; cin >> n >> m;
  vector<string> S(n), T(m);
  rep(i, n) cin >> S[i];
  rep(i, m) cin >> T[i];
  set<string> st2(all(T));
  set<int> st;
  rep(i, n) st.insert(i);
  string ans;
  auto dfs = [&](auto dfs, string str, int rem_) -> void {
    if(st.empty()) {
      if(str.size() >= 3 && !st2.count(str)) {
        ans = str;
      }
      return;
    }
    set<int> st_org = st;
    for(int ne: st_org) {
      if(str == "") {
        st.erase(ne);
        dfs(dfs, S[ne], rem_);
        if(ans != "") return;
        st.insert(ne);
      } else {
        st.erase(ne);
        rep(i, rem_+1) {
          dfs(dfs, str+"_"+string(i, '_')+S[ne], rem_-i);
          if(ans != "") return;
        }
        st.insert(ne);
      }
    }
  };
  int rem = 16;
  rep(i, n) rem -= S[i].size();
  rem -= n-1;
  dfs(dfs, "", rem);
  if(ans == "") cout << -1 << endk;
  else cout << ans << endk;
  return 0;
}
