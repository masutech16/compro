#include <chrono>
#include <random>

// 乱数生成器を返す
std::mt19937 make_mt() { return std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()); }
