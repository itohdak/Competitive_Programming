#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
    S[i] += 'o';
  }
  int ans = 0;
  rep(i, N) {
    for(int j=S[i].size()-1; j>0; j--) {
      if(S[i][j] == 'o' && S[i][j-1] == '.') {
        ans++;
        rep(k, j) S[i][k] = 'o';
        if(i+1<N) REP(k, j-1, S[i].size()) S[i+1][k] = 'o';
      }
    }
  }
  cout << ans << endl;
  return 0;
}
