#include "WiresModule.h"

int GetWireToCut(Color colors[6]) {
	int yellowCount = 0;
	int whiteCount = 0;
	int redCount = 0;

	for (int i = 0; i < 6; i++) {
		if (colors[i] == Yellow)
			yellowCount++;
		else if (colors[i] == White)
			whiteCount++;
		else if (colors[i] == Red)
			redCount++;
	}

	if (yellowCount == 0)
		return 2;

	if (yellowCount == 1 && whiteCount > 1)
		return 3;

	if (redCount == 0)
		return 5;

	return 4;
}

WiresModule::WiresModule(AbstractControllerModule* controllerModule, Color colors[6]): BaseModule(controllerModule) {
	for (int i = 0; i < 6; i++)
		this->colors[i] = colors[i];

	wireToCut = wires[GetWireToCut(colors)];
}

void WiresModule::Start() {
	BaseModule::Start();

	for (int i = 0; i < 6; i++) {
		pinMode(wires[i].pin, INPUT_PULLUP);
		wires[i].color = colors[i];
	}
}

void WiresModule::Update() {
	BaseModule::Update();

	for (ConnectedWire wire : wires) {
		if (digitalRead(wire.pin) == LOW) {
			if (wire.pin == wireToCut.pin)
				Complete();
			else
				Fail();
		}
	}
}