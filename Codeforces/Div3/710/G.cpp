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
  int n = s.size();
  vector<ll> sum(n+1);
  rrep(i, n) {
    sum[i] = sum[i+1] | (1LL<<(s[i]-'a'));
  }
  map<char, vector<int>> pos;
  ll bit = 0;
  rep(i, n) {
    pos[s[i]].push_back(i);
    bit |= (1LL<<(s[i]-'a'));
  }
  string ans;
  int tmp = 0;
  while(bit) {
    rrep(i, 26) {
      if(!((bit>>i)&1)) continue;
      char c = 'a'+i;
      int next_pos = *lower_bound(all(pos[c]), tmp);
      if((sum[next_pos] & bit) == bit) {
        ans += c;
        bit ^= (1LL<<i);
        tmp = next_pos+1;
        break;
      }
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
