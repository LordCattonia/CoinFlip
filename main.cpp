#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

bool isCheating = { false };

int cheatCount;
int userInt;
std::string cheatInput;
int userInput;

int main() {
    srand (time(NULL));
    std::cout<<"How many coins to flip: ";
    std::cin>>userInput;
    if (userInput == 6286) {
        isCheating = true;
        std::cout<<"How many coins: ";
        std::cin>>cheatCount;
        std::cout<<"Enter cheat pattern ["<<cheatCount<<"x H|T]: ";
        std::cin>>cheatInput;
        system("CLS");
    }
    if (isCheating) {
        std::cout<<' ';
        for (int i=0;i<cheatCount;i++){
            for (int i=0;i<100;i++){
                char randomFlip = ' ';
                if (rand() % 2) {
                    randomFlip = 'H';
                } else {
                    randomFlip = 'T';
                }
                std::cout<<'\b'<<randomFlip;
                sleep_until(system_clock::now() +  std::chrono::milliseconds(i));
            }
            std::cout<<'\b'<<cheatInput[i];            
            std::cout<<" |  ";
        }
    } else {
        std::cout<<' ';
        for (int i=0;i<userInput;i++){
            for (int i=0;i<100;i++){
                sleep_until(system_clock::now() +  std::chrono::milliseconds(i));
                char randomFlip = ' ';
                if (rand() % 2) {
                    randomFlip = 'H';
                } else {
                    randomFlip = 'T';
                }
                std::cout<<'\b'<<randomFlip;
            }
            std::cout<<" |  ";
        }
    }
    return 0;
}