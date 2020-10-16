#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<int> A;
vector<vector<int> > G;
vector<vector<ll> > dp;
int N, K;
void dfs(int tmp, int par) {
  for(int ne: G[tmp]) {
    if(ne != par) {
      dfs(ne, tmp);
    }
  }
  rep(dep, N) {
    if(dep == 0) { // include self in the subset
      ll sum = 0;
      for(int ne: G[tmp]) {
        if(ne == par) continue;
        sum += dp[ne][K-1];
      }
      dp[tmp][0] = A[tmp] + sum;
    } else {
      for(int ne: G[tmp]) {
        if(ne == par) continue;
        ll sum = 0;
        for(int other: G[tmp]) {
          if(other == ne || ne == par) continue;
          // tmpからの距離はdep-1以上で，かつ，tmpをはさんだ他の子ノードとの距離がK-1以上になる条件
          sum += dp[other][max(dep-1, K-dep-1)];
        }
        dp[tmp][dep] = max(dp[tmp][dep], dp[ne][dep-1] + sum);
      }
    }
  }
  for(int dep=N-1; dep>0; dep--) {
    dp[tmp][dep-1] = max(dp[tmp][dep-1], dp[tmp][dep]);
  }
}

int main() {
  cin >> N >> K;
  K++;
  A = vector<int>(N);
  rep(i, N) cin >> A[i];
  G = vector<vector<int> >(N);
  rep(i, N-1) {
    int from, to;
    cin >> from >> to;
    from--, to--;
    G[from].push_back(to);
    G[to].push_back(from);
  }
  dp = vector<vector<ll> >(N, vector<ll>(N+5, 0));
  dfs(0, -1);
  cout << dp[0][0] << endl;
  return 0;
}

