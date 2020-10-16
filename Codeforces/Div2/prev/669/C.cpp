#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  int n; cin >> n;
  vector<int> ans(n);
  vector<vector<int>> v(2);
  rep(i, n) v[0].push_back(i);
  int flag = 0;
  vector<int> done(n+1);
  while(v[flag].size() > 1) {
    v[1-flag].clear();
    for(int i=0; i<v[flag].size(); i+=2) {
      if(i+1 == v[flag].size()) {
        v[1-flag].push_back(v[flag][i]);
        continue;
      }
      int in1, in2;
      cout << "? " << v[flag][i]+1 << ' ' << v[flag][i+1]+1 << endl;
      cin >> in1;
      cout << "? " << v[flag][i+1]+1 << ' ' << v[flag][i]+1 << endl;
      cin >> in2;
      if(in1 > in2) {
        ans[v[flag][i]] = in1;
        done[in1] = true;
        v[1-flag].push_back(v[flag][i+1]);
      } else {
        ans[v[flag][i+1]] = in2;
        done[in2] = true;
        v[1-flag].push_back(v[flag][i]);
      }
    }
    flag = 1-flag;
  }
  rep(i, n) if(!done[i+1]) ans[v[flag][0]] = i+1;
  cout << "! ";
  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
