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
const ll mod = 2;
// const ll mod2 = 998244353;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] ^ A[i];
  vector<vector<int>> v(n+1, vector<int>(n+1, 0));
  for(int l=1; l<=n; l++) {
    if(l == 1) rep(i, n) v[i][i+l] = A[i];
    else rep(i, n+1-l) v[i][i+l] = v[i][i+l-1] ^ v[i+1][i+l];
  }
  // rep(i, n) cout << v[i] << endk;
  SparseTable<int, op, e> st(v);
  int q; cin >> q;
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    cout << st.query(l, l, r+1, r+1) << endk;
  }
  return 0;
}
