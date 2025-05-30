#include "../header/scene.hpp"
#include "../header/interfaceTerminal.hpp"
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::flush;
using std::cin;
//Copy constructor
// Scene& Scene::operator=(const Scene& other) {
//     if (this != &other) {
//         this->choice = other.choice;
//     }
//     return *this;
// }


//openers dialogue-- until where my hug at
Scene::Scene():
	optionName(0)
{}
Scene::Scene(char name):
	optionName(name)
{}
char Scene::getOptionName(){
	return optionName;
}
void openingScene::dialogue(){
    string output = "You are Natalie Fitzgerald, a university student whose friend went missing at a frat party...\n";
    trickleDisplayString(output, 1);

    // cin >> userChoice;

    // if (choice == 'a') {
    //     return new takeHug();
    // } else if (choice == 'b') {
    //     return new rejectHug();
    // }

    // return nullptr; // if invalid input
}
void openingScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeHug('t');
	nextPossibleScenes.at(1)=new rejectHug('r');
	std::cout<<"Updated possible Scenes\n";
}


//if you take the hug
void takeHug::dialogue(){
    string output = "";
    output = " He reeks of tequila and cologne that never fully covered up whatever he did last night.\n Natalie: Chad, have you been drinking?! \n Chad: Have you not? It's Halloweekend, babe. \n It’s Thursday.";
    trickleDisplayString(output, 50);
}
void takeHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	for(Scene* currentPointer : nextPossibleScenes){
		cout<<currentPointer->getOptionName()<<endl;
	}
}

//if you dont take the hug
void rejectHug::dialogue(){
    string output = "";
    output = "Damn, Natalie. Acting brand new?";
    trickleDisplayString(output, 50);
}
void rejectHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	for(Scene* currentPointer : nextPossibleScenes){
		cout<<currentPointer->getOptionName()<<endl;
	}
}

//Continuing scene: kevin and lilith intro
void firstShotOptionScene::dialogue(){
    string output = "";
    output = "Natalie: Whatever. Have you seen [REDACTED]? She was not at her apartment, has not shown up to class, and her location is off… 
    \n Chad: Bro… I dunno. She is probably out getting hazed with her bigs or whatever. \n His eyes light up. 
    \nChad: But yo, forget that—you need to catch up. SHOTS. NOW. \n He grabs my arm, dragging me towards the kitchen. 
    \n Lilith: That girl was so hard to keep still — \n Kevin: NATALIEEE! Youre so late! Lilith already threw up twice! 
    \n It is 10:15 pm…the party started at 10. \n Lilith: Kevin, that was you. \n Kevin: IT IS FIVE O'CLOCK SOMEWHEREEEE, SO— 
    \n Lilith: So where is that friend of yours? [REDACTED], right? \n Natalie: I could ask you the same question. Aren't you the sweetheart of this frat? 
    \n Lilith: I mean, yeah—but we got like, over a hundred girls rushing. I dont remember every newbie.
    \n Chad walks pulls two bottles out of the fridge, waving them around.
    \n Chad : PICK YOUR POISON!
    \n Take the shot[t]
    \n Reject the shot[r]";
    trickleDisplayString(output, 50);
}
void firstShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeFirstShot('t');
	nextPossibleScenes.at(1)=new rejectFirstShot('r');
	std::cout<<"Updated possible Scenes\n";
}

//take first shot
void secondShotOptionScene::dialogue(){
    string output = "";
    output = "Kevin: WOOOAAAAAHH THAS LIQA!!!
    \n Lilith: I'm tired of babysitting him, Chad, tag in.
    \n Lilith grabs my arm and pulls me to the couch.
    \n Lilith: So what do you think of Kevin , he's cute huh? 
    \n Well yes..
    \n Natalie: Dude…
    \n Lilith: My bad I'm just trying to help my bro out. After all, I heard that you and your man just broke up..
    \n She pulls out small bottle of tequila from her purse.
    \n Lilith: Oops did that slip out , well I'm too deep in now to not tell you, but i need another shot so WE forget that I told you!
    \n Take the shot: Kevin’s cute, and I wanna know more[t]
    \n Reject the shot: I need to find my friend[r]";
    trickleDisplayString(output, 50);
}
void secondShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeSecondShot('t');
	nextPossibleScenes.at(1)=new rejectSecondShot('r');
	std::cout<<"Updated possible Scenes\n";
}


