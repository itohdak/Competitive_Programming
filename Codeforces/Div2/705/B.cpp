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

pair<int, int> hm(string s) {
  assert(s[2] == ':');
  return {(s[0]-'0')*10+(s[1]-'0'), (s[3]-'0')*10+(s[4]-'0')};
}
void solve() {
  int h, m; cin >> h >> m;
  string s; cin >> s;
  auto [hh, mm] = hm(s);
  map<int, int> mp = {{0, 0}, {1, 1}, {2, 5}, {5, 2}, {8, 8}};
  while(true) {
    vector<int> tmp = {hh/10, hh%10, mm/10, mm%10};
    bool ok = true;
    for(int i: tmp) {
      if(!mp.count(i)) {
        ok = false;
        break;
      }
    }
    if(ok) {
      int hh2 = mp[mm%10]*10 + mp[mm/10];
      int mm2 = mp[hh%10]*10 + mp[hh/10];
      if(hh2 < h && mm2 < m) {
        cout << hh/10 << hh%10 << ":" << mm/10 << mm%10 << endk;
        return;
      }
    }
    mm++;
    if(mm == m) {
      mm = 0;
      hh++;
      if(hh == h) hh = 0;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
