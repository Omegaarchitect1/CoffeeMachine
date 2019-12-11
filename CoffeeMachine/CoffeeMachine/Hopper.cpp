#include "pch.h"
#include "Hopper.h"
#include <iostream>


Hopper::Hopper()
{
	currentBeans = 0;
	currentGrinds = 0;
}


Hopper::~Hopper()
{

}

void Hopper::Fill(int beans)
{
	if (beans > 0)
	{
		std::cout << "\nYou add " << beans << " to the Hopper" << std::endl;
		currentBeans = beans;
		std::cout << "\nYou currently have " << beans << " in the Hopper" << std::endl;
	}
	else if (beans == 0)
	{
		std::cout << "\nYou added no beans to the hopper." << std::endl;
	}
	else
	{
		std::cout << "\nEnter a valid amount." << std::endl;
	}
}

bool Hopper::HasEnoughBeans()
{
	if (currentBeans >= beansPerGrind)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Hopper::GrindBeans()
{
	int timestoGrind = 0;

	while (beansPerGrind * timestoGrind <= currentBeans)
	{
		timestoGrind++;
	}
	timestoGrind--;
	if (timestoGrind > 0)
	{
		std::cout << "Grinding..." << std::endl;
	}

	currentBeans -= beansPerGrind * timestoGrind;
	currentGrinds += ouncesMade * timestoGrind;

	std::cout << "You now have " << currentGrinds << " ounces of grinds and " << currentBeans << " beans left over." << std::endl;
}

bool Hopper::HasEnoughGrinds()
{
	if (currentGrinds >= ouncesMade)
	{
		return true;
	}
	else
	{
		return false;
	}
}
