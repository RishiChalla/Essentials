/*
   Copyright 2021 Rishi Challa

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once

#include "Container.h"

/**
 * The main namespace for data structures in the essentials library
 */
namespace Essentials::DataStructures {

	/**
	 * A namespace alias to the data structures namespace
	 */
	namespace ds = DataStructures;

	/**
	 * A data structure representing a list
	 */
	template<typename T> class List : public Container<T> {
	public:
		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		virtual T& operator[](size_t index) = 0;

		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		virtual const T& operator[](size_t index) const = 0;

		/**
		 * Adds a new item to the end of the list
		 * @param item The item to add to the list
		 */
		virtual void push(const T& item) = 0;

		/**
		 * Adds a new item to the end of the list
		 * @param item The item to add to the list
		 */
		virtual void push(T&& item) = 0;

		/**
		 * Adds multiple new items to the end of the list
		 * @param items The items to add to the list
		 */
		virtual void push(const List<T>& items) = 0;

		/**
		 * Adds an item at any position in the list
		 * @param item The item to add
		 * @param index The index to add after (ie [0, 1, 2] .add(3, 1) -> [0, 1, 3, 2])
		 */
		virtual void add(const T& item, size_t index) = 0;

		/**
		 * Adds an item at any position in the list
		 * @param item The item to add
		 * @param index The index to add after (ie [0, 1, 2] .add(3, 1) -> [0, 1, 3, 2])
		 */
		virtual void add(T&& item, size_t index) = 0;

		/**
		 * Removes an element from the list at a certain index
		 * @param index The index to remove
		 */
		virtual void remove(size_t index) = 0;

		/**
		 * Removes elements from the list at a certain index
		 * @param index The index to remove
		 * @param count The number of elements to remove, by default is 1
		 */
		virtual void remove(size_t index, size_t count) = 0;

		/**
		 * Completely clears all items in the list
		 */
		virtual void clear() = 0;

		/**
		 * Checks if an index is valid for the list
		 * @param index The index to check
		 * @returns Whether or not the index is valid for this list
		 */
		virtual bool contains(size_t index) const = 0;

		/**
		 * Checks if an element is in the list (Uses == to check)
		 * @param item The item to check for
		 * @returns Whether or not the list contains the element
		 */
		virtual bool contains(const T& item) const = 0;

		/**
		 * Gets the index of the first match of an element (-1 if not found)
		 * @param item The element to search for
		 * @returns The index of the element (-1 if not found)
		 */
		virtual int indexOf(const T& item) const = 0;

		/**
		 * Gets the index of the last match of an element (-1 if not found)
		 * @param item The element to search for
		 * @returns The index of the element (-1 if not found)
		 */
		virtual int lastIndexOf(const T& item) const = 0;
	};
}

/**
 * A namespace alias to the Essentials namespace
 */
namespace es = Essentials;