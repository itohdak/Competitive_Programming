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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> X(n), Y(n), T(n);
  rep(i, n) {
    cin >> X[i] >> Y[i] >> T[i];
  }
  map<int, vector<pair<int, int>>> mpX, mpY;
  rep(i, n) {
    mpX[X[i]].push_back({Y[i], i});
    mpY[Y[i]].push_back({X[i], i});
  }
  UnionFind uf(n+1);
  int cnt = n+1;
  for(auto& [x, v]: mpX) {
    sort(all(v));
    rep(i, v.size()-1) {
      if(i+1 < v.size() && v[i].first+k >= v[i+1].first) {
        if(!uf.same(v[i].second, v[i+1].second)) {
          cnt--;
          uf.unite(v[i].second, v[i+1].second);
        }
      }
    }
  }
  for(auto& [y, v]: mpY) {
    sort(all(v));
    rep(i, v.size()-1) {
      if(i+1 < v.size() && v[i].first+k >= v[i+1].first) {
        if(!uf.same(v[i].second, v[i+1].second)) {
          cnt--;
          uf.unite(v[i].second, v[i+1].second);
        }
      }
    }
  }
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return T[i] < T[j];
  });
  int tmp = 0;
  rep(i, n+1) {
    while(tmp < n && T[id[tmp]] <= i) {
      if(!uf.same(id[tmp], n)) {
        cnt--;
        uf.unite(id[tmp], n);
      }
      tmp++;
    }
    if(cnt-1 <= i+1) {
      cout << i << endk;
      break;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
