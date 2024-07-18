//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "check_hidden_heap.h"
using namespace std;

static void test_1_1() {
  std::vector<int> arr = {1, 2, 4, 1, 2, 5, 12, 11, 5};
  int s = 2;
  auto result = check_hidden_heap(arr, s);
  
  // Debería imprimir 1 (HeapType::MinHeap)
  std::cout << static_cast<int>(result) << std::endl;
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}