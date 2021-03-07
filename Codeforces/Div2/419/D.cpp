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

#define MAX_N 2000005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r);
  ans = (ans * finv[r]) % mod;
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];

  vector<ll> B(n);
  if(n%4 == 1) {
    rep(i, n) {
      if(i%2==0) {
        B[i] = comb((n-1)/2, i/2);
      }
    }
  } else if(n%4 == 2) {
    rep(i, n) {
      if(i%2==0) {
        B[i] = comb((n-2)/2, i/2);
        B[i+1] = comb((n-2)/2, i/2);
      }
    }
  } else if(n%4 == 3) {
    rep(i, (n+1)/2) {
      if(i == 0) B[i] = 1;
      else if(i%2) (B[i] = B[i-1] + comb((n-1)/2, i/2)) %= mod;
      else (B[i] = comb((n-1)/2, i/2) - B[i-1] + mod) %= mod;
    }
    REP(i, (n+1)/2, n) {
      if((n-1-i)%2) B[i] = B[n-1-i];
      else B[i] = -B[n-1-i];
    }
  } else {
    rep(i, n) {
      if(i%2==0) {
        B[i] = comb((n-2)/2, i/2);
        B[i+1] = -comb((n-2)/2, i/2);
      }
    }
  }
  // cout << B << endk;
  ll ans = 0;
  rep(i, n) {
    (ans += mod + A[i] * B[i] % mod) %= mod;
  }
  cout << ans << endk;

// 1
// 1 1
// 1 2 -1
// 1 -1 1 -1
// 1 0 2 0 1
// 1 1 2 2 1 1
// 1 2 1 4 -1 2 -1
// 1 -1 3 -3 3 -3 1 -1
// 1 0 4 0 6 0 4 0 1
// 1 1 4 4 6 6 4 4 1 1
// 1 2 3 8 2 12 -2 8 -3 2 -1
// 1 -1 5 -5 10 -10 10 -10 5 -5 1 -1
// 1 0 6 0 15 0 20 0 15 0 6 0 1

  // for(int n=1; n<=15; n++) {
  //   rep(k, n) {
  //     int sign[] = {1, 1, 1, -1};
  //     vector<vector<int>> B(n);
  //     rep(i, n) B[i] = vector<int>(n-i);
  //     B[0][k] = 1;
  //     int s = 0;
  //     rep(i, n-1) {
  //       rep(j, n-i) {
  //         if(j) {
  //           B[i+1][j-1] += B[i][j] * sign[s];
  //           (s += 1) %= 4;
  //         }
  //         if(j < n-i-1) {
  //           B[i+1][j] += B[i][j] * sign[s];
  //           (s += 1) %= 4;
  //         }
  //       }
  //     }
  //     cout << B[n-1][0] << ' ';
  //   }
  //   cout << endk;
  // }
  return 0;
}
