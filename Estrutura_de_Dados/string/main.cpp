#include <cstdio>
#include "mystring.h"

String fn(String a, String b)
{
  return a + b;
}

int main()
{
  char s1[128], s2[128];

  scanf("%s %s", s1, s2);

  String x1(s1);
  String x2(x1);
  String x3, x4, x5, x6;
  x3 = String(s2);
  x4 = x3 = x3;

  x5 = x1 + x2;
  x6 = fn(x3, x4);

  printf("%s\n", x5.c_str());
  printf("%s\n", x6.c_str());

  return 0;
}