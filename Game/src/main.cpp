#include "hyperion.h"
using namespace Hyperion;

int main(void) {

	HPRCore a;

	a.Init();

	while (a.Update());
}