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
  int n, q; cin >> n >> q;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  vector<ll> K(q); rep(i, q) cin >> K[i];
  ll tmp = 0;
  // cout << sum << endk;
  rep(i, q) {
    tmp += K[i];
    int p = upper_bound(all(sum), tmp) - begin(sum) - 1;
    if(p == n) {
      tmp = 0;
      cout << n << endk;
    } else {
      cout << n-p << endk;
    }
  }
  return 0;
}
