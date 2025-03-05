/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:29:29 by sakitaha          #+#    #+#             */
/*   Updated: 2025/03/05 18:25:53 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "test.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::srand(std::time(0));

  std::vector<int> v;
  testContainer(v, "vector");

  std::deque<int> d;
  testContainer(d, "deque");

  std::list<int> lst;
  testContainer(lst, "list");

  const std::vector<int> cv(arr, arr + sizeof(arr) / sizeof(arr[0]));
  testContainer(cv, "const vector");

  const std::deque<int> cd(arr, arr + sizeof(arr) / sizeof(arr[0]));
  testContainer(cd, "const deque");

  const std::list<int> clst(arr, arr + sizeof(arr) / sizeof(arr[0]));
  testContainer(clst, "const list");
  return 0;
}
