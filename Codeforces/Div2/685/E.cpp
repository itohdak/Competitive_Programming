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
  int n; cin >> n;
  vector<int> ans(n);
  vector<int> in(5);
  cout << "OR 1 2" << endl;  cin >> in[0];
  cout << "OR 2 3" << endl;  cin >> in[1];
  cout << "OR 1 3" << endl;  cin >> in[2];
  cout << "XOR 1 2" << endl; cin >> in[3];
  cout << "XOR 2 3" << endl; cin >> in[4];
  rep(i, 16) {
    vector<int> b(5);
    rep(j, 5) b[j] = (in[j]>>i)&1;
    if(!b[0]) {
      if(b[1] && b[2]) ans[2] += 1<<i;
    } else {
      if(b[1] && !b[2]) ans[1] += 1<<i;
      else if(!b[1] && b[2]) ans[0] += 1<<i;
      else {
        if(b[3]) {
          if(b[4]) {
            ans[0] += 1<<i;
            ans[2] += 1<<i;
          } else {
            ans[1] += 1<<i;
            ans[2] += 1<<i;
          }
        } else {
          if(b[4]) {
            ans[0] += 1<<i;
            ans[1] += 1<<i;
          } else {
            ans[0] += 1<<i;
            ans[1] += 1<<i;
            ans[2] += 1<<i;
          }
        }
      }
    }
  }
  REP(i, 3, n) {
    cout << "XOR 1 " << i+1 << endl;
    int in; cin >> in;
    ans[i] = in ^ ans[0];
  }
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
