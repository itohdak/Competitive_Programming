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
  int k, n, m; cin >> k >> n >> m;
  vector<int> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  int i = 0, j = 0;
  int ng = 0;
  vector<int> ans;
  while(i < n || j < m) {
    while(i < n && (A[i] == 0 || A[i] <= k)) {
      ng = 0;
      ans.push_back(A[i]);
      if(A[i] == 0) k++;
      i++;
    }
    ng++;
    while(j < m && (B[j] == 0 || B[j] <= k)) {
      ng = 0;
      ans.push_back(B[j]);
      if(B[j] == 0) k++;
      j++;
    }
    ng++;
    if(ng > 10) {
      cout << -1 << endk;
      return;
    }
  }
  assert(i == n && j == m);
  assert(ans.size() == n+m);
  rep(i, n+m) cout << ans[i] << ' ';
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
