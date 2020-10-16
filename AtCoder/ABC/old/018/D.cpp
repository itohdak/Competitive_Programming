#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to;
  int score;
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;
  vector<vector<edge>> G(N);
  rep(i, R) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    G[x].push_back({y, z});
  }
  ll ans = 0;
  rep(i, 1<<N) {
    if(__builtin_popcount(i) != P) continue;
    vector<ll> score(M);
    rep(j, N) {
      if(i>>j&1) {
        for(edge e: G[j]) {
          score[e.to] += e.score;
        }
      }
    }
    // cout << i << ' ' << score << endl;
    sort(all(score), greater<ll>());
    ans = max(accumulate(score.begin(), score.begin()+Q, 0LL), ans);
  }
  cout << ans << endl;
  return 0;
}
