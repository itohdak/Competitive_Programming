#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
void solve() {
  int n, m; cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<vector<int>>> cnt(4, vector<vector<int>>(n, vector<int>(m)));
  // left, right, up, down
  int k = 0;
  rep(i, n) {
    char c = ' ';
    int tmp = 0;
    rep(j, m) {
      if(S[i][j] == c) {
        cnt[k][i][j] = tmp;
        tmp++;
      } else {
        cnt[k][i][j] = 0;
        c = S[i][j];
        tmp = 1;
      }
    }
  }
  k++;
  rep(i, n) {
    char c = ' ';
    int tmp = 0;
    rrep(j, m) {
      if(S[i][j] == c) {
        cnt[k][i][j] = tmp;
        tmp++;
      } else {
        cnt[k][i][j] = 0;
        c = S[i][j];
        tmp = 1;
      }
    }
  }
  k++;
  rep(j, m) {
    char c = ' ';
    int tmp = 0;
    rep(i, n) {
      if(S[i][j] == c) {
        cnt[k][i][j] = tmp;
        tmp++;
      } else {
        cnt[k][i][j] = 0;
        c = S[i][j];
        tmp = 1;
      }
    }
  }
  k++;
  rep(j, m) {
    char c = ' ';
    int tmp = 0;
    rrep(i, n) {
      if(S[i][j] == c) {
        cnt[k][i][j] = tmp;
        tmp++;
      } else {
        cnt[k][i][j] = 0;
        c = S[i][j];
        tmp = 1;
      }
    }
  }
  // rep(k, 4) cout << cnt[k] << "\n";
  vector<vector<int>> mx(n, vector<int>(m, inf));
  rep(i, n) rep(j, m) {
    rep(k, 4) mx[i][j] = min(cnt[k][i][j], mx[i][j]);
  }
  // cout << mx << endl;
  ll ans = 0;
  rep(i, n) {
    SegmentTree<int> seg(m, [](int a, int b) { return min(a, b); }, INT_MAX);
    SegmentTree<int> seg2(m, [](int a, int b) { return min(a, b); }, INT_MAX);
    rep(j, m) {
      seg.update(j, mx[i][j]+j);
      seg2.update(j, mx[i][j]-j);
    }
    rep(j, m) {
      int l = seg2.query(j-mx[i][j], j+1)+j;
      int r = seg.query(j, j+mx[i][j]+1)-j;
      ans += min(l, r)+1;
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
