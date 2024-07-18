//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "check_hidden_heap.h"
using namespace std;

static void test_1_3() {
  double arr[] = {100, 2.3, 3, 50, 4.5, 5, 60, 6, 7.5};
  int s = 3;
  auto result = check_hidden_heap(arr, s);
  
  // Debería imprimir 1 (HeapType::MinHeap)
  std::cout << static_cast<int>(result) << std::endl;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}