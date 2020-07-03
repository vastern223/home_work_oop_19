#include<iostream>
#include<ctime>
#include"CombatVehicle.h"
#include"AirDefenseVehicle.h"
#include"ArmoredCar.h"
#include"Tank.h"
using namespace std;


void Fight_info(CombatVehicle& bp1, CombatVehicle& bp2)
{
	cout << "attacks: " << bp1.Get_name() << endl;
	cout << "is defended: " << bp2.Get_name() << endl;
	cout << "causes damage: " << bp1.Attack() << " xp" << endl;
	cout << "life left in: " << bp2.Get_name() << ":" << bp2.Get_health() << " xp" << endl << endl;
}


bool Round(CombatVehicle& bp1, CombatVehicle& bp2)
{
	cout << "Battle: " << bp1.Get_name() << " vs " << bp2.Get_name() << endl;
	cout << "-------------------------" << endl;
	int counter = 0;

	while (bp1.IsDestroyed() == false && bp2.IsDestroyed() == false)
	{
		bp2.Defense(bp1.Attack());

		cout << "round: " << ++counter << ";" << endl;

		Fight_info(bp1, bp2);

		if (bp2.IsDestroyed())
		{
			cout << "vin: " << bp1.Get_name() << endl;
			return true;
		}

		bp1.Defense(bp2.Attack());

		Fight_info(bp2, bp1);

		cout << endl;
		if (bp1.IsDestroyed())
		{
			cout << "vin: " << bp2.Get_name() << endl;
			return false;
		}
	} 

}


void Wars()
{
	const int  size = 5;
	CombatVehicle* combat1[size];
	int random = 0;
	for (int i = 0; i < size; i++)
	{	
		random = rand() % 3;
		if (random == 0)
		{
			combat1[i] = new Tank(2.5, rand() % 5 + 1, 1.4, "tank", "t-234", rand() % 100 + 200);
		}
		else if (random == 1)
		{
			combat1[i] = new AirDefenseVehicle(rand() % 100 + 1, rand() % 10 + 1, rand() % 5 + 1, "AirDefense", "l-432", rand() % 100 + 100);
		}
		else if (random == 2)
		{
			combat1[i] = new ArmoredCar(rand() % 2 + 1, rand() % 10, "ArmoredCar", "p234", rand() % 200 + 100);
		}

	}

	CombatVehicle* combat2[size];
	int random1 = 0;
	for (int i = 0; i < size; i++)
	{
		random1 = rand() % 3;
		if (random1 == 0)
		{
			combat2[i] = new Tank(2.0, rand() % 5 + 1, 1.4, "tank", "t-234", rand() % 100 + 200);
		}
		else if (random1 == 1)
		{
			combat2[i] = new AirDefenseVehicle(rand() % 100 + 1, rand() % 10 + 1, rand() % 5 + 1, "AirDefense", "l-432", rand() % 100 + 100);
		}
		else if (random1 == 2)
		{
			combat2[i] = new ArmoredCar(rand() % 2 + 1, rand() % 10, "ArmoredCar", "p234", rand() % 200 + 100);
		}

	}

	for (int i = 0,j=0;;)
	{
		if (Round(*combat1[i],*combat2[j]))
		{
			++j;				
		}
		else
		{
			++i;
		}
		if (j == size)
		{
			system("pause");
			system("cls");
			cout << "Vin comand 1" << endl;
			return;
		}
		else if(i == size)
		{
			system("pause");
			system("cls");
			cout << "Vin comand 2" << endl;
			return;
		}
		
		system("pause");
		system("cls");
	}


}


int main()
{
	srand(time(NULL));
	Wars();

	system("pause");
	return 0;
}

