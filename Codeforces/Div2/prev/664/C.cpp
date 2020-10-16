#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(m); rep(i, m) cin >> B[i];
  rep(k, 1<<9) {
    bool ok = true;
    rep(i, n) {
      bool ok2 = false;
      rep(j, m) {
        if((A[i]&B[j]|k) == k) {
          ok2 = true;
          break;
        }
      }
      if(!ok2) {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << k << endk;
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
