#include <vector>

class Elevator {
public:
  Elevator(int numFloor, int capacity, int weightLimit);
  bool canRide(int weight);
  void ride(int weight, int getOutAt, int cntIteration);
  int  getStopCount();
  void init();

private:
  int capacity;                 // 定員
  int weightLimit;              // 重量制限

  int currentNumPeople;         // 現在の乗員数
  int currentWeight;            // 現在の乗員の総重量

  std::vector<int> stopFloor;   // 現在押されている行き先
  int numStopFloor;             // 現在押されている行き先のフロア数  
};
