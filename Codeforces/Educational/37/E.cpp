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
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

set<int> se;
vector<set<int> > G;
vector<int> ans;
void dfs(int v) {
  se.erase(v);
  int tmp = 0;
  while(!se.empty()) {
    auto itr = se.upper_bound(tmp);
    if(itr == se.end()) break;
    tmp = *itr;
    if(!G[v].count(tmp)) {
      se.erase(tmp);
      ans[ans.size()-1]++;
      dfs(tmp);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, N) se.insert(i);
  G = vector<set<int> >(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  int comp = 0;
  rep(i, N) {
    if(se.count(i)) {
      comp++;
      ans.push_back(1);
      dfs(i);
    }
  }
  cout << comp << endl;
  sort(all(ans));
  for(int a: ans) cout << a << ' '; cout << endl;
  return 0;
}

