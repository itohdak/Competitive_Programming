#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, B;
  cin >> n >> B;
  vector<int> A(n);
  vector<int> odd(n, 0), even(n, 0);
  for(int i=0; i<n; i++){
    cin >> A[i];
    if(i != 0){
      odd[i] = odd[i-1];
      even[i] = even[i-1];
    }
    if(A[i] % 2 == 0)
      even[i]++;
    else
      odd[i]++;
  }
  vector<int> able_to_cut;
  for(int i=1; i<n; i+=2){
    if(even[i] == odd[i])
      able_to_cut.push_back(i);
  }
  vector<int> able_cost;
  for(int i=0; i<able_to_cut.size()-1; i++){
    int tmp = able_to_cut[i];
    if(abs(A[tmp+1] - A[tmp]) <= B)
      able_cost.push_back(abs(A[tmp+1] - A[tmp]));
  }
  sort(able_cost.begin(), able_cost.end(), greater<int>());

  int N = (int)able_cost.size();
  ll dp[N+1][B+1];
  for(int i=0; i<N+1; i++)
    for(int j=0; j<B+1; j++)
      dp[i][j] = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<B+1; j++){
      if(j < able_cost[i])
	dp[i+1][j] = dp[i][j];
      else
	dp[i+1][j] = max(dp[i][j], dp[i][j-able_cost[i]] + 1);
    }
  }
  cout << dp[N][B] << endl;
  return 0;
}

