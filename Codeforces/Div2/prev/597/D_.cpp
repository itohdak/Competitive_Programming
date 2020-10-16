#include <bits/stdc++.h>
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

vector<vector<ll> > cost;
vector<pair<int, int> > conn;
vector<int> build;
ll prim(int N) {
  vector<ll> mincost(N, inf);
  vector<bool> used(N, false);
  vector<int> from(N);
  mincost[0] = 0;

  ll res = 0;
  while(true) {
    int v = -1;
    rep(u, N) { if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u; }
    if (v == -1) break; // all vertices are covered
    used[v] = true;
    res += mincost[v];
    if(v != 0) {
      if(v == N-1 || from[v] == N-1)
        build.push_back(min(v, from[v]));
      else
        conn.push_back(make_pair(v, from[v]));
    }
    rep(u, N) {
      if(cost[v][u] < mincost[u]) {
        mincost[u] =  cost[v][u];
        from[u] = v;
      }
    }
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > XY(N);
  vector<ll> C(N), K(N);
  rep(i, N) cin >> XY[i].first >> XY[i].second;
  rep(i, N) cin >> C[i];
  rep(i, N) cin >> K[i];
  cost = vector<vector<ll> >(N+1, vector<ll>(N+1));
  rep(i, N+1) REP(j, i+1, N+1) {
    if(j == N) {
      cost[i][j] = C[i];
      cost[j][i] = C[i];
    } else {
      ll c = (abs(XY[i].first - XY[j].first) + abs(XY[i].second - XY[j].second)) * (K[i] + K[j]);
      cost[i][j] = c;
      cost[j][i] = c;
    }
  }
  cout << prim(N+1) << endl;
  cout << build.size() << endl;
  for(auto b: build) cout << b+1 << ' ';
  cout << endl;
  cout << conn.size() << endl;
  for(auto c: conn) cout << c.first+1 << ' ' << c.second+1 << endl;
  return 0;
}

