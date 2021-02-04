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
	 * A data structure repsenting a Stack
	 */
	template<typename T> class Stack : public Container<T> {
	public:
		/**
		 * Adds a new item to the end of the stack
		 * @param item The item to add
		 */
		virtual void push(T& item) = 0;

		/**
		 * Adds multiple new items to the end of the stack
		 * @param items The items to add to the stack
		 */
		virtual void push(Container<T>& items) = 0;

		/**
		 * Removes the last item from the stack
		 * @returns the removed element
		 */
		virtual T& pop() = 0;

		/**
		 * Peeks at the last item from the stack without removing it
		 * @returns The last element from the stack
		 */
		virtual T& peek() = 0;
	};
}

/**
 * A namespace alias to the Essentials namespace
 */
namespace es = Essentials;