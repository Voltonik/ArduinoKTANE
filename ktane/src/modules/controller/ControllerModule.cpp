#include "ControllerModule.h"

ControllerModule::ControllerModule(long explodeTime, uint8_t maxStrikes): AbstractControllerModule(explodeTime, maxStrikes) {

}

void ControllerModule::Start() {
	AbstractControllerModule::Start();

	display.begin();

	display.setContrast(35);
}

char* TimeToString(unsigned long t) {
	static char str[5];
	t = t % 3600;
	int m = t / 60;
	int s = t % 60;
	sprintf(str, "%02d:%02d", m, s);
	return str;
}

void ControllerModule::Fail() {

}

void ControllerModule::Complete() {

}

void ControllerModule::Update() {
	AbstractControllerModule::Update();

	if (currentTime <= 0 || strikes > maxStrikes) {
		running = false;
		Fail();
	}

	unsigned long seconds = currentTime / 1000;
	unsigned long minutes = seconds / 60;

	seconds %= 60;
	minutes %= 60;

	display.clearDisplay();

	display.setCursor(5, 8);
	display.setTextSize(1);

	display.print("Strikes: ");

	for (int i = 0; i < maxStrikes; i++) {
		display.print(i < strikes ? 'x' : '_');
		display.print(' ');
	}

	display.setCursor(13, 30);
	display.setTextSize(2);
	display.println(TimeToString(currentTime / 1000));
	display.display();
}