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
  vector<int> A(n);
  vector<int> cnt(2);
  rep(i, n) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  if(cnt[0] == 0 || cnt[1] == 0) {
    cout << n << endk;
    rep(i, n) cout << A[i] << ' ';
    cout << endk;
  } else if(n/2 % 2 == 0) {
    cout << n/2 << endk;
    int m = (cnt[0]<cnt[1] ? 1 : 0);
    rep(i, n/2) cout << m << ' ';
    cout << endk;
  } else if(cnt[0] == cnt[1]) {
    cout << n/2 << endk;
    rep(i, n/2) cout << 0 << ' ';
    cout << endk;
  } else {
    cout << n/2+1 << endk;
    int m = (cnt[0]<cnt[1] ? 1 : 0);
    rep(i, n/2+1) cout << m << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
