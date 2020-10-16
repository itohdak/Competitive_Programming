#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int comb(int n){
  return n * (n-1) / 2;
};

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  vector< vector<int> > G(n, vector<int>(n, 0));
  if(a + b >= n){
    cout << "YES" << endl;
    if(a + b == n){
      int i = 1;
      while(b > 0){
	G[0][i] = G[i][0] = 1;
	i++; b--;
      }
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	cout << G[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

