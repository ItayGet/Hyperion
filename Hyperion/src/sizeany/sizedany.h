#pragma once
#include "api.h"
#include "boost/any.hpp"

namespace Hyperion {
	class HPR_API SizedAny : public boost::any {
	private:
		size_t size = 0;
	public:
		SizedAny() {

		}

		template<typename T>
		SizedAny(T val) : boost::any(val) {
			size = sizeof(val);
		}

		template< class ValueType, class... Args >
		boost::decay_t<ValueType>& emplace(Args&&... args) {
			size = sizeof(ValueType);
			return boost::any::emplace(args);
		}

		template<typename ValueType>
		SizedAny& operator=(const ValueType& rhs) {
			boost::any::operator=(rhs);
			size = sizeof(ValueType);
			return *this;
		}

		template<typename ValueType>
		SizedAny& operator=(ValueType&& rhs) {
			boost::any::operator=(rhs);
			size = sizeof(ValueType);
			return *this;
		}

		SizedAny& operator=(const SizedAny& rhs);

		void swap(SizedAny& other);

		size_t getSize();
	};
}