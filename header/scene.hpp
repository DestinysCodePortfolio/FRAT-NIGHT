#pragma once
#include <cstdint>
#include <vector>
#include <string>
using std::string;
using std::vector;

class Scene{
		const char optionName;
	protected:
		void trickleDisplayString(const string& inputString, uint8_t delay);
	public: 
		Scene();
		Scene(char name);
		virtual ~Scene() = default;
		Scene(Scene& other) = delete;
		Scene& operator=(Scene& other) = delete;
		char getOptionName();
		virtual string dialogue()=0;
		virtual void updatePossibleScenes(vector<Scene*>& nextPossibleScenes)=0;
};

struct openingScene:public Scene{
	openingScene(): Scene(){}
	openingScene(char name): Scene(name){}
	~openingScene() override=default;
	openingScene(openingScene& other) = delete;
	openingScene& operator=(openingScene& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct takeHug:public Scene{
	takeHug(): Scene(){}
	takeHug(char name): Scene(name){}
	~takeHug() override=default;
	takeHug(takeHug& other) = delete;
	takeHug& operator=(takeHug& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectHug:public Scene{
	rejectHug(): Scene(){}
	rejectHug(char name): Scene(name){}
	~rejectHug() override=default;
	rejectHug(rejectHug& other) = delete;
	rejectHug& operator=(rejectHug& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct firstShotOptionScene:public Scene{
	firstShotOptionScene(): Scene(){}
	firstShotOptionScene(char name): Scene(name){}
	~firstShotOptionScene() override=default;
	firstShotOptionScene(firstShotOptionScene& other) = delete;
	firstShotOptionScene& operator=(firstShotOptionScene& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectFirstShot:public Scene{
	rejectFirstShot(): Scene(){}
	rejectFirstShot(char name): Scene(name){}
	~rejectFirstShot() override=default;
	rejectFirstShot(rejectFirstShot& other) = delete;
	rejectFirstShot& operator=(rejectFirstShot& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct secondShotOptionScene:public Scene{
	secondShotOptionScene(): Scene(){}
	secondShotOptionScene(char name): Scene(name){}
	~secondShotOptionScene() override=default;
	secondShotOptionScene(secondShotOptionScene& other) = delete;
	secondShotOptionScene& operator=(secondShotOptionScene& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};


struct takeSecondShot:public Scene{
	takeSecondShot(): Scene(){}
	takeSecondShot(char name): Scene(name){}
	~takeSecondShot() override=default;
	takeSecondShot(takeSecondShot& other) = delete;
	takeSecondShot& operator=(takeSecondShot& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct pressHer:public Scene{
	pressHer(): Scene(){}
	pressHer(char name): Scene(name){}
	~pressHer() override=default;
	pressHer(pressHer& other) = delete;
	pressHer& operator=(pressHer& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct lookForKevinScene: public Scene{
	lookForKevinScene(): Scene(){}
	lookForKevinScene(char name): Scene(name){}
	~lookForKevinScene() override=default;
	lookForKevinScene(lookForKevinScene& other) = delete;
	lookForKevinScene& operator=(lookForKevinScene& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct kevinArgument: public Scene{
	kevinArgument(): Scene(){}
	kevinArgument(char name): Scene(name){}
	~kevinArgument() override=default;
	kevinArgument(kevinArgument& other) = delete;
	kevinArgument& operator=(kevinArgument& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct kevinRomance: public Scene{
	kevinRomance(): Scene(){}
	kevinRomance(char name): Scene(name){}
	~kevinRomance() override=default;
	kevinRomance(kevinRomance& other) = delete;
	kevinRomance& operator=(kevinRomance& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct rejectThirdShot: public Scene{
	rejectThirdShot(): Scene(){}
	rejectThirdShot(char name): Scene(name){}
	~rejectThirdShot() override=default;
	rejectThirdShot(rejectThirdShot& other) = delete;
	rejectThirdShot& operator=(rejectThirdShot& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct takeThirdShot: public Scene{
	takeThirdShot(): Scene(){}
	takeThirdShot(char name): Scene(name){}
	~takeThirdShot() override=default;
	takeThirdShot(takeThirdShot& other) = delete;
	takeThirdShot& operator=(takeThirdShot& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct lookAroundForCLues: public Scene{
	lookAroundForCLues(): Scene(){}
	lookAroundForCLues(char name): Scene(name){}
	~lookAroundForCLues() override=default;
	lookAroundForCLues(lookAroundForCLues& other) = delete;
	lookAroundForCLues& operator=(lookAroundForCLues& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct bathroom : public Scene {
    bool checkedCabinet;
    bool checkedFlag;
    bool checkedMirror;
    char lastChecked;
    ~bathroom() override=default;
	bathroom(bathroom& other) = delete;
	bathroom& operator=(bathroom& other) = delete;
    bathroom(char name, bool cab = false, bool flag = false, bool mirror = false, char last = 0)
        : Scene(name), checkedCabinet(cab), checkedFlag(flag), checkedMirror(mirror), lastChecked(last) {}
    string dialogue() override;
    void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

    string dialogue() override;
    void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct lookKitchenOrBedroom: public Scene{
	lookKitchenOrBedroom(): Scene(){}
	lookKitchenOrBedroom(char name): Scene(name){}
	~lookKitchenOrBedroom() override=default;
	lookKitchenOrBedroom(lookKitchenOrBedroom& other) = delete;
	lookKitchenOrBedroom& operator=(lookKitchenOrBedroom& other) = delete;
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct room:public Scene{
	room(): Scene(){}
	room(char name): Scene(name){}
	~room() override=default;
	room(room& other) = delete;
	room& operator=(room& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};
struct failRoofieScene:public Scene{
	failRoofieScene(): Scene(){}
	failRoofieScene(char name): Scene(name){}
	~failRoofieScene() override=default;
	failRoofieScene(failRoofieScene& other) = delete;
	failRoofieScene& operator=(failRoofieScene& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct kitchen : public Scene {
    bool checkedKitchenCabinet;
    bool checkedFridge;
    bool checkedSink;
    char lastChecked; 
	bool roofieAttempt = false; 
	bool slippedSomethingInDrink = false;
	bool gotPassword = false;
    ~kitchen() override=default;
	kitchen(kitchen& other) = delete;
	kitchen& operator=(kitchen& other) = delete;
  kitchen(char name, bool cab = false, bool fridge = false, bool sink = false, bool attempt = false, bool roofie = false, char last = 0, bool pass = false)
    : Scene(name), checkedKitchenCabinet(cab), checkedFridge(fridge), checkedSink(sink), roofieAttempt(attempt), slippedSomethingInDrink(roofie), lastChecked(last), gotPassword(pass) {}
    string dialogue() override;
    void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct bedroomNoPassword: public Scene {
	bedroomNoPassword(): Scene(){}
	bedroomNoPassword(char name): Scene(name){}
	~bedroomNoPassword() override=default;
	bedroomNoPassword(bedroomNoPassword& other) = delete;
	bedroomNoPassword& operator=(bedroomNoPassword& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct bedroomPassword: public Scene {
	bedroomPassword(): Scene(){}
	bedroomPassword(char name): Scene(name){}
	~bedroomPassword() override=default;
	bedroomPassword(bedroomPassword& other) = delete;
	bedroomPassword& operator=(bedroomPassword& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct policeEnding: public Scene {
	policeEnding(): Scene(){}
	policeEnding(char name): Scene(name){}
	~policeEnding() override=default;
	policeEnding(policeEnding& other) = delete;
	policeEnding& operator=(policeEnding& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct canonEnding: public Scene {
	canonEnding(): Scene(){}
	canonEnding(char name): Scene(name){}
	~canonEnding() override=default;
	canonEnding(bedroomNoPassword& other) = delete;
	canonEnding& operator=(canonEnding& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct runQuickTimeEvent: public Scene {
	runQuickTimeEvent(): Scene(){}
	runQuickTimeEvent(char name): Scene(name){}
	~runQuickTimeEvent() override=default;
	runQuickTimeEvent(runQuickTimeEvent& other) = delete;
	runQuickTimeEvent& operator=(runQuickTimeEvent& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

struct failedQuickTimeEvent: public Scene {
	failedQuickTimeEvent(): Scene(){}
	failedQuickTimeEvent(char name): Scene(name){}
	~failedQuickTimeEvent() override=default;
	failedQuickTimeEvent(failedQuickTimeEvent& other) = delete;
	failedQuickTimeEvent& operator=(failedQuickTimeEvent& other) = delete;  
	string dialogue() override;
	void updatePossibleScenes(vector<Scene*>& nextPossibleScenes) override;
};

