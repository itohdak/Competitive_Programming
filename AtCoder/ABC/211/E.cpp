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

#define MAX_N 300005

class UnionFind
{
public:
  int par[MAX_N];
  int depth[MAX_N];
  int nGroup[MAX_N];

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<string> S(n); rep(i, n) cin >> S[i];
  int ans = 0;
  REP(h, 1, k+1) { // 高さhの連結成分
    int w = k-h+1; // 横はw以下
    if(w <= 0) continue;
    rep(i, 1<<(h*w)) {
      if(__builtin_popcount(i) != k) continue;
      vector<vector<bool>> A(h, vector<bool>(w));
      rep(j, h*w) {
        if((i>>j)&1) {
          A[j/w][j%w] = true;
        }
      }
      UnionFind uf(h*w);
      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, 1, 0, -1};
      rep(x, h) rep(y, w) {
        if(A[x][y]) {
          rep(_k, 4) {
            int nx = x+dx[_k], ny = y+dy[_k];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(A[nx][ny]) uf.unite(x*w+y, nx*w+ny);
          }
        }
      }
      int root = -1;
      bool ok = true;
      rep(x, h) rep(y, w) {
        if(!A[x][y]) continue;
        if(root != -1 && root != uf.root(x*w+y)) ok = false;
        root = uf.root(x*w+y);
      }
      if(!ok) continue;
      ok = false;
      rep(y, w) if(A[0][y]) ok = true;
      if(!ok) continue;
      ok = false;
      rep(y, w) if(A[h-1][y]) ok = true;
      if(!ok) continue;
      ok = false;
      rep(x, h) if(A[x][0]) ok = true;
      if(!ok) continue;

      // cout << endk;
      // rep(x, h) {
      //   rep(y, w) cout << A[x][y];
      //   cout << endk;
      // }

      rep(x, n) rep(y, n) {
        ok = true;
        rep(dx, h) {
          rep(dy, w) {
            if(!A[dx][dy]) continue;
            if(x+dx >= n || y+dy >= n || S[x+dx][y+dy] == '#') {
              ok = false;
              break;
            }
          }
          if(!ok) break;
        }
        if(ok) ans++;
      }
    }
  }
  cout << ans << endk;
  return 0;
}
