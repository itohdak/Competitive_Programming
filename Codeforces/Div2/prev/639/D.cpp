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

int N, M;
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
int pos2int(int x, int y) {
  return x * M + y;
}
int main() {
  cin >> N >> M;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  UnionFind uf(M);
  bool ok = true;
  int white1=0, white2=0;
  rep(i, N) {
    int flag = 0;
    int pos;
    rep(j, M) {
      if(S[i][j] == '#') {
        if(flag == 0) {
          flag++;
          pos = j;
        }
        else if(flag == 1) uf.unite(j, pos);
        else if(flag == 2) flag++;
      } else {
        if(flag == 1) flag++;
      }
    }
    if(flag == 0) white1++;
    if(flag == 3) ok = false;
  }
  rep(j, M) {
    int flag = 0;
    rep(i, N) {
      if(S[i][j] == '#') {
        if(flag == 0) flag++;
        else if(flag == 2) flag++;
      } else {
        if(flag == 1) flag++;
      }
    }
    if(flag == 0) white2++;
    if(flag == 3) ok = false;
  }
  unordered_set<int> se;
  rep(i, M) se.insert(uf.root(i));
  if(ok) {
    if(white1==0 && white2==0) cout << se.size() << endl;
    else if(white1>0 && white2>0) cout << se.size()-white2 << endl;
    else cout << -1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
