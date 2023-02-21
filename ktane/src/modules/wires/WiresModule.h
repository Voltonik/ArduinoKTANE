#include "../base/BaseModule.h"

class WiresModule: public BaseModule {
private:


public:
	WiresModule(AbstractControllerModule* controllerModule);

	void Start();
	void Update();
};