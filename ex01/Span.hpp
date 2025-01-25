/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:51:34 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/25 15:56:05 by sakitaha         ###   ########.fr       */
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
