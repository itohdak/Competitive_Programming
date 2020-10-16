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

void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
void solve() {
  int N;
  cin >> N;
  vector<ll> S(N);
  rep(i, N) cin >> S[i];
  vector<vector<int>> G(N);
  vector<bool> vis(N);
  rrep(i, N) {
    vector<ll> div;
    find_divisor(i+1, div);
    for(ll d: div) {
      if(S[i] > S[d-1]) {
        G[d-1].push_back(i);
      }
    }
  }
  rep(i, N) G[i].push_back(N);
  vector<int> dfs(N+1);
  dfs[0] = 0;
  rep(i, N) {
    for(int ne: G[i]) {
      dfs[ne] = max(dfs[i]+1, dfs[ne]);
    }
  }
  cout << dfs[N] << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
