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

namespace atcoder {
  namespace internal {

    template <class E> struct csr {
      std::vector<int> start;
      std::vector<E> elist;
      csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
          start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
          start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
          elist[counter[e.first]++] = e.second;
        }
      }
    };

    struct scc_graph {
    public:
     scc_graph(int n) : _n(n) {}

      int num_vertices() { return _n; }

      void add_edge(int from, int to) { edges.push_back({from, {to}}); }

      std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
          low[v] = ord[v] = now_ord++;
          visited.push_back(v);
          for (int i = g.start[v]; i < g.start[v + 1]; i++) {
            auto to = g.elist[i].to;
            if (ord[to] == -1) {
              self(self, to);
              low[v] = std::min(low[v], low[to]);
            } else {
              low[v] = std::min(low[v], ord[to]);
            }
          }
          if (low[v] == ord[v]) {
            while (true) {
              int u = visited.back();
              visited.pop_back();
              ord[u] = _n;
              ids[u] = group_num;
              if (u == v) break;
            }
            group_num++;
          }
        };
        for (int i = 0; i < _n; i++) {
          if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
          x = group_num - 1 - x;
        }
        return {group_num, ids};
      }

      std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
          groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
          groups[ids.second[i]].push_back(i);
        }
        return groups;
      }

    private:
      int _n;
      struct edge {
        int to;
      };
      std::vector<std::pair<int, edge>> edges;
    };

  }  // namespace internal

  struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
      int n = internal.num_vertices();
      assert(0 <= from && from < n);
      assert(0 <= to && to < n);
      internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
  };
}  // namespace atcoder

void solve() {
  int n, m; cin >> n >> m;
  atcoder::scc_graph g(n);
  vector<pair<int, int>> E(m);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    E[i] = {a, b};
    g.add_edge(a, b);
  }
  auto scc = g.scc();
  int sz = scc.size();
  vector<vector<int>> G(sz);
  vector<int> id(n);
  rep(i, sz) for(auto v: scc[i]) id[v] = i;
  for(auto [a, b]: E) if(id[a] != id[b]) G[id[a]].push_back(id[b]);
  vector<int> ans(sz);
  vector<bool> loop(sz);
  rep(i, sz) if(scc[i].size() > 1) loop[i] = true;
  for(auto [a, b]: E) if(a == b) loop[id[a]] = true;
  chmax(ans[id[0]], (loop[id[0]] ? 3 : 1));
  rep(cur, sz) {
    for(int ne: G[cur]) {
      if(ans[cur] == 1) {
        if(ans[ne] == 0) ans[ne] = 1;
        else if(ans[ne] == 1) ans[ne] = 2;
      } else if(ans[cur] > 1) {
        chmax(ans[ne], ans[cur]);
      }
      if(ans[ne] && loop[ne]) ans[ne] = 3;
    }
  }
  rep(i, n) cout << (ans[id[i]] == 3 ? -1 : ans[id[i]]) << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
