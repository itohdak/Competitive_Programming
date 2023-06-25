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

bool done[200050];
int memo[200050];
int memo2[200050];
void solve(int n, BinaryIndexedTree<int>& bit) {
  int k; cin >> k;
  auto bsearch = [&]() {
    auto test = [&](int m) {
      int ret;
      if(!done[m]) {
        cout << "? " << 1 << ' ' << m << endl;
        cin >> ret;
        done[m] = true;
        memo[m] = ret;
        memo2[m] = bit.sum(0, m);
      } else {
        ret = memo[m] + bit.sum(0, m) - memo2[m];
      }
      return ret <= m-k;
    };
    int ok = n, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  int ret = bsearch();
  cout << "! " << ret << endl;
  bit.add(ret-1, 1);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  rep(i, n) {
    done[i] = false;
    memo[i] = -1;
    memo2[i] = -1;
  }
  BinaryIndexedTree<int> bit(n);
  while(t--) solve(n, bit);
  return 0;
}
