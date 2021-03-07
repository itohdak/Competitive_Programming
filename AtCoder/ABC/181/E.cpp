#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> H(n), W(m);
  rep(i, n) cin >> H[i];
  sort(all(H));
  rep(i, m) cin >> W[i];
  vector<ll> suml(n+1), sumr(n+1);
  rep(i, n) {
    suml[i+1] += suml[i];
    if(i%2) suml[i+1] += H[i]-H[i-1];
  }
  rrep(i, n) {
    sumr[i] += sumr[i+1];
    if(i%2) sumr[i] += H[i+1]-H[i];
  }
  // cout << suml << sumr << endk;
  ll ans = longinf;
  rep(i, m) {
    int j = lower_bound(all(H), W[i]) - begin(H);
    if(j%2) {
      chmin(ans, W[i]-H[j-1]+suml[j-1]+sumr[j]);
    } else {
      chmin(ans, H[j]-W[i]+suml[j]+sumr[j+1]);
    }
  }
  cout << ans << endk;
  return 0;
}
