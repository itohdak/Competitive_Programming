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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<string> S(n); rep(i, n) cin >> S[i];
  auto bfs = [&](int s, int n) {
    vector<int> dist(n*n, inf);
    queue<pair<int, int>> q;
    int cost = (S[0][0] != 'a');
    q.push({s, cost});
    dist[s] = cost;
    vector<bool> vis(n*n);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] < d) continue;
      vis[cur] = true;
      int dx[] = {0, 1};
      int dy[] = {1, 0};
      int x = cur/n, y = cur%n;
      rep(k, 2) {
        int nx = x+dx[k], ny = y+dy[k];
        int ne = nx*n+ny;
        if(nx >= n || ny >= n) continue;
        int cost = (S[nx][ny] != 'a');
        if(dist[ne] > dist[cur] + cost) {
          dist[ne] = dist[cur] + cost;
          q.push({ne, dist[ne]});
        }
      }
    }
    return dist;
  };
  auto dist = bfs(0, n);
  // TODO
  set<int> s;
  int mx = -1;
  rep(i, n) rep(j, n) {
    int cur = i*n+j;
    if(dist[cur] == k) {
      if(mx < i+j) {
        mx = i+j;
        s.clear();
      }
      if(mx == i+j) {
        s.insert(i*n+j);
      }
    }
  }
  if(dist[n*n-1] < k) {
    cout << string(2*n-1, 'a') << endk;
    return 0;
  }
  string ans(mx+1, 'a');
  if(mx == -1) {
    ans += S[0][0];
    s.insert(0);
    mx++;
  }
  auto bfs2 = [&](set<int> s, int n) {
    string ret;
    rep(i, 2*n-1-mx) {
      map<char, set<int>> next;
      int dx[] = {1, 0};
      int dy[] = {0, 1};
      for(int cur: s) {
        int x = cur/n;
        int y = cur%n;
        rep(k, 2) {
          int nx = x+dx[k];
          int ny = y+dy[k];
          int ne = nx*n+ny;
          if(nx >= n || ny >= n) continue;
          next[S[nx][ny]].insert(ne);
        }
      }
      if(i == 2*n-1-mx-1) break;
      auto& [mnc, ns] = *next.begin();
      ret += mnc;
      s = ns;
    }
    return ret;
  };
  ans += bfs2(s, n);
  cout << ans << endk;
  return 0;
}
