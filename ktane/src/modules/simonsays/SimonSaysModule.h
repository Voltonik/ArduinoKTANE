#include "../base/BaseModule.h"
#include "../base/pitches.h"

enum ButtonColor {
	BtnNone,
	BtnRed,
	BtnYellow,
	BtnBlue,
	BtnGreen
};

class Button {
public:
	int pin;
	bool blinkState;
	ButtonColor color;
	bool lastState;

	Button(int _pin = -1) {
		pin = _pin;

		if (pin == -1)
			color = ButtonColor::BtnNone;
	}
};

class SimonSaysModule: public BaseModule {
private:
	Button buttons[4] = { Button(22), Button(25), Button(23), Button(24) };

	ButtonColor colors[4] = { ButtonColor::BtnRed, ButtonColor::BtnYellow, ButtonColor::BtnBlue, ButtonColor::BtnGreen };
	int notes[4] = { NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4 };

	int redLED = 26, greenLED = 27, blueLED = 28;

	ButtonColor orderedCodedPattern[5];
	Button correctButtons[5];

	bool visualizing = false;
	unsigned long previousVisualTime = 0;
	unsigned long previousCompleteSeq = 0;
	unsigned long lastInterrupt = 0;

	int seq = 0;
	int i = 0;
	int strikes = 0;

public:
	SimonSaysModule(AbstractControllerModule* controllerModule, int statusLED);

	void Start();
	void Fail();
	void Update();

	void AddCorrectButton(ButtonColor color);
	void SetLEDColor(ButtonColor color);
};
