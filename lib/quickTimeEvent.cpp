#include "../header/quickTimeEvent.hpp"
#include <iostream>

quickTimeEvent::quickTimeEvent(double dur, std::string crrctAns){
    soln = crrctAns;
    //userInp = getInp;
    duration = dur;
}

void quickTimeEvent::setDuration(double newDur){
    duration = newDur;
}

double quickTimeEvent::getDuration(){ return duration; }

bool quickTimeEvent::startEvent(){
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



/*example tests to demonstrate functionality 
int main(){
    quickTimeEvent run(17, "lrlrlrlrlrlr");
    run.setDuration(7);
    if(run.startEvent()){
        std::cout << "You're a runner you're a track star!!\n";
    }else{
        std::cout << "You got murdered :(\n";
    }

    quickTimeEvent roofie(1, "roofie");
    roofie.setDuration(6);
    if(roofie.startEvent()){
        std::cout << "Walter White core\n";
    }else{
        std::cout << "No drugging ppl for you\n";
    }
    return 0;
}

*/