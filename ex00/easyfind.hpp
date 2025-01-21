/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:41:40 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/21 19:49:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename T> typename T::iterator easyfind(T &t, int n) {
  typename T::iterator it = std::find(t.begin(), t.end(), n);
  if (it == t.end()) {
    std::ostringstream oss;
    oss << "Value " << n << " not found";
    throw std::out_of_range(oss.str());
  }
  return it;
}

template <typename T> void testEasyFind(T &t, const std::string &type, int n) {
  std::cout << "Searching " << n << " in " << type << " ... ";
  try {
    std::cout << *(easyfind(t, n)) << " is found! :D" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

template <typename T>
void printContainer(const T &container, const std::string &type) {
  std::cout << "Values in " << type << " : ";
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

#endif // EASYFIND_HPP
