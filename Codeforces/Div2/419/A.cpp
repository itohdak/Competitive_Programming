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
  vector<int> times;
  rep(i, 24) rep(j, 60) {
    if(i % 10 == j / 10 && i / 10 == j % 10) {
      times.push_back(i * 60 + j);
    }
  }
  int now = ((s[0]-'0') * 10 + (s[1]-'0')) * 60 + ((s[3]-'0') * 10 + (s[4]-'0'));
  auto itr = upper_bound(all(times), now-1);
  if(itr == times.end()) {
    cout << 24*60 - now + times[0] << endk;
  } else {
    cout << *itr - now << endk;
  }
  return 0;
}
