#include "../header/quickTimeEvent.hpp"
#include <iostream>

quickTimeEvent::quickTimeEvent(double dur, std::string crrctAns){
    soln = crrctAns;
    duration = dur;
}

void quickTimeEvent::setDuration(double newDur){
    duration = newDur;
}

double quickTimeEvent::getDuration(){ return duration; }

bool quickTimeEvent::startEvent(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Quick time event starting, you have " << duration << " seconds to type the following exactly: \n" << soln << '\n';
    const auto start{std::chrono::steady_clock::now()};
    getline(std::cin, userInp);
    const auto finish{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{finish - start};
    if(elapsed_seconds.count() < duration && userInp == soln){
        return true;
    }
    return false;
}