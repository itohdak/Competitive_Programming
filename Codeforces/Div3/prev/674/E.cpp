#include <bits/stdc++.h>
#include <print.hpp>
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
  ll n; cin >> n;
  vector<ll> A(3), B(3);
  vector<ll> Aorig(3), Borig(3);
  rep(i, 3) cin >> Aorig[i];
  rep(i, 3) cin >> Borig[i];
  ll mx = 0;
  rep(i, 3) mx += min(Aorig[i], Borig[(i+1)%3]);
  ll mn = longinf;
  rep(j, 3) {
    ll cur = 0;
    copy(all(Aorig), begin(A));
    copy(all(Borig), begin(B));
    rrep(i, 3) {
      ll tmp = min(A[(i+j)%3], B[(i+j)%3]);
      A[(i+j)%3] -= tmp; B[(i+j)%3] -= tmp;
      tmp = min(A[(i+j)%3], B[(i+j+2)%3]);
      A[(i+j)%3] -= tmp; B[(i+j+2)%3] -= tmp;
      cur += A[(i+j)%3];
    }
    chmin(mn, cur);
  }
  cout << mn << ' ' << mx << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
