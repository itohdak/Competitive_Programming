
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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> par(n+1, vector<int>(5, -1));
  rep(j, 5) par[0][j] = 0;
  rep(i, n) {
    if(i == 0) {
      rep(j, 5) {
        if(par[i][j] != -1) {
          rep(k, 5) if(k != j) par[i+1][k] = j;
        }
      }
    } else {
      if(A[i] > A[i-1]) {
        rep(j, 5) {
          if(par[i][j] != -1) {
            for(int k=j+1; k<5; k++) par[i+1][k] = j;
          }
        }
      } else if(A[i] < A[i-1]) {
        rep(j, 5) {
          if(par[i][j] != -1) {
            rep(k, j) par[i+1][k] = j;
          }
        }
      } else {
        rep(j, 5) {
          if(par[i][j] != -1) {
            rep(k, 5) if(k != j) par[i+1][k] = j;
          }
        }
      }
    }
  }
  rep(j, 5) {
    if(par[n][j] != -1) {
      vector<int> ans;
      int p = j;
      rrep(i, n) {
        ans.push_back(p);
        p = par[i+1][p];
      }
      reverse(all(ans));
      rep(i, n) cout << ans[i]+1 << ' ';
      cout << endk;
      return 0;
    }
  }
  cout << -1 << endk;
  return 0;
}
