#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(2*n);
  vector<int> even, odd;
  rep(i, 2*n) {
    cin >> A[i];
    if(A[i]%2==0) even.emplace_back(i+1);
    else          odd.emplace_back(i+1);
  }
  int cnt = n-1;
  int ie = 0, io = 0;
  while(cnt > 0) {
    if(ie+1 < (int)even.size()) {
      cout << even[ie] << ' ' << even[ie+1] << endl;
      ie+=2;
      cnt--;
    } else {
      cout << odd[io] << ' ' << odd[io+1] << endl;
      io+=2;
      cnt--;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
