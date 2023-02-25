#include "../base/BaseModule.h"
#include "structs.h"

class WiresModule: public BaseModule {
private:
	ConnectedWire wires[4] = { ConnectedWire(53), ConnectedWire(52), ConnectedWire(51), ConnectedWire(50) };
	Color colors[4];
	ConnectedWire wireToCut;

	int GetWireToCut(Color colors[4]);
	bool contains(ConnectedWire wires[4], ConnectedWire item);
public:
	WiresModule(AbstractControllerModule* controllerModule, int statusLED, Color colors[4]);

	void Start();
	void Update();
};
