#include<iostream>
#include<string.h>
#include<cstdlib>
#include<time.h>

typedef struct Position
{
	int x = 0;
	int y = 0;

	void print()
	{
		std::cout << x  << "," << y << std::endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile 
{
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

int main()
{
	Missile rocket;
	int input; 
	int codes[4] = { rand() % 10 + 1,rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, };
	int inputCodes[4];
	bool CODES = false;



	std::cout << "Choose the Warhead :  " << std::endl;
	std::cout << "1) Nuclear" << std::endl;
	std::cout << "2) Explosive" << std::endl;
	std::cin >> input;

	if (input == 1)
	{
		rocket.payload = WarHead::NUCLEAR;
	}
	else if(input == 2)
	{
		rocket.payload = WarHead::EXPLOSIVE;
	}
	else
	{
		std::cout << "Incorrect Input" << std::endl;
	}

	std::srand(static_cast<unsigned>(time(NULL)));
	
	rocket.target.coordinates.x = rand() % 100 + 1;
	rocket.target.coordinates.y = rand() % 100 + 1;

	std::cout << "Target at co-ordinates : ";
	rocket.target.coordinates.print();

	std::cout << "LAUNCH CODES: ";

	for (int index = 0; index < 4; index++)
	{
		std::cout << codes[index] << " ";
	}

	std::cout << std::endl;

	for (int index = 0; index < 4; index++)
	{
		std::cin >> inputCodes[index];
	}
	
	for (int index = 0; index < 4; index++)
	{
		if (inputCodes[index] == codes[index])
		{
			std::cout << "CODE CORRECT" << std::endl;
			CODES = true;
		}
		else
		{
			std::cout << "INCORRECT" << std::endl;
			CODES = false;
		}
	}


	std::cout << std::endl;

	if (CODES == true)
	{
		rocket.arm();

		while (true)
		{
			if (rocket.coordinates.x == rocket.target.coordinates.x)
			{
				if (rocket.coordinates.y == rocket.target.coordinates.y)
				{
					std::cout << "HIT" << std::endl;
					break;
				}
			}
			if (rocket.coordinates.x > rocket.target.coordinates.x || rocket.coordinates.y > rocket.target.coordinates.y)
			{
				std::cout << "NOT VIABLE" << std::endl;
				std::cout << "DISARMING ROCKET" << std::endl;
				rocket.arm();
				break;
			}

			rocket.update();

			std::cout << "VIABLE" << std::endl;
		}
	}

	system("pause");
}


