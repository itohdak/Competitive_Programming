#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

template<typename T>
vector<vector<T>> matmul(vector<vector<T>>& A,
                         vector<vector<T>>& B,
                         ll mod) {
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
  ll _mod;

  MatExp(vector<vector<T>> trans, ll mod): _trans(trans), _mod(mod) {
    assert(_trans.size() == _trans[0].size());
    _n = _trans.size();
    init();
  }

  void init() {
    M.assign(size, vector<vector<T>>(_n, vector<T>(_n)));
    copy(all(_trans), M[0].begin());
    for(int i=1; i<size; i++) {
      M[i] = matmul(M[i-1], M[i-1], _mod);
    }
  }

  vector<vector<T>> build(ll k) {
    vector<vector<T>> ret(_n, vector<T>(_n));
    rep(i, _n) ret[i][i] = 1;
    rep(i, size) {
      if((k>>i)&1) ret = matmul(ret, M[i], _mod);
    }
    return ret;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a, x, m; cin >> a >> x >> m;
  vector<vector<ll>> trans(2, vector<ll>(2));
  trans[0][0] = a;
  trans[0][1] = 1;
  trans[1][1] = 1;
  MatExp matexp(trans, m);
  vector<vector<ll>> one(2, vector<ll>(1));
  one[0][0] = one[1][0] = 1;
  auto ret = matexp.build(x-1);
  cout << matmul(ret, one, m)[0][0] << endk;
  return 0;
}
