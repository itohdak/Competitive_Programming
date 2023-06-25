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
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  vector<int> Bcopy(all(B));
  sort(all(Bcopy));
  Bcopy.erase(unique(all(Bcopy)), Bcopy.end());
  auto idb = [&](int b) {
    return lower_bound(all(Bcopy), b) - Bcopy.begin();
  };
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  int m = Bcopy.size();
  BinaryIndexedTree<int> bit(m);
  ll ans = 0;
  int l = 0;
  while(l < n) {
    int r = l;
    while(r < n && A[id[r]] == A[id[l]]) {
      bit.add(idb(B[id[r]]), 1);
      r++;
    }
    for(int i=l; i<r; i++) {
      ans += bit.sum(idb(B[id[i]]), m);
    }
    l = r;
  }
  cout << ans << endk;
  return 0;
}
