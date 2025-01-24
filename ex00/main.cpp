/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:29:29 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/25 02:03:34 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "test.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

static const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void testVector() {
  std::vector<int> v;
  setupContainer(v);
  displayInfo(v, "vector");
  testEasyFind(v, 0);
  testEasyFind(v, -1);
}

void testDeque() {
  std::deque<int> d;
  setupContainer(d);
  displayInfo(d, "deque");
  testEasyFind(d, 1);
  testEasyFind(d, 11);
}

void testList() {
  std::list<int> lst;
  setupContainer(lst);
  displayInfo(lst, "list");
  testEasyFind(lst, 2);
  testEasyFind(lst, 13);
}

void testConstVector() {
  const std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayInfo(v, "const vector");
  testEasyFind(v, 3);
  testEasyFind(v, 17);
}

void testConstDeque() {
  const std::deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayInfo(d, "const deque");
  testEasyFind(d, 5);
  testEasyFind(d, 19);
}

void testConstList() {
  const std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
  displayInfo(lst, "const list");
  testEasyFind(lst, 7);
  testEasyFind(lst, 23);
}

int main() {
  testVector();
  testDeque();
  testList();
  testConstVector();
  testConstDeque();
  testConstList();
  return 0;
}
