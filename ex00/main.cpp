/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:29:29 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/21 19:52:02 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

static const int MAX_CONTAINER_SIZE = 5;

void testVector() {
  std::cout << "\n=== Testing Vector ===" << std::endl;
  std::vector<int> v;
  for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
    v.push_back(i);
  }
  printContainer(v, "vector");
  testEasyFind(v, "vector", 1);
  testEasyFind(v, "vector", 7);
}

void testDeque() {
  std::cout << "\n=== Testing Deque ===" << std::endl;
  std::deque<int> d;
  for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
    d.push_back(i * 2);
  }
  printContainer(d, "deque");
  testEasyFind(d, "deque", 0);
  testEasyFind(d, "deque", 7);
}

void testList() {
  std::cout << "\n=== Testing List ===" << std::endl;
  std::list<int> lst;
  for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
    lst.push_back(i * 3);
  }
  printContainer(lst, "list");
  testEasyFind(lst, "list", 3);
  testEasyFind(lst, "list", 7);
}

int main() {
  testVector();
  testDeque();
  testList();
  return 0;
}
