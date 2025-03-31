#include "Complex.h"
#include "sportcar.h"

void main()
{
	//Complex a, b, c;
//	a.read("A =");
//	b.read("B =");
	Car myCar;
	Car momsCar(10, "K5", 2);

	myCar.whereAmI();
	momsCar.whereAmI();
	myCar.changeGear(3);
	momsCar.speedUp();
	momsCar.display();
}