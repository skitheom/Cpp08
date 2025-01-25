/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:53:28 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/26 01:34:04 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <stdexcept>

const unsigned int Span::kMaxSpan = std::numeric_limits<unsigned int>::max();

Span::Span() : data_(), maxSize_(0), minSpan_(kMaxSpan) {
  displayDebugMsg("Span default constructor called");
}

Span::Span(unsigned int maxSize)
    : data_(), maxSize_(maxSize), minSpan_(kMaxSpan) {
  displayDebugMsg("Span size constructor called");
}

Span::Span(const Span &other)
    : data_(other.data_), maxSize_(other.maxSize_), minSpan_(other.minSpan_) {
  displayDebugMsg("Span copy constructor called");
}

Span::~Span() { displayDebugMsg("Span destructor called"); }

Span &Span::operator=(const Span &other) {
  displayDebugMsg("Span copy assignment operator called");
  if (this != &other) {
    data_ = other.data_;
    maxSize_ = other.maxSize_;
    minSpan_ = other.minSpan_;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (data_.size() >= maxSize_) {
    throw std::out_of_range("The capacity is full, unable to add a new number");
  }
  std::multiset<int>::iterator it = data_.insert(n);
  evaluateMinSpan(it, n);
#ifdef DISPLAY_DEBUG_MSG
  std::ostringstream oss;
  oss << n << " is added to your data \t(Updated minSpan: " << minSpan_ << ")";
  std::cout << oss.str() << std::endl;
#endif
}

unsigned int Span::shortestSpan() const {
  if (data_.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate the shortest span");
  }
  return minSpan_;
}

unsigned int Span::longestSpan() const {
  if (data_.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate the longest span");
  }
  std::multiset<int>::iterator minIt = data_.begin();
  std::multiset<int>::iterator maxIt = data_.end();
  --maxIt;
  return calculateSpan(*maxIt, *minIt);
}

unsigned int Span::calculateSpan(int n1, int n2) const {
  long long diff = static_cast<long long>(n1) - static_cast<long long>(n2);
  diff = std::abs(diff);
  return static_cast<unsigned int>(diff);
}

void Span::updateMinSpan(int n1, int n2) {
  unsigned int currentSpan = calculateSpan(n1, n2);
  minSpan_ = std::min(minSpan_, currentSpan);
}

void Span::processPrevValue(std::multiset<int>::iterator &it, int n) {
  std::multiset<int>::iterator prevIt = it;
  --prevIt;
  updateMinSpan(n, *prevIt);
}

void Span::processNextValue(std::multiset<int>::iterator &it, int n) {
  std::multiset<int>::iterator nextIt = it;
  ++nextIt;
  updateMinSpan(*nextIt, n);
}

void Span::evaluateMinSpan(std::multiset<int>::iterator &it, int n) {
  if (minSpan_ == 0) {
    return;
  }
  if (it != data_.begin()) {
    processPrevValue(it, n);
  }
  if (++it != data_.end()) {
    --it;
    processNextValue(it, n);
  }
}

void Span::displayDebugMsg(const std::string &msg) const {
#ifdef DISPLAY_DEBUG_MSG
  std::cout << msg << std::endl;
#endif
  (void)msg;
}
