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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> cnt(n); // 何個シフトしたときに|pi-i|が0になるか
  rep(i, n) cnt[(P[i]-i-1+n)%n]++;
  // cout << cnt << endk;
  ll tmp = 0;
  ll mn = longinf;
  int mni = 0;
  int h = 0, l = 0;
  rep(i, n) {
    tmp += abs(P[i]-i-1);
    (P[i]-i-1>0 ? h : l)++;
  }
  rep(i, n) {
    // cout << i << ' ' << tmp << ' ' << l << ' ' << h << endk;
    if(mn > tmp) {
      mn = tmp;
      mni = i;
    }
    tmp -= abs(P[n-1-i]-n);
    tmp += abs(P[n-1-i]-1);
    tmp += (l-1)-h;
    l += cnt[(i+1)%n];
    h -= cnt[(i+1)%n];
    l--;
    h++;
  }
  cout << mn << ' ' << mni << endk;
  return 0;
}
