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
	 * A Data structure representing a Queue
	 */
	template<typename T> class Queue : public Container<T> {
	public:
		/**
		 * Adds a new item to the end of the queue
		 * @param item The item to add
		 */
		virtual void push(T& item) = 0;

		/**
		 * Adds multiple items to the end of the queue
		 * @param items The items to add to the container
		 */
		virtual void push(Container<T>& items) = 0;

		/**
		 * Removes the first element from the queue
		 * @returns The element removed
		 */
		virtual T& dequeue() = 0;

		/**
		 * Returns the first element of the queue without returning it
		 * @returns The first element of the queue
		 */
		virtual T& peek() = 0;
	};
}

/**
 * A namespace alias to the Essentials namespace
 */
namespace es = Essentials;