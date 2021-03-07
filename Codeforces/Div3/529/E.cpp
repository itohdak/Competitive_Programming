#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  if(n % 2) {
    cout << 0 << endk;
  } else {
    int cnt1 = 0, cnt2 = 0;
    rep(i, n) {
      if(s[i] == '(') cnt1++;
      else cnt2++;
    }
    if(abs(cnt1-cnt2) != 2) {
      cout << 0 << endk;
    } else {
      vector<bool> ok_front(n+1, true), ok_back(n+1, true);
      vector<int> cnt_front(n+1), cnt_back(n+1);
      rep(i, n) {
        cnt_front[i+1] = cnt_front[i] + (s[i] == '(' ? 1 : -1);
        ok_front[i+1] = ok_front[i] && (cnt_front[i+1] >= 0);
      }
      rrep(i, n) {
        cnt_back[i] = cnt_back[i+1] + (s[i] == '(' ? 1 : -1);
        ok_back[i] = ok_back[i+1] && (cnt_back[i] <= 0);
      }
      int ans = 0;
      rep(i, n) {
        if(ok_front[i] && ok_back[i+1] && cnt_front[i]+cnt_back[i+1]-(s[i] == '(' ? 1 : -1) == 0) ans++;
      }
      cout << ans << endk;
    }
  }
  return 0;
}
