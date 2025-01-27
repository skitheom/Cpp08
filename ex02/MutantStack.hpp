/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:13 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/27 18:31:12 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>
#include <string>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() { printDebugMsg(DEFAULT_CONSTRUCTOR); }

  MutantStack(const MutantStack &other) : std::stack<T>(other) {
    printDebugMsg(COPY_CONSTRUCTOR);
  }

  ~MutantStack() { printDebugMsg(DESTRUCTOR); }

  MutantStack &operator=(const MutantStack &other) {
    printDebugMsg(ASSIGNMENT_OPERATOR);
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }

  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  iterator begin() {
    printDebugMsg(BEGIN_NON_CONST);
    return this->c.begin();
  }

  iterator end() {
    printDebugMsg(END_NON_CONST);
    return this->c.end();
  }

  const_iterator begin() const {
    printDebugMsg(BEGIN_CONST);
    return this->c.begin();
  }

  const_iterator end() const {
    printDebugMsg(END_CONST);
    return this->c.end();
  }

  reverse_iterator rbegin() {
    printDebugMsg(RBEGIN_NON_CONST);
    return this->c.rbegin();
  }

  reverse_iterator rend() {
    printDebugMsg(REND_NON_CONST);
    return this->c.rend();
  }

  const_reverse_iterator rbegin() const {
    printDebugMsg(RBEGIN_CONST);
    return this->c.rbegin();
  }

  const_reverse_iterator rend() const {
    printDebugMsg(REND_CONST);
    return this->c.rend();
  }

private:
  enum DebugMsgType {
    DEFAULT_CONSTRUCTOR,
    COPY_CONSTRUCTOR,
    DESTRUCTOR,
    ASSIGNMENT_OPERATOR,
    BEGIN_NON_CONST,
    END_NON_CONST,
    BEGIN_CONST,
    END_CONST,
    RBEGIN_NON_CONST,
    REND_NON_CONST,
    RBEGIN_CONST,
    REND_CONST
  };

  void printDebugMsg(MutantStack<T>::DebugMsgType msgType) const {
#ifdef DISPLAY_DEBUG_MSG
    static const char *messages[] = {
        "Default constructor called",  "Copy constructor called",
        "Destructor called",           "Assignment operator called",
        "begin() called (non-const)",  "end() called (non-const)",
        "begin() called (const)",      "end() called (const)",
        "rbegin() called (non-const)", "rend() called (non-const)",
        "rbegin() called (const)",     "rend() called (const)"};
    std::cerr << "[DEBUG] " << messages[msgType] << std::endl;
#endif
    (void)msgType;
  }
};

#endif // MUTANTSTACK_HPP
