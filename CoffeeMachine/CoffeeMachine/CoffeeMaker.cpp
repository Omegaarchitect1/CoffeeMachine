#include "pch.h"
#include "CoffeeMaker.h"
#include <iostream>
#include <string>


CoffeeMaker::CoffeeMaker()
{
	heatE = new HeatingElement();
	hop = new Hopper();
	res = new Resevoir();
}


CoffeeMaker::~CoffeeMaker()
{
	delete heatE;
	delete hop;
	delete res;
}

void CoffeeMaker::UseCoffeeMachine()
{
	bool usingCoffeeMachine = true;
	

	while (usingCoffeeMachine)
	{
		bool validInput = false;

		do
		{
			//Menu
			std::cout << "There are currently: " << std::endl;
			std::cout << res->currentCupsOfWater << " Cups of water in the Resevoir" << std::endl;
			std::cout << hop->currentBeans << " Beans in the Hopper" << std::endl;
			std::cout << hop->currentGrinds << " Grinds in the Hopper" << std::endl;
			std::cout << " " << std::endl;
			std::cout << "You need " << res->cupsOfWaterPerCup << " cups of water and" << 
				hop->ouncesMade << " ounces of grinds to make a cup of coffee" << std::endl;
			std::cout << "You need " << hop->beansPerGrind << " beans to make that many grinds." << std::endl;
			std::cout << " " << std::endl;
			std::cout << "Would you like to (enter a number):" << std::endl;
			std::cout << "(1) Make Coffee" << std::endl;
			std::cout << "(2) Add water to reservoir" << std::endl;
			std::cout << "(3) Add beans to the hopper" << std::endl;
			std::cout << "(4) Grind the beans in the hopper" << std::endl;
			std::cout << "(5) Quit making coffee" << std::endl;

			std::string input;
			int inputI;

			try
			{
				std::cin >> input;

				inputI = std::stoi(input);

				switch (inputI)
				{
				case 1: //make coffee
					MakeCoffee();
					validInput = true;
					break;

				case 2: // add water
					AddWater();
					validInput = true;
					break;

				case 3: //add beans
					AddBeans();
					validInput = true;
					break;

				case 4: //grind beans
					GrindBeans();
					validInput = true;
					break;

				case 5: //quit
					usingCoffeeMachine = false;
					validInput = true;
					break;

				default:
					std::cout << "Invalid input. Please try again." << std::endl;
					break;
				}
			}
			catch (...)
			{
				std::cout << "Invalid input. Please try again." << std::endl;
			}


		} while (!validInput);
	}

	std::cout << "Thank you for using the Coffee Machine" << std::endl;
}

void CoffeeMaker::MakeCoffee()
{
	if (res->HasEnoughWater())
	{
		if (hop->HasEnoughGrinds())
		{
			int cupsWatercanMake = res->currentCupsOfWater / res->cupsOfWaterPerCup;
			int cupsGrindsCanMake = hop->currentGrinds / hop->ouncesMade;

			int cupsToMake;

			if (cupsWatercanMake <= cupsGrindsCanMake)//less or equal water
			{
				cupsToMake = cupsWatercanMake;
			}
			else //less grinds
			{
				cupsToMake = cupsGrindsCanMake;
			}

			res->currentCupsOfWater -= res->cupsOfWaterPerCup * cupsToMake;
			hop->currentGrinds -= hop->ouncesMade * cupsToMake;

			heatE->Heat();

			std::cout << "You've made " << cupsToMake << " cups of coffee!" << std::endl;
		}
		else
		{
			std::cout << "You don't have enough coffee grinds" << std::endl;
		}
	}
	else
	{
		std::cout << "You don't have enough water" << std::endl;
	}

}

void CoffeeMaker::AddWater()
{

		bool validInput = false;

	do
	{
		//Menu
		std::cout << "There are currently " << std::endl;
		std::cout << res->currentCupsOfWater << "Cups of water in the Resevoir" << std::endl;
		std::cout << "How many cups of water would you like to add? (enter a number)" << std::endl;


		std::string input;
		int inputI;

		try
		{
			std::cin >> input;

			inputI = std::stoi(input);

			res->Fill(inputI);

			validInput = true;
		}

		catch (...)
		{
			std::cout << "Invalid input. Please try again." << std::endl;
		}


	} while (!validInput);
}

void CoffeeMaker::AddBeans()
{

	bool validInput = false;

	do
	{
		//Menu
		std::cout << "There are currently " << hop->currentBeans << " beans in the Hopper" << std::endl;
		std::cout << "How many beans would you like to add? (enter a number)" << std::endl;


		std::string input;
		int inputI;

		try
		{
			std::cin >> input;

			inputI = std::stoi(input);

			hop->Fill(inputI);

			validInput = true;
		}

		catch (...)
		{
			std::cout << "Invalid input. Please try again." << std::endl;
		}


	} while (!validInput);
}

void CoffeeMaker::GrindBeans()
{
	if (hop->HasEnoughBeans())
	{
		hop->GrindBeans();

	}
	else
	{
		std::cout << "You don't have enough beans to grind" << std::endl;
		std::cout << "You need" << hop->beansPerGrind << "beans to be able to grind." << std::endl;
		std::cout << "you only have" << hop->currentBeans << "beans" << std::endl;
	}
}
