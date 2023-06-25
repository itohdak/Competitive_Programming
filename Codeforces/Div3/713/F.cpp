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
  int n; ll c; cin >> n >> c;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n-1); rep(i, n-1) cin >> B[i];
  ll ans = longinf;
  ll tmp = 0;
  ll spent = 0;
  rep(i, n) {
    // cout << tmp << ' ' << spent << ' ' << (c-tmp+A[i]-1)/A[i]+spent << endk;
    chmin(ans, (c-tmp+A[i]-1)/A[i]+spent);
    if(i < n-1) {
      ll need = (B[i]-tmp+A[i]-1)/A[i];
      spent += need + 1;
      tmp = tmp + need * A[i] - B[i];
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
