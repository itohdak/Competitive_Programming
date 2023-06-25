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
  int n, m, q; cin >> n >> m >> q;
  vector<int> T(q), X(q), Y(q);
  vector<int> val;
  val.push_back(0);
  rep(i, q) {
    cin >> T[i] >> X[i] >> Y[i];
    X[i]--;
    val.push_back(Y[i]);
  }
  sort(all(val));
  val.erase(unique(all(val)), end(val));
  auto id = [&](int v) -> int {
    return lower_bound(all(val), v) - begin(val);
  };
  int len = val.size();
  BinaryIndexedTree<int> cntA(len), cntB(len);
  cntA.add(0, n); cntB.add(0, m);
  BinaryIndexedTree<ll> sumA(len), sumB(len);
  ll ans = 0;
  vector<int> A(n), B(m);
  rep(i, q) {
    int t = T[i], x = X[i], y = Y[i];
    if(t == 1) {
      int a = A[x];
      int idy = id(y), ida = id(a);
      if(y > a) {
        int cnt1 = cntB.sum(0, ida);
        int cnt2 = cntB.sum(ida, idy);
        ll sum2 = sumB.sum(ida, idy);
        ans += 1LL*(y-a)*cnt1 + 1LL*y*cnt2 - sum2;
      } else {
        int cnt1 = cntB.sum(0, idy);
        int cnt2 = cntB.sum(idy, ida);
        ll sum2 = sumB.sum(idy, ida);
        ans += 1LL*(y-a)*cnt1 + sum2 - 1LL*a*cnt2;
      }
      cntA.add(ida, -1);
      sumA.add(ida, -a);
      cntA.add(idy, 1);
      sumA.add(idy, y);
      A[x] = y;
    } else {
      int b = B[x];
      int idy = id(y), idb = id(b);
      if(y > b) {
        int cnt1 = cntA.sum(0, idb);
        int cnt2 = cntA.sum(idb, idy);
        ll sum2 = sumA.sum(idb, idy);
        ans += 1LL*(y-b)*cnt1 + 1LL*y*cnt2 - sum2;
      } else {
        int cnt1 = cntA.sum(0, idy);
        int cnt2 = cntA.sum(idy, idb);
        ll sum2 = sumA.sum(idy, idb);
        ans += 1LL*(y-b)*cnt1 + sum2 - 1LL*b*cnt2;
      }
      cntB.add(idb, -1);
      sumB.add(idb, -b);
      cntB.add(idy, 1);
      sumB.add(idy, y);
      B[x] = y;
    }
    cout << ans << endk;
    // rep(i, len) cout << val[i] << ' '; cout << endk;
    // rep(i, len) cout << cntA.sum(i, i+1) << ' '; cout << endk;
    // rep(i, len) cout << sumA.sum(i, i+1) << ' '; cout << endk;
    // rep(i, len) cout << cntB.sum(i, i+1) << ' '; cout << endk;
    // rep(i, len) cout << sumB.sum(i, i+1) << ' '; cout << endk;
  }
  return 0;
}
