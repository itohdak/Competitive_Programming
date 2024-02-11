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

#define mint modint<1000000007>
template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

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
ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n, m, l; cin >> n >> m >> l;
  // 何番目の頂点を見ていて，今まで何個の辺を使ったか．連結成分最大数はいくつか．
  // vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(m+1, vector<mint>(l+1)));
  // dp[0][0][0] = 1;
  // rep(i, n) {
  //   rep(j, m+1) {
  //     rep(mx, l+1) {
  //       REP(k, 1, l+1) {
  //         if(i+k > n) break;
  //         if(j+k-1 <= m) dp[i+k][j+k-1][max(k, mx)] += dp[i][j][mx] * perm(n-i, k); // 直鎖
  //         if(j+k <= m && k != 1) dp[i+k][j+k][max(k, mx)] += dp[i][j][mx] * perm(n-i, k); // ループ
  //       }
  //     }
  //   }
  // }
  // rep(i, n+1) {
  //   rep(j, m+1) {
  //     rep(mx, l+1) {
  //       cout << dp[i][j][mx].value() << ' ';
  //     }
  //     cout << endk;
  //   }
  //   cout << endk;
  // }
  // cout << (dp[n][m][l] * fac[n]).value() << endk;
  vector<vector<vector<mint>>> dp((2*l)+1, vector<vector<mint>>(n+1, vector<mint>(m+1)));
  dp[1][0][0] = 1;
  rep(i, 2*l) {
    if(i == 0) continue;
    rep(j, n+1) {
      rep(k, m+1) {
        int cnt = i/2+1;
        int rem = n-j;
        if(i%2) { // 直鎖
          dp[i+1][j][k] += dp[i][j][k]; // 何もしない
          REP(p, 1, n+1) {
            if(j + cnt * p > n) break;
            if(k + (cnt-1) * p > m) break;
            dp[i+1][j+cnt*p][k+(cnt-1)*p] += dp[i][j][k] * perm(rem, cnt*p) * finv[p] * (cnt > 1 ? modinv(modpow(2, p)) : 1);
          }
        } else { // ループ
          dp[i+1][j][k] += dp[i][j][k]; // 何もしない
          REP(p, 1, n+1) {
            if(j + cnt * p > n) break;
            if(k + cnt * p > m) break;
            dp[i+1][j+cnt*p][k+cnt*p] += dp[i][j][k] * perm(rem, cnt*p) * finv[p] * modinv(modpow(2*cnt, p));
          }
        }
      }
    }
  }
  rep(i, 2*l+1) {
    rep(j, n+1) {
      rep(k, m+1) {
        cout << dp[i][j][k].value() << ' ';
      }
      cout << endk;
    }
    cout << endk;
  }
  cout << dp[2*l][n][m].value() << endk;
  return 0;
}
