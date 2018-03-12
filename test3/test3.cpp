#include <iostream>
#include "solution.hpp"

int main()
{
  // expected : 5
  int A1[] = {60, 80, 40};
  int B1[] = { 2,  3,  5};
  std::cout << solution(A1, B1, 3, 5, 2, 200) << std::endl;

  // expected : 6
  int A2[] = {40, 40, 100, 80, 20};
  int B2[] = { 3,  3,   2,  2,  3};
  std::cout << solution(A2, B2, 5, 3, 5, 200) << std::endl;

  // expected : 11
  int A3[] = {40, 40, 40, 40, /**/ 80, /**/ 200, 50, /**/ 70, 70, 70};
  int B3[] = { 8,  2,  2,  3, /**/  3, /**/   1,  1, /**/  1, 10, 10};
  std::cout << solution(A3, B3, 10, 10, 4, 250) << std::endl;

  return 0;
}
