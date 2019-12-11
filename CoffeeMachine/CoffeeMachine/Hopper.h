#pragma once
class Hopper
{
public:
	Hopper();
	~Hopper();

	void Fill(int beans);
	bool HasEnoughBeans();
	void GrindBeans();
	bool HasEnoughGrinds();

	const int beansPerGrind = 45;
	const int ouncesMade = 10;

	int currentBeans;
	int currentGrinds;
};

