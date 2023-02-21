#pragma once
#include "Arduino.h"

class AbstractModule {
private:
protected:

public:
	bool running;

	virtual void Start();
	virtual void Update();
};