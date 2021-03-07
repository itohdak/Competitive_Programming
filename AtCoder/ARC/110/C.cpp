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
  int n; cin >> n;
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> id(n); rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return P[i] > P[j];
  });
  BinaryIndexedTree<int> bit(n);
  ll sum = 0;
  for(int i: id) {
    sum += bit.sum(i);
    bit.add(i, 1);
  }
  if(sum == n-1) {
    vector<int> ans;
    int mn = n-1;
    for(int i: id) {
      for(int j=i; j<mn; j++) {
        ans.push_back(j);
        swap(P[j], P[j+1]);
      }
      chmin(mn, i);
    }
    bool ok = true;
    rep(i, n) if(P[i] != i+1) ok = false;
    if(ok) for(int a: ans) cout << a+1 << endk;
    else cout << -1 << endk;
  } else {
    cout << -1 << endk;
  }
  return 0;
}
