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
	 * A data structure representing a list
	 * (Does not inherit from container to satisfy aggregate conditions)
	 */
	template<typename T, size_t L> class Array {
	public:
		/**
		 * The data of the array
		 */
		T data[L];

		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		T& operator[](size_t index) {
			assert(index < L);
			return data[index];
		}

		/**
		 * Gets an element from the list at an index
		 * @param index The index of the element to retrieve
		 * @returns The element (null if it is out of range)
		 */
		const T& operator[](size_t index) const {
			assert(index < L);
			return data[index];
		}

		/**
		 * Returns the length of the data structure
		 * @returns The length of the array
		 */
		inline size_t length() const {
			return L;
		}

		/**
		 * Checks if an index is valid for the list
		 * @param index The index to check
		 * @returns Whether or not the index is valid for this list
		 */
		inline bool contains(const size_t& index) const {
			return index < L;
		}

		/**
		 * Checks if an element is in the list (Uses == to check)
		 * @param item The item to check for
		 * @returns Whether or not the list contains the element
		 */
		bool contains(const T& item) const {
			for (size_t i = 0; i < L; i++) {
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
			for (size_t i = 0; i < L; i++) {
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
			for (size_t i = L - 1; i >= 0; i--) {
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