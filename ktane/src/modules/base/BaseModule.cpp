#include "BaseModule.h"

BaseModule::BaseModule(AbstractControllerModule* controllerModule, int statusLED) {
	this->controllerModule = controllerModule;
}

void BaseModule::Start() {
	AbstractModule::Start();

}

void BaseModule::Update() {
	AbstractModule::Update();
}

void BaseModule::Complete() {
	running = false;
}

void BaseModule::Fail() {
	Serial.println("fail");
	controllerModule->strikes++;
	tone(controllerModule->speaker, NOTE_G3, 200);
}