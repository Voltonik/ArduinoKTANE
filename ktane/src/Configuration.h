#include "modules/base/AbstractModule.h"

class Configuration {
public:
	AbstractModule** modules = new AbstractModule * [5];

	Configuration(AbstractModule** modules) {
		this->modules = modules;
	}

	void Start() {
		for (uint8_t i = 0; i < 5; i++) {
			modules[i]->Start();
		}
	}

	void Update() {
		for (uint8_t i = 0; i < 5; i++) {
			if (modules[i]->running) {
				modules[i]->Update();
			}
		}
	}
};