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
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> P(n), id(n);
  rep(i, n) {
    cin >> P[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return P[i] < P[j];
  });
  vector<tuple<int, int, int>> query(m);
  vector<int> idq(m);
  rep(i, m) {
    int l, r, x; cin >> l >> r >> x;
    l--; r--; x--;
    query[i] = {l, r, x};
    idq[i] = i;
  }
  sort(all(idq), [&](int i, int j) {
    return P[get<2>(query[i])] < P[get<2>(query[j])];
  });
  BinaryIndexedTree<int> bit(n);
  vector<string> ans(m);
  int tmp = 0;
  for(int i: idq) {
    auto [l, r, x] = query[i];
    while(id[tmp] != x) bit.add(id[tmp++], 1);
    if(x - l == bit.sum(r) - bit.sum(l-1)) ans[i] = "Yes";
    else ans[i] = "No";
  }
  rep(i, m) cout << ans[i] << endk;
  return 0;
}
