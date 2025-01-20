/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:41:40 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/21 04:13:42 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &t, int n) {

  typename T::iterator it = t.begin();
  while (it != t.end()) {
    if (*it == n) {
      return it;
    }
    ++it;
  }
  throw std::out_of_range("Value not found");
}

#endif // EASYFIND_HPP
