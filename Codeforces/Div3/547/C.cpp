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
  int n; cin >> n;
  vector<int> Q(n-1); rep(i, n-1) cin >> Q[i];
  vector<int> sum(n); rep(i, n-1) sum[i+1] = sum[i] + Q[i];
  int mn = *min_element(all(sum));
  rep(i, n) sum[i] += abs(mn)+1;
  set<int> st; rep(i, n) st.insert(i+1);
  rep(i, n) st.erase(sum[i]);
  if(st.empty()) {
    rep(i, n) cout << sum[i] << ' ';
    cout << endk;
  } else {
    cout << -1 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
