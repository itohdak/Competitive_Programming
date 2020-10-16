#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
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
const ll mod = 998244353;

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size(), M = T.size();
  vector<vector<ll> > dp(N, vector<ll>(M));
  rep(i, N) {
    rep(j, M) {
      if(S[i] == T[j]) {
	if(j == M-1) {
	} else {
	  dp[i][j] = dp[i-1][j+1];
	}
      } else {
	dp[i][j] = dp[i-1][j];
      }
    }
  }
  return 0;
}
