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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string t = "RGB";
  int mn = inf;
  auto calc = [&](int b) {
    string a(n, ' ');
    rep(i, n) a[i] = t[(b+i)%3];
    int res = inf;
    int tmp = 0;
    rep(i, k) if(s[i] != a[i]) tmp++;
    chmin(res, tmp);
    REP(i, k, n) {
      if(s[i] != a[i]) tmp++;
      if(s[i-k] != a[i-k]) tmp--;
      chmin(res, tmp);
    }
    return res;
  };
  chmin(mn, calc(0));
  chmin(mn, calc(1));
  chmin(mn, calc(2));
  cout << mn << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
