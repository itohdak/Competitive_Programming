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
  vector<ll> B = A;
  sort(all(B));
  B.erase(unique(all(B)), end(B));
  auto id = [&](ll a) {
    return lower_bound(all(B), a) - begin(B);
  };
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int m = B.size();
  BinaryIndexedTree<int> bit(m);
  auto bsearch = [&]() {
    int sum = bit.sum(0, m);
    if(sum&1) {
      int ok = m-1, ng = -1;
      while(ok-ng>1) {
        int mid = (ok+ng)/2;
        (bit.sum(0, mid+1) >= (sum+1)/2 ? ok : ng) = mid;
      }
      return B[ok];
    } else {
      int ok = m-1, ng = -1;
      while(ok-ng>1) {
        int mid = (ok+ng)/2;
        (bit.sum(0, mid+1) >= sum/2 ? ok : ng) = mid;
      }
      int ok1 = ok;
      ok = m-1, ng = -1;
      while(ok-ng>1) {
        int mid = (ok+ng)/2;
        (bit.sum(0, mid+1) >= sum/2+1 ? ok : ng) = mid;
      }
      int ok2 = ok;
      return (B[ok1]+B[ok2])/2;
    }
  };
  vector<ll> dp(n);
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    bit.add(id(A[cur]), 1);
    if(depth&1) dp[cur] = longinf;
    if(par != -1 && G[cur].size() == 1) {
      dp[cur] = bsearch();
    }
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur, depth+1);
      if(depth&1) chmin(dp[cur], dp[ne]);
      else chmax(dp[cur], dp[ne]);
    }
    bit.add(id(A[cur]), -1);
  };
  dfs(dfs, 0, -1, 0);
  cout << dp[0] << endk;
  return 0;
}
