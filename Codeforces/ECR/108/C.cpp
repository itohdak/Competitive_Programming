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
  vector<int> U(n);
  rep(i, n) {
    cin >> U[i];
    U[i]--;
  }
  vector<ll> S(n);
  vector<vector<ll>> A(n);
  rep(i, n) {
    cin >> S[i];
    A[U[i]].push_back(S[i]);
  }
  vector<vector<ll>> sum(n);
  rep(i, n) {
    sort(all(A[i]), greater<ll>());
    sum[i] = vector<ll>(A[i].size()+1);
    rep(j, A[i].size()) {
      sum[i][j+1] += sum[i][j] + A[i][j];
    }
  }
  // cout << sum << endk;
  vector<ll> ans(n+1);
  rep(i, n) {
    rep(j, A[i].size()+1) {
      if(j == 0) continue;
      ans[j] += sum[i][A[i].size()/j*j];
    }
  }
  rep(i, n+1) if(i) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
