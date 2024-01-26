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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m, d; cin >> n >> m >> d;
  vector<int> S(m);
  rep(i, m) {
    cin >> S[i];
    S[i]--;
  }
  S.push_back(n);
  auto calc = [&](int p1, int p2) {
    return (p2-p1)/d + ((p2-p1)%d>0);
  };
  int cnt = 0;
  rep(i, m) {
    int prev = (i==0 ? 0 : S[i-1]);
    int next = S[i+1];
    int cur = S[i];
    int wo = calc(prev, next);
    int w = calc(prev, cur) + calc(cur, next);
    if(w > wo) {
      cnt++;
    }
  }
  int ans = 0;
  rep(i, m+1) {
    int prev = (i==0 ? 0 : S[i-1]);
    int cur = S[i];
    ans += calc(prev, cur);
  }
  if(cnt == 0) {
    cout << ans << ' ' << m << endk;
  } else {
    cout << ans-1 << ' ' << cnt << endk;
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
