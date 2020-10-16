#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  vector<int> cntAll(N+1);
  rep(i, N) cntAll[i+1] = cntAll[i] + (S[i]=='1');
  vector<string> T(K);
  rep(i, N) T[i%K] += S[i];
  int ans = N;
  rep(k, K) {
    int M = T[k].size();
    vector<int> cnt(M+1);
    rep(i, M) cnt[i+1] = cnt[i] + (T[k][i]=='1');
    vector<vector<int>> dp(M+1, vector<int>(3));
    rep(i, M) {
      dp[i+1][0] = dp[i][0] + (T[k][i]=='1');
      dp[i+1][1] = min(dp[i][0], dp[i][1]) + (T[k][i]=='0');
      dp[i+1][2] = min({dp[i][0], dp[i][1], dp[i][2]}) + (T[k][i]=='1');
    }
    int mn = min({dp[M][0], dp[M][1], dp[M][2]});
    ans = min(mn+cntAll[N]-cnt[M], ans);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
