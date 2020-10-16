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

void solve() {
  int N;
  cin >> N;
  ll peven=0, podd=0;
  rep(i, N) {
    ll p;
    cin >> p;
    if(p % 2 == 0) peven++;
    else podd++;
  }
  int M;
  cin >> M;
  vector<ll> Q(M);
  ll qeven=0, qodd=0;
  rep(i, M) {
    ll q;
    cin >> q;
    if(q % 2 == 0) qeven++;
    else qodd++;
  }
  cout << peven * qeven + podd * qodd << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

