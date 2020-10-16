#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  ll ans = longinf;
  for(ll c=1; c<=1e9; c++) {
    ll tmp = 1;
    ll cost = 0;
    bool ok = true;
    rep(i, n) {
      cost += abs(A[i]-tmp);
      if(tmp > LONG_LONG_MAX/c) {
        ok = false;
        break;
      }
      tmp *= c;
    }
    if(!ok) break;
    chmin(ans, cost);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
