#include "WiresModule2.h"

int WiresModule2::GetWireToCut(Color colors[3]) {
	int yellowCount = 0;
	int whiteCount = 0;
	int redCount = 0;

	for (int i = 0; i < 3; i++) {
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

WiresModule2::WiresModule2(AbstractControllerModule* controllerModule, int statusLED, Color colors[3]): BaseModule(controllerModule, statusLED) {
	for (int i = 0; i < 3; i++)
		this->colors[i] = colors[i];

	wireToCut = wires[1];
}

void WiresModule2::Start() {
	BaseModule::Start();

	for (int i = 0; i < 3; i++) {
		pinMode(wires[i].pin, INPUT_PULLUP);
		wires[i].color = colors[i];
	}
}

bool WiresModule2::contains(ConnectedWire wires[3], ConnectedWire item) {
	for (int i = 0; i < 3; i++) {
		if (wires[i].pin == item.pin) {
			return true;
		}
	}
	return false;
}

void WiresModule2::Update() {
	BaseModule::Update();

	for (int i = 0; i < 3; i++) {
		if (digitalRead(wires[i].pin) == HIGH) {
			if (wires[i].pin == wireToCut.pin)
				Complete();
			else {
				controllerModule->Lose();
			}
		}
	}
}