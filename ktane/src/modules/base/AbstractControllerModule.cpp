#include "AbstractControllerModule.h"

AbstractControllerModule::AbstractControllerModule(long explodeTime, uint8_t maxStrikes) {
	this->explodeTime = explodeTime;
	this->currentTime = explodeTime;

	this->maxStrikes = maxStrikes;
}

void AbstractControllerModule::Start() {
	AbstractModule::Start();
}

void AbstractControllerModule::Update() {
	AbstractModule::Update();

	currentTime = explodeTime - millis();

	if (currentTime <= 0)
		Lose();
}

void AbstractControllerModule::Strike() {
	strikes++;

	if (strikes > maxStrikes)
		Lose();
}

void AbstractControllerModule::Lose() {
	running = false;
}

void AbstractControllerModule::Win() {
	running = false;
}