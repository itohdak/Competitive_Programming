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
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> T(n);
  vector<pair<int, int>> topics;
  rep(i, n) {
    cin >> T[i];
    topics.emplace_back(T[i], i);
  }
  sort(all(topics));

  bool ok = true;
  vector<set<int>> neighbor(n);
  rep(i, n) {
    for(int j: G[i]) {
      if(T[j] < T[i]) neighbor[i].insert(T[j]);
      else if(T[j] == T[i]) ok = false;
    }
  }
  rep(i, n) if((int)neighbor[i].size() < T[i]-1) ok = false;

  if(ok) {
    for(auto t: topics) cout << t.second+1 << ' ';
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
