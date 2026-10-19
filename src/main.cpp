#include <iostream>
#include <random>
#include <string>
#include <vector>


// Character Map, the first index is SSR, the seccond is SR, the third is R
std::vector<std::vector<std::string>> characters = {{"Yuki Kazue", "Asuka Langley Soryu", "Hatsune Miku"}, {"Toji Fushiguro", "Shiki Rowan", "Kasane Teto"}, {"Megumin", "Aqua", "Akita Neru"}};

int randomNumberRange(int low, int high){
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(low, high); // define the range

  return distr(gen);
}

void pull(){
  int rank = randomNumberRange(0, 2);
  int character = randomNumberRange(0, 2);

  std::cout << "You rolled: " << characters[rank][character] << '\n';  
}

int main(){

  while (true){
    char choice;

    std::cin >> choice;

    if (choice == 'q'){
      break;
    }
    else if (choice == 'r'){
      pull();
    }
    else std::cout << "Incorect Command\n";
  }
  
  return 0;
}
