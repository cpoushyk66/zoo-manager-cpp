#include "Animal.h"
#include <string>

Animal::Animal(int ls, std::string at)
{
	life_span = ls;
	animal_type = at;
	animalTotal++;

	std::cout << "Constructing " << at << " that lives " << ls << " years" << std::endl;
}

void Animal::grow_older()
{
	if (++age == getLifeSpan())
	{
		die();
	}
}

void Animal::die()
{
	std::cout << "Animal " << animal_type << " is dying" << std::endl;

	if (cage_on_left != nullptr)
	{
		cage_on_left->cage_on_right = cage_on_right;
	}
	if (cage_on_right != nullptr)
	{
		cage_on_right->cage_on_left = cage_on_left;
	}

	std::cout << "Deconstructed a " << animal_type << std::endl;
	std::cout << "Deconstructing " << animal_type << " living " << age << " out of " << life_span << std::endl;

	delete this;
}

Animal::~Animal()
{
	animalTotal--;
}

void Animal::spawn()
{
	if (AnimalType() == cage_on_right->AnimalType())
	{
		Animal* Baby = MakeBaby();

		std::cout << "\t Spawned a baby " << animal_type << std::endl;

		Animal* temp = cage_on_right;

		while (Baby->cage_on_left == nullptr)
		{
			if (temp->cage_on_right == nullptr)
			{
				Baby->cage_on_left = temp;
				temp->cage_on_right = Baby;
			}
			else
			{
				temp = temp->cage_on_right;
			}
		}
	}
}

const int& Animal::getAge() const
{
	return age;
}

void Animal::setAge(int ag)
{
	age = ag;
}

const int& Animal::getLifeSpan() const
{
	return life_span;
}

int Animal::animalTotal = 0;

int Animal::getAnimalTotal()
{
	return animalTotal;
}

const std::string Animal::AnimalType() const
{
	return animal_type;
}

Animal::Animal()
{

}

Tiger::Tiger() : Animal(10, "tiger")
{
	tigerTotal++;
}

Tiger::~Tiger()
{
	tigerTotal--;
}

void Tiger::eat()
{

	if (cage_on_left != nullptr)
	{
		if (edible_animal == cage_on_left->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			this->cage_on_left->die();
		}
	}
	if (cage_on_right != nullptr)
	{

		if (edible_animal == cage_on_right->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			this->cage_on_right->die();
		}
	}
}

Tiger* Tiger::MakeBaby()
{
	Tiger* babyTiger = new Tiger;
	return babyTiger;
}

int Tiger::tigerTotal = 0;

int Tiger::getTigerTotal()
{
	return tigerTotal;
}

std::string Tiger::getEdibleAnimal()
{
	return edible_animal;
}

Chicken::Chicken() : Animal(5, "chicken")
{
	chickenTotal++;
}

Chicken::~Chicken()
{
	chickenTotal--;
}

void Chicken::eat()
{
	if (cage_on_left != nullptr)
	{
		if (edible_animal == cage_on_left->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			this->cage_on_left->die();
		}
	}
	if (cage_on_right != nullptr)
	{
		if (edible_animal == cage_on_right->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			this->cage_on_right->die();
		}
	}
}

Chicken* Chicken::MakeBaby()
{
	Chicken* babyChicken = new Chicken;
	return babyChicken;
}

int Chicken::chickenTotal = 0;

int Chicken::getChickenTotal()
{
	return chickenTotal;
}

std::string Chicken::getEdibleAnimal()
{
	return edible_animal;
}

Hyena::Hyena() : Animal(3, "hyena")
{
	hyenaTotal++;
}

Hyena::~Hyena()
{
	hyenaTotal--;
}

void Hyena::eat()
{

	if (cage_on_left != nullptr)
	{
		if (cage_on_left->AnimalType() == edible_animal)
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			cage_on_left->die();
		}
	}
	if (cage_on_right != nullptr)
	{
		if (cage_on_right->AnimalType() == edible_animal)
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			cage_on_right->die();
		}
	}
}

Hyena* Hyena::MakeBaby()
{
	Hyena* babyHyena = new Hyena;
	return babyHyena;
}

int Hyena::hyenaTotal = 0;

int Hyena::getHyenaTotal()
{
	return hyenaTotal;
}

std::string Hyena::getEdibleAnimal()
{
	return edible_animal;
}

Possum::Possum() : Animal(3, "possum")
{
	possumTotal++;
}

Possum::~Possum()
{
	possumTotal--;
}

