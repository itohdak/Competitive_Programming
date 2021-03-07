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
  int n; ll m; cin >> n >> m;
  vector<ll> A(n);
  vector<int> B(n);
  vector<vector<ll>> C(2);
  rep(i, n) cin >> A[i];
  rep(i, n) {
    cin >> B[i]; B[i]--;
    C[B[i]].push_back(A[i]);
    // cout << C[B[i]] << endl;
  }
  vector<vector<ll>> sum(2);
  rep(i, 2) {
    sort(all(C[i]), greater<ll>());
    int sz = C[i].size();
    sum[i] = vector<ll>(sz+1);
    rep(j, sz) sum[i][j+1] = sum[i][j] + C[i][j];
  }
  if(sum[0].back() + sum[1].back() < m) {
    cout << -1 << endk;
  } else {
    ll ans = longinf;
    rep(i, sum[0].size()) {
      int j = lower_bound(all(sum[1]), m-sum[0][i]) - begin(sum[1]);
      if(j == sum[1].size()) continue;
      chmin(ans, i+j*2);
    }
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
