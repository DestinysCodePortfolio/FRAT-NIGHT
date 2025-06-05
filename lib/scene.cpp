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
string openingScene::dialogue(){
    string output = string("You are Natalie Fitzgerald, a university student whose friend went missing at a frat party...\n");
    trickleDisplayString(output, 1);
    return output;

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
string takeHug::dialogue(){
    string output = string("\n He reeks of tequila and cologne that never fully covered up whatever he did last night.")
    + "\n Natalie: Chad, have you been drinking?!"
    + "\n Chad: Have you not? It's Halloweekend, babe."
    + "\n >It's Thursday. This man needs a life."
    + "\n Ask about [REDACTED] [t]";
    trickleDisplayString(output, 10);
    return output;
}

void takeHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
    nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new firstShotOptionScene('t');
	std::cout<<"Updated possible Scenes\n";
}



//if you dont take the hug
string rejectHug::dialogue(){
    string output = string("\n Damn, Natalie. Acting brand new?")
    + "\n Ask about [REDACTED] [t]";
    trickleDisplayString(output, 25);
    return output;
}

void rejectHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new firstShotOptionScene('t');
	std::cout<<"Updated possible Scenes\n";
}



//Continuing scene: kevin and lilith intro
string firstShotOptionScene::dialogue(){
    string output = string("\n Natalie: Whatever. Have you seen [REDACTED]? She was not at her apartment, has not shown up to class, and her location is off…")
    + "\n Chad: Bro… I dunno. She is probably out getting hazed with her bigs or whatever."
    + "\n >His eyes light up."
    + "\n Chad: But yo, forget that—you need to catch up. SHOTS. NOW."
    + "\n >He grabs my arm, dragging me towards the kitchen."
    + "\n Lilith: That girl was so hard to keep still —"
    + "\n Kevin: NATALIEEE! Youre so late! Lilith already threw up twice!"
    + "\n >It is 10:15 pm…the party started at 10."
    + "\n Lilith: Kevin, that was you."
    + "\n Kevin: IT IS FIVE O'CLOCK SOMEWHEREEEE, SO—"
    + "\n Lilith: So where is that friend of yours? [REDACTED], right?"
    + "\n Natalie: I could ask you the same question. Aren't you the sweetheart of this frat?"
    + "\n Lilith: I mean, yeah—but we got like, over a hundred girls rushing. I dont remember every newbie."
    + "\n >Chad pulls two bottles out of the fridge, waving them around."
    + "\n Chad : PICK YOUR POISON!"
    + "\n Take the shot[t]"
    + "\n Reject the shot[r]";
    trickleDisplayString(output, 25);
    return output;
}
void firstShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new secondShotOptionScene('t');
	nextPossibleScenes.at(1)=new rejectFirstShot('r');
	std::cout<<"Updated possible Scenes\n";
}

string rejectFirstShot::dialogue(){
  string output = string("\n I push the cup back toward him. I need to find her.")
    + "\n Chad: I know you're paranoid about your friend and all, but she aint here little lady. Stop killing the vibe."
    + "\n Natalie: Fine I'll find her myself, jerk."
     + "\n Leave and look for clues[c]";
    trickleDisplayString(output, 25);
    return output;
}
void rejectFirstShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
    nextPossibleScenes.resize(1);
    nextPossibleScenes.at(0)=new lookAroundForCLues('c');
    std::cout<<"Updated possible Scenes\n";
}

string lookAroundForCLues::dialogue(){
  string output = string("\n The music swells again, loud enough to shake the drywall.")
  + "\n I weave through the bodies and pass some guy in a horse mask vomiting into a potted plant."
  + "\n My shoulders brush past strangers who don’t even notice I’m there. "
  + "\n  check bathroom [c] ";
    trickleDisplayString(output, 25);
    return output;
} 
void lookAroundForCLues :: updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new bathroom('c');
	std::cout<<"Updated possible Scenes\n";
}

string bathroom::dialogue(){
string output;
    if (!checkedCabinet) output += " check medicine cabinet [c]\n";
    if (!checkedFlag)    output += " check frat flag [f]\n";
    if (!checkedMirror)  output += " look in the mirror [m]\n";
    if (checkedCabinet && checkedFlag && checkedMirror){
        output += " leave bathroom [l]\n";
       }
    trickleDisplayString(output, 25);
    return output;
}

