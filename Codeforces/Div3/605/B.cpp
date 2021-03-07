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
  map<char, int> cnt;
  int n = s.size();
  rep(i, n) cnt[s[i]]++;
  int ud = min(cnt['U'], cnt['D']);
  int lr = min(cnt['L'], cnt['R']);
  if(ud == 0 && lr == 0) {
    cout << 0 << endk;
    cout << endk;
  } else if(ud == 0) {
    cout << 2 << endk;
    cout << "RL" << endk;
  } else if(lr == 0) {
    cout << 2 << endk;
    cout << "UD" << endk;
  } else {
    int ans = (ud + lr) * 2;
    cout << ans << endk;
    cout << string(ud, 'U') + string(lr, 'R') + string(ud, 'D') + string(lr, 'L') << endk;
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
