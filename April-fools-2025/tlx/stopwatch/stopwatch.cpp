#include "stopwatch.h"
#include <bitset>
#include <chrono> 
#include <climits>
#include <iostream>
#include <random>

void solution() {
  // while(true) {
  //   auto nw = std::chrono::system_clock::now();
  //   stopWatch();
  //   auto now_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(nw.time_since_epoch()).count();
  //   auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(nw.time_since_epoch()).count();
  //   now_ns++;
  //   now_ns++;
  //   now_ns++;
  //   now_ns++;
  //   now_ns++;
  //   std::string time_str = std::to_string(now_ns) + std::to_string(now_ms);
  //   // std::cout <<time_str <<std::endl;
  //   // time_str = std::to_string(now_ns) + std::to_string(now_ms);
  //   // std::cout <<time_str <<std::endl;
  //   std::size_t hash_val = std::hash<std::string> {}(time_str);
  //   hash_val ^= (hash_val >> 13);
  //   hash_val ^= (hash_val << 7);
  //   hash_val ^= (hash_val >> 17);
  //   std::bitset<64> bits(hash_val);
  //   for (int i = 0; i < 64; i++) {
  //     if ((now_ns & (1LL << (i % 30))) != 0) {
  //       bits.flip(i);
  //     }
  //   }
  //   std::vector<unsigned int> primes = {2, 3, 5, 7, 265, 13, 17, 19, 23, 29};
  //   for (auto prime : primes) {
  //     hash_val = hash_val * prime + (now_ns % prime);
  //   }
  //   unsigned int final_seed = hash_val ^ bits.to_ullong();
  //   final_seed = ((final_seed * 265U) + 265265265U) % UINT_MAX;
  //   mt19937 rng2 = std::mt19937(final_seed);
  //   int skor = rng2() % 101;
  //   if(skor==100) {
  //     std::cout <<final_seed <<std::endl;
  //     break;
  //   }
  //   // std::cout <<std::endl;
  // }
  stopWatch();
  unsigned int final_seed = 905007380;
  rng = mt19937(final_seed);
  lookAtWatch();
  return;
}
