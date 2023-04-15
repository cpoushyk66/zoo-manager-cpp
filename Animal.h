#ifndef ANIMAL_H
#define ANIMAL_H


#include <string>
#include <iostream>

class Animal
{
  public:

    //! Give birth to a new animal with the input lifespan and type
    Animal(int lifespan, std::string anim_type);
    virtual ~Animal();

   //! Ages the animal by one year, killing it if too old.
    /*! Make it grow older by one year.
     * If the age exceeds the lifespan, the
     * animal must die.
     */
    void grow_older();

    //! Hooks up with like animals in right neighboring cage.
    /*! Check the neighbor in the cage on the right and spawn if feasible.
     * Spawning is the following process:
     * - Check the neighbor animal in the right cage.
     * - If the neighbor animal is of the same type,
     *   create a new animal of the same type and put it in a new cage at the end of the row of cages, on the right.
     */
    void spawn();

    //! Abstract method to create a baby. Implementation is specific to which kind of animal it is.
    // THIS IS AN ABSTRACT METHOD THAT MUST BE DECLARED AND IMPLEMENTED IN THE DERIVED CLASSES
    virtual Animal* MakeBaby() = 0;

    //! Eats a specific animal when it appears in a neighboring cage.
    /*! Check neighboring (both left and right) cages, and eat the neighbor if feasible.
     *  When this animal eats another animal, the other animal must die.
     *  When an animal is eaten, use cout to announce the type of the animal that was eaten.
     */
    // THIS IS AN ABSTRACT METHOD THAT MUST BE DECLARED AND IMPLEMENTED IN THE DERIVED CLASSES
    virtual void eat() = 0;

    /*! Die and be removed from the zoo.
     * This method should be invoked in the grow_older() method 
     * when the age has exceeded the lifespan. It must also be invoked
     * in the eat() method of derived classes if the animal is eaten.
     * Use cout to print an announcement that this animal is dead.
     * When dead, the animal must be removed from the zoo,
     * and memory must be cleaned up properly.
    */
    void die();

    //! returns the age of the animal
    const int& getAge() const;

    //! sets the age of the animal
    void setAge(int ag);

    const int& getLifeSpan() const;

    virtual std::string getEdibleAnimal() = 0;

    static int getAnimalTotal();

    //! report on the type of animal this is
    const std::string AnimalType() const; 

    // Pointers to the animals in the neighboring cages
    // The collection of all of the animals linked together
    // is the zoo.
    //! The animal in the cage on the right
    Animal * cage_on_right = nullptr;
    //! The animal in the cage on the left
    Animal * cage_on_left = nullptr;



  protected:

    int life_span; // maximum age in years
    std::string animal_type;
    int age = 0; // age in years
    static int animalTotal;

    // All animals need a type and lifespan, do dont let this constructor work
    Animal();

};


//! Tiger, with its properties hardcoded
class Tiger : public Animal
{
  public:

    Tiger();
   ~Tiger();

    void eat();
    Tiger* MakeBaby();
    static int getTigerTotal();
    std::string getEdibleAnimal();

  private:

   std::string edible_animal = "possum";
   static int tigerTotal;
};

//! Chicken, with its properties hardcoded
class Chicken : public Animal
{
  public:

    Chicken();
   ~Chicken();

    void eat();
    Chicken* MakeBaby();
    static int getChickenTotal();
    std::string getEdibleAnimal();

  private:

   std::string edible_animal = "hyena";
   static int chickenTotal;
};

//! Hyena, with its properties hardcoded
class Hyena : public Animal
{
  public:

    Hyena();
   ~Hyena();

    void eat();
    Hyena* MakeBaby();
    static int getHyenaTotal();
    std::string getEdibleAnimal();

  private:

   std::string edible_animal = "tiger";
   static int hyenaTotal;
};


//! Possum, with its properties hardcoded
class Possum : public Animal
{
  public:

    Possum();
   ~Possum();

    void eat();
    Possum* MakeBaby();
    static int getPossumTotal();
    std::string getEdibleAnimal();

  private:

   std::string edible_animal = "chicken";
   static int possumTotal;
};



//! Create all of the initial animals and arrange the linked list of them
Animal* Zoo(int nb_tigers, int nb_hyenas, int nb_possums, int nb_chickens);

//! Cycle through the zoo and have all of the eligible animals spawn with one or more neighbor
void SpawningCycle(Animal* linkedlist);

//! Cycle through the zoo and have all of the eligible animals eat one or more neighbor
void FeedingCycle(Animal* linkedlist);

//! Cycle through the zoo and have all them all age, killing off the ones that are too old. Returns the new head of the linked list of animals.
Animal* AgingCycle(Animal* linkedlist);

//! Print number of animals in the zoo, and the number of each type of animal.
void ShowTheZoo();

//! Delete all of the animals and clean up the linked list.
void CleanTheZoo(Animal* linkedlist);

#endif

