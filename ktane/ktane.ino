#include "src/modules/base/AbstractModule.h"
#include "src/modules/base/AbstractControllerModule.h"
#include "src/modules/wires/WiresModule.h"
#include "src/modules/wires/WiresModule2.h"
#include "src/modules/simonsays/SimonSaysModule.h"
#include "src/modules/symbols/SymbolsModule.h"

AbstractControllerModule* controllerModule = new AbstractControllerModule(300000, 2);

WiresModule wiresModule1 = WiresModule(controllerModule, 40, new Color[6]{ Color::Yellow, Color::Yellow, Color::Black, Color::Black, Color::Blue, Color::White });
WiresModule2 wiresModule2 = WiresModule2(controllerModule, 41, new Color[3]{ Color::Yellow, Color::Black, Color::White });
SimonSaysModule simonSaysModule = SimonSaysModule(controllerModule, 42);
// SymbolsModule symbolsModule = SymbolsModule(controllerModule, 43, new Symbols[4]{ Phi, bT, RightC, Three });

void setup() {
	Serial.begin(9600);

	controllerModule->Start();
	wiresModule1.Start();
	wiresModule2.Start();
	simonSaysModule.Start();
	// symbolsModule.Start();
}

void loop() {
	if (controllerModule->running) {
		controllerModule->Update();
		if (wiresModule1.running)
			wiresModule1.Update();
		if (wiresModule2.running)
			wiresModule2.Update();
		if (simonSaysModule.running)
			simonSaysModule.Update();
		// if (symbolsModule.running)
		// 	symbolsModule.Update();
	}
}