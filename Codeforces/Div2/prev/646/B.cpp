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
  string S;
  cin >> S;
  int N = S.size();
  vector<int> cntl(N+1), cntr(N+1);
  rep(i, N) {
    cntl[i+1] = cntl[i];
    if(S[i] == '0') cntl[i+1]++;
  }
  rrep(i, N) {
    cntr[i] = cntr[i+1];
    if(S[i] == '0') cntr[i]++;
  }
  // cout << cntl << cntr << endl;
  int ans = inf;
  rep(i, N+1) {
    ans = min(i-cntl[i]+cntr[i], ans);
    ans = min(cntl[i]+N-i-cntr[i], ans);
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
