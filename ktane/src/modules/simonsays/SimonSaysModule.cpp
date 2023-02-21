#include "SimonSaysModule.h"

SimonSaysModule::SimonSaysModule(AbstractControllerModule* controllerModule): BaseModule(controllerModule) {

}

void SimonSaysModule::Start() {
	BaseModule::Start();

}


void SimonSaysModule::Update() {
	BaseModule::Update();

	if (Serial.available() > 0) {
		String data = Serial.readString();

		if (data == "fail") {
			Fail();
		}
	}
}