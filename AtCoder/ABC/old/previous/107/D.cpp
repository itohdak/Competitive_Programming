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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  auto bsearch = [&]() {
    auto test = [&](ll m) -> bool {
      vector<int> a(n);
      rep(i, n) a[i] = (A[i] >= m ? 1 : -1);
      vector<int> cum(n+1);
      rep(i, n) cum[i+1] = cum[i] + a[i];
      ll cnt = 0;
      BinaryIndexedTree<int> bit(2*n+1);
      rep(i, n+1) {
        cnt += bit.sum(0, cum[i]+n+1);
        bit.add(cum[i]+n, 1);
      }
      return cnt >= (1LL*n*(n+1)/2+1)/2;
    };
    ll ok = 0, ng = longinf;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
