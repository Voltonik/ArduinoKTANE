#pragma once
#include "AbstractControllerModule.h"
#include "AbstractModule.h"

class BaseModule: public AbstractModule {
private:
protected:
	AbstractControllerModule* controllerModule;

public:
	BaseModule(AbstractControllerModule* controllerModule);

	virtual void Start();
	virtual void Update();

	virtual void Complete();
	void Fail();
};