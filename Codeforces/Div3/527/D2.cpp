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
  map<int, vector<pair<int, int>>> mp;
  {
    int l = 0;
    while(l < n) {
      int r = l;
      while(r < n && A[r] == A[l]) r++;
      mp[A[l]].push_back({l, r});
      l = r;
    }
  }
  BinaryIndexedTree<int> bit(n);
  auto bsearch = [&](int l) {
    auto test = [&](int m) {
      return bit.sum(l, m) == m-l;
    };
    int ng = n+1, ok = l+1;
    while(abs(ok-ng)>1) {
      int mid = (ng+ok)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  auto bsearch_l = [&](int r) {
    auto test = [&](int m) {
      return bit.sum(m, r) == r-m;
    };
    int ng = -1, ok = r;
    while(abs(ok-ng)>1) {
      int mid = (ng+ok)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  for(auto& [_, v]: mp) {
    vector<int> tmp;
    for(auto& [l, r]: v) {
      for(int i=l; i<r; i++) {
        bit.add(i, 1);
      }
      tmp.push_back(l);
    }
    int prev = 0;
    for(auto& i: tmp) {
      if(i < prev) continue;
      int l = bsearch_l(i);
      int r = bsearch(l);
      if(l == 0 && r == n) {
        cout << "YES" << endk;
        return 0;
      }
      if((r-l)&1) {
        cout << "NO" << endk;
        return 0;
      }
      i = r;
    }
  }
  return 0;
}
