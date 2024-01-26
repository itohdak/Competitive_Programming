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
  int n; cin >> n;
  vector<int> L(n), R(n), A(n), B(n);
  rep(i, n) {
    cin >> L[i] >> R[i] >> A[i] >> B[i];
    L[i]--; A[i]--;
  }
  int q; cin >> q;
  vector<int> X(q);
  rep(i, q) {
    cin >> X[i];
    X[i]--;
  }
  vector<tuple<int, int, int>> C;
  rep(i, n) {
    C.push_back({L[i], 1, i});
    C.push_back({B[i], -1, i});
  }
  rep(i, q) {
    C.push_back({X[i], 2, i});
  }
  vector<int> P(q, -1);
  UnionFind uf(n);
  sort(all(C));
  set<int> st;
  int l = 0;
  while(l < C.size()) {
    int r = l;
    while(r < C.size() && get<0>(C[r]) == get<0>(C[l]) && get<1>(C[r]) == -1) {
      assert(st.count(get<2>(C[r])));
      st.erase(get<2>(C[r]));
      r++;
    }
    while(r < C.size() && get<0>(C[r]) == get<0>(C[l]) && get<1>(C[r]) == 1) {
      if(st.size()) uf.unite(*st.begin(), get<2>(C[r]));
      st.insert(get<2>(C[r]));
      r++;
    }
    while(r < C.size() && get<0>(C[r]) == get<0>(C[l]) && get<1>(C[r]) == 2) {
      if(st.size()) P[get<2>(C[r])] = *st.begin();
      r++;
    }
    l = r;
  }
  vector<int> mx(n);
  rep(i, n) {
    chmax(mx[uf.root(i)], B[i]-1);
  }
  rep(i, n) {
    mx[i] = mx[uf.root(i)];
  }
  rep(i, q) {
    if(P[i] == -1) {
      cout << X[i]+1 << ' ';
    } else {
      cout << max(X[i], mx[P[i]])+1 << ' ';
    }
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
