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

map<string, int> mp;
void solve() {
  string s; cin >> s;
  cout << mp[s]+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for(char c1='a'; c1<='z'; c1++) {
    for(char c2='a'; c2<='z'; c2++) {
      if(c1 == c2) continue;
      string s;
      s += c1;
      s += c2;
      mp[s] = mp.size();
    }
  }
  // cout << mp << endk;
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