string bathroomCheck::dialogue() {
    string output;
    if (checkedItem == 'c') {
        output += "You open the creaky door to the medicine cabinet. Inside: bandages, half-used toothpaste, and a small, chilling surprise — a blister pack of Rohypnol.\n";
        output += "Do you take it? → [grab it]\n";
        output += "You pocket the pills. You don’t know why. Maybe you just don’t trust the people who live here — and that instinct feels right.\n";
    } else if (checkedItem == 'f') {
        output += "Hung crooked on the wall across from the toilet, a filthy frat flag flutters slightly from a draft you can't place.\n";
        output += "Typical — they couldn’t even decorate with taste.\n";
        output += "You pull it aside.\n";
        output += "Behind it, nailed into the wall, dangles a small key on a string — the fabric stained a dark, tacky red. Blood?\n";
        output += "Do you take it? → [take the key]\n";
        output += "You hesitate. The stain is too fresh to ignore. Too thick to be paint.\n";
        output += "Still, your hand moves on its own. You slip the string off the nail and clutch the key — it's small, rusted, and old. Not meant for safety. Meant for secrets.\n";
        output += "The metal is warm.\n";
        output += "From somewhere behind you:\nDrip.\nDrip.\nDrip.\nThree sharp echoes. Like footsteps in shallow water.\n";
    } else if (checkedItem == 'm') {
        output += "You see her blood on the walls.\n";
        output += "The smell of metal makes you nauseous.\n";
        output += "You blink and realize it wasn't real. You see yourself, and you feel her watching too.\n";
    }
    trickleDisplayString(output, 25);
    return output;
}
void bathroomCheck::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    // After showing the narrative, go back to the main bathroom scene with updated flags
    nextPossibleScenes.clear();
    nextPossibleScenes.push_back(new bathroom('b', checkedCabinet, checkedFlag, checkedMirror));
}

void bathroom::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    nextPossibleScenes.clear();
    if (!checkedCabinet)
        nextPossibleScenes.push_back(new bathroomCheck('c', true, checkedFlag, checkedMirror));
    if (!checkedFlag)
        nextPossibleScenes.push_back(new bathroomCheck('f', checkedCabinet, true, checkedMirror));
    if (!checkedMirror)
        nextPossibleScenes.push_back(new bathroomCheck('m', checkedCabinet, checkedFlag, true));
    if (checkedCabinet && checkedFlag && checkedMirror)
        nextPossibleScenes.push_back(new lookKitchenOrBedroom('l'));
    std::cout << "Updated possible Scenes\n";
}

string lookKitchenOrBedroom::dialogue(){
    string output = string("\n > I step out the bathroom recollecting my thoughts from the expierence i just had.")
    +  " \n > The kitchen is a mess, and you can see the bedroom from here , which I assume is Chads."
    + " \n  The party is still going strong, and you can hear the bass thumping through the walls."
    + "\n > I can see chad in the kitchen, maybe i can get him to ... not notice me snooping but how ??? "
    + "\n  go to the kitchen [k]"
    + "\n  go to the bathroom [u].";
    trickleDisplayString(output, 25);
    return output;
}
void lookKitchenOrBedroom::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
     nextPossibleScenes.resize(2);
     nextPossibleScenes.at(0)=new kitchen('k');
    // nextPossibleScenes.at(1)=new room('k');
    // std::cout<<"Updated possible Scenes\n";
    cout << "RELEASE MEEE";
}
string kitchen::dialogue() {
    string output = string("\n > The kitchen is a mess. Sticky floors, red solo cups stacked like pyramids, and the smell of burnt pizza fighting the stench of beer.")
    + "\n  [f] Open fridge"
    + "\n  [s] Look in the sink"
    + "\n  [c] Open cabinet" 
     + "\n Slip something in Chad's drink";
    trickleDisplayString(output, 25);
    return output;
}
string kitchenCheck::dialogue() {
    string output;
    if (checkedItem == 'c') {
        output += "Chad : YO GET THE FUCK OUTTA MY FRIDGE FAT FUCK”;
    } else if (checkedItem == 'f') {
        output += "Hung crooked on the wall across from the toilet, a filthy frat flag flutters slightly from a draft you can't place.\n";
        output += "Typical — they couldn’t even decorate with taste.\n";
        output += "You pull it aside.\n";
        output += "Behind it, nailed into the wall, dangles a small key on a string — the fabric stained a dark, tacky red. Blood?\n";
        output += "Do you take it? → [take the key]\n";
        output += "You hesitate. The stain is too fresh to ignore. Too thick to be paint.\n";
        output += "Still, your hand moves on its own. You slip the string off the nail and clutch the key — it's small, rusted, and old. Not meant for safety. Meant for secrets.\n";
        output += "The metal is warm.\n";
        output += "From somewhere behind you:\nDrip.\nDrip.\nDrip.\nThree sharp echoes. Like footsteps in shallow water.\n";
    } else if (checkedItem == 'm') {
        output += "You see her blood on the walls.\n";
        output += "The smell of metal makes you nauseous.\n";
        output += "You blink and realize it wasn't real. You see yourself, and you feel her watching too.\n";
    }
    trickleDisplayString(output, 25);
    return output;
}
void bathroomCheck::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    // After showing the narrative, go back to the main bathroom scene with updated flags
    nextPossibleScenes.clear();
    nextPossibleScenes.push_back(new bathroom('b', checkedCabinet, checkedFlag, checkedMirror));
}

