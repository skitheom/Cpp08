/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:41:40 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/25 01:54:15 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <sstream>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &t, int n) {
  typename T::iterator it = std::find(t.begin(), t.end(), n);
  if (it == t.end()) {
    std::ostringstream oss;
    oss << "value " << n << " not found";
    throw std::out_of_range(oss.str());
  }
  return it;
}

template <typename T> typename T::const_iterator easyfind(const T &t, int n) {
  typename T::const_iterator it = std::find(t.begin(), t.end(), n);
  if (it == t.end()) {
    std::ostringstream oss;
    oss << "value " << n << " not found";
    throw std::out_of_range(oss.str());
  }
  return it;
}

#endif // EASYFIND_HPP
