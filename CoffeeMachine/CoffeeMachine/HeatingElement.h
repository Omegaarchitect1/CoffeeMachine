#pragma once
class HeatingElement
{
private:
	const int maxHeat = 185;
	const int roomTemp = 75;
	const int heatIncriment = 10;
public:
	HeatingElement();
	~HeatingElement();

	void Heat();
	bool IsHeated();

	int currentheat;

};

