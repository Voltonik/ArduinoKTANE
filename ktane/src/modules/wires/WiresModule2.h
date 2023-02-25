#include "../base/BaseModule.h"
#include "structs.h"

class WiresModule2: public BaseModule {
private:
	ConnectedWire wires[3] = { ConnectedWire(49), ConnectedWire(48), ConnectedWire(47) };
	Color colors[3];
	ConnectedWire wireToCut;
	ConnectedWire failedWires[3];

	int GetWireToCut(Color colors[3]);
	bool contains(ConnectedWire wires[3], ConnectedWire item);
public:
	WiresModule2(AbstractControllerModule* controllerModule, int statusLED, Color colors[3]);

	void Start();
	void Update();
};