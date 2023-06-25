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

#define MAX_N 200

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
  int n, m; cin >> n >> m;
  vector<string> S(n); rep(i, n) cin >> S[i];
  int cnt = 0;
  rep(i, n) rep(j, m) {
    if(S[i][j] == '#') {
      UnionFind uf(n*m);
      S[i][j] = '.';
      rep(_i, n) rep(_j, m) {
        if(S[_i][_j] == '#') continue;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        rep(k, 4) {
          int nx = _i+dx[k], ny = _j+dy[k];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(S[nx][ny] == '#') continue;
          uf.unite(_i*m+_j, nx*m+ny);
        }
      }
      set<int> root;
      rep(_i, n) rep(_j, m) {
        if(S[_i][_j] == '#') continue;
        root.insert(uf.root(_i*m+_j));
      }
      if(root.size() == 1) cnt++;
      S[i][j] = '#';
    }
  }
  cout << cnt << endk;
  return 0;
}
