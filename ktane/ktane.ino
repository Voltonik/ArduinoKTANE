#include "src/modules/base/AbstractModule.h"
#include "src/modules/controller/ControllerModule.h"
#include "src/modules/wires/WiresModule.h"
#include "src/modules/simonsays/SimonSaysModule.h"
#include "src/modules/symbols/SymbolsModule.h"

ControllerModule* controllerModule = new ControllerModule(300000, 2);

AbstractModule** modules = new AbstractModule * [5] {
	controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
};

void setup() {
	Serial.begin(9600);

	for (uint8_t i = 0; i < 5; i++) {
		modules[i]->Start();
	}
}

void loop() {
	for (uint8_t i = 0; i < 5; i++) {
		if (modules[i]->running) {
			modules[i]->Update();
		}
	}
}