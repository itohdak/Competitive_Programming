#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> cnt(n+1);
  vector<int> diff(n, inf); // 猶予
  vector<bool> ok(n);
  map<int, vector<int>> mp;
  rep(i, n) {
    cnt[i+1] = cnt[i];
    if(A[i] <= i+1 && i+1-A[i]<=cnt[i]) {
      ok[i] = true;
      diff[i] = cnt[i]-(i+1-A[i]);
      mp[diff[i]].push_back(i);
      cnt[i+1]++;
    }
  }
  vector<int> X(q), Y(q), id(q);
  rep(i, q) {
    cin >> X[i] >> Y[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return X[i] < X[j];
  });
  vector<int> ans(q);
  BinaryIndexedTree<int> bit(n), bit2(n);
  rep(i, n) if(ok[i]) bit.add(diff[i], 1);
  int prev = 0;
  int lb = 0;
  rep(i, q) {
    REP(j, prev, X[id[i]]) {
      if(ok[j]) {
        lb++;
        for(auto k: mp[lb-1]) bit2.add(k, 1);
      }
      bit.add(diff[j], -1);
    }
    cout << id[i] << ' '
         << bit.sum(n-1) << ' '
         << (lb==0 ? 0 : bit.sum(lb-1)) << ' '
         << (cnt[n]-cnt[n-Y[id[i]]]) << endk;
    ans[id[i]] = bit.sum(n-1) - (lb==0 ? 0 : bit.sum(lb-1)) - (cnt[n]-cnt[n-Y[id[i]]] - (bit2.sum(n-1) - bit2.sum(n-1-Y[id[i]])));
    prev = X[id[i]];
  }
  rep(i, q) cout << ans[i] << endk;
  cout << diff << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
