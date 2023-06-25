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
  string s; cin >> s;
  vector<int> X(s.size());
  rep(i, s.size()) X[i] = s[s.size()-1-i]-'0';
  ll sum = accumulate(all(X), 0LL);
  ll tmp = 0;
  string ans;
  int i = 0;
  while(i < (int)s.size() || tmp > 0) {
    if(i < s.size()) tmp += sum;
    ans += char('0'+tmp%10);
    sum -= X[i];
    tmp /= 10;
    i++;
  }
  reverse(all(ans));
  cout << ans << endk;
  return 0;
}
