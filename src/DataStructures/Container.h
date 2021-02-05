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

/**
 * The main namespace for data structures in the essentials library
 */
namespace Essentials::DataStructures {

	/**
	 * A namespace alias to the data structures namespace
	 */
	namespace ds = DataStructures;

	/**
	 * All data structures must inherit from this class
	 */
	template<typename T> class Container {
	public:
		/**
		 * Returns the length of the data structure
		 * @returns The length of the data structure
		 */
		virtual size_t length() const = 0;
	};
}

/**
 * A namespace alias to the Essentials namespace
 */
namespace es = Essentials;