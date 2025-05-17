#pragma once
#include <cstdint>
#include <string>
using std::string;

struct Scene{
    Scene() = default;
    virtual ~Scene() = default;
    Scene(Scene& other) = delete;
    Scene& operator=(Scene& other) = delete;
    virtual void dialogue()=0;    
};

class openingScene:public Scene{
    void dialogue() override;
};

class takeFirstShot:public Scene{
    void dialogue() override;
};