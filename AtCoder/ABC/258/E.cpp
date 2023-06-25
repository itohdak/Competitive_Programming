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

class Doubling {
public:
  int N;
  int logK;
  vector<vector<int>> next;

  Doubling(int N, vector<int>& ini, ll K) {
    logK = log2(K);
    next = vector<vector<int>>(logK+1, vector<int>(N));
    rep(i, N) next[0][i] = ini[i];
    rep(k, logK) {
      rep(i, N) {
        next[k+1][i] = (next[k][i] == -1 ? -1 : next[k][next[k][i]]);
      }
    }
  }

  int query(int p, ll q) {
    for(int k=logK; k>=0; k--) {
      if(p == -1) break;
      if((q>>k)&1) p = next[k][p];
    }
    return p;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; ll x; cin >> n >> q >> x;
  vector<ll> W(n);
  rep(i, n) cin >> W[i];
  vector<ll> WW(2*n);
  rep(i, n) WW[i] = WW[i+n] = W[i];
  vector<ll> cum(2*n+1);
  rep(i, 2*n) cum[i+1] = cum[i] + WW[i];
  vector<int> A(n);
  vector<ll> cnt(n);
  rep(i, n) {
    int pos = (lower_bound(all(cum), cum[i]+(x%cum[n])) - begin(cum)) % n;
    A[i] = pos;
    cnt[i] = n*(x/cum[n]) + (x%cum[n] && i == pos ? n : (pos-i+n)%n);
  }
  Doubling dbl(n, A, 1000000000000LL);
  rep(i, q) {
    ll k; cin >> k;
    int ret = dbl.query(0, k-1);
    cout << cnt[ret] << endk;
  }
  return 0;
}
