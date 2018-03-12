#include <iostream>
#include <array>
#include <algorithm>

class Elevator {
public:
  Elevator(int numFloor, int capacity, int weightLimit)
    : capacity(capacity), weightLimit(weightLimit),
      currentNumPeople(0), currentWeight(0),
      stopFloor(numFloor, -1), numStopFloor(0)
  {}

  bool canRide(int weight) {
    // 定員, 重量制限から乗れるか判定
    return ( currentNumPeople < capacity && currentWeight + weight <= weightLimit );
  }

  void ride(int weight, int getOutAt, int cntIteration) {
    currentNumPeople++;         // 乗員を増やす
    currentWeight += weight;    // 乗員の重量を増やす

    // 今回の搭乗で行き先が指定されているかをイテレーション回数で記録 → 計算量削減
    if ( stopFloor[getOutAt] != cntIteration ) {
      // 行き先を追加
      stopFloor[getOutAt] = cntIteration;
      numStopFloor++;
    }
  }

  int getStopCount() {
    return 1 + numStopFloor;    // 地上階に戻る分で +1 しておく
  }

  void init() {
    currentNumPeople = 0;
    currentWeight    = 0;
    numStopFloor     = 0;
  }

private:
  int capacity;                 // 定員
  int weightLimit;              // 重量制限

  int currentNumPeople;         // 現在の乗員数
  int currentWeight;            // 現在の乗員の総重量

  std::vector<int> stopFloor;   // 現在押されている行き先
  int numStopFloor;             // 現在押されている行き先のフロア数  
};


int solution(int A[], int B[], int N, int M, int X, int Y) {
  int cntStop = 0;
  int cntIteration = 1;           // 何回目の搭乗か. (上記の計算量の削減のため)
  Elevator elevator(M + 1, X, Y); // O(M)
  for (int i = 0; i < N; /*void*/) {
    // std::cerr << i << " : (" << A[i] << ", " << B[i] << ")" << std::endl;
    if ( elevator.canRide( A[i] ) ) {
      // std::cerr << "ride " << i << std::endl;
      elevator.ride( A[i], B[i], cntIteration );
      i++;
    }
    else {
      // std::cerr << "move elevator : " << elevator.getStopCount() << " times" << std::endl;
      cntStop += elevator.getStopCount();
      elevator.init();
      cntIteration++;
    }
  }

  // std::cerr << "move elevator : " << elevator.getStopCount() << " times" << std::endl;
  cntStop += elevator.getStopCount();

  return cntStop;
}


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
