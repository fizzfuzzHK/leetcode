#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(auto& v : vec){
    cin >> v;
  }
  sort(vec.begin(), vec.end(), greater<int>());

  int ans = 0;
  int count = N;
  bool second = false;
  for(auto& v : vec){
    if(second == false){
      second = true;
    }
    else{
      ans += v;
      second = false;
      --count;
      if(count == 0){
        break;
      }
    }
  }
  cout << ans << endl;
}