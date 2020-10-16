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

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
public:
  SparseTable() : SparseTable(0) {}
  SparseTable(int n) : SparseTable(vector<vector<S>>(n, e())) {}
  SparseTable(const vector<vector<S>>& v) : h(int(v.size())), w(int(v[0].size())) {
    logH = logW = 1;
    while(1LL<<logH < h) logH++;
    while(1LL<<logW < w) logW++;
    init(v);
  }
  void init(const vector<vector<S>>& v) {
    d = vector<vector<vector<vector<S>>>>(logH, vector<vector<vector<S>>>(h, vector<vector<S>>(logW, vector<S>(w, e()))));
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) d[0][i][0][j] = v[i][j];
      for(int logj=1; logj<logW; logj++) {
        for(int j=0; j+(1<<(logj-1))<w; j++) {
          d[0][i][logj][j] = op(d[0][i][logj-1][j], d[0][i][logj-1][j+(1<<(logj-1))]);
        }
      }
    }
    for(int logi=1; logi<logH; logi++) {
      for(int i=0; i+(1<<(logi-1))<h; i++) {
        for(int logj=0; logj<logW; logj++) {
          for(int j=0; j<w; j++) {
            d[logi][i][logj][j] = op(d[logi-1][i][logj][j], d[logi-1][i+(1<<(logi-1))][logj][j]);
          }
        }
      }
    }
  }
  S query(int x1, int y1, int x2, int y2) {
    assert(x2-x1 != 0);
    assert(y2-y1 != 0);
    int lenX = x2-x1;
    int lenY = y2-y1;
    int logX = 0, logY = 0;
    while(1LL<<(logX+1) <= lenX) logX++;
    while(1LL<<(logY+1) <= lenY) logY++;
    S res1 = op(d[logX][x1][logY][y1], d[logX][x1][logY][y2-(1<<logY)]);
    S res2 = op(d[logX][x2-(1<<logX)][logY][y1], d[logX][x2-(1<<logX)][logY][y2-(1<<logY)]);
    return op(res1, res2);
  }
private:
  int h, w, size, logH, logW;
  vector<vector<vector<vector<S>>>> d;
};
int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}
void solve() {
  int n, m; cin >> n >> m;
  int q; cin >> q;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<vector<vector<int>>> sum(4, vector<vector<int>>(n+1, vector<int>(m+1)));
  map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}};
  rep(i, n) rep(j, m) sum[mp[S[i][j]]][i+1][j+1]++;
  rep(i, n+1) rep(j, m) rep(k, 4) sum[k][i][j+1] += sum[k][i][j];
  rep(j, m+1) rep(i, n) rep(k, 4) sum[k][i+1][j] += sum[k][i][j];
  vector<vector<int>> cnt(n, vector<int>(m, inf));
  auto count = [&](int c, int i, int j, int l) {
    assert(0 <= i && i < n && 0 <= j && j < m);
    int ii = i, jj = j;
    switch(c) {
    case 0:
      break;
    case 1:
      jj = min(m-1, jj+l);
      break;
    case 2:
      ii = min(n-1, ii+l);
      jj = min(m-1, jj+l);
      break;
    case 3:
      ii = min(n-1, ii+l);
      break;
    }
    return sum[c][ii+1][jj+1] - sum[c][max(0, ii-l+1)][jj+1] - sum[c][ii+1][max(0, jj-l+1)] + sum[c][max(0, ii-l+1)][max(0, jj-l+1)];
  };
  rep(i, n) rep(j, m) rep(k, 4) {
    auto bsearch = [&](int c) {
      auto test = [&](int t) {
        return count(c, i, j, t) == 1LL*t*t;
      };
      int ok = 0, ng = inf;
      while(ng-ok>1) {
        int mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    chmin(cnt[i][j], bsearch(k));
  }
  SparseTable<int, op, e> seg(cnt);
  rep(_, q) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--;
    auto bsearch = [&]() {
      auto test = [&](int t) {
        return seg.query(r1+t-1, c1+t-1, r2-t, c2-t) >= t;
      };
      int ok = 0, ng = min((r2-r1)/2, (c2-c1)/2)+1;
      while(ng-ok>1) {
        int mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    int res = bsearch();
    cout << 4 * res * res << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
