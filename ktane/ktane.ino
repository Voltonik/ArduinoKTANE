#include "EEPROM.h"

#include "src/modules/base/AbstractModule.h"
#include "src/modules/controller/ControllerModule.h"
#include "src/modules/wires/WiresModule.h"
#include "src/modules/simonsays/SimonSaysModule.h"
#include "src/modules/symbols/SymbolsModule.h"

#include "src/Configuration.h"

ControllerModule* controllerModule = new ControllerModule(300000, 2);

Configuration configs[5]{
	Configuration(new AbstractModule * [5] {
		controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
	}),
	Configuration(new AbstractModule * [5] {
		controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
	}),
	Configuration(new AbstractModule * [5] {
		controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
	}),
	Configuration(new AbstractModule * [5] {
		controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
	}),
	Configuration(new AbstractModule * [5] {
		controllerModule,
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Black, Black, Blue, White }),
		new WiresModule(controllerModule, new Color[6]{ Yellow, Yellow, Red, Red, Black, Red }),
		new SimonSaysModule(controllerModule),
		new SymbolsModule(controllerModule)
	})
};

Configuration currentConfig;


void(*resetArduino) (void) = 0;

void LoadConfig(int config) {
	EEPROM.write(0, config);

	resetArduino();
}

void setup() {
	Serial.begin(9600);

	currentConfig = configs[EEPROM.read(0)];

	currentConfig.Start();
}

void loop() {
	currentConfig.Update();
}