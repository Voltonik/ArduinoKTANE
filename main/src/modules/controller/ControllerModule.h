#include "../base/BaseModule.h"
#include "SevSeg.h"

class ControllerModule: public BaseModule {
private:
	float explodeTime;
	float currentTime;

	SevSeg timerSevenSeg;

public:
	ControllerModule(float explodeTime): BaseModule(*this) {
		this->explodeTime = explodeTime;
		this->currentTime = explodeTime;
	}


	void Start() {
		byte numDigits = 4;
		byte digitPins [] = { 10, 11, 12, 13 };
		byte segmentPins [] = { 9, 2, 3, 5, 6, 8, 7, 4 };

		bool resistorsOnSegments = true;
		bool updateWithDelaysIn = true;
		byte hardwareConfig = COMMON_CATHODE;

		timerSevenSeg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
		timerSevenSeg.setBrightness(90);
	}

	void Update() {
		currentTime = explodeTime - millis();

		timerSevenSeg.setNumber(4999, 3);
		timerSevenSeg.refreshDisplay();

		if (currentTime <= 0) {
			timerSevenSeg.setChars("boom");
			timerSevenSeg.refreshDisplay();
		}
	}
};