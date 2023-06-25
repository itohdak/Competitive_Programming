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
  char c = *min_element(all(s));
  int cnt = 0;
  string others;
  rep(i, n) {
    if(s[i] == c) cnt++;
    else others += s[i];
  }
  sort(all(others));
  if(others.size() == 0) {
    cout << string(cnt, c) << endk;
  } else if(cnt == 1) {
    cout << string(1, c) + others << endk;
  } else {
    if(cnt-2 > others.size() && (others.size() == 1 || others.back() != others.front())) {
      string ans;
      ans += c;
      ans += others[0];
      ans += string(cnt-1, c);
      int j = lower_bound(all(others), others[0]+1) - begin(others);
      if(j < others.size()) ans += others[j];
      REP(k, 1, others.size()) if(k != j) ans += others[k];
      cout << ans << endk;
    } else {
      string ans;
      ans += string(2, c);
      cnt -= 2;
      int j = 0;
      rep(i, cnt) {
        if(j < others.size()) ans += others[j++];
        ans += c;
      }
      ans += others.substr(j, others.size()-j);
      cout << ans << endk;
    }
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
