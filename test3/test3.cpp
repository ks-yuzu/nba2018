#include <iostream>
#include <array>
#include <algorithm>

class Elevator {
public:
  Elevator(int numFloor, int capacity, int weightLimit)
    : capacity(capacity), weightLimit(weightLimit),
      currentNumPeople(0), currentWeight(0),
      stopFloor(numFloor, false)
  {}

  bool canRide(int weight) {
    return ( currentNumPeople < capacity && currentWeight + weight <= weightLimit );
  }

  void ride(int weight, int getOutAt) {
    currentNumPeople++;
    currentWeight += weight;

    stopFloor[getOutAt] = true;
  }

  int getStopCount() {
    return std::count_if(std::begin(stopFloor), std::end(stopFloor), [](bool i){return i;}) + 1;
  }

  void init() {
    currentNumPeople = 0;
    currentWeight    = 0;
    std::fill(std::begin(stopFloor), std::end(stopFloor), false);
  }

private:
  int capacity;
  int weightLimit;

  int currentNumPeople;
  int currentWeight;

  std::vector<bool> stopFloor;
};


int solution(int A[], int B[], int N, int M, int X, int Y) {
  int stopCount = 0;
  Elevator elevator(M + 1, X, Y);
  for (int i = 0; i < N; /*void*/) {
    // std::cerr << i << " : (" << A[i] << ", " << B[i] << ")" << std::endl;
    if ( elevator.canRide( A[i] ) ) {
      // std::cerr << "ride " << i << std::endl;
      elevator.ride( A[i], B[i] );
      i++;
    }
    else {
      // std::cerr << "move elevator : " << elevator.getStopCount() << " times" << std::endl;
      stopCount += elevator.getStopCount();
      elevator.init();
    }
  }

  // std::cerr << "move elevator : " << elevator.getStopCount() << " times" << std::endl;
  stopCount += elevator.getStopCount();

  return stopCount;
}


int main()
{
  // expected : 5
  int A[] = {60, 80, 40};
  int B[] = { 2,  3,  5};
  std::cout << solution(A, B, 3, 5, 2, 200) << std::endl;

  // expected : 6
  // int A[] = {40, 40, 100, 80, 20};
  // int B[] = { 3,  3,   2,  2,  3};
  // std::cout << solution(A, B, 5, 3, 5, 200) << std::endl;

  return 0;
}

