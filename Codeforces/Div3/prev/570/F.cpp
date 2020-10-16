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

#define MAX_N 200005

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
  int n; cin >> n;
  vector<ll> A(n);
  map<ll, vector<int>> mp;
  rep(i, n) {
    cin >> A[i];
    mp[A[i]].push_back(i);
  }
  UnionFind uf(n);
  for(auto ele: mp) {
    int top = *ele.second.begin();
    for(int i: ele.second) uf.unite(i, top);
  }
  for(auto ele: mp) {
    int i = ele.first;
    int top = *ele.second.begin();
    for(int j=2; i*j<=200000; j++) {
      if(mp.count(i*j)) {
        uf.unite(top, *mp[i*j].begin());
      }
    }
  }
  vector<int> mx(n);
  rep(i, n) {
    chmax(mx[uf.root(i)], A[i]);
    cout << uf.root(i) << ' ';
  }
  cout << endk;
  sort(all(mx));
  cout << accumulate(begin(mx), begin(mx)+min(n, 3), 0LL) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
