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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll ans = 0;
  ll ans2 = 0;
  {
    vector<int> id(n);
    rep(i, n) id[i] = i;
    sort(all(id), [&](int i, int j) {
      return A[i] > A[j];
    });
    int i = 0;
    BinaryIndexedTree<int> bit(n);
    while(i < n) {
      ll tmp = A[id[i]];
      vector<int> tmpv;
      while(i < n && tmp == A[id[i]]) {
        tmpv.push_back(id[i]);
        ans2 += bit.sum(id[i]);
        i++;
      }
      for(int i: tmpv) {
        bit.add(i, 1);
      }
    }
  }
  vector<ll> diff(31);
  auto dfs = [&](auto dfs, int d, vector<int>& v) -> void {
    if(d == -1) return;
    vector<int> L, R;
    ll cnt = 0;
    ll one = 0, zero = 0;
    for(int i: v) {
      if((A[i]>>d)&1) {
        one++;
        L.push_back(i);
      } else {
        zero++;
        cnt += one;
        R.push_back(i);
      }
    }
    ll sum = one * zero;
    diff[d] += (sum-cnt)-cnt;
    if(!L.empty()) dfs(dfs, d-1, L);
    if(!R.empty()) dfs(dfs, d-1, R);
  };
  vector<int> id(n); rep(i, n) id[i] = i;
  dfs(dfs, 30, id);
  rrep(d, 31) {
    if(diff[d] < 0) {
      ans += (1LL<<d);
      ans2 += diff[d];
    }
  }
  cout << ans2 << ' ' << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
