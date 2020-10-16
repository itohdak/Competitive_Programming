#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, c;
  cin >> N >> c;
  vector<int> A(N-1), B(N-1);
  rep(i, N-1) cin >> A[i];
  rep(i, N-1) cin >> B[i];
  vector<vector<ll> > dp(N, vector<ll>(2, longinf)); // (stairs, elevator)
  dp[0][0] = 0;
  dp[0][1] = 0;
  REP(i, 1, N) {
    dp[i][0] = min(dp[i-1][0] + A[i-1], dp[i-1][1] + c + A[i-1]);
    dp[i][1] = min(dp[i-1][0] + B[i-1], dp[i-1][1] + B[i-1]);
  }
  rep(i, N)
    cout << min(dp[i][0], dp[i][1]+c) << ' ';
  cout << endl;
  return 0;
}

