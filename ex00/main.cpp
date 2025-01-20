/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:29:29 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/21 04:29:30 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <set>
#include <vector>

void testVector() {
  std::cout << "=== Vector ===" << std::endl;
  try {
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::vector<int>::iterator it = easyfind(v, 3);
    std::cout << "Found: " << *it << " in Vector" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void testList() {
  std::cout << "=== List ===" << std::endl;
  try {
    std::list<int> lst;
    lst.push_back(0);
    lst.push_back(2);
    lst.push_back(4);
    lst.push_back(8);
    lst.push_back(16);

    std::list<int>::iterator it = easyfind(lst, 32);
    std::cout << "Found: " << *it << " in List" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void testSet() {
  std::cout << "=== Set ===" << std::endl;
  try {
    std::set<int> s;
    s.insert(0);
    s.insert(3);
    s.insert(6);
    s.insert(9);
    s.insert(12);

    std::set<int>::iterator it = easyfind(s, 12);
    std::cout << "Found: " << *it << " in Set" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  testVector();
  testList();
  testSet();
  return 0;
}
