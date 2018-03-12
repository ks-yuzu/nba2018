#include "solution.hpp"
#include "elevator.hpp"

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
