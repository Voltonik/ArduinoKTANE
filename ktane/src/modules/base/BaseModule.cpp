#include "BaseModule.h"

BaseModule::BaseModule(AbstractControllerModule* controllerModule) {
	this->controllerModule = controllerModule;
}

void BaseModule::Start() {
	AbstractModule::Start();
}

void BaseModule::Update() {
	AbstractModule::Update();
}

void BaseModule::Complete() {

}

void BaseModule::Fail() {
	controllerModule->strikes++;
}