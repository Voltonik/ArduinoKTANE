#include "../base/BaseModule.h"

enum Color {
	Yellow,
	White,
	Red,
	Blue,
	Black,
	Green
};

struct ConnectedWire {
	int pin;
	bool connected;
	Color color;

	ConnectedWire(int _pin = A0) {
		pin = _pin;
	}
};

class WiresModule: public BaseModule {
private:
	ConnectedWire wires[6] = { ConnectedWire(A0), ConnectedWire(A1), ConnectedWire(A2), ConnectedWire(A3), ConnectedWire(A4), ConnectedWire(A5) };
	Color colors[6];
	ConnectedWire wireToCut;

public:
	WiresModule(AbstractControllerModule* controllerModule, Color colors[6]);

	void Start();
	void Update();
};