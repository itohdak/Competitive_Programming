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

void solve() {
  int n, k, x, d;
  cin >> n >> k >> x >> d;
  int m; cin >> m;
  vector<tuple<int, int, int>> A;
  rep(i, m) {
    int p, l, r; cin >> p >> l >> r;
    p--; l--;
    A.push_back({l, +1, p});
    A.push_back({r, -1, p});
  }
  sort(all(A));
  vector<int> cnt(n);
  int l = 0, r = 0;
  int lpos = 0, rpos = 0;
  BinaryIndexedTree<int> bit(m+1), bit2(m+1);
  bit.add(0, n);
  while(r < x) {
    while(rpos < 2*m && get<0>(A[rpos]) < r) {
      auto [pos, s, p] = A[rpos];
      if(s == +1) {
        bit.add(cnt[p], -1);
        bit2.add(cnt[p], -cnt[p]);
        cnt[p]++;
        bit.add(cnt[p], +1);
        bit2.add(cnt[p], +cnt[p]);
      }
      rpos++;
    }
    r++;
  }
  auto func = [&]() {
    auto bsearch = [&]() {
      auto test = [&](int r) {
        return bit.sum(0, r) >= k;
      };
      int ok = m+1, ng = 0;
      while(ok-ng>1) {
        int mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    auto ok = bsearch();
    int ret = bit2.sum(0, ok-1) + (k-bit.sum(0, ok-1))*(ok-1);
    // cout << l << ' ' << r << ' ' << cnt << ' ' << bit2.sum(0, ok-1) << ' ' << ok << ' ' << ret << endk;
    return ret;
  };
  int ans = m;
  while(r < d) {
    chmin(ans, func());
    l++;
    while(lpos < 2*m && get<0>(A[lpos]) <= l) {
      auto [pos, s, p] = A[lpos];
      if(s == -1) {
        bit.add(cnt[p], -1);
        bit2.add(cnt[p], -cnt[p]);
        cnt[p]--;
        bit.add(cnt[p], +1);
        bit2.add(cnt[p], +cnt[p]);
      }
      lpos++;
    }
    while(rpos < 2*m && get<0>(A[rpos]) < r) {
      auto [pos, s, p] = A[rpos];
      if(s == +1) {
        bit.add(cnt[p], -1);
        bit2.add(cnt[p], -cnt[p]);
        cnt[p]++;
        bit.add(cnt[p], +1);
        bit2.add(cnt[p], +cnt[p]);
      }
      rpos++;
    }
    r++;
  }
  chmin(ans, func());
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
