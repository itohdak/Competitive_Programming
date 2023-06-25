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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

#define mint modint<mod>
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
  friend ostream& operator<<(ostream& os, const modint& m) {
    return os << m.value();
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

void solve() {
  make();
  int n; cin >> n;
  map<string, int> cnt;
  {
    string s = "BW?";
    rep(i, 9) {
      string tmp;
      tmp += s[i/3];
      tmp += s[i%3];
      cnt[tmp] = 0;
    }
  }
  rep(i, n) {
    string s; cin >> s;
    cnt[s]++;
  }
  vector<vector<mint>> bal(10, vector<mint>(202020));
  int mid = 101010;
  bal[0][mid] = 1;
  string s = "BW?";
  rep(i, 9) {
    string tmp;
    tmp += s[i/3];
    tmp += s[i%3];
    rep(j, 202020) {
      if(tmp == "??") {
        rep(k, cnt[tmp]+1) {
          rep(l, cnt[tmp]+1-k) {
            if(j+k-l >= 0 && j+k-l < 202020) {
              bal[i+1][j+k-l] += bal[i][j] * comb(cnt[tmp], k) * comb(cnt[tmp]-k, l) * modpow(2, cnt[tmp]-k-l);
            }
          }
        }
      } else if(tmp == "BB") {
        if(j+cnt[tmp] < 202020) bal[i+1][j+cnt[tmp]] += bal[i][j];
      } else if(tmp == "WW") {
        if(j-cnt[tmp] >= 0) bal[i+1][j-cnt[tmp]] += bal[i][j];
      } else if(tmp == "B?" || tmp == "?B") {
        rep(k, cnt[tmp]+1) {
          if(j+k < 202020) {
            bal[i+1][j+k] += bal[i][j] * comb(cnt[tmp], k);
          }
        }
      } else if(tmp == "W?" || tmp == "?W") {
        rep(k, cnt[tmp]+1) {
          if(j-k >= 0) {
            bal[i+1][j-k] += bal[i][j] * comb(cnt[tmp], k);
          }
        }
      } else {
        bal[i+1][j] += bal[i][j];
      }
    }
  }
  mint ans = bal[9][mid];
  if(cnt["WB"] + cnt["W?"] + cnt["?B"] + cnt["??"] == n) {
    ans -= 1;
  }
  if(cnt["BW"] + cnt["B?"] + cnt["?W"] + cnt["??"] == n) {
    ans -= 1;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
