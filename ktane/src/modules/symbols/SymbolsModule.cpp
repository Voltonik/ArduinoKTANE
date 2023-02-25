#include "SymbolsModule.h"

SymbolsModule::SymbolsModule(AbstractControllerModule* controllerModule, int statusLED, Symbols orderedSymbols[4]): BaseModule(controllerModule, statusLED) {
	for (int i = 0; i < 4; i++)
		this->orderedSymbols[i] = orderedSymbols[i];
}

void SymbolsModule::Start() {
	BaseModule::Start();

	for (int i = 0; i < 6; i++) {
		pinMode(symbolButtons[i].pin, INPUT_PULLUP);
		symbolButtons[i].symbol = orderedSymbols[i];
	}
}

bool CheckPattern(Symbols pattern[4], Symbols ordered[4]) {
	for (int i = 0; i < 4; i++) {
		if (pattern[i] != ordered[i])
			return false;
	}
	return true;
}

void SymbolsModule::Update() {
	BaseModule::Update();

	Symbols currentInput[4] = { None, None, None, None };

	for (int i = 0; i < 4; i++) {
		bool btnState = digitalRead(symbolButtons[i].pin);

		if (btnState != symbolButtons[i].previousState) {
			symbolButtons[i].toggled = !symbolButtons[i].toggled;
			if (symbolButtons[i].toggled) {
				for (int j = 0; j < 4; j++) {
					if (currentInput[j] == None) {
						currentInput[j] = symbolButtons[i].symbol;
						break;
					} else if (j == 3) {
						if (CheckPattern(currentInput, orderedSymbols))
							Complete();
						else {
							for (int k = 0; k < 4; k++)
								symbolButtons[k].toggled = false;
							Fail();
							Serial.println("symbols failed");
						}
					}
				}
			}
		}
	}
}