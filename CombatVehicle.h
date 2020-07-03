#pragma once
#include<iostream>
#include<string>
using namespace std;

class CombatVehicle
{
protected:

	string type;
	string model;
	float health;

public:
	CombatVehicle():type(nullptr), model(nullptr), health(0) { }

	CombatVehicle(string type,string model,float health):type(type), model(model), health(health){ }

	string Get_name()const
	{
		return type;
	}
	float Get_health()const
	{
		return health;
	}

    bool IsDestroyed()
	{
		if (health <= 0)
			return true;
		else
			return false;	
	}
	virtual void ShowInfo()const  
	{
		cout << "Type: " << type << endl;
		cout << "Model: " << model << endl;
		cout << "Health: " << health << endl;
	}

	virtual float Attack()const = 0;

	virtual void Defense(int damage) = 0;


};

