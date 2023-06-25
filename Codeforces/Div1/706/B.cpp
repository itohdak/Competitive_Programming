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
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> cntL(n), cntR(n);
  rep(i, n-1) {
    if(P[i] < P[i+1]) cntL[i+1] = cntL[i] + 1;
    else cntL[i+1] = 0;
  }
  rrep(i, n) {
    if(i-1 < 0) continue;
    if(P[i-1] > P[i]) cntR[i-1] = cntR[i] + 1;
    else cntR[i-1] = 0;
  }
  multiset<int> st;
  rep(i, n) {
    st.insert(cntL[i]);
    st.insert(cntR[i]);
  }
  int ans = 0;
  rep(i, n) {
    if(cntL[i] == 0 || cntR[i] == 0) continue;
    if(cntL[i] == cntR[i]) {
      if(cntL[i] % 2 == 0) {
        st.erase(st.find(cntL[i]));
        st.erase(st.find(cntR[i]));
        if(*st.rbegin() < cntL[i]) ans++;
        st.insert(cntL[i]);
        st.insert(cntR[i]);
      }
    } else if(cntL[i] > cntR[i]) {
      if((cntL[i]+1)/2*2-1 < cntR[i]) {
        st.erase(st.find(cntL[i]));
        if(*st.rbegin() < cntL[i]) ans++;
        st.insert(cntL[i]);
      }
    } else {
      if((cntR[i]+1)/2*2-1 < cntL[i]) {
        st.erase(st.find(cntR[i]));
        if(*st.rbegin() < cntR[i]) ans++;
        st.insert(cntR[i]);
      }
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
