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
  string s, t; cin >> s >> t;
  BinaryIndexedTree<int> bit(n+1);
  rep(i, n) {
    if(s[i] > t[i]) bit.add(i, 1);
    else if(s[i] < t[i]) bit.add(i, 2);
    else bit.add(i, 0);
  }
  bit.add(n, 3);
  auto bsearch = [&]() {
    int ok = n, ng = -1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (bit.sum(0, mid+1) ? ok : ng) = mid;
    }
    return ok;
  };
  int q; cin >> q;
  rep(_, q) {
    char c; cin >> c;
    int x, y; cin >> x >> y;
    x--;
    if(c == 'S') {
      s[x] = char('0'+y);
    } else {
      t[x] = char('0'+y);
    }
    if(s[x] > t[x]) bit.add(x, 1-bit.sum(x, x+1));
    else if(s[x] < t[x]) bit.add(x, 2-bit.sum(x, x+1));
    else bit.add(x, 0-bit.sum(x, x+1));
    int i = bsearch();
    // rep(i, n+1) cout << bit.sum(i, i+1) << ' '; cout << endk;
    // cout << i << endk;
    // cout << bit.sum(i, i+1) << endk;
    if(bit.sum(i, i+1) == 1) cout << ">" << endk;
    else if(bit.sum(i, i+1) == 2) cout << "<" << endk;
    else cout << "=" << endk;
  }
  return 0;
}
