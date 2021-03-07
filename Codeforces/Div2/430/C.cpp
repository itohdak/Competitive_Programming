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

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  map<int, set<int>> mp;
  vector<int> cnt(200005, 0);
  rep(i, 200005) mp[0].insert(i);
  vector<int> ans(n);
  auto dfs = [&](auto dfs, int cur, int par, int depth) -> void {
    vector<ll> res;
    find_divisor(A[cur], res); // 約数を求める
    for(ll d: res) { // 約数のカウントを1増やす
      int c = cnt[d];
      assert(mp[c].count(d));
      mp[c].erase(d);
      if(mp[c].empty()) mp.erase(c);
      mp[c+1].insert(d);
      cnt[d]++;
    }
    if(depth) {
      if(mp.count(depth)) {
        ans[cur] = *(--mp[depth].end());
      } else {
        ans[cur] = 1;
      }
    } else {
      ans[cur] = A[cur];
    }
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur, depth+1);
      }
    }
    for(ll d: res) {
      int c = cnt[d];
      assert(mp[c].count(d));
      mp[c].erase(d);
      if(mp[c].empty()) mp.erase(c);
      mp[c-1].insert(d);
      cnt[d]--;
    }
  };
  dfs(dfs, 0, -1, 0);
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
