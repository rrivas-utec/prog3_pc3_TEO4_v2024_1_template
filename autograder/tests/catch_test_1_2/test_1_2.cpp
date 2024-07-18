//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "check_hidden_heap.h"
using namespace std;

static void test_1_2() {
  std::vector<int> arr = {20, 1, 15, 2, 3, 10, 8, 4, 5};
  int s = 3;
  auto result = check_hidden_heap(arr, s);
  
  // Debería imprimir 1 (HeapType::MinHeap)
  std::cout << static_cast<int>(result) << std::endl;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}