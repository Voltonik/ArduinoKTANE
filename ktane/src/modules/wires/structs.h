#pragma once

enum Color {
	Yellow,
	White,
	Red,
	Blue,
	Black,
	Green
};

class ConnectedWire {
public:
	int pin;
	bool connected;
	Color color;

	ConnectedWire(int _pin = A0) {
		pin = _pin;
	}
};