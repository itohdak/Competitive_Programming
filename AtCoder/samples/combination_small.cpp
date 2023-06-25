#include "header.hpp"

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

// make()


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
/* 小さいmod (特にn>mod) に対する [nC0, nC1, ... , nCn] % mod を計算する */
vector<int> make_comb_small(int n, int mod) {
  vector<int> comb(n);
  comb[0] = 1;
  int denom = 1, numer = 1; // 分母、分子
  int cnt = 0; // nCkがmodで何回割り切れるか
  for(int k=1; k<n; k++) {
    int tmp_n = n-k;
    while(tmp_n % mod == 0) {
      tmp_n /= mod;
      cnt++;
    }
    int tmp_d = k;
    while(tmp_d % mod == 0) {
      tmp_d /= mod;
      cnt--;
    }
    (numer *= tmp_n) %= mod;
    (denom *= tmp_d) %= mod;
    if(cnt) {
      comb[k] = 0;
    } else {
      comb[k] = numer * modinv(denom, mod) % mod;
    }
  }
  return comb;
}
