#pragma once
#include"CombatVehicle.h"
class Tank : public CombatVehicle
{
private:

	float recharge_time;
	int shot_accuracy;
	float armor_thickness;

public:
	Tank() :recharge_time(0), shot_accuracy(0), armor_thickness(0) {}
	Tank(float recharge_time, int shot_accuracy, float armor_thickness, string type, string model, float health) :recharge_time(recharge_time), shot_accuracy(shot_accuracy), armor_thickness(armor_thickness), CombatVehicle(type, model, health) { }

	void ShowInfo()const final
	{
		CombatVehicle::ShowInfo();
		cout << "Recharge time: " << recharge_time << endl;
		cout << "Shot accuracy: " << shot_accuracy << endl;
		cout << "Armor thickness: " << armor_thickness << endl;
	}
	float Attack()const final
	{
		return 100 * shot_accuracy / recharge_time;
	}
	void Defense(int damage) final
	{
		health -= (damage - armor_thickness);
	}

};

