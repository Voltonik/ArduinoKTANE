#include "../base/BaseModule.h"

enum Symbols {
	None,
	Phi,
	bT,
	RightC,
	Three
};

class SymbolButton {
public:
	int pin;
	bool toggled, previousState;
	Symbols symbol;

	SymbolButton(int _pin = A0) {
		pin = _pin;
	}
};

class SymbolsModule: public BaseModule {
private:
	SymbolButton symbolButtons[4] = { SymbolButton(A0), SymbolButton(A1), SymbolButton(A2), SymbolButton(A3) };
	Symbols orderedSymbols[4];

public:
	SymbolsModule(AbstractControllerModule* controllerModule, int statusLED, Symbols orderedSymbols[4]);

	void Start();
	void Update();
};