void bathroom::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    nextPossibleScenes.clear();
    if (!checkedCabinet)
        nextPossibleScenes.push_back(new bathroomCheck('c', true, checkedFlag, checkedMirror));
    if (!checkedFlag)
        nextPossibleScenes.push_back(new bathroomCheck('f', checkedCabinet, true, checkedMirror));
    if (!checkedMirror)
        nextPossibleScenes.push_back(new bathroomCheck('m', checkedCabinet, checkedFlag, true));
    if (checkedCabinet && checkedFlag && checkedMirror)
        nextPossibleScenes.push_back(new lookKitchenOrBedroom('l'));
    std::cout << "Updated possible Scenes\n";
}

//take first shot
string secondShotOptionScene::dialogue(){
    string output = string("\n Kevin: WOOOAAAAAHH THAS LIQA!!!")
    + "\n Lilith: I'm tired of babysitting him, Chad, tag in."
    + "\n >Lilith grabs my arm and pulls me to the couch."
    + "\n Lilith: So what do you think of Kevin , he's cute huh?"
    + "\n >Well yes.."
    + "\n Natalie: Dude…"
    + "\n Lilith: My bad I'm just trying to help my bro out. After all, I heard that you and your man just broke up.."
    + "\n >She pulls out small bottle of tequila from her purse."
    + "\n Lilith: Oops did that slip out , well I'm too deep in now to not tell you, but i need another shot so WE forget that I told you!"
    + "\n Take the shot: Kevin’s cute, and I wanna know more[t]"
    + "\n Reject the shot: I need to find my friend[r]";
    trickleDisplayString(output, 25);
    return output;
}
void secondShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeSecondShot('t');
	nextPossibleScenes.at(1)=new pressHer('r');
	std::cout<<"Updated possible Scenes\n";
}



//takes second shot
string takeSecondShot::dialogue(){
    string output = string("\n Lilith: Well the reason why he’s so drunk is cause he was trying to get the balls to talk to you again. Ever since yall met, he can't shut up about how he wants to get to know you more - you should go and talk to him right now see for yourself!")
    + "\n Leave and look for Kevin[t]"
    + "\n Press her about what happened to[REDACTED][r]";
    trickleDisplayString(output, 25);
    return output;
}

void takeSecondShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new lookForKevinScene('t');
	nextPossibleScenes.at(1)=new pressHer('r');
	std::cout<<"Updated possible Scenes\n";
}

//press her
string pressHer::dialogue(){
    string output = string("\n Lilith : I did what he would have wanted.")
    + "\n ..."
    + "\n Lilith: I told you I don't know already, anyway I'm going back in to distract Chad while you get Kevin's attention, tell me how it goes.";
    trickleDisplayString(output, 25);
    return output;
}

void pressHer::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new lookForKevinScene('t');
	std::cout<<"Updated possible Scenes\n";
}





///QUESTION FOR PEDRO HOW WE GONNA TRANSITION IS ONE OPTION TO GO BACK TO LOOK FOR KEVIN OKAY?  

//look for kevin
string lookForKevinScene:: dialogue(){
    string output = string("\n >I see Kevin next to the bathroom, keeping to himself. He doesn’t look like he's doing too well, as if he were about to profusely vomit.")
    + "\n >I sidle up to him, nervous with the revelation that Lilith gave me. We aren’t necessarily close, but we became pretty good friends"
    + "\n >during our English class, as we did a final presentation together and both became academic victims."
    + "\n Kevin: So, where have you been? I haven’t seen you since our project last quarter."
    + "\n Natalie: WHAT?"
    + "\n >The music is blaring. My ears are ringing."
    + "\n Kevin: WHERE HAVE YOU BEEN?!"
    + "\n Natalie: WHAT???"
    + "\n >He laughs, and gestures to the porch."
    + "\n Kevin: OUTSIDE. LET'S GO OUTSIDEEE."
    + "\n >We push through the crowd of people and eventually make it outside."
    + "\n Kevin: Anyways, as I was saying, or rather screaming, what have you been up to lately?"
    + "\n Natalie: I've been looking for [REDACTED]. I haven’t seen her around in a few days, and no one has told me where she is. Have you seen her around?"
    + "\n >He looks on edge."
    + "\n Intensify your glare[t]"
    + "\n Put your hand on his arm, feigning innocent conern[r]";
    trickleDisplayString(output, 25);
    return output;
}

void lookForKevinScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new kevinArgument('t');
	nextPossibleScenes.at(1)=new kevinRomance('r');
	std::cout<<"Updated possible Scenes\n";
}

//kevin argument + death ending
string kevinArgument:: dialogue(){
    string output = string("\n Kevin: Natalie, no one here knows anything. You’re supposed to be her best friend. How would we know, and you wouldn't?")
    + "\n Natalie: BULLSHIT KEVIN!"
    + "\n Kevin: Natalie I swear I don't know."
    + "\n Natalie: THE LAST NIGHT I HEARD FROM HER, SHE WAS WITH YOU, LILITH, AND CHAD. YOU GUYS SHOULD HAVE AT LEAST SEEN HER LEAVE."
    + "\n Kevin: She got a ride,  but that's the last we saw of her too. Lower your voice before they hear you."
    + "\n Natalie: Kevin, that's it. I'm going to the police like I should have in the first place."
    + "\n >Kevin slams you into the wall and covers your mouth. He drags you towards the woods in the backyard, forcing you to be quiet. "
    + "\n >He tells you if you stay quiet, he’ll show you the truth."
    + "\n >The air around me seems to grow heavier as Kevin pulls me deeper into the shadow of the woods."
    + "\n >The muffled bass of the music from the party behind us does nothing to drown out the growing sense of dread in my gut." 
    + "\n >I try to keep my footing, but Kevin’s grip is unrelenting."
    + "\n >He slams me against a rough tree trunk, the bark scraping against my back, the suddenness of it stealing my breath."
    + "\n >My pulse races in my ears, louder than the thudding beat inside. I try to scream, but Kevin’s hand is already over my mouth, his fingers cold and trembling."
    + "\n Kevin: You should have kept quiet, Natalie. But fear not,this is a privilege for her and for you. As his children we must obey, he's been waiting for you."
    + "\n Kevin: We will all be in his kingdom together, your death will have purpose, your flesh will bring us one step closer to reuniting with our father! επιστροφή σε μας Διόνυσο!"
    + "\n >I writhe in pain as zip ties tighten around my wrists, he pries my jaw open and pours sour wine down my throat."
    + "\n >I try to spit it out, but he covers my mouth, forcing me to choke it down. I feel lighter as I accept my fate and see the haze of the candles slowly fade into darkness."
    + "\n >I'm sorry Evelyn , I couldn't save you."
    + "\n Press q to quit";
    trickleDisplayString(output, 25);
    return output;
}
void kevinArgument::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){

}


//Kevin romance
string kevinRomance:: dialogue(){
    string output = string("Kevin becomes flushed and stammers.")
    +  "\n Kevin:  I, I don’t know I’m sorry. All I know is that when someone’s been gone for this long… they probably aren’t coming back Natalie."
    + "\n Kevin:  I think it might be time for you to let the police handle it, and for you to move on."
    + "\n >The weight of the situation truly crashes down on me. My throat swells and tears stream down"
    + "\n >my face. He brushes the tear off of my cheek. Our eyes lock, and my body relaxes. I always"
    + "\n >thought he was some douche, but this moment feels genuine. Was Lilith telling the truth?"
    + "\n Kevin: We will find her, I promise. She wouldn’t want you to panic, Natalie. I don’t want to see you like this." 
    + "\n >He hands me a red solo cup."
    + "\n Kevin: We will go to the police station first thing tomorrow, together. But tonight let’s just relax."
    + "\n Take shot [t]"
    + "\n Reject shot [r]"; 
    trickleDisplayString(output, 25);
    return output;
}

void kevinRomance::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeThirdShot('t'); //would take you to kevinDeathEnding
	nextPossibleScenes.at(1)=new rejectThirdShot('r'); 
	std::cout<<"Updated possible Scenes\n";
}