//reject first shot 
void rejectFirstShot::dialogue(){
    string output = "";
    output = "Chad: I know you're paranoid about your friend and all , but she aint here little lady. Stop killing the vibe.
    \n Natalie - Fine I'll find her myself, jerk.";
    trickleDisplayString(output, 50);
}


//takes second shot
void takeSecondShot::dialogue(){
    string output = "";
    output = "Lilith: Well the reason why he’s so drunk is cause he was trying to get the balls to talk to you again. Ever since yall met, he can't shut up about how he wants to get to know you more - you should go and talk to him right now see for yourself!
    \n Leave and look for Kevin[t]
    \n Press her about what happened to[REDACTED][r]";
    trickleDisplayString(output, 50);
}

void takeSecondShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new lookForKevin('t');
	nextPossibleScenes.at(1)=new pressHer('r');
	std::cout<<"Updated possible Scenes\n";
}

//press her
void pressHer::dialogue(){
    string output = "";
    output = "Lilith : I did what he would have wanted.
    \n ...
    \n Lilith: I told you I don't know already, anyway I'm going back in to distract Chad while you get Kevin's attention, tell me how it goes."
    trickleDisplayString(output, 50);
}

void pressHer::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new lookForKevin('t');
	std::cout<<"Updated possible Scenes\n";
}

///QUESTION FOR PEDRO HOW WE GONNA TRANSITION IS ONE OPTION TO GO BACK TO LOOK FOR KEVIN OKAY?  

//look for kevin
void lookForKevinScene:: dialogue(){
    string output = "";
    output = " I see Kevin next to the bathroom, keeping to himself. He doesn’t look like he's doing too well, as if he were about to profusely vomit.
    \n I sidle up to him, nervous with the revelation that Lilith gave me. We aren’t necessarily close, but we became pretty good friends 
    \n during our English class, as we did a final presentation together and both became academic victims.
    \n  Kevin: So, where have you been? I haven’t seen you since our project last quarter.
    \n Natalie: WHAT?
    \n The music is blaring. My ears are ringing.
    \n Kevin: WHERE HAVE YOU BEEN?!
    \n Natalie: WHAT???
    \n He laughs, and gestures to the porch.
    \n Kevin: OUTSIDE. LET'S GO OUTSIDEEE.
    \n We push through the crowd of people and eventually make it outside.
    \n Kevin: Anyways, as I was saying, or rather screaming, what have you been up to lately?
    \n Natalie: I've been looking for [REDACTED]. I haven’t seen her around in a few days, and no one has told me where she is. Have you seen her around?
    \n He looks on edge.
    \n Intensify your glare[t]
    \n Put your hand on his arm, feigning innocent conern[r]";
    trickleDisplayString(output, 50);
}

void lookForKevinScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new glare('t');
	nextPossibleScenes.at(1)=new touchHim('r');
	std::cout<<"Updated possible Scenes\n";
}

//kevin argument
void kevinArgument:: dialogue(){
    string output = "";
    output = "Kevin: Natalie, no one here knows anything. You’re supposed to be her best friend. How would we know, and you wouldn't?
    \n Natalie: BULLSHIT KEVIN!
    \n Kevin: Natalie I swear I don't know.
    \n Natalie: THE LAST NIGHT I HEARD FROM HER, SHE WAS WITH YOU, LILITH, AND CHAD. YOU GUYS SHOULD HAVE AT LEAST SEEN HER LEAVE.
    \n Kevin: She got a ride,  but that's the last we saw of her too. Lower your voice before they hear you.
    \n Natalie: Kevin, that's it. I'm going to the police like I should have in the first place.
    \n Kevin slams you into the wall and covers your mouth. He drags you towards the woods in the backyard, forcing you to be quiet. 
    \nHe tells you if you stay quiet, he’ll show you the truth.";
    trickleDisplayString(output, 50);
}

