#pragma once
#include "AbstractcontrollerModule.h"
#include "AbstractModule.h"

class BaseModule: public AbstractModule {
protected:
	AbstractControllerModule* controllerModule;

public:
	BaseModule(AbstractControllerModule* controllerModule, int statusLED);

	virtual void Start();
	virtual void Update();

	virtual void Complete();
	virtual void Fail();
};