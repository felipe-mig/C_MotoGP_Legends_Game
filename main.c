//  --------------------------------------

//  Author: Felipe Iglesias
//  Date: 21-02-2025
//  Version: 1.5
//  Contact: felipemiglesias@gmail.com
//  https://github.com/felipe-mig

// -------------------------------------- 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race
{
  int numberOfLaps;
  int currentLap;
  char *firstPlaceDriverName;
  char *firstPlaceRaceBikeColor;
};

struct RaceBike
{
  char *driverName;
  char *raceBikeColor;
  int totalLapTime;
};

// Print functions section
void printIntro()
{
  printf("\n\nWelcome ladies and gentelman to the \033[38;5;226mMotoGP Legends\033[0m Race.\nWhere The top MotoGP riders of all time will have one last dance!\n\n");
};

void printCountDown()
{
  printf("Legends Ready! In...\n5\n4\n3\n2\n1\nGO!\n\n");
};

void printFirstPlaceAfterLap(struct Race race)
{
  printf("After lap number %d\n", race.currentLap);
  printf("First Place is: %s in the %s!\n", race.firstPlaceDriverName, race.firstPlaceRaceBikeColor);
};

void printCongratulation(struct Race race)
{
  printf("\nLet's all give a massive applause to %s for an amazing race!.\nWhat an eye opening event to see this two legends having one last dance!\n\n", race.firstPlaceDriverName);
};

// Logic functions section
int calculateTimeToCompleteLap()
{
  int speed = (rand() % 4) + 1;
  int acceleration = (rand() % 4) + 1;
  int nerves = (rand() % 4) + 1;

  return speed + acceleration + nerves;
};

void updateRaceBike(struct RaceBike *raceBikePointer)
{
  raceBikePointer->totalLapTime += calculateTimeToCompleteLap();
};

// Race Logic
void updateFirstPlace(struct Race *race, struct RaceBike *raceBike1, struct RaceBike *raceBike2, struct RaceBike *raceBike3)
{
  if (raceBike1->totalLapTime <= raceBike2->totalLapTime) {
    race->firstPlaceDriverName = raceBike1->driverName;
    race->firstPlaceRaceBikeColor = raceBike1->raceBikeColor;
  } 
  else if (raceBike3->totalLapTime <= raceBike1->totalLapTime && raceBike2->totalLapTime){
    race->firstPlaceDriverName = raceBike3->driverName;
    race->firstPlaceRaceBikeColor = raceBike3->raceBikeColor;
  }
  else
  {
    race->firstPlaceDriverName = raceBike2->driverName;
    race->firstPlaceRaceBikeColor = raceBike2->raceBikeColor;
  };
};

void startRace(struct RaceBike *raceBike1, struct RaceBike *raceBike2, struct RaceBike *raceBike3)
{
  struct Race race = {
    numberOfLaps : 15,
    currentLap : 1,
    firstPlaceDriverName : "",
    firstPlaceRaceBikeColor : ""
  };
  for (int i = 1; i <= race.numberOfLaps; i++)
  {
    updateRaceBike(raceBike1);
    updateRaceBike(raceBike2);
    updateRaceBike(raceBike3);
    updateFirstPlace(&race, raceBike1, raceBike2, raceBike3);
    printFirstPlaceAfterLap(race);
    race.currentLap++;
  };
  printCongratulation(race);
};

int main()
{
  srand(time(0));

  // Competitors
  struct RaceBike Bike1 = {"\033[38;5;9mCasey Stoner 27\033[0m", "\033[38;5;9mRed Ducati\033[0m", 0};
  struct RaceBike Bike2 = {"\033[38;5;21mValentino Rossi 46\033[0m", "\033[38;5;21mBlue Yamaha\033[0m", 0};
  struct RaceBike Bike3 = {"\033[38;5;202mMarc Marquez 93\033[0m", "\033[38;5;202mOrange Honda\033[0m", 0};

  printIntro();
  printCountDown();

  startRace(&Bike1, &Bike2, &Bike3);

};