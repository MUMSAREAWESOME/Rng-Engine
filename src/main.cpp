#include <iostream>
#include <random>
#include <string>
#include <vector>


// Character pool, index one is SSR, then SR, then R
std::vector<std::vector<std::string>> characters = {{"Yuki Kazue", "Asuka Langley Soryu", "Hatsune Miku"}, {"Toji Fushiguro", "Shiki Rowan", "Kasane Teto"}, {"Megumin", "Aqua", "Akita Neru"}};

int randomNumberRange(int low, int high){
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(low, high); // define the range

  return distr(gen);
}

void pull(int& pity){
  int rank;

  if (pity > 6){
    rank = randomNumberRange(0, 1);
    pity = 0;
  }
  else {
    rank = 2;
    pity += 1;
  }

  int character = randomNumberRange(0, 2);

  std::cout << "You rolled: " << characters[rank][character] << '\n';
}

int main(){
  int pity = 0;

  while (true){
    char choice;

    std::cin >> choice;

    if (choice == 'q'){
      break;
    }
    else if (choice == 'r'){
      pull(pity);
    }
    else std::cout << "Incorect Command\n";
  }

  return 0;
}
