#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k, m; cin >> n >> k >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B;
  int l = 0;
  while(l < n) {
    B.push_back(A[l]); l++;
    while(l < n && (B.back()/abs(B.back())) * (A[l]/abs(A[l])) == 1) {
      B.back() += A[l];
      l++;
    }
  }
  // cout << B << "\n";
  while((int)B.size() > k) {
    ll mn = longinf;
    int mni = -1;
    rep(i, B.size()-1) {
      ll cur = (abs(B[i+1])+abs(B[i]))-abs(B[i+1]+B[i]);
      if(cur < mn) {
        mni = i;
        mn = cur;
      }
    }
    vector<ll> newB;
    rep(i, B.size()) {
      if(i != mni) {
        newB.push_back(B[i]);
      } else {
        if(B[i] > 0) {
          if(i+2<(int)B.size()) newB.push_back(abs(B[i]+B[i+1])+B[i+2]);
          else                  newB.push_back(abs(B[i]+B[i+1]));
          i++;
        } else {
          if((int)newB.size()) newB.back() += abs(B[i]+B[i+1]);
          else                 newB.push_back(abs(B[i]+B[i+1]));
        }
        i++;
      }
    }
    B = vector<ll>(newB.size());
    copy(all(newB), B.begin());
  }
  // cout << B << endl;
  ll ans = 0;
  for(ll b: B) ans += abs(b);
  cout << ans << "\n";
  return 0;
}
