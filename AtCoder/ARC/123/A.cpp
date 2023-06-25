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
  vector<ll> A(3); rep(i, 3) cin >> A[i];
  ll ans = longinf;
  auto check = [&](ll a, ll b, ll offset=0) {
    if(a >= b) chmin(ans, a-b+offset);
  };
  // a1を固定
  check(2*A[1]-A[0], A[2]);
  if((A[2]+A[0])&1) check((A[2]+A[0]+1)/2, A[1], 1);
  else check((A[2]+A[0])/2, A[1]);
  // // a2を固定
  // check(2*A[1]-A[2], A[0]);
  // check(2*A[1]-A[0], A[2]);
  // a3を固定
  reverse(all(A));
  check(2*A[1]-A[0], A[2]);
  if((A[2]+A[0])&1) check((A[2]+A[0]+1)/2, A[1], 1);
  else check((A[2]+A[0])/2, A[1]);
  cout << ans << endk;
  return 0;
}
