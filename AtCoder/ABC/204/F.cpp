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
// const ll mod = 1e9+7;
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

template<typename T>
vector<vector<T>> matmul(vector<vector<T>>& A,
                         vector<vector<T>>& B) {
  assert(A[0].size() == B.size());
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<T>> ret(n, vector<T>(l));
  rep(i, n) rep(k, l) rep(j, m) (ret[i][k] += A[i][j] * B[j][k]) %= mod;
  return ret;
}

template<typename T>
struct MatExp {

  vector<vector<T>> _trans;
  int _n;
  vector<vector<vector<T>>> M;
  int size = 60;

  MatExp(vector<vector<T>> trans): _trans(trans) {
    assert(_trans.size() == _trans[0].size());
    _n = _trans.size();
    init();
  }

  void init() {
    M.assign(size, vector<vector<T>>(_n, vector<T>(_n)));
    copy(all(_trans), M[0].begin());
    for(int i=1; i<size; i++) {
      M[i] = matmul(M[i-1], M[i-1]);
    }
  }

  vector<vector<T>> build(ll k) {
    vector<vector<T>> ret(_n, vector<T>(_n));
    rep(i, _n) ret[i][i] = 1;
    rep(i, size) {
      if((k>>i)&1) ret = matmul(ret, M[i]);
    }
    return ret;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h; ll w; cin >> h >> w;
  vector<vector<ll>> T(1<<h, vector<ll>(1<<h));
  int mx = 6;
  vector<ll> dp(mx+1);
  dp[0] = 1;
  rep(i, mx+1) {
    if(i+1 < mx+1) (dp[i+1] += dp[i]) %= mod;
    if(i+2 < mx+1) (dp[i+2] += dp[i]) %= mod;
  }
  rep(i, 1<<h) {
    rep(j, 1<<h) {
      if(i&j) continue;
      int s = i^j;
      int l = 0;
      ll tmp = 1;
      while(l < h) {
        while(l < h && (s>>l)&1) l++;
        int r = l;
        while(r < h && !((s>>r)&1)) r++;
        (tmp *= dp[r-l]) %= mod;
        l = r;
      }
      T[i][j] = tmp;
    }
  }
  MatExp<ll> M(T);
  auto ret = M.build(w);
  cout << ret[0][0] << endk;
  return 0;
}
