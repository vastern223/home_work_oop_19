#pragma once
#include"CombatVehicle.h"
class AirDefenseVehicle : public CombatVehicle
{
private:

	int range;
	int firing_speed;
	int mobility;

public:

	AirDefenseVehicle():range(0), firing_speed(0), mobility(0){ }
	AirDefenseVehicle(int range,int firing_speed,int mobility, string type, string model, float health):range(range), firing_speed(firing_speed), mobility(mobility), CombatVehicle(type, model, health) { }
	
	void ShowInfo()const final
	{
		CombatVehicle::ShowInfo();
		cout << "Range: " << range << endl;
		cout << "Firing speed: " << firing_speed << endl;
		cout << "Mobility: " << mobility << endl;
	}
	float Attack()const final
	{
		return (150 + range * (firing_speed / 10));
	}
	void Defense(int damage) final
	{
		health -= (damage / mobility);
	}
};

