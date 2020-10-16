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
  int n; cin >> n;
  vector<ll> M(n); rep(i, n) cin >> M[i];
  vector<ll> inc(n+1), dec(n+1);
  rep(i, n) inc[i+1] = inc[i] + min(M[i], (i==n-1 ? longinf : M[i+1]));
  rrep(i, n) dec[i] = dec[i+1] + min(M[i], (i==0 ? longinf : M[i-1]));
  // cout << inc << endk << dec << endk;
  ll mx = 0;
  int mxi = 0;
  rep(i, n) {
    if(mx < inc[i]+M[i]+dec[i+1]) {
      mx = inc[i]+M[i]+dec[i+1];
      mxi = i;
    }
  }
  rep(i, n) {
    if(i < mxi) cout << min(M[i], (i==n-1 ? longinf : M[i+1])) << ' ';
    else if(i == mxi) cout << M[i] << ' ';
    else cout << min(M[i], (i==0 ? longinf : M[i-1])) << ' ';
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
