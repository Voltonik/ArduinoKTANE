#include "modules/base/BaseModule.h"
#include "modules/controller/ControllerModule.h"
#include "modules/wire/WireModule.h"

BaseModule modules[5] = {
	ControllerModule(),
	WireModule(),
	WireModule(),
	WireModule(),
	WireModule(),
};

void setup() {
	Serial.begin(9600);
	
	for (BaseModule module : modules) {
		module.Start();
	}
}

void loop() {
	for (BaseModule module : modules) {
		module.Update();
	}
}