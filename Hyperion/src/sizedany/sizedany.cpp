#include "sizedany.h"

namespace Hyperion {
	size_t SizedAny::getSize() {
		return size;
	}

	void SizedAny::swap(SizedAny& other) {
		boost::any::swap(other);
		auto tmp = size;
		size = other.size;
		other.size = tmp;
	}

	SizedAny& SizedAny::operator=(const SizedAny& rhs) {
		boost::any::operator=(rhs);
		size = rhs.size;
		return *this;
	}
}