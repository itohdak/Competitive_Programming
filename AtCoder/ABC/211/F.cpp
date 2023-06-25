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

struct S {
  int val;
};
struct F {
  int d;
};
S op(S a, S b) {
  return S{a.val+b.val};
}
S e() {
  return S{0};
}
S mapping(F f, S x) {
  return S{f.d+x.val};
}
F composition(F f, F g) {
  return F{f.d+g.d};
}
F id() {
  return F{0};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  int mx = 100005;
  vector<vector<pair<int, int>>> P(n);
  vector<pair<int, tuple<int, int, int>>> Lall;
  rep(i, n) {
    int m; cin >> m;
    P[i].assign(m, pair<int, int>());
    for(auto& [x, y]: P[i]) {
      cin >> x >> y;
    }
    vector<pair<int, pair<int, int>>> L;
    rep(j, m) {
      auto [x1, y1] = P[i][j];
      auto [x2, y2] = P[i][(j+1)%m];
      if(x1 == x2) {
        L.push_back({x1, {min(y1, y2), max(y1, y2)}});
      }
    }
    sort(all(L));
    vector<S> init(mx, S{0});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
    for(auto [x, p]: L) {
      auto [y1, y2] = p;
      if(seg.prod(y1, y2).val) {
        Lall.push_back({x, {y1, y2, -1}});
        seg.apply(y1, y2, F{-1});
      } else {
        Lall.push_back({x, {y1, y2, 1}});
        seg.apply(y1, y2, F{1});
      }
    }
  }
  int q; cin >> q;
  vector<pair<int, int>> Q(q);
  for(auto& [x, y]: Q) {
    cin >> x >> y;
    Lall.push_back({x, {0, 0, 0}});
  }
  sort(all(Lall));
  vector<int> ids(q);
  iota(all(ids), 0);
  sort(all(ids), [&](int i, int j) {
    return Q[i].first < Q[j].first;
  });
  vector<int> ans(q);
  {
    int sz = Lall.size();
    vector<S> init(mx, S{0});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
    int i = 0;
    int j = 0;
    while(i < sz) {
      int l = i;
      while(i < sz && Lall[i].first == Lall[l].first) {
        auto [y1, y2, t] = Lall[i].second;
        if(t == 1) {
          seg.apply(y1, y2, F{1});
        } else if(t == -1) {
          seg.apply(y1, y2, F{-1});
        }
        i++;
      }
      // cout << Lall[l].first << endk;
      // rep(j, 10) cout << seg.prod(j, j+1).val << ' ';
      // cout << endk;
      while(j < q && (i == sz || Q[ids[j]].first < Lall[i+1].first)) {
        int y = Q[ids[j]].second;
        ans[ids[j]] = seg.prod(y, y+1).val;
      // cout << "q " << Q[ids[j]] << endk;
      // rep(k, 10) cout << seg.prod(k, k+1).val << ' ';
      // cout << endk;
        j++;
      }
    }
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
