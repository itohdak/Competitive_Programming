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
  vector<int> A(16); rep(i, 16) cin >> A[i];
  ll ans = 0;
  rep(i, 1<<16) {
    vector<bool> use(36);
    bool ok = true;
    rep(j, 16) {
      if((i>>j)&1) {
        int x = j/4, y = j%4;
        int ne = (x+1)*6+(y+1);
        use[ne] = true;
      } else {
        if(A[j]) ok = false;
      }
    }
    if(!ok) continue;
    UnionFind uf(36);
    rep(j, 36) {
      int x = j/6, y = j%6;
      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, 1, 0, -1};
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx < 0 || ny < 0 || nx >= 6 || ny >= 6) continue;
        int ne = nx*6+ny;
        if(use[j] && use[ne]) uf.unite(j, ne);
        if(!use[j] && !use[ne]) uf.unite(j, ne);
      }
    }
    set<int> st;
    set<int> st2;
    rep(j, 36) {
      if(use[j]) st.insert(uf.root(j));
      st2.insert(uf.root(j));
    }
    if(st.size() == 1 && st2.size() == 2) ans++;
  }
  cout << ans << endk;
  return 0;
}
