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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  map<pair<int, int>, vector<ll>> mp;
  rep(c1, 4) rep(c2, 4) {
    mp[{min(c1, c2), max(c1, c2)}] = vector<ll>();
  }
  rep(i, n) {
    int c1, c2; ll v; cin >> c1 >> v >> c2;
    c1--; c2--;
    mp[{min(c1, c2), max(c1, c2)}].push_back(v);
  }
  map<pair<int, int>, vector<ll>> sum;
  map<pair<int, int>, int> cnt;
  for(auto& [p, v]: mp) {
    sort(all(v), greater<ll>());
    vector<ll> s(v.size()+1);
    rep(i, v.size()) s[i+1] = s[i] + v[i];
    sum[p] = s;
    cnt[p] = v.size();
  }
  // cout << mp << endl << sum << endl << cnt << endl;
  vector<pair<int, int>> P = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
  ll ans = 0;
  ll tmp = 0;
  vector<int> cnt2(4);
  vector<int> cnt3(6);
  UnionFind uf(4);
  auto dfs = [&](auto dfs, int i) -> void {
    if(i == 6) {
      int rem = 0;
      rep(j, 4) rem += cnt2[j]%2;
      uf.init(4);
      set<int> st;
      rep(j, 6) {
        if(cnt3[j]) {
          uf.unite(P[j].first, P[j].second);
          st.insert(P[j].first);
          st.insert(P[j].second);
        }
      }
      bool ok = true;
      for(int j: st) {
        if(!uf.same(j, *st.begin())) ok = false;
      }
      if(ok && rem <= 2) {
        // cout << cnt2 << endk;
        ll tmp2 = tmp;
        rep(j, 4) if(cnt2[j]) tmp2 += sum[{j, j}].back();
        chmax(ans, tmp2);
      }
      return;
    }
    set<int> kouho = {0, cnt[P[i]]-1, cnt[P[i]]};
    for(int j: kouho) {
      if(j < 0) continue;
      cnt2[P[i].first] += j;
      cnt2[P[i].second] += j;
      cnt3[i] += j;
      tmp += sum[P[i]][j];
      dfs(dfs, i+1);
      cnt2[P[i].first] -= j;
      cnt2[P[i].second] -= j;
      cnt3[i] -= j;
      tmp -= sum[P[i]][j];
    }
  };
  dfs(dfs, 0);
  rep(j, 4) chmax(ans, sum[{j, j}].back());
  cout << ans << endk;
  return 0;
}
