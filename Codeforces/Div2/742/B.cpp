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

int XOR[300010];
void solve() {
  int a, b; cin >> a >> b;
  int x = XOR[a-1];
  int ans = a;
  if(x != b) {
    if((x^b) == a) ans += 2;
    else ans++;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(i, 300010) {
    if(i == 0) XOR[i] = 0;
    else XOR[i] = XOR[i-1]^i;
  }
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
