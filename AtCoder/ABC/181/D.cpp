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
  int n = s.size();
  map<int, int> cnt;
  rep(i, n) cnt[s[i]-'0']++;
  for(int i=0; i<pow(10, min(n, 3)); i+=8) {
    map<int, int> need;
    int tmp = i;
    rep(j, min(n, 3)) {
      need[tmp%10]++;
      tmp /= 10;
    }
    bool ok = true;
    for(auto ele: need) {
      if(!(cnt.count(ele.first) && cnt[ele.first] >= ele.second)) {
        ok = false;
      }
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
