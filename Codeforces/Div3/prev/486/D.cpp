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
  vector<ll> A(n);
  set<ll> st;
  rep(i, n) {
    cin >> A[i];
    st.insert(A[i]);
  }
  sort(all(A));
  rep(i, n) {
    ll a = A[i];
    ll pw = 1;
    while(*A.rbegin() >= a+pw*2) {
      if(st.count(a+pw) && st.count(a+pw*2)) {
        cout << 3 << endk;
        cout << a << ' ' << a+pw << ' ' << a+pw*2 << endk;
        return;
      }
      pw *= 2;
    }
  }
  rrep(i, n) {
    ll a = A[i];
    ll pw = 1;
    while(*A.begin() <= a-pw*2) {
      if(st.count(a-pw) && st.count(a-pw*2)) {
        cout << 3 << endk;
        cout << a << ' ' << a-pw << ' ' << a-pw*2 << endk;
        return;
      }
      pw *= 2;
    }
  }
  rep(i, n) {
    ll a = A[i];
    ll pw = 1;
    while(*A.rbegin() >= a+pw) {
      if(st.count(a+pw)) {
        cout << 2 << endk;
        cout << a << ' ' << a+pw << endk;
        return;
      }
      pw *= 2;
    }
  }
  rrep(i, n) {
    ll a = A[i];
    ll pw = 1;
    while(*A.begin() <= a-pw) {
      if(st.count(a-pw)) {
        cout << 2 << endk;
        cout << a << ' ' << a-pw << endk;
        return;
      }
      pw *= 2;
    }
  }
  cout << 1 << endk;
  cout << A[0] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
