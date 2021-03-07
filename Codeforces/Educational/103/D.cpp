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
  string s; cin >> s;
  vector<int> cntR(n);
  char d[2] = {'R', 'L'};
  int l = 0, r = 0;
  while(l < n) {
    while(l < n && s[l] == 'L') l++;
    r = l;
    while(r < n && s[r] == d[(r-l)%2]) r++;
    for(int i=l; i<r; i+=2) cntR[i] = r-i;
    l = r;
  }
  vector<int> cntL(n);
  l = n-1, r = n-1;
  while(r >= 0) {
    while(r >= 0 && s[r] == 'R') r--;
    l = r;
    while(l >= 0 && s[l] == d[(r-l+1)%2]) l--;
    for(int i=r; i>l; i-=2) cntL[i] = i-l;
    r = l;
  }
  rep(i, n+1) {
    cout << (i < n ? cntR[i] : 0) + (i ? cntL[i-1] : 0) + 1 << ' ';
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
