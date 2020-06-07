#pragma once
#include "api.h"
#include "boost/any.hpp"

namespace Hyperion {
	/// <summary>
	/// An expansion of <c>boost::any</c> which also stores the size of the currently held type.
	/// </summary>
	/// <remark>
	/// The <c>boost::any</c> class stores any type of data by storing it inside a <c>void*</c
	/// </remark>
	/// <seealso cref="boost::any" />
	class HPR_API SizedAny : public boost::any {
	private:
		/// <summary>
		/// The size of the currently held type.
		/// </summary>
		size_t size = 0;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="SizedAny"/> class.
		/// </summary>
		SizedAny() {

		}

		/// <summary>
		/// Initializes a new instance of the <see cref="SizedAny"/> class.
		/// </summary>
		/// <param name="val">The new value of the class.</param>
		template<typename T>
		SizedAny(T val) : boost::any(val) {
			size = sizeof(val);
		}

		/// <summary>
		/// Assigns <paramref name="rhs" /> as the new value.
		/// </summary>
		/// <param name="rhs">The new value</param>
		template<typename ValueType>
		SizedAny& operator=(const ValueType& rhs) {
			boost::any::operator=(rhs);
			size = sizeof(ValueType);
			return *this;
		}

		/// <summary>
		/// Assigns <paramref name="rhs" /> as the new value.
		/// </summary>
		/// <param name="rhs">the new value.</param>
		template<typename ValueType>
		SizedAny& operator=(ValueType&& rhs) {
			boost::any::operator=(rhs);
			size = sizeof(ValueType);
			return *this;
		}

		/// <summary>
		/// Assigns <paramref name="rhs" /> as the new value.
		/// </summary>
		/// <param name="rhs">the new value.</param>
		SizedAny& operator=(const SizedAny& rhs);

		
		/// <summary>
		/// Swaps two <see cref="SizedAny" />s.
		/// </summary>
		/// <param name="other">The other <see cref="SizedAny" />.</param>
		void swap(SizedAny& other);

		/// <summary>
		/// Gets the size of the currently held type.
		/// </summary>
		/// <returns>The size of the currently held type.</returns>
		size_t getSize();
	};
}