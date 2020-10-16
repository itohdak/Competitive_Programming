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
const ll mod = 1e9+7;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  set<int> se;
  rep(i, N) {
    cin >> A[i];
    se.insert(A[i]);
  }
  if(se.size() > K) cout << -1 << endl;
  else {
    rep(i, N) {
      if(se.size() == K) break;
      se.insert(i+1);
    }
    cout << N * K << endl;
    rep(i, N) for(int s: se) cout << s << ' ';
    cout << endl;
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
