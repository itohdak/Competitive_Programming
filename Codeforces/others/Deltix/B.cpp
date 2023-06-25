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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  set<int> pos;
  rep(i, n-2) {
    if(s.substr(i, 3) == "abc") {
      pos.insert(i);
    }
  }
  rep(i, q) {
    int p; char c;
    cin >> p >> c;
    p--;
    for(int i=p-2; i<=p; i++) {
      if(i < 0 || i+3 > n) continue;
      if(s.substr(i, 3) == "abc") {
        assert(pos.count(i));
        pos.erase(i);
      }
    }
    s[p] = c;
    for(int i=p-2; i<=p; i++) {
      if(i < 0 || i+3 > n) continue;
      if(s.substr(i, 3) == "abc") {
        pos.insert(i);
      }
    }
    cout << pos.size() << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
