#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  ll n; cin >> n;
  vector<ld> XL(n), XR(n), Y(n);
  rep(i, n) cin >> XL[i] >> XR[i] >> Y[i];
  ld minAngle = 0, maxAngle = M_PI;
  rep(i, n) REP(j, i+1, n) {
    if(Y[i] == Y[j]) {
    } else if(Y[i] > Y[j]) {
      minAngle = max(atan2l(Y[i]-Y[j], XR[i]-XL[j]), minAngle);
      maxAngle = min(atan2l(Y[i]-Y[j], XL[i]-XR[j]), maxAngle);
    } else {
      cout << atan2l(Y[j]-Y[i], XR[j]-XL[i])*180/M_PI << "\n";
      minAngle = max(atan2l(Y[j]-Y[i], XR[j]-XL[i]), minAngle);
      maxAngle = min(atan2l(Y[j]-Y[i], XL[j]-XR[i]), maxAngle);
    }
  }
  ld angle = (abs(minAngle-M_PI/2)<abs(maxAngle-M_PI/2) ?
              minAngle :
              maxAngle);
  cout << angle*180/M_PI << "\n";
  ld mn = longinf;
  ld mx = -longinf;
  rep(i, n) {
    mn = min(XL[i]-Y[i]/tan(angle), mn);
    mx = min(XR[i]-Y[i]/tan(angle), mx);
  }
  cout << fixed << setprecision(10) << mx-mn << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