string takeThirdShot:: dialogue(){
    string output = string("The alcohol burns as it pours down my throat...")
    + "\n >..."
    + "\n ... I don't feel so good...my eyes close"
    + "\n >..."
    + "\n >The air around me seems to grow heavier as Kevin pulls me deeper into the shadow of the woods."
    + "\n >The muffled bass of the music from the party behind us does nothing to drown out the growing sense of dread in my gut." 
    + "\n >I try to keep my footing, but Kevin’s grip is unrelenting."
    + "\n >He slams me against a rough tree trunk, the bark scraping against my back, the suddenness of it stealing my breath."
    + "\n >My pulse races in my ears, louder than the thudding beat inside. I try to scream, but Kevin’s hand is already over my mouth, his fingers cold and trembling."
    + "\n Kevin: You should have kept quiet, Natalie. But fear not,this is a privilege for her and for you. As his children we must obey, he's been waiting for you."
    + "\n Kevin: We will all be in his kingdom together, your death will have purpose, your flesh will bring us one step closer to reuniting with our father! επιστροφή σε μας Διόνυσο!"
    + "\n >I writhe in pain as zip ties tighten around my wrists, he pries my jaw open and pours sour wine down my throat."
    + "\n >I try to spit it out, but he covers my mouth, forcing me to choke it down. I feel lighter as I accept my fate and see the haze of the candles slowly fade into darkness."
    + "\n >I'm sorry Evelyn , I couldn't save you."
    + "\n Press q to quit.";
    trickleDisplayString(output, 25);
    return output;
}

void takeThirdShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){

}


string rejectThirdShot:: dialogue(){
    string output = string("\n Kevin: Natalie, no one here knows anything. You’re supposed to be her best friend. How would we know, and you wouldn't?")
    + "\n Natalie: BULLSHIT KEVIN!"
    + "\n Kevin: Natalie I swear I don't know."
    + "\n Natalie: THE LAST NIGHT I HEARD FROM HER, SHE WAS WITH YOU, LILITH, AND CHAD. YOU GUYS SHOULD HAVE AT LEAST SEEN HER LEAVE."
    + "\n Kevin: She got a ride,  but that's the last we saw of her too. Lower your voice before they hear you."
    + "\n Natalie: Kevin, that's it. I'm going to the police like I should have in the first place."
    + "\n Kevin slams you into the wall and covers your mouth. He drags you towards the woods in the backyard, forcing you to be quiet. "
    + "\n He tells you if you stay quiet, he’ll show you the truth."
    + "\n The air around me seems to grow heavier as Kevin pulls me deeper into the shadow of the woods."
    + "\n The muffled bass of the music from the party behind us does nothing to drown out the growing sense of dread in my gut." 
    + "\n I try to keep my footing, but Kevin’s grip is unrelenting."
    + "\n He slams me against a rough tree trunk, the bark scraping against my back, the suddenness of it stealing my breath."
    + "\n My pulse races in my ears, louder than the thudding beat inside. I try to scream, but Kevin’s hand is already over my mouth, his fingers cold and trembling."
    + "\n Kevin: You should have kept quiet, Natalie. But fear not,this is a privilege for her and for you. As his children we must obey, he's been waiting for you."
    + "\n Kevin: We will all be in his kingdom together, your death will have purpose, your flesh will bring us one step closer to reuniting with our father! επιστροφή σε μας Διόνυσο!"
    + "\n >I writhe in pain as zip ties tighten around my wrists, he pries my jaw open and pours sour wine down my throat."
    + "\n >I try to spit it out, but he covers my mouth, forcing me to choke it down. I feel lighter as I accept my fate and see the haze of the candles slowly fade into darkness."
    + "\n >I'm sorry Evelyn , I couldn't save you."
    + "\n Press q to quit";
    trickleDisplayString(output, 25);
    return output;
} 

void rejectThirdShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){

}


// vvv Put this in the main game screen, not in the scene class

void Scene::trickleDisplayString(const string& inputString, uint8_t delay){
	const size_t BOX_WIDTH = 100; // Width inside the borders
	const size_t PADDING = 2;
	const size_t MAX_LINE = BOX_WIDTH - PADDING * 4;


	istringstream inputStream(inputString);
	vector<string> lines;
	string rawLine;


	// Word-wrap logic
	while (getline(inputStream, rawLine)) {
			istringstream wordStream(rawLine);
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
        size_t RIGHT_PADDINNG = 0;
        if(l.length() + PADDING < BOX_WIDTH){
            RIGHT_PADDINNG = BOX_WIDTH - (l.length() + PADDING);
        }

        string padded = string(PADDING, ' ') + l + string(RIGHT_PADDINNG, ' ');
        cout << VERTICAL;
        for(char c: padded){
            cout << c << flush;
            sleep_for(milliseconds(delay));
        }
        cout <<  endl;
	}


	// Bottom border
	cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;
}