#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<long long int> f(N + 1,0);
  vector<int> a(M + 1,0);

  for(int i = 0;i < M;i++){
    cin >> a[i];
  }
  
  long long int temp1,temp2; 
  int j = 0;

  f[0] = 1;
  temp1 = f[0];
  temp2 = 0;

  for(int i = 1;i < N + 1;i++){
    //f[i] がaと一致しない場合は行う
    if(i != a[j]){
      f[i] = temp1 + temp2;
    }else{
      j++;
    }
    temp2 = f[i - 1];
    temp1 = f[i];
    f[i] %= 1000000007;
  }

  cout << f[N] << endl;
}
