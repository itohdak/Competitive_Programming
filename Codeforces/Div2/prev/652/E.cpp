#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> W(n);
  rep(i, n) cin >> W[i];
  vector<vector<int>> X(m, vector<int>(2));
  vector<int> cnt(n);
  vector<set<int>> G(n);
  rep(i, m) {
    rep(j, 2) {
      cin >> X[i][j];
      X[i][j]--;
      cnt[X[i][j]]++;
      G[X[i][j]].insert(i);
    }
  }
  priority_queue<pair<int, int>> q;
  vector<int> S(n);
  rep(i, n) {
    S[i] = W[i] - cnt[i];
    if(S[i] >= 0) q.emplace(S[i], i);
  }
  int rem = m;
  vector<int> ans;
  while(rem > 0 && !q.empty()) {
    // cout << rem << ' ' << q.size() << endl;
    int v = q.top().first;
    int id = q.top().second;
    q.pop();
    vector<int> add;
    for(int i: G[id]) {
      rem--;
      rep(j, 2) {
        if(X[i][j] != id) {
          G[X[i][j]].erase(i);
          S[X[i][j]]++;
          if(S[X[i][j]] == 0) add.push_back(X[i][j]);
        }
      }
      ans.push_back(i);
    }
    G[id].clear();
    for(int i: add) q.emplace(S[i], i);
  }
  if(rem > 0) {
    cout << "DEAD" << "\n";
  } else {
    reverse(all(ans));
    cout << "ALIVE" << "\n";
    for(int a: ans) cout << a+1 << ' ';
    cout << "\n";
  }
  return 0;
}
