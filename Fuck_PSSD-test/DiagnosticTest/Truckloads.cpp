#include "Truckloads.h"

Truckloads::Truckloads(/* args */) {}

int Truckloads::numTrucks(int numCrates, int loadSize) {
  if (loadSize >= numCrates) {
    return 1;
  }
  int n = numCrates / 2;
  int trucks = numTrucks(n, loadSize) + numTrucks(numCrates - n, loadSize);
  return trucks;
}

Truckloads::~Truckloads() {}
