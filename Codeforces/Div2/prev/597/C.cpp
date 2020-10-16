#include <bits/stdc++.h>
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

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<ll> dp(N);
  if(S[0] == 'w' || S[0] == 'm') {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  REP(i, 1, N) {
    if(S[i] == 'w' || S[i] == 'm') {
      cout << 0 << endl;
      return 0;
    }
    dp[i] = dp[i-1];
    if(S[i] == S[i-1] && (S[i] == 'u' || S[i] == 'n')) {
      if(i == 1) dp[i]++;
      else dp[i] += dp[i-2];
    }
    dp[i] %= mod;
  }
  cout << dp[N-1] << endl;
  return 0;
}

