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
  int n, m; cin >> n >> m;
  vector<string> S(n);
  set<string> st;
  rep(i, n) {
    cin >> S[i];
    st.insert(S[i]);
  }
  set<string> done;
  string same;
  string ans;
  for(auto s: st) {
    if(done.count(s)) continue;
    string t = s;
    reverse(all(t));
    if(st.count(t)) {
      if(s == t) same = s;
      else {
        ans += s;
        done.insert(t);
      }
    }
    done.insert(s);
  }
  cout << ans.size() * 2 + same.size() << endk;
  cout << ans + same;
  reverse(all(ans));
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
