#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if(a == b)
    cout << a + b + c * 2 << endl;
  else
    cout << min(a, b) * 2 + c * 2 + 1 << endl;
  return 0;
}

