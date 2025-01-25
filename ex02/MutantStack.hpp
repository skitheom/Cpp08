/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:58:13 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/26 01:32:06 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>
template <class T> class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
  ~MutantStack() {}

  MutantStack<T> &operator=(const MutantStack<T> &other) {
    if (this != other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }

  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }

  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif // MUTANTSTACK_HPP
