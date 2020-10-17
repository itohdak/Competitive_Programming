#include <bits/stdc++.h>
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
const ld eps = 1e-10;

class NearPalindromesDiv1 {
public:
  int solve(string s) {
    vector<int> cnt(26);
    for(char c: s) cnt[c-'a']++;
    vector<int> rem;
    rep(i, 26) {
      cnt[i] %= 2;
      if(cnt[i]) rem.push_back(i);
    }
    int ans = inf;
    int n = rem.size();
    rep(i, n) {
      int tmp = 0;
      for(int j=0; j+1<n; j+=2) {
        tmp += (rem[(i+j+1)%n]+26-rem[(i+j)%n])%26;
      }
      ans = min(ans, tmp);
    }
    return ans;
  };
};

int main() {
  string s = "abcdefgh";
  cout << NearPalindromesDiv1().solve(s) << endl;
}
