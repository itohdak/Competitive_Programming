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
  vector<ll> A(n);
  vector<int> id(n);
  rep(i, n) {
    cin >> A[i];
    id[i] = i;
  }
  BinaryIndexedTree<ll> bit(n);
  sort(all(id), [&](int i, int j) {
    return A[i] > A[j];
  });
  ll sum = 0;
  int i = 0;
  while(i < n) {
    vector<int> pos;
    ll a = A[id[i]];
    while(i < n && a == A[id[i]]) {
      pos.push_back(id[i]);
      sum += bit.sum(id[i]);
      i++;
    }
    for(int p: pos) {
      bit.add(p, 1);
    }
  }
  cout << (sum > 1LL*n*(n-1)/2-1 ? "NO" : "YES") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
