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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  string b; cin >> b;
  vector<ll> B(n); rep(i, n) B[i] = b[i]-'0';
  ll l = -1000000000LL, r = 1000000000LL;
  int cnt0 = 4-B[0]-B[1]-B[2]-B[3];
  multiset<ll> st;
  rep(i, 4) st.insert(A[i]);
  for(int i=4; i<n; i++) {
    st.insert(A[i]);
    if(B[i] == 1) {
      if(cnt0 == 4) {
        chmax(l, *(--st.end())+1);
      }
    } else {
      if(cnt0 == 0) {
        chmin(r, *st.begin()-1);
      }
    }
    assert(st.find(A[i-4]) != st.end());
    st.erase(st.find(A[i-4]));
    cnt0 += -B[i]+B[i-4];
  }
  cout << l << ' ' << r << endk;
  return 0;
}
