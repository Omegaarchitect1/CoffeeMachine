#include "pch.h"
#include "Resevoir.h"
#include <iostream>


Resevoir::Resevoir()
{
	currentCupsOfWater = 0;
}


Resevoir::~Resevoir()
{
}

void Resevoir::Fill(int cupsOfWater)
{
	if (cupsOfWater > 0)
	{
		std::cout << "\nYou add " << cupsOfWater << " cups of water to the Resevoir" << std::endl;
		currentCupsOfWater = cupsOfWater;
		std::cout << "\nYou currently have " << cupsOfWater << "cups of water in the Resevoir" << std::endl;
	}
	else if (cupsOfWater == 0)
	{
		std::cout << "\nYou added no Cupers of water to the resevoir." << std::endl;
	}
	else
	{
		std::cout << "\nEnter a valid amount." << std::endl;
	}
}

bool Resevoir::HasEnoughWater()
{
	if (currentCupsOfWater >= cupsOfWaterPerCup)
	{
		return true;
	}
	else
	{
		return false;
	}
}

