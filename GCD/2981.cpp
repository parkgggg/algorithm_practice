#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
  if(b == 0){
      return a;
  }else{
      return gcd(b, a%b);
  }
}

int main(){
    
  int array_n[101] = {};
  int array_minus[101] = {};
  int array_gcd[101] = {};

  int n;
  scanf ("%d", &n);
  
  for (int i = 1; i <= n; i++){
    scanf("%d", &array_n[i]);
  }
  
  for (int i = 1; i < n; i++){
    array_minus[i] = array_n[i+1] - array_n[i];
  }
  
  int g = 0;
  for (int i = 1; i <= n-2; i++){
    if (g < gcd(array_minus[i], array_minus[i+1])){
        g = gcd(array_minus[i], array_minus[i+1]);
    }
  }
    
  for (int i = 2; i * i <= g; i++){
    if (i % i == g){
      printf("%d ", i);
    }
    else if (g % i == 0){
      printf("%d %d ", i, g/i);
    }
  }
  return 0;
}