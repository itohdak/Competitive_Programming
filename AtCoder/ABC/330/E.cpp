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
  int n, q; cin >> n >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  set<int> st;
  rep(i, n+1) {
    st.insert(i);
  }
  vector<int> cnt(n+1);
  rep(i, n) {
    st.erase(A[i]);
    if(A[i] < n+1) {
      cnt[A[i]]++;
    }
  }
  rep(_, q) {
    int i, x; cin >> i >> x;
    i--;
    int a = A[i];
    if(a < n+1) {
      cnt[a]--;
      if(cnt[a] == 0) {
        st.insert(a);
      }
    }
    A[i] = x;
    if(x < n+1) {
      cnt[x]++;
      st.erase(x);
    }
    // cout << st << endk;
    cout << *st.begin() << endk;
  }
  return 0;
}
