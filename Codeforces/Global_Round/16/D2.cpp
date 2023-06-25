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
const ll mod = 1e9+7;
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

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> A(n*m);
  rep(i, n*m) cin >> A[i];
  vector<int> id(n*m);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(A[i] == A[j]) {
      return i < j;
    } else {
      return A[i] < A[j];
    }
  });
  // cout << id << endk;
  ll ans = 0;
  int l = 0;
  rep(i, n) {
    vector<int> order;
    while(l < (i+1)*m) {
      int r = l;
      while(r < (i+1)*m && A[id[r]] == A[id[l]]) r++;
      for(int j=r-1; j>=l; j--) order.push_back(id[j]);
      l = r;
    }
    // cout << order << endk;
    sort(all(order), [&](int i, int j) {
      if(A[i] == A[j]) {
        return i > j;
      } else {
        return A[i] < A[j];
      }
    });
    BinaryIndexedTree<int> bit(n*m);
    for(int j: order) {
      ans += bit.sum(0, j);
      bit.add(j, 1);
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
