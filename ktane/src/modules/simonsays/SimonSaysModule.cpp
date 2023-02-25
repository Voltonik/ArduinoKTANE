#include "SimonSaysModule.h"

SimonSaysModule::SimonSaysModule(AbstractControllerModule* controllerModule, int statusLED): BaseModule(controllerModule, statusLED) {

}

ButtonColor GetDecodedColor(ButtonColor codedColor, int strikes) {
	if (strikes == 0) {
		switch (codedColor) {
		case BtnRed:
			return BtnBlue;

		case BtnBlue:
			return BtnRed;

		case BtnGreen:
			return BtnYellow;

		case BtnYellow:
			return BtnGreen;
		}
	} else if (strikes == 1) {
		switch (codedColor) {
		case BtnRed:
			return BtnYellow;

		case BtnBlue:
			return BtnGreen;

		case BtnGreen:
			return BtnBlue;

		case BtnYellow:
			return BtnRed;
		}
	} else {
		switch (codedColor) {
		case BtnRed:
			return BtnGreen;

		case BtnBlue:
			return BtnRed;

		case BtnGreen:
			return BtnYellow;

		case BtnYellow:
			return BtnBlue;
		}
	}
}

int decodedColors = 0;
int correctColors = 1;

void SimonSaysModule::Start() {
	BaseModule::Start();

	randomSeed(analogRead(0));

	pinMode(redLED, OUTPUT);
	pinMode(greenLED, OUTPUT);
	pinMode(blueLED, OUTPUT);

	digitalWrite(redLED, HIGH);
	digitalWrite(greenLED, HIGH);
	digitalWrite(blueLED, HIGH);

	for (int i = 0; i < 5; i++) {
		orderedCodedPattern[i] = colors[random(4)];

		if (i < 4) {
			pinMode(buttons[i].pin, INPUT_PULLUP);

			buttons[i].lastState = digitalRead(buttons[i].pin);

			buttons[i].color = colors[i];
			if (buttons[i].color == orderedCodedPattern[0])
				correctButtons[0] = buttons[i];
		}
	}
}

bool visualizing = false;
unsigned long previousVisualTime = 0;

void SimonSaysModule::AddCorrectButton(ButtonColor color) {
	for (int i = 0; i < 5; i++) {
		if (correctButtons[i].pin == -1) {
			for (int j = 0; j < 4; j++) {
				if (buttons[j].color == color) {
					correctButtons[i] = buttons[j];
					return;
				}
			}
		}
	}
}

void SimonSaysModule::SetLEDColor(ButtonColor color) {
	switch (color) {
	case BtnRed:
		digitalWrite(redLED, LOW);
		digitalWrite(greenLED, HIGH);
		digitalWrite(blueLED, HIGH);
		break;
	case BtnGreen:
		digitalWrite(redLED, HIGH);
		digitalWrite(greenLED, LOW);
		digitalWrite(blueLED, HIGH);
		break;
	case BtnYellow:
		digitalWrite(redLED, LOW);
		digitalWrite(greenLED, LOW);
		digitalWrite(blueLED, HIGH);
		break;
	case BtnBlue:
		digitalWrite(redLED, HIGH);
		digitalWrite(greenLED, HIGH);
		digitalWrite(blueLED, LOW);
		break;
	}
}

void SimonSaysModule::Fail() {
	BaseModule::Fail();
}

void SimonSaysModule::Update() {
	BaseModule::Update();

	unsigned long time = millis();


	if (time - previousVisualTime >= 1000 && time - previousCompleteSeq >= 5000) {
		previousVisualTime = time;
		visualizing = true;
		seq++;

		if (decodedColors == 0 && i <= correctColors) {

			correctButtons[i].blinkState = !correctButtons[i].blinkState;

			if (correctButtons[i].blinkState) {
				SetLEDColor(correctButtons[i].color);
			} else {
				digitalWrite(redLED, HIGH);
				digitalWrite(greenLED, HIGH);
				digitalWrite(blueLED, HIGH);
			}
		}
		if (seq % 2 == 0) {
			i++;
		}
	} else if (i >= correctColors) {
		visualizing = false;
		i = 0;
		previousCompleteSeq = time;
	}

	if (time - lastInterrupt > 50) {
		lastInterrupt = time;
		for (int i = 0; i < 4; i++) {
			bool btnState = digitalRead(buttons[i].pin);
			if (btnState != buttons[i].lastState && !visualizing) {
				buttons[i].lastState = btnState;
				if (!btnState) {
					if (buttons[i].color == GetDecodedColor(orderedCodedPattern[decodedColors], strikes)) {
						Serial.println(correctColors);
						if (correctColors <= 5) {
							decodedColors++;
							if (decodedColors == correctColors) {
								AddCorrectButton(orderedCodedPattern[correctColors]);
								correctColors++;
								decodedColors = 0;
								previousCompleteSeq = time - 5000;
							}

						} else {
							Serial.println("WIN");
							Complete();
						}
					} else {
						Fail();
						strikes++;
						decodedColors = 0;
						previousCompleteSeq = time - 5000;
					}
				}
			}
		}
	}
}