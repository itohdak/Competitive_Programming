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
  int n, k; cin >> n >> k;
  vector<int> P(n); rep(i, n) cin >> P[i];
  set<int> st;
  int ans = 1;
  int sub = 0;
  int cnt = 0;
  int flag = 0;
  rep(i, n) {
    if(i < k) {
      st.insert(P[i]);
      if(i && P[i] > P[i-1]) cnt++;
      if(cnt != k-1) {
        flag = 0;
      } else if(!flag) {
        sub++;
        flag = 1;
      }
    } else {
      st.insert(P[i]);
      if(*st.begin() != P[i-k] || *st.rbegin() != P[i]) {
        ans++;
      }
      st.erase(P[i-k]);
      if(P[i-k+1] > P[i-k]) cnt--;
      if(P[i] > P[i-1]) cnt++;
      if(cnt != k-1) {
        flag = 0;
      } else if(!flag) {
        sub++;
        flag = 1;
      }
    }
  }
  cout << ans-max(0, sub-1) << endk;
  return 0;
}
