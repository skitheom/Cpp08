/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:57:53 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/27 18:50:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

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

void emptyStackTest(bool enableSegFault = false) {
  std::cout << "\n=== Empty Stack Test ===" << std::endl;
  MutantStack<int> emptyMutantStack;
  std::stack<int> emptyStack;

  if (!enableSegFault) {
    std::cout << "Avoiding Segmentation fault by return;\n"
              << "Call 'emptyStackTest(true);' to test top() on empty stack"
              << std::endl;
    return;
  }
  std::cout << "Trying top() on empty mutant stack:" << std::endl;
  emptyMutantStack.top();
  std::cout << "Trying top() on empty stack:" << std::endl;
  emptyStack.top();
}

void largeDataTest() {

  std::cout << "\n=== Large Data Test  ===" << std::endl;

  MutantStack<int> mstack;
  const int largeSize = 100000;

  std::cout << "Trying to push() " << largeSize << " elements..." << std::endl;
  for (int i = 0; i < largeSize; ++i) {
    mstack.push(i);
  }
  std::cout << "Size of MutantStack: " << mstack.size() << std::endl;

  std::cout << "Trying to pop() " << largeSize << " elements..." << std::endl;
  for (int i = 0; i < largeSize; ++i) {
    mstack.pop();
  }
  std::cout << "Size of MutantStack: " << mstack.size() << std::endl;
}

void nonConstIteratorTest() {
  std::cout << "\n=== Non Const Iterator Test ===" << std::endl;

  MutantStack<int> mstack;
  const int size = 10;

  for (size_t i = 0; i < size; i++) {
    mstack.push(i);
  }

  std::cout << "Contents in regular order:";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << " " << *it;
  }
  std::cout << "\nContents in reverse order:";
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << " " << *rit;
  }
  std::cout << std::endl;
}

void constIteratorTest() {
  std::cout << "\n=== Const Iterator Test ===" << std::endl;

  MutantStack<int> tmpStack;
  const int size = 10;

  for (size_t i = 0; i < size; i++) {
    tmpStack.push(i);
  }

  const MutantStack<int> cmStack = tmpStack;

  std::cout << "Contents in regular order:";
  for (MutantStack<int>::const_iterator cit = cmStack.begin();
       cit != cmStack.end(); ++cit) {
    std::cout << " " << *cit;
  }

  std::cout << "\nContents in reverse order:";
  for (MutantStack<int>::const_reverse_iterator rcit = cmStack.rbegin();
       rcit != cmStack.rend(); ++rcit) {
    std::cout << " " << *rcit;
  }
  std::cout << std::endl;
}

void compatibilityTest() {
  std::cout << "\n=== Compatibility Test ===" << std::endl;

  MutantStack<int> mstack;
  const int size = 4;

  for (size_t i = 0; i < size; i++) {
    mstack.push(i);
  }

  std::vector<int> v;
  std::deque<int> d;
  std::list<int> lst;
  std::stack<int> stk;

  for (size_t i = 0; i < size; i++) {
    v.push_back(i);
    d.push_back(i);
    lst.push_back(i);
    stk.push(i);
  }

  for (size_t i = 0; i < size; i++) {
    std::cout << "MutantStack: " << mstack.top() << ", ";
    mstack.pop();

    std::cout << "std::vector: " << v.back() << ", ";
    v.pop_back();

    std::cout << "std::deque: " << d.back() << ", ";
    d.pop_back();

    std::cout << "std::list:" << lst.back() << ", ";
    lst.pop_back();

    std::cout << "std::stack: " << stk.top() << std::endl;
    stk.pop();
  }
}

int main() {
  sampleTest();
  emptyStackTest(); // emptyStackTest(true); <- for testing
  largeDataTest();
  nonConstIteratorTest();
  constIteratorTest();
  compatibilityTest();
  return 0;
}
