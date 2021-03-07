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
  vector<int> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  vector<vector<int>> G(n), R(n);
  rep(i, n) {
    if(i+1 < n && A[i+1] == A[i]) {
      G[i].push_back(i+1);
      R[i+1].push_back(i);
    } else {
      for(int j=2; A[i]*j<=A.back(); j++) {
        int k = lower_bound(all(A), A[i]*j) - begin(A);
        if(k != n && A[k] == A[i]*j) {
          G[i].push_back(k);
          R[k].push_back(i);
        }
      }
    }
  }
  vector<int> mx(n, 1);
  rrep(i, n) {
    for(int ne: R[i]) chmax(mx[ne], mx[i]+1);
  }
  cout << n - *max_element(all(mx)) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
