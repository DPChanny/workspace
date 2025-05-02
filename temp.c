#include <stdio.h>

int gcd_recursive(int a, int b) {
  if (b == 0)
    return a;

  printf("%d = %d * %d + %d\n", a, b, a / b, a % b);
  return gcd_recursive(b, a % b);
}

int main() {
  int num1, num2, gcd;

  printf("두 정수를 입력하세요: ");
  scanf("%d %d", &num1, &num2);

  gcd = gcd_recursive(num1, num2);
  printf("%d와 %d의 최대공약수는 %d이다.\n", num1, num2, gcd);
  return 0;
}