void Possum::eat()
{
	if (cage_on_left != nullptr)
	{
		if (edible_animal == cage_on_left->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			cage_on_left->die();
		}
	}
	if (cage_on_right != nullptr)
	{
		if (edible_animal == cage_on_right->AnimalType())
		{
			std::cout << "Animal " << AnimalType() << " is eating " << edible_animal << std::endl;
			this->cage_on_right->die();
		}
	}
}

Possum* Possum::MakeBaby()
{
	Possum* babyPossum = new Possum;
	return babyPossum;
}

int Possum::possumTotal = 0;

int Possum::getPossumTotal()
{
	return possumTotal;
}

std::string Possum::getEdibleAnimal()
{
	return edible_animal;
}


Animal* Zoo(int nb_tigers, int nb_hyenas, int nb_possums, int nb_chickens)
{

	Animal* head = nullptr;
	Animal* tail = nullptr;

	for (int i = 0; i < nb_hyenas; i++)
	{
		Hyena* hyena = new Hyena;

		if (head == nullptr)
		{
			head = hyena;
			tail = hyena;
		}
		else
		{
			hyena->cage_on_left = tail;
			tail->cage_on_right = hyena;
			tail = hyena;
		}
	}

	for (int i = 0; i < nb_tigers; i++)
	{
		Tiger* tiger = new Tiger;

		if (head == nullptr)
		{
			head = tiger;
			tail = tiger;
		}
		else
		{
			tiger->cage_on_left = tail;
			tail->cage_on_right = tiger;
			tail = tiger;
		}
	}

	for (int i = 0; i < nb_possums; i++)
	{
		Possum* possum = new Possum;

		if (head == nullptr)
		{
			head = possum;
			tail = possum;
		}
		else
		{
			possum->cage_on_left = tail;
			tail->cage_on_right = possum;
			tail = possum;
		}
	}

	for (int i = 0; i < nb_chickens; i++)
	{
		Chicken* chicken = new Chicken;

		if (head == nullptr)
		{
			head = chicken;
			tail = chicken;
		}
		else
		{
			chicken->cage_on_left = tail;
			tail->cage_on_right = chicken;
			tail = chicken;
		}
	}

	return head;
}

void SpawningCycle(Animal* linkedlist)
{
	Animal* temp = linkedlist;
	int MAX_LOOP = Animal::getAnimalTotal() - 1;

	for (int i = 0; i < MAX_LOOP; i++)
	{
		temp->spawn();
		temp = temp->cage_on_right;
	}
}

void FeedingCycle(Animal* linkedlist)
{

	Animal* temp = linkedlist;
	bool escapeCon = false;

	while(temp->cage_on_right != nullptr || escapeCon == false)
	{

		temp->eat();

		if (temp->cage_on_right != nullptr)
		{		
			temp = temp->cage_on_right;
		}
		else
		{
			escapeCon = true;
		}	
	}
}

Animal* AgingCycle(Animal* linkedlist)
{
	Animal* temp = linkedlist;
	Animal* temp2;

	while (temp->cage_on_right != nullptr)
	{
		temp2 = temp->cage_on_right;
		temp->grow_older();
		temp = temp2;
		
	}
	while (temp->cage_on_left != nullptr)
	{
		temp = temp->cage_on_left;
	}
	
	return temp;
}

void ShowTheZoo()
{
	std::cout << "Zoo Population: " << Animal::getAnimalTotal() << std::endl;
	std::cout << "    Hyenas:   " << Hyena::getHyenaTotal() << ": " << Hyena::getHyenaTotal() * 100 / Animal::getAnimalTotal() << "%" << std::endl;
	std::cout << "    Tigers:   " << Tiger::getTigerTotal() << std::endl;
	std::cout << "    Possums:  " << Possum::getPossumTotal() << std::endl;
	std::cout << "    Chickens: " << Chicken::getChickenTotal() << std::endl;
}

void CleanTheZoo(Animal* linkedlist)
{
	Animal* temp = linkedlist;
	Animal* temp2 = temp;
	bool prepCon = false;

	while (prepCon == false)
	{
		if (temp->cage_on_right == nullptr)	
		{
			prepCon = true;
		}
		else
		{
			temp = temp->cage_on_right;
		}
	}

	prepCon = false;

	while (prepCon == false)
	{
		if (temp->cage_on_left != nullptr)
		{
			temp2 = temp;
			temp = temp->cage_on_left;
			temp2->die();
		}
		else if (temp->cage_on_left == nullptr)
		{
			temp->die();
			prepCon = true;
		}
	}
}