#include "pch.h"
#include "HeatingElement.h"
#include <iostream>
#include<chrono>
#include<thread>


HeatingElement::HeatingElement()
{
	currentheat = roomTemp;
}


HeatingElement::~HeatingElement()
{

}

void HeatingElement::Heat()
{
	while (!IsHeated())
	{
		currentheat += heatIncriment;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		std::cout << "current Heat:" << currentheat << std::endl;
	}
	std::cout << "DING!" << std::endl;
}

bool HeatingElement::IsHeated()
{
	if (currentheat >= maxHeat)
	{
		return true;
	}
	else
	{
		return false;
	}
}
