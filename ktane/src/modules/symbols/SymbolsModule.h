#include "../base/BaseModule.h"

class SymbolsModule: public BaseModule {
private:


public:
	SymbolsModule(AbstractControllerModule* controllerModule);

	void Start();
	void Update();
};