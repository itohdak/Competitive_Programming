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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  map<ll, queue<int>> mp;
  rep(i, n) mp[A[i]].push(i);
  vector<int> ids;
  for(auto [_, q]: mp) {
    if(ids.empty()) {
      while(q.size()) {
        ids.push_back(q.front());
        q.pop();
      }
    } else {
      queue<int> qtmp;
      while(q.size() && q.front() <= ids.back()) {
        qtmp.push(q.front());
        q.pop();
      }
      while(q.size()) {
        ids.push_back(q.front());
        q.pop();
      }
      while(qtmp.size()) {
        ids.push_back(qtmp.front());
        qtmp.pop();
      }
    }
  }
  assert(ids.size() == n);
  ll ans = 0;
  BinaryIndexedTree<int> bit(n);
  rep(i, n) bit.add(i, 1);
  rep(i, n) {
    if(i) {
      if(ids[i] > ids[i-1]) {
        ans += bit.sum(ids[i]) - bit.sum(ids[i-1]);
      } else {
        ans += bit.sum(n-1) - bit.sum(ids[i-1]);
        ans += bit.sum(ids[i]);
      }
      bit.add(ids[i], -1);
    } else {
      ans += bit.sum(ids[i]);
      bit.add(ids[i], -1);
    }
  }
  cout << ans << endk;
  return 0;
}
