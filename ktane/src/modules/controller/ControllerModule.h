#include "../base/AbstractControllerModule.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class ControllerModule: public AbstractControllerModule {
private:
	Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 8, 7, 9);
	int backlight = 10;

public:
	ControllerModule(long explodeTime, uint8_t maxStrikes);

	void Start();
	void Update();

	void Strike();
	void Lose();
	void Win();
};