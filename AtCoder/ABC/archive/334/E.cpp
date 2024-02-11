#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

#define MAX_N 1010101

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

using mint = modint998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  UnionFind uf(h*w);
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if(S[i][j] == '.') continue;
    rep(k, 4) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '#') {
        uf.unite(i*w+j, nx*w+ny);
      }
    }
  }
  set<int> st;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') st.insert(uf.root(i*w+j));
  }
  int m = st.size();
  mint ans = 0;
  int cnt = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    set<int> st;
    rep(k, 4) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '#') {
        st.insert(uf.root({nx*w+ny}));
      }
    }
    ans += (m-st.size()+1);
    cnt++;
  }
  ans /= cnt;
  cout << ans.val() << endk;
  return 0;
}
