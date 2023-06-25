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
  vector<int> B(n);
  int root = -1;
  rep(i, n) {
    cin >> B[i];
    B[i]--;
    if(B[i] == i) root = i;
  }
  vector<int> P(n);
  vector<int> dist(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    dist[P[i]] = i;
  }
  vector<int> ans(n);
  rep(i, n) {
    ans[i] = dist[i]-dist[B[i]];
    if(i != root && ans[i] <= 0) {
      cout << -1 << endk;
      return;
    }
  }
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
