#include <iostream>

using namespace std;

int gcd(int a, int b) {
   if (a < b) 
    return gcd(b, a);
  if (b == 0) 
    return a;
  else 
    return gcd(b, a % b);
}

int main(){
  int a, b, n;
  cin >> a >> b >> n;

  int disjoints = 0;
  
  for(int i = a; i <= b; i++){
    if(gcd(i, n) == 1)
      disjoints++;
  }
  
  cout << disjoints << endl;
}