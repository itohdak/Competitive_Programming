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

void solve() {
  int n; cin >> n;
  vector<ll> X(n); rep(i, n) cin >> X[i];
  vector<ll> V(n); rep(i, n) cin >> V[i];
  vector<ll> x(n); rep(i, n) x[i] = X[i];
  sort(all(x));
  x.erase(unique(all(x)), end(x));
  vector<int> xid(n);
  rep(i, n) xid[i] = lower_bound(all(x), X[i]) - begin(x);
  BinaryIndexedTree<ll> bit(n);
  BinaryIndexedTree<int> cnt(n);
  rep(i, n) {
    bit.add(xid[i], X[i]);
    cnt.add(xid[i], 1);
  }
  vector<int> id(n);
  rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    if(V[i] == V[j]) return X[i] > X[j];
    else return V[i] > V[j];
  });
  ll ans = 0;
  for(int i: id) {
    // cout << cnt.sum(xid[i]) << '*' <<  X[i] << '-' << bit.sum(xid[i]) << endk;
    ans += cnt.sum(xid[i]) * X[i] - bit.sum(xid[i]);
    bit.add(xid[i], -X[i]);
    cnt.add(xid[i], -1);
    // cout << ans << endk;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
