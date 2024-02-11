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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<ll> cum(n+1);
  rep(i, n) {
    cum[i+1] = cum[i];
    if(!(i%2) && i > 0) {
      cum[i+1] += A[i]-A[i-1];
    }
  }
  int q; cin >> q;
  rep(i, q) {
    int l, r; cin >> l >> r;
    int j = lower_bound(all(A), l) - begin(A);
    int k = upper_bound(all(A), r) - begin(A);
    if(j == k) {
      if(!(j%2)) {
	cout << r-l << endk;
      } else {
	cout << 0 << endk;
      }
    } else {
      ll ans = 0;
      if(!(j%2)) {
	ans += A[j]-l;
      }
      if(!(k%2)) {
	ans += r-A[k-1];
      }
      ans += cum[k]-cum[j+1];
      cout << ans << endk;
    }
  }
  return 0;
}
