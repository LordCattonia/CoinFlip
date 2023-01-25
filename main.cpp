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
        std::cout<<"|  ";
        for (int i=0;i<cheatCount-1;i++){
            for (int i=0;i<50;i++){
                char randomFlip = ' ';
                if (rand() % 2) {
                    randomFlip = 'H';
                } else {
                    randomFlip = 'T';
                }
                std::cout<<'\b'<<randomFlip;
                sleep_until(system_clock::now() +  std::chrono::milliseconds(i*2));
            }
            std::cout<<'\b'<<cheatInput[i];            
            std::cout<<" |  ";
        }
        for (int i=0;i<50;i++) {
            char randomFlip = ' ';
            if (rand() % 2) {
                randomFlip = 'H';
            } else {
                randomFlip = 'T';
            }
            std::cout<<'\b'<<randomFlip;
            sleep_until(system_clock::now() +  std::chrono::milliseconds(i*2));
        }
        std::cout<<'\b'<<cheatInput[cheatCount-1];
        std::cout<<" |";
    } else {
        std::cout<<"|  ";
        for (int i=0;i<userInput-1;i++){
            for (int i=0;i<50;i++){
                sleep_until(system_clock::now() +  std::chrono::milliseconds(i*2));
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
        for (int i=0;i<50;i++) {
            char randomFlip = ' ';
            if (rand() % 2) {
                randomFlip = 'H';
            } else {
                randomFlip = 'T';
            }
            std::cout<<'\b'<<randomFlip;
            sleep_until(system_clock::now() +  std::chrono::milliseconds(i*2));
        }
        std::cout<<" |";
    }
    return 0;
}