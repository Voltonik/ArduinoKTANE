#pragma once
#include "AbstractModule.h"

class AbstractControllerModule: public AbstractModule {
private:
protected:
	long explodeTime;
	long currentTime;

	uint8_t maxStrikes;

public:
	AbstractControllerModule(long explodeTime, uint8_t maxStrikes);

	int strikes;

	virtual void Start();
	virtual void Update();

	virtual void Fail() = 0;
	virtual void Complete() = 0;
};