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

ll one = 1LL*12*10000000000;
ll G = 1000000000;
void solve() {
  ll a, b, c; cin >> a >> b >> c;
  vector<ll> T = {a, b, c};
  sort(all(T));
  do {
    ll H = T[0], M = T[1], S = T[2];
    rep(h, 12) {
      rep(m, 60) {
        rep(s, 60) {
          ll hexp = H-(h*60*60+m*60+s)*G*1;
          ll mexp = M-(m*60+s)*G*12;
          ll sexp = S-s*G*720;
          ll diff_m_h = (mexp - hexp + 360*one) % (360*one);
          ll diff_s_m = (sexp - mexp + 360*one) % (360*one);
          ll diff_s_h = (sexp - hexp + 360*one) % (360*one);
          if(diff_m_h % (12 - 1)) continue;
          if(diff_s_m % (720 - 12)) continue;
          if(diff_s_h % (720 - 1)) continue;
          if(diff_m_h / (12 - 1) != diff_s_m / (720 - 12)) continue;
          if(diff_m_h / (12 - 1) != diff_s_h / (720 - 1)) continue;
          ll nano = diff_m_h / (12 - 1);
          if(nano >= 1000000000) continue;
          cout << h << ' ' << m << ' ' << s << ' ' << nano << endk;
          return;
        }
      }
    }
  } while(next_permutation(all(T)));
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
