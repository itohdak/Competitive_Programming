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
  vector<ll> A(14); rep(i, 14) cin >> A[i];
  ll ans = 0;
  rep(i, 14) {
    ll tmp = 0;
    vector<ll> B(14);
    copy(all(A), begin(B));
    rep(j, 14) {
      if(j == i) {
        B[j] = A[j]/14;
      } else {
        B[j] = A[j] + A[i]/14 + (A[i]%14>(j+14-i-1)%14);
      }
      if(B[j]%2 == 0) tmp += B[j];
    }
    // cout << B << endk;
    chmax(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
