/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:23:27 by sakitaha          #+#    #+#             */
/*   Updated: 2025/03/05 18:34:52 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <cstdlib>
#include <iostream>
#include <string>

template <typename T> void setupContainer(T &t) {
  const int MAX_CONTAINER_SIZE = 10;
  for (int i = 0; i < MAX_CONTAINER_SIZE; i++) {
    t.push_back(i);
  }
}

template <typename T> void displayInfo(T &t, const std::string &type) {
  std::cout << "\n=== Testing " << type << " ===" << std::endl;
  std::cout << "Values:";
  for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

template <typename T> void displayInfo(const T &t, const std::string &type) {
  std::cout << "\n=== Testing " << type << " ===" << std::endl;
  std::cout << "Values:";
  for (typename T::const_iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

template <typename T> void testEasyFind(T &t, int n) {
  std::cout << "Searching " << n << "\t->\t";
  try {
    std::cout << *(easyfind(t, n)) << " is found! :D" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

template <typename T> void testEasyFind(const T &t, int n) {
  std::cout << "Searching " << n << "\t->\t";
  try {
    std::cout << *(easyfind(t, n)) << " is found! :D" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

template <typename T> void testContainer(T &t, const std::string &type) {
  setupContainer(t);
  displayInfo(t, type);
  testEasyFind(t, rand() % 10);
  testEasyFind(t, rand() % 99);
  testEasyFind(t, -1);
}

template <typename T> void testContainer(const T &t, const std::string &type) {
  displayInfo(t, type);
  testEasyFind(t, rand() % 10);
  testEasyFind(t, rand() % 99);
  testEasyFind(t, -1);
}

#endif // TEST_HPP
