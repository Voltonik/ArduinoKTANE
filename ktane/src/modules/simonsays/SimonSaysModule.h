#include "../base/BaseModule.h"

class SimonSaysModule: public BaseModule {
private:


public:
	SimonSaysModule(AbstractControllerModule* controllerModule);

	void Start();
	void Update();
};