//KEVIN KILLS YOU ENDING
void kevinDeathEnding:: dialogue(){
    string output = "";
    output = "The air around me seems to grow heavier as Kevin pulls me deeper into the shadow of the woods. 
    \nThe muffled bass of the music from the party behind us does nothing to drown out the growing sense of dread in my gut. 
    \nI try to keep my footing, but Kevin’s grip is unrelenting.
    \nHe slams me against a rough tree trunk, the bark scraping against my back, the suddenness of it stealing my breath.
    \nMy pulse races in my ears, louder than the thudding beat inside. I try to scream, but Kevin’s hand is already over my mouth, his fingers cold and trembling.
    \nKevin: You should have kept quiet, Natalie. But fear not,this is a privilege for her and for you. As his children we must obey, he's been waiting for you.
    \nKevin: We will all be in his kingdom together, your death will have purpose, your flesh will bring us one step closer to reuniting with our father! επιστροφή σε μας Διόνυσο!
    \n I writhe in pain as zip ties tighten around my wrists, he pries my jaw open and pours sour wine down my throat.
    \n I try to spit it out, but he covers my mouth, forcing me to choke it down. I feel lighter as I accept my fate and see the haze of the candles slowly fade into darkness.
    \n I'm sorry Evelyn , I couldn't save you.";
    trickleDisplayString(output, 50);
}

//Kevin romance
void kevinRomance:: dialogue(){
    string output = "";
    output = "Kevin becomes flushed and stammers.
    \n Kevin:  I, I don’t know I’m sorry. All I know is that when someone’s been gone for this long… they probably aren’t coming back Natalie.
    \n Kevin:  I think it might be time for you to let the police handle it, and for you to move on.
    \n The weight of the situation truly crashes down on me. My throat swells and tears stream down 
    \n my face. He brushes the tear off of my cheek. Our eyes lock, and my body relaxes. I always 
    \n thought he was some douche, but this moment feels genuine. Was Lilith telling the truth? 
    \n Kevin: We will find her, I promise. She wouldn’t want you to panic, Natalie. I don’t want to see you like this. 
    \n He hands me a red solo cup.
    \n Kevin: We will go to the police station first thing tomorrow, together. But tonight let’s just relax.
    \n Take shot [t] 
    \n Reject shot [r]"; 
    trickleDisplayString(output, 50);
}

void lookForKevinScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeThirdShot('t'); //would take you to kevinDeathEnding
	nextPossibleScenes.at(1)=new rejectThirdShot('r'); //would take you to kevinArgument
	std::cout<<"Updated possible Scenes\n";
}

void Scene::trickleDisplayString(const string& inputString, uint8_t delay){
    const size_t BOX_WIDTH = 70; // Width inside the borders
    const size_t PADDING = 2;
    const size_t MAX_LINE = BOX_WIDTH - PADDING * 2;

    std::istringstream inputStream(inputString);
    std::vector<string> lines;
    string rawLine;

    // Word-wrap logic
    while (std::getline(inputStream, rawLine)) {
        std::istringstream wordStream(rawLine);
        string word, line;
        while (wordStream >> word) {
            if (line.length() + word.length() + 1 > MAX_LINE) {
                lines.push_back(line);
                line = word;
            } else {
                if (!line.empty()) line += " ";
                line += word;
            }
        }
        if (!line.empty()) {
            lines.push_back(line);
        }
        if (rawLine.empty()) lines.push_back("");
    }

    // Box characters
    const char CORNER = '+';
    const char HORIZONTAL = '=';
    const char VERTICAL = '|';

    // Top border
    cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;

    // Display lines with borders and padding
    for (const auto& l : lines) {
        string padded = string(PADDING, ' ') + l;
        padded += string(BOX_WIDTH - padded.length(), ' '); // Right space padding
        cout << VERTICAL;
        for (char c : padded) {
            cout << c << flush;
            sleep_for(milliseconds(delay));
        }
        cout << VERTICAL << endl;
    }

    // Bottom border
    cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;
}
