#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> A(n), B(m);
  set<ll> stA, stB;
  rep(i, n) {
    cin >> A[i];
    stA.insert(A[i]);
  }
  rep(i, m) {
    cin >> B[i];
    stB.insert(B[i]);
  }
  for(ll a: stA) {
    if(stB.count(a)) {
      cout << "YES\n";
      cout << 1 << ' ' << a << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
