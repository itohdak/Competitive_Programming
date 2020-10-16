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

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  auto same = [](string s) {
    return s[0] == s[1];
  };
  if(same(s) && same(t)) {
    cout << "YES" << endk;
    rep(i, n) cout << "abc";
    cout << endk;
  } else if(same(s) || same(t)) {
    if(same(t)) swap(s, t);
    set<char> st = {'a', 'b', 'c'};
    st.erase(s[0]);
    st.erase(t[0]);
    st.erase(t[1]);
    cout << "YES" << endk;
    if(st.size() == 1) {
      if(s[0] == t[0]) {
        rep(i, n) cout << s[0] << *st.begin() << t[1];
        cout << endk;
      } else {
        rep(i, n) cout << t[0] << *st.begin() << s[0];
        cout << endk;
      }
    } else {
      reverse(all(t));
      rep(i, n) cout << s[0] << t;
      cout << endk;
    }
  } else {
    G = vector<vector<int>>(3);
    vis = vector<bool>(3);
    rep(i, 3) rep(j, 3) {
      if(i != j &&
         !((s[0]-'a')==i && (s[1]-'a')==j) &&
         !((t[0]-'a')==i && (t[1]-'a')==j)) G[i].push_back(j);
    }
    rep(i, 3) dfs(i);
    reverse(all(Tpl));
    cout << "YES" << endk;
    rep(i, 3) cout << string(n, 'a'+Tpl[i]);
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
