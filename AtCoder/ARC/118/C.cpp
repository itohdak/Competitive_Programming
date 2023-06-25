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
  vector<int> avail;
  for(int i=1; i<=10000; i++) {
    if(i == 6 || i == 15 || i == 10) continue;
    else if(i%6==0 && i%5) avail.push_back(i);
    else if(i%15==0 && i%2) avail.push_back(i);
    else if(i%10==0 && i%3) avail.push_back(i);
    else if(i%30==0) avail.push_back(i);
  }
  vector<int> ans(n);
  ans[0] = 6, ans[1] = 15, ans[2] = 10;
  int j = 0;
  REP(i, 3, n) ans[i] = avail[j++];
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
