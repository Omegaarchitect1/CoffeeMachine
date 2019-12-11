#pragma once
class Resevoir
{
public:
	Resevoir();
	~Resevoir();

	void Fill(int cupsOfWater);
	bool HasEnoughWater();

	const int cupsOfWaterPerCup = 1;

	int currentCupsOfWater;
};

