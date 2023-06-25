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

template< typename T >
struct BinaryIndexedTree {
  using U =
    typename std::conditional<std::is_same<T, long long>::value,
                              unsigned long long,
                              unsigned int>::type;

  BinaryIndexedTree(int sz) : _n(sz) {
    data.assign(++sz, 0);
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while(p <= _n) {
      data[p - 1] += U(x);
      p += p & -p;
    }
  }

private:
  vector< U > data;
  int _n;

  U sum(int r) {
    U ret = 0;
    while(r > 0) {
      ret += data[r - 1];
      r -= r & -r;
    }
    return ret;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  vector<ll> A(n), B(n), C(n);
  rep(i, n) {
    cin >> A[i] >> B[i] >> C[i];
    chmin(B[i], A[i]);
    chmin(C[i], A[i]);
  }
  BinaryIndexedTree<ll> bitl(n), bitr(n);
  vector<ll> costl(n), costr(n);
  rep(i, n) {
    costl[P[i]] = min(A[P[i]], bitl.sum(0, P[i])+B[P[i]]);
    bitl.add(P[i], B[P[i]]);
  }
  rrep(i, n) {
    costr[P[i]] = min(A[P[i]], bitr.sum(P[i], n)+C[P[i]]);
    bitr.add(P[i], C[P[i]]);
  }
  cout << costl << ' ' << costr << endk;
  vector<ll> suml(n+1), sumr(n+1);
  rep(i, n) suml[i+1] = suml[i] + costl[i];
  rrep(i, n) sumr[i] = sumr[i+1] + costr[i];
  ll ans = longinf;
  rep(i, n+1) {
    chmin(ans, suml[i]+sumr[i]);
  }
  cout << ans << endk;
  return 0;
}
