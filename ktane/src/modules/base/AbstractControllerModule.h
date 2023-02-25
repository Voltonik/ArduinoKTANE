#pragma once
#include "AbstractModule.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "pitches.h"

class AbstractControllerModule: public AbstractModule {
private:
protected:
	long explodeTime = 0;
	long currentTime = 0;

	int maxStrikes = 2;

	Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 8, 7, 9);
	int backlight = 10;

public:
	int strikes = 0;

	AbstractControllerModule(long explodeTime = 10000, int maxStrikes = 2);

	int speaker = 2;

	int currentConfig = 0;

	void Start();
	void Update();

	void Lose();
	void Win();
};