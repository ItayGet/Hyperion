#include "hpr.h"

int main(void) {
	bool succ = false;
	Hyperion::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		a.addShape({ glm::vec3(1., 0., -5.), .25, glm::vec3(.1, 0., 1.), 0.5 });
		a.addShape({ glm::vec3(.5, 0., -5.), .25, glm::vec3(.75, .75, .75), 1., });
		a.addShape({ glm::vec3(0., 0., -5.), .25,  glm::vec3(.5, .5, .5), 2. });
		a.addShape({ glm::vec3(-.5, 0., -5.), .25,  glm::vec3(.25, .25, .25), 3., });
		a.addShape({ glm::vec3(-1., 0., -5.), .25,  glm::vec3(0., 1., 0.), 4. });
		while (a.update()) {
			
		}
	}
	a.terminate();
}