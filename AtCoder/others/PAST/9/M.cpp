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
  int n, q; cin >> n >> q;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<string> names;
  auto dfs = [&](auto dfs, string cur) -> void {
    if(cur.size()) names.push_back(cur);
    if(cur.size() == 5) return;
    for(char c='a'; c<='z'; c++) {
      dfs(dfs, cur+c);
    }
  };
  dfs(dfs, string(""));
  int m = names.size();
  BinaryIndexedTree<int> bit(m);
  rep(i, n) {
    int j = lower_bound(all(names), S[i]) - begin(names);
    bit.add(j, 1);
  }
  auto bsearch = [&](int x) {
    auto test = [&](int t) {
      return bit.sum(0, t+1) <= x;
    };
    int ok = 0, ng = m;
    while((ok-ng)/2) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  rep(i, q) {
    int x; string t; cin >> x >> t;
    x--;
    auto ret = bsearch(x);
    string name = names[ret+1];
    int rem = x-bit.sum(0, ret);
    cout << name << endk;
  }
  rep(i, n) cout << S[i] << ' ';
  cout << endk;
  return 0;
}
