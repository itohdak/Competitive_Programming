#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    string S;
    cin >> S;
    vector<int> odd, even;
    rep(i, S.size()) {
      int tmp = int(S[i] - '0');
      if(tmp % 2 == 0) even.push_back(tmp);
      else odd.push_back(tmp);
    }
    int io=0, ie=0;
    rep(i, S.size()) {
      if(io == odd.size()) {
        cout << even[ie];
        ie++;
      } else if(ie == even.size()) {
        cout << odd[io];
        io++;
      } else if(odd[io] > even[ie]){
        cout << even[ie];
        ie++;
      } else {
        cout << odd[io];
        io++;
      }
    }
    cout << endl;
  }
  return 0;
}

