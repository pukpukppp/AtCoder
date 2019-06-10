#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> f(N,0);
  vector<int> a(M,0);

  for(int i = 0;i < M;i++){
    cin >> a[i];
    a[i] -= 1;
    cout << a[i];
  }
  
  int temp1,temp2;

  f[0] = 1;
  f[1] = 2;

  temp1 = f[0];
  temp2 = f[1];

  int j = 0;

  //1,2段目が抜けていた場合
  if(a[0] == 0){
    f[0] = 0;
    j++;
  } 
  if(a[0] == 1 || a[1] == 1){
    f[1] = 0;
    j++;
  }

  for(int i = 2;i < N;i++){
    //f[i] がaと一致しない場合は行う
    if(f[i] != a[j]){
      f[i] = temp1 + temp2;
      temp2 = f[i - 1];
      temp1 = f[i];
    }else{
      j++;
      cout <<"TT"
    }
  }

  cout << f[N - 1] << endl;
}
