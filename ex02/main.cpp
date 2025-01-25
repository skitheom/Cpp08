/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:57:53 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/26 01:07:41 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

void sampleTest() {
  std::cout << "\n=== Sample Test ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void edgeCaseTest() {
  std::cout << "\n=== Edge Case Test ===" << std::endl;
  ;
  // TODO: later to write here
}

void testLargeData() {
  std::cout << "\n=== Test: Large Data ===" << std::endl;
  MutantStack<int> mstack;
  const int largeSize = 10000;

  for (int i = 0; i < largeSize; ++i) {
    mstack.push(i);
  }

  std::cout << "Size after pushing " << largeSize
            << " elements: " << mstack.size() << std::endl;

  for (int i = 0; i < largeSize; ++i) {
    mstack.pop();
  }

  std::cout << "Size after popping all elements: " << mstack.size()
            << std::endl;
}

void testReverseIterator() {
  std::cout << "\n=== Test: Reverse Iterator ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(1);
  mstack.push(2);
  mstack.push(3);
  mstack.push(4);

  std::cout << "Contents in reverse order:" << std::endl;
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << *rit << std::endl;
  }
}

/*
void testCustomContainer() {
  std::cout << "\n=== Test: Custom Container ===" << std::endl;
  MutantStack<int, std::vector<int>> mstack; // std::vector を使用
  mstack.push(42);
  mstack.push(84);

  for (MutantStack<int, std::vector<int>>::iterator it = mstack.begin(); it !=
mstack.end(); ++it) { std::cout << *it << std::endl;
  }
}
 */

void testStdStackCompatibility() {
  std::cout << "\n=== Test: std::stack Compatibility ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(10);
  mstack.push(20);

  std::stack<int> s(mstack);

  std::cout << "Contents of std::stack:" << std::endl;
  while (!s.empty()) {
    std::cout << s.top() << std::endl;
    s.pop();
  }
}

int main() {
  sampleTest();
  edgeCaseTest();
  testLargeData();
  testReverseIterator();
  testStdStackCompatibility();
  return 0;
}
