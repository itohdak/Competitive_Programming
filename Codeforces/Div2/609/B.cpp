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
  int n; ll m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  sort(all(A));
  sort(all(B));
  ll mn = longinf;
  rep(i, n) {
    bool ok = true;
    ll diff = ((B[i]-A[0])%m+m)%m;
    rep(j, n) {
      if(((B[(i+j)%n]-A[j])%m+m)%m != diff) ok = false;
    }
    if(ok) chmin(mn, diff);
  }
  cout << mn << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
