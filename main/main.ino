#include "src/modules/base/BaseModule.h"
#include "src/modules/controller/ControllerModule.h"
#include "src/modules/wire/WireModule.h"

ControllerModule controllerModule = ControllerModule(5 * (60 * 1000));

BaseModule modules[5] = {
	controllerModule,
	WireModule(&controllerModule),
	WireModule(&controllerModule),
	WireModule(&controllerModule),
	WireModule(&controllerModule),
};

void setup() {
	Serial.begin(9600);

	for (BaseModule module : modules) {
		module.Start();
	}
}

void loop() {
	for (BaseModule module : modules) {
		if (module.running)
			module.Update();
	}
}