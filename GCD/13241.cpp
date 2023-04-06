#include <iostream>

using namespace std;

///유클리드 호제법
///양의 정수 a,b (a > b)에 대해 a = b*q + r (0 <= r < b)이 성립하면,
///a,b 의 최대공약수(Great Common Divisor)는 b,r의 최대공약수와 같다 => gcd(a,b) = gcd(b, r)
///만약 r = 0이라면 a, b의 최대공약수는 b가 된다. => 반복해서 나누다가 r=0(나머지가 0)이 될 때의 나누는 수가 최대공약수가 됨.

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main() {  
  unsigned long long a, b, c;
  cin >> a >> b;
  if (b > a){
    c = gcd(b, a);
  }else{
    c = gcd(a, b);
  }

  int answer = 0;
  for (int i = 0; i < c; i++){
    answer = answer*10;
    answer++;
  }
  cout << answer << endl;
  return 0;
}