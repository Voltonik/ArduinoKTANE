#pragma once
#include "AbstractModule.h"

class AbstractControllerModule: public AbstractModule {
private:
protected:
	long explodeTime;
	long currentTime;

	uint8_t maxStrikes = 2;

public:
	AbstractControllerModule(long explodeTime, uint8_t maxStrikes);

	uint8_t strikes = 0;

	virtual void Start();
	virtual void Update();

	virtual void Strike();
	virtual void Lose();
	virtual void Win();
};