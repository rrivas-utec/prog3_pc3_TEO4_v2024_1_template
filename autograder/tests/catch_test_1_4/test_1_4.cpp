//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "check_hidden_heap.h"
using namespace std;

static void test_1_4() {
  std::vector<string> arr = {"zebra", "apple", "banana", "cat",
                             "dog", "elephant", "fox", "giraffe", "horse"};
  int s = 3;
  auto result = check_hidden_heap(arr, s);
  
  // Debería imprimir 1 (HeapType::MinHeap)
  std::cout << static_cast<int>(result) << std::endl;
  
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}