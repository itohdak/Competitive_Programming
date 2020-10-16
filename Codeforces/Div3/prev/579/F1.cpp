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
  int n, r; cin >> n >> r;
  vector<int> A(n), B(n); rep(i, n) cin >> A[i] >> B[i];
  vector<int> pos, neg;
  rep(i, n) (B[i] >= 0 ? pos : neg).push_back(i);
  sort(all(pos), [&](int i, int j) {
    if(A[i] == A[j]) return B[i] > B[j];
    else return A[i] < A[j];
  });
  sort(all(neg), [&](int i, int j) {
    if(A[i]+B[i] == A[j]+B[j]) return A[i] < A[j];
    else return A[i]+B[i] > A[j]+B[j];
  });
  int m = 60001;
  // int m = 50*n+1;
  vector<vector<int>> dp(n+1, vector<int>(m, -inf));
  dp[0][m/2] = 0;
  vector<int> id;
  for(int i: pos) id.push_back(i);
  for(int i: neg) id.push_back(i);
  rep(i, n) {
    rep(j, m) {
      chmax(dp[i+1][j], dp[i][j]);
      if(j+B[id[i]]>=0 && j+B[id[i]]<m) {
        if(r + j - m/2 >= A[id[i]] && r + j - m/2 + B[id[i]] >= 0) {
          chmax(dp[i+1][j+B[id[i]]], dp[i][j]+1);
        }
      }
    }
  }
  // cout << id << endk;
  // rep(i, n+1) {
  //   rep(j, m) {
  //     if(dp[i][j] < -inf/2) cout << '-' << ' ';
  //     else cout << dp[i][j] << ' ';
  //   }
  //   cout << endk;
  // }
  cout << (*max_element(all(dp[n]))==n ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
