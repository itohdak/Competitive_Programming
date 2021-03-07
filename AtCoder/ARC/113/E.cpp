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

void solve() {
  string s; cin >> s;
  int n = s.size();
  map<char, int> cnt;
  for(char c: s) cnt[c]++;
  if(cnt['a'] == n) cout << s << endk;
  else if(cnt['b'] == n) cout << s << endk;
  else {
    if(s[0] == 'a') {
      int r = n-1;
      while(r >= 0 && s[r] == 'b') {
        r--;
        cnt['b']--;
      }
      if(cnt['b'] == 0) {
        cout << s << endk;
        return;
      }
      while(r >= 0 && s[r] == 'a') r--;
      // reverse(begin(s), begin(s)+r+1);
      string snew;
      for(int i=r; i>=1; i--) snew += s[i];
      for(int i=r+2; i<n; i++) snew += s[i];
      // assert(s[0] == 'b');
      n = s.size();
    }
    int lastb = n-1;
    while(lastb >= 0 && s[lastb] == 'a') lastb--;
    deque<int> pos;
    rep(i, n) if(s[i] == 'a') pos.push_back(i);
    set<int> st;
    while(pos.size()) {
      if(pos.size() < 2) break;
      if(pos.front() > lastb) break;
      st.insert(pos.front()); pos.pop_front();
      st.insert(pos.front()); pos.pop_front();
    }
    string ans;
    rep(i, n) if(!st.count(i)) ans += s[i];
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
