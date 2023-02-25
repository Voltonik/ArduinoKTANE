#include "AbstractcontrollerModule.h"

AbstractControllerModule::AbstractControllerModule(long explodeTime = 10000, int maxStrikes = 2) {
	this->explodeTime = explodeTime;
	this->currentTime = explodeTime;

	this->maxStrikes = maxStrikes;
}

void AbstractControllerModule::Start() {
	AbstractModule::Start();

	tone(speaker, NOTE_C4, 1000);

	display.begin();
	display.setContrast(17);

	pinMode(backlight, OUTPUT);
	analogWrite(backlight, 0);
}

char* TimeToString(unsigned long t) {
	static char str[5];
	t = t % 3600;
	int m = t / 60;
	int s = t % 60;
	sprintf(str, "%02d:%02d", m, s);
	return str;
}

bool win = false;

void AbstractControllerModule::Win() {
	running = false;
	win = true;

	display.clearDisplay();

	display.setCursor(5, 8);
	display.setTextSize(1);

	display.print("Defused");
}

unsigned long prevSecs;
unsigned long blink;
bool state;

void AbstractControllerModule::Update() {
	AbstractModule::Update();

	if (strikes > maxStrikes)
		Lose();

	currentTime = explodeTime - millis();

	if (currentTime <= 0)
		Lose();

	unsigned long time = millis();

	unsigned long seconds = currentTime / 1000;
	unsigned long minutes = seconds / 60;

	seconds %= 60;
	minutes %= 60;

	if (time - prevSecs > 2000) {
		tone(speaker, NOTE_F7, 200);

		prevSecs = time;
	}

	if (currentTime < 30000) {
		if (time - blink >= 500) {
			blink = time;

			state = !state;

			if (state)
				analogWrite(backlight, 160);
			else
				analogWrite(backlight, 0);
		}
	}

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

void AbstractControllerModule::Lose() {
	running = false;
}
