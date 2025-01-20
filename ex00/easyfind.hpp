/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:41:40 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/21 05:06:52 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &t, int n) {
  typename T::iterator it = std::find(t.begin(), t.end(), n);
  if (it == t.end()) {
    throw std::out_of_range("Value not found");
  }
  return it;
}

#endif // EASYFIND_HPP
