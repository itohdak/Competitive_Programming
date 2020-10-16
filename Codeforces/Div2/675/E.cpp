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

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<pair<int, string>> ans(n);
  string tmp;
  vector<int> pos;
  vector<char> prev;
  prev.push_back(char('a'-1));
  auto answer = [&]() {
    int sz = tmp.size();
    string a;
    if(sz > 10) {
      rep(i, 5) a += tmp[sz-1-i];
      a += "...";
      rrep(i, 2) a += tmp[i];
    } else {
      rrep(i, sz) a += tmp[i];
    }
    return make_pair(sz, a);
  };
  auto can_remove = [&]() {
    assert(tmp.back() == prev.back());
    return *(++prev.rbegin()) < prev.back();
  };
  rrep(i, n) {
    tmp += s[i];
    pos.push_back(i);
    if(prev.back() != s[i]) prev.push_back(s[i]);
    int sz = tmp.size();
    if(sz < 2) {
      ans[i] = answer();
      continue;
    }
    if(tmp[sz-1] == tmp[sz-2] && pos[sz-1]+1 == pos[sz-2] && can_remove()) {
      tmp.pop_back();
      tmp.pop_back();
      pos.pop_back();
      pos.pop_back();
      if(prev.back() != tmp.back()) prev.pop_back();
    }
    ans[i] = answer();
  }
  rep(i, n) cout << ans[i].first << ' ' << ans[i].second << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
