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

struct Mo {
  using ADD = function< void(int) >;
  using DEL = function< void(int) >;
  using REM = function< void(int) >;

  int width;
  vector< int > left, right, order;
  vector< bool > v;

  Mo(int N, int Q) : width((int) sqrt(N)), order(Q), v(N) {
    iota(begin(order), end(order), 0);
  }

  void add(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  void run(const ADD &add, const DEL &del, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if(v[idx]) add(idx);
      else del(idx);
    };
    for(auto idx : order) {
      while(nl > left[idx]) push(--nl);
      while(nr < right[idx]) push(nr++);
      while(nl < left[idx]) push(nl++);
      while(nr > right[idx]) push(--nr);
      rem(idx);
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  int q; cin >> q;
  Mo mo(n, q);
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    mo.add(l, r);
  }
  vector<int> cnt(n);
  vector<int> ans(q);
  int tmp = 0;
  auto add = [&](int idx) {
    cnt[A[idx]]++;
    if(cnt[A[idx]]%2 == 0) tmp++;
  };
  auto del = [&](int idx) {
    cnt[A[idx]]--;
    if(cnt[A[idx]]%2 == 1) tmp--;
  };
  auto rem = [&](int idx) {
    ans[idx] = tmp;
  };
  mo.run(add, del, rem);
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
