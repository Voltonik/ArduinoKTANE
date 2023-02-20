#pragma once

class ControllerModule;

class BaseModule {
private:
protected:
	ControllerModule* controllerModule;

public:
	bool running;
	bool completed;

	BaseModule(ControllerModule* controllerModule) {
		this->controllerModule = controllerModule;
	}

	virtual void Start() {
		running = true;
	}

	virtual void Update() {

	}
};