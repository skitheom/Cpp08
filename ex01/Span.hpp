/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:51:34 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/25 14:39:39 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>

class Span {
private:
  static const unsigned int kMaxSpan;

  std::multiset<int> data_;
  unsigned int maxSize_;
  unsigned int minSpan_;

  Span();

public:
  Span(unsigned int maxSize);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  void addNumber(int n);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

private:
  unsigned int calculateSpan(int next, int prev) const;
  void updateMinSpan(int next, int prev);
  void processPrevValue(std::multiset<int>::iterator &it, int n);
  void processNextValue(std::multiset<int>::iterator &it, int n);
  void evaluateMinSpan(std::multiset<int>::iterator &it, int n);
  void displayDebugMsg(const std::string &msg) const;
};

#endif // SPAN_HPP

/*
Should output:
$> ./ex01
2
14
$>

Last but not least, it would be wonderful to fill your Span using a range of
iterators. Making thousands calls to addNumber() is so annoying. Implement a
member function to add many numbers to your Span in one call.

If you don’t have a clue, study the Containers.

Some member functions take a range of iterators in order to add a sequence of
elements to the container.
 */

/*



  void addNumber(int n) {
    if (numbers_.size() >= maxSize_) {
      throw std::out_of_range("Span is full");
    }

    // 現在の値をセットに挿入
    auto result = numbers_.insert(n);

    // 挿入した値のイテレータ
    auto it = result;

    // 前後の値を取得してスパンを計算
    if (it != numbers_.begin()) {
      int prev = *std::prev(it);
      minSpan_ = std::min(minSpan_, n - prev);
    }
    if (std::next(it) != numbers_.end()) {
      int next = *std::next(it);
      minSpan_ = std::min(minSpan_, next - n);
    }
  }

  int shortestSpan() const {
    if (numbers_.size() < 2) {
      throw std::logic_error("Not enough numbers to calculate span");
    }
    return minSpan_;
  }

  int longestSpan() const {
    if (numbers_.size() < 2) {
      throw std::logic_error("Not enough numbers to calculate span");
    }
    return *numbers_.rbegin() - *numbers_.begin(); // 最大値 - 最小値
  }
};

std::multiset<型名> mst;


Develop a Span class that can store a maximum of N integers. N is an unsigned
int variable and will be the only parameter passed to the constructor.

This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new
element if there are already N elements stored should throw an exception.

Next, implement two member functions: shortestSpan() and longestSpan()

They will respectively find out the shortest span or the longest span (or
distance, if you prefer) between all the numbers stored, and return it. If there
are no numbers stored, or only one, no span can be found. Thus, throw an
exception.

Of course, you will write your own tests and they will be way more thorough than
the ones below. Test your Span at least with a minimum of 10 000 numbers. More
would be even better
 */
