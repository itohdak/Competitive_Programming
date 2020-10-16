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
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> hor, ver;
  ll ans = 1;
  rep(i, n) {
    int y, lx, rx;
    cin >> y >> lx >> rx;
    hor.push_back({y, lx, rx});
    if(lx == 0 && rx == 1000000) ans++;
  }
  rep(j, m) {
    int x, ly, ry;
    cin >> x >> ly >> ry;
    ver.push_back({ly, 1, x});
    ver.push_back({ry+1, -1, x});
    if(ly == 0 && ry == 1000000) ans++;
  }
  sort(all(hor));
  sort(all(ver));
  BinaryIndexedTree<int> bit(1000001);
  // bit.add(0, 1);
  // bit.add(1000000, 1);
  int j = 0;
  rep(i, n) {
    const auto [y, lx, rx] = hor[i];
    while(j < 2*m && get<0>(ver[j]) <= y) {
      bit.add(get<2>(ver[j]), get<1>(ver[j]));
      // cout << "add " << get<2>(ver[j]) << ' ' << get<1>(ver[j]) << endk;
      j++;
    }
    ans += bit.sum(rx) - (lx == 0 ? 0 : bit.sum(lx-1));
    // cout << y << ' ' << ans << ' ' << bit.sum(1000000) << endk;
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
