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
  vector<vector<int>> from(n);
  vector<vector<int>> to(n);
  rep(i, n) {
    int a1, a2; cin >> a1 >> a2;
    a1--; a2--;
    from[a1].push_back(i);
    from[a2].push_back(i);
    to[i].push_back(a1);
    to[i].push_back(a2);
  }
  // cout << from << endk;
  vector<int> ans;
  ans.push_back(0);
  while((int)ans.size() < n) {
    int b1 = from[ans.back()][0];
    int b2 = from[ans.back()][1];
    if(find(all(to[b1]), b2) != end(to[b1])) {
      ans.push_back(b2);
      ans.push_back(b1);
    } else {
      ans.push_back(b1);
      ans.push_back(b2);
    }
  }
  rrep(i, n) cout << ans[i]+1 << ' ';
  cout << endk;
  return 0;
}
