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
  int n, m; cin >> n >> m;
  vector<int> T(n);
  vector<ll> X(n);
  rep(i, n) {
    cin >> T[i] >> X[i];
  }
  ll ans = 0;
  vector<ll> A, B;
  priority_queue<ll> Q;
  ll tmp = 0;
  rep(i, n) {
    if(T[i] == 0) {
      Q.push(-X[i]);
      tmp += X[i];
    } else if(T[i] == 1) {
      A.push_back(X[i]);
    } else {
      B.push_back(X[i]);
    }
  }
  sort(all(A), greater<ll>());
  sort(all(B), greater<ll>());
  ll cnt = 0;
  int l = 0;
  rep(i, min(m, (int)B.size())+1) {
    if(i) {
      cnt += B[i-1];
      while(cnt && l < A.size()) {
	Q.push(-A[l]);
	tmp += A[l];
	l++;
	cnt--;
      }
    }
    while(Q.size() > m-i) {
      ll top = Q.top();
      Q.pop();
      tmp += top;
    }
    chmax(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
