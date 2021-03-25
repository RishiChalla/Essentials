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

#include "List.h"
#include <assert.h>

/**
 * The main namespace for data structures in the essentials library
 */
namespace Essentials::DataStructures {

	/**
	 * A namespace alias to the data structures namespace
	 */
	namespace ds = DataStructures;

	/**
	 * An array based heap storage list implementation
	 */
	template<typename T> class ArrayList : public List<T> {
	private:
		/**
		 * The data of the array list
		 */
		T* data = nullptr;

		/**
		 * The length of the array list
		 */
		size_t size = 0;

		/**
		 * The capacity of the array list
		 */
		size_t cap = 0;
	
		/**
		 * Reallocates the memory of the array list
		 * @param newCap the size of the new allocation
		 */
		void realloc(size_t newCap) {
			T* newBlock = new T[newCap];

			if (newCap < size)
				size = newCap;

			for (size_t i = 0; i < size; i++) {
				newBlock[i] = std::move(data[i]);
			}

			for (size_t i = 0; i < size; i++) {
				data[i].~T();
			}
			
			delete[] data;
			data = newBlock;
			cap = newCap;
		}

	public:

		/**
		 * Creates a new empty ArrayList with enough space for 2 elements by default
		 */
		ArrayList() {
			realloc(2);
		}

		/**
		 * Creates a new empty ArrayList with enough space for num elements
		 * @param num The number of elements to prepare for
		 */
		ArrayList(size_t num) {
			realloc(num);
		}

		/**
		 * Frees resources
		 */
		~ArrayList() {
			clear();
			delete[] data;
		}

		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		T& operator[](size_t index) {
			assert(index < size);
			return data[index];
		}

		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		const T& operator[](size_t index) const {
			assert(index < size);
			return data[index];
		}

		/**
		 * Adds a new item to the end of the list
		 * @param item The item to add to the list
		 */
		void push(const T& item) {
			if (size >= cap)
				realloc(cap + cap / 2);
			data[size] = item;
			size++;
		}

		/**
		 * Adds a new item to the end of the list
		 * @param item The item to add to the list
		 */
		void push(T&& item) {
			if (size >= cap)
				realloc(cap + cap / 2);
			data[size] = std::move(item);
			size++;
		}

		/**
		 * Adds multiple new items to the end of the list
		 * @param items The items to add to the list
		 */
		void push(const List<T>& items) {
			prepare(items.length());
			for (size_t i = 0; i < items.length(); i++) {
				data[size] = items[i];
				size++;
			}
		}

		/**
		 * Adds an item at any position in the list
		 * @param item The item to add
		 * @param index The index to add after (ie [0, 1, 2] .add(3, 1) -> [0, 1, 3, 2])
		 */
		void add(const T& item, size_t index) {
			if (size >= cap)
				realloc(cap + cap / 2);
			
			for (size_t i = size - 1; i >= index; i--)
				data[i+1] = std::move(data[i]);
			
			data[index] = item;
			size++;
		}

		/**
		 * Adds an item at any position in the list
		 * @param item The item to add
		 * @param index The index to add after (ie [0, 1, 2] .add(3, 1) -> [0, 1, 3, 2])
		 */
		void add(T&& item, size_t index) {
			if (size >= cap)
				realloc(cap + cap / 2);
			
			for (size_t i = size - 1; i >= index; i--)
				data[i+1] = std::move(data[i]);
			
			data[index] = std::move(item);
			size++;
		}

		/**
		 * Adds a new element to the back of the ArrayList given the arguments to the constructor of the element
		 */
		template<typename... Args>
		T& emplace(Args&&... args) {
			if (size >= cap)
				realloc(cap + cap / 2);
			new(&data[size]) T(std::forward<Args>(args)...);
			size++;
			return data[size - 1];
		}

		/**
		 * Removes elements from the list at a certain index
		 * @param index The index to remove
		 */
		void remove(size_t index) {
			assert(index < size);
			data[index].~T();
			for (size_t i = index+1; i < size; i++) {
				data[i-1] = std::move(data[i]);
			}
			size--;
		}

		/**
		 * Removes elements from the list at a certain index
		 * @param index The index to remove
		 * @param count The number of elements to remove, by default is 1
		 */
		void remove(size_t index, size_t count) {
			assert(index < size);
			for (size_t i = index; i < size; i++) {
				if (i < index + count)
					data[index].~T();
				else
					data[i-count] = std::move(data[i]);
			}
			size -= count;
		}

		/**
		 * Completely removes all items in the list
		 */
		void clear() {
			for (size_t i = 0; i < size; i++) {
				data[i].~T();
			}
			size = 0;
		}

		/**
		 * Returns the length of the data structure
		 * @returns The length of the arraylist
		 */
		inline size_t length() const {
			return size;
		}

		/**
		 * Expands the ArrayList's capacity for an amount of new items
		 * @param num The number of items to prepare for
		 */
		void prepare(size_t num) {
			if (size + num > cap)
				realloc(size + num);
		}

		/**
		 * Checks if an index is valid for the list
		 * @param index The index to check
		 * @returns Whether or not the index is valid for this list
		 */
		bool contains(size_t index) const {
			return index < size;
		}

		/**
		 * Checks if an element is in the list (Uses == to check)
		 * @param item The item to check for
		 * @returns Whether or not the list contains the element
		 */
		bool contains(const T& item) const {
			for (size_t i = 0; i < size; i++) {
				if (item == data[i]) return true;
			}
			return false;
		}

		/**
		 * Gets the index of the first match of an element (-1 if not found)
		 * @param item The element to search for
		 * @returns The index of the element (-1 if not found)
		 */
		int indexOf(const T& item) const {
			for (size_t i = 0; i < size; i++) {
				if (item == data[i]) return static_cast<int>(i);
			}
			return -1;
		}

		/**
		 * Gets the index of the last match of an element (-1 if not found)
		 * @param item The element to search for
		 * @returns The index of the element (-1 if not found)
		 */
		int lastIndexOf(const T& item) const {
			for (size_t i = size - 1; i >= 0; i--) {
				if (item == data[i]) return static_cast<int>(i);
			}
			return -1;
		}
	};
}

/**
 * A namespace alias to the Essentials namespace
 */
namespace es = Essentials;