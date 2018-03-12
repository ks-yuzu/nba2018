#include "elevator.hpp"

Elevator::Elevator(int numFloor, int capacity, int weightLimit)
  : capacity(capacity), weightLimit(weightLimit),
    currentNumPeople(0), currentWeight(0),
    stopFloor(numFloor, -1), numStopFloor(0)
{}


bool Elevator::canRide(int weight) {
  // 定員, 重量制限から乗れるか判定
  return ( currentNumPeople < capacity && currentWeight + weight <= weightLimit );
}


void Elevator::ride(int weight, int getOutAt, int cntIteration) {
  currentNumPeople++;         // 乗員を増やす
  currentWeight += weight;    // 乗員の重量を増やす

  // 今回の搭乗で行き先が指定されているかをイテレーション回数で記録 → 計算量削減
  if ( stopFloor[getOutAt] != cntIteration ) {
    // 行き先を追加
    stopFloor[getOutAt] = cntIteration;
    numStopFloor++;
  }
}


int Elevator::getStopCount() {
  return 1 + numStopFloor;    // 地上階に戻る分で +1 しておく
}


void Elevator::init() {
  currentNumPeople = 0;
  currentWeight    = 0;
  numStopFloor     = 0;
}
