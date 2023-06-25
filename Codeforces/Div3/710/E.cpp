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
  vector<int> Q(n); rep(i, n) cin >> Q[i];
  Q.push_back(n+1);
  vector<int> mn(n+1), mx(n+1);
  set<int> stm, stM;
  set<int> used;
  int j = 1;
  int prev = 0;
  rep(i, n+1) {
    if(i == 0 || Q[i] != Q[i-1]) {
      mn[i] = mx[i] = Q[i];
      used.insert(Q[i]);
      while(j <= (i == 0 ? 0 : Q[i-1])) {
        if(!used.count(j)) {
          stm.insert(j);
          stM.insert(j);
        }
        j++;
      }
      for(int p=prev+1; p<i; p++) {
        mn[p] = *stm.begin(); stm.erase(stm.begin());
        mx[p] = *(--stM.end()); stM.erase(--stM.end());
      }
      prev = i;
    }
  }
  rep(i, n) cout << mn[i] << ' '; cout << endk;
  rep(i, n) cout << mx[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
