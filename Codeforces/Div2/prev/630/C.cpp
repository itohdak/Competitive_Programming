#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

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
  int N, K;
  string S;
  cin >> N >> K >> S;
  int ans = 0;
  UnionFind uf(N);
  rep(i, N) {
    int c = 0;
    set<int> idx;
    idx.insert(i);
    if(i+K<N) idx.insert(i+K);
    if(N-1-i>=0) idx.insert(N-1-i);
    if(N-1-i-K>=0) idx.insert(N-1-i-K);
    for(int j: idx) uf.unite(*idx.begin(), j);
  }
  vector<set<int> > vse(N);
  rep(i, N) vse[uf.root(i)].insert(i);
  for(auto se: vse) {
    map<char, int> mp;
    for(int i: se) {
      if(!mp.count(S[i])) mp[S[i]] = 0;
      mp[S[i]]++;
    }
    int mx = 0;
    for(auto m: mp) mx = max(m.second, mx);
    ans += se.size() - mx;
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
