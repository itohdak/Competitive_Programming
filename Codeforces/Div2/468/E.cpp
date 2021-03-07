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
  cout << fixed << setprecision(20);
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> pos(26);
  rep(i, n) pos[s[i]-'a'].push_back(i);
  int ans = 0;
  rep(i, 26) {
    int mx = 0;
    rep(j, n) {
      int tmp = 0;
      map<char, int> cnt;
      for(int k: pos[i]) {
        cnt[s[(k+j)%n]]++;
      }
      for(auto ele: cnt) {
        if(ele.second == 1) tmp++;
      }
      chmax(mx, tmp);
    }
    ans += mx;
  }
  cout << (ld)1 * ans / n << endk;
  return 0;
}
