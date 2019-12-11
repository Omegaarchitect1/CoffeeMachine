#include "HeatingElement.h"
#include "Hopper.h"
#include "Resevoir.h"
class CoffeeMaker
{
private:
	HeatingElement * heatE;
	Hopper * hop;
	Resevoir * res;
public:
	CoffeeMaker();
	~CoffeeMaker();

	void UseCoffeeMachine();
	void MakeCoffee();

	void AddWater();
	void AddBeans();
	void GrindBeans();
};

