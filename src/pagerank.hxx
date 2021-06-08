#pragma once
#include <vector>
#include <utility>

using std::vector;
using std::move;




// *-DIM (CUDA)
// ------------
// Good launch config.

// For pagerank cuda block-per-vertex
#define BLOCK_DIM_B 256
#define GRID_DIM_B  4096

// For pagerank cuda thread-per-vertex
#define BLOCK_DIM_T 256
#define GRID_DIM_T  4096




template <class T>
struct PagerankOptions {
  int repeat;
  int switchDegree;
  int switchLimit;
  T   damping;
  T   tolerance;
  int maxIterations;

  PagerankOptions(int repeat=1, int switchDegree=BLOCK_DIM_B, int switchLimit=BLOCK_DIM_T, T damping=0.85, T tolerance=1e-6, int maxIterations=500) :
  repeat(repeat), switchDegree(switchDegree), switchLimit(switchLimit), damping(damping), tolerance(tolerance), maxIterations(maxIterations) {}
};


template <class T>
struct PagerankResult {
  vector<T> ranks;
  int   iterations;
  float time;

  PagerankResult(vector<T>&& ranks, int iterations=0, float time=0) :
  ranks(ranks), iterations(iterations), time(time) {}

  PagerankResult(vector<T>& ranks, int iterations=0, float time=0) :
  ranks(move(ranks)), iterations(iterations), time(time) {}
};
