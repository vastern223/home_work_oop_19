#pragma once
#include"CombatVehicle.h"
class ArmoredCar : public CombatVehicle
{
private:

	int number_of_weapons;
	int speed;

public:
	ArmoredCar() :number_of_weapons(0), speed(0) { }
	ArmoredCar(int number_of_weapons, int speed, string type, string model, float health) :number_of_weapons(number_of_weapons), speed(speed), CombatVehicle(type, model, health) { }

	void ShowInfo()const final
	{
		CombatVehicle::ShowInfo();
		cout << "Number of weapons: " << number_of_weapons << endl;
		cout << "Speed: " << speed << endl;
	}
	float Attack()const final
	{
		return 50 * speed;
	}

	void Defense(int damage) final
	{
		health -=damage - speed/2;
	}
};

