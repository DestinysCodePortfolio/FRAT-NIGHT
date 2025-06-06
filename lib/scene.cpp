#include "../header/scene.hpp"
#include "../header/quickTimeEvent.hpp"
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
    string output = string("> You are Natalie Fitzgerald, a university student whose friend went missing at a frat party a couple nights ago.")
    + "\n> You are here at another party, trying to unravel the mystery of her disappearance. You know they did it. You just can't prove it. "
    + "\n My ears throb with every bass drop pounding through the floorboards."
    + "\n  Sweat clings to my back. The house is packed wall to wall—drunken laughter, sticky floors, and that sour-sweet stench of booze and regret."
    + "\n ???: YO! Look who finally decided to pull up!"
    + "\n  A can sprays open. A vodka seltzer fizzes out all over Chad’s hand as he slides into view,  stumbling a little with his arms open."
    + "\n Chad: “Where my hug at?"
    + "\n Take the hug[t]"
    + "\n Reject the hug[r]";
    trickleDisplayString(output, 1);
    return output;


}
void openingScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeHug('t');
	nextPossibleScenes.at(1)=new rejectHug('r');
}

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
}

string rejectHug::dialogue(){
    string output = string("\n Damn, Natalie. Acting brand new?")
    + "\n Ask about [REDACTED] [t]";
    trickleDisplayString(output, 10);
    return output;
}

void rejectHug::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new firstShotOptionScene('t');
}

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
    trickleDisplayString(output, 10);
    return output;
}
void firstShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new secondShotOptionScene('t');
	nextPossibleScenes.at(1)=new rejectFirstShot('r');
}

string rejectFirstShot::dialogue(){
  string output = string("\n I push the cup back toward him. I need to find her.")
    + "\n Chad: I know you're paranoid about your friend and all, but she aint here little lady. Stop killing the vibe."
    + "\n Natalie: Fine I'll find her myself, jerk."
     + "\n Leave and look for clues[c]";
    trickleDisplayString(output, 10);
    return output;
}
void rejectFirstShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
    nextPossibleScenes.resize(1);
    nextPossibleScenes.at(0)=new lookAroundForCLues('c');
}

string lookAroundForCLues::dialogue(){
  string output = string("\n The music swells again, loud enough to shake the drywall.")
  + "\n I weave through the bodies and pass some guy in a horse mask vomiting into a potted plant."
  + "\n My shoulders brush past strangers who don’t even notice I’m there. "
  + "\n  check bathroom [c] ";
    trickleDisplayString(output, 10);
    return output;
} 
void lookAroundForCLues :: updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new bathroom('c');
}

string bathroom::dialogue() {
    string output;

    if (lastChecked == 'c') {
        output += "You open the creaky door to the medicine cabinet. Inside: bandages, half-used toothpaste, and a small, chilling surprise — a blister pack of Rohypnol.\n";
        output += "You pocket the pills. You don’t know why. Maybe you just don’t trust the people who live here — and that instinct feels right.\n";
    } else if (lastChecked == 'f') {
        output += "Hung crooked on the wall across from the toilet, a filthy frat flag flutters slightly from a draft you can't place.\n";
        output += "Typical — they couldn’t even decorate with taste.\n";
        output += "You pull it aside.\n";
        output += "Behind it, nailed into the wall, dangles a small key on a string — the fabric stained a dark, tacky red. Blood?\n";
        output += "Do you take it? → [take the key]\n";
        output += "You hesitate. The stain is too fresh to ignore. Too thick to be paint.\n";
        output += "Still, your hand moves on its own. You slip the string off the nail and clutch the key — it's small, rusted, and old. Not meant for safety. Meant for secrets.\n";
        output += "The metal is warm.\n";
        output += "From somewhere behind you:\nDrip.\nDrip.\nDrip.\nThree sharp echoes. Like footsteps in shallow water.\n";
    } else if (lastChecked == 'm') {
        output += "You see her blood on the walls.\n";
        output += "The smell of metal makes you nauseous.\n";
        output += "You blink and realize it wasn't real. You see yourself, and you feel her watching too.\n";
    }

    if (!checkedCabinet) output += " check medicine cabinet [c]\n";
    if (!checkedFlag)    output += " check frat flag [f]\n";
    if (!checkedMirror)  output += " look in the mirror [m]\n";
    if (checkedCabinet && checkedFlag && checkedMirror)
        output += " leave bathroom [l]\n";

    trickleDisplayString(output, 10);
    return output;
}
void bathroom::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    nextPossibleScenes.clear();
    if (!checkedCabinet)
        nextPossibleScenes.push_back(new bathroom('c', true, checkedFlag, checkedMirror, 'c'));
    if (!checkedFlag)
        nextPossibleScenes.push_back(new bathroom('f', checkedCabinet, true, checkedMirror, 'f'));
    if (!checkedMirror)
        nextPossibleScenes.push_back(new bathroom('m', checkedCabinet, checkedFlag, true, 'm'));
    if (checkedCabinet && checkedFlag && checkedMirror)
        nextPossibleScenes.push_back(new lookKitchenOrBedroom('l'));
}



string lookKitchenOrBedroom::dialogue(){
    string output = string("\n > I step out the bathroom recollecting my thoughts from the expierence i just had.")
    +  " \n > The kitchen is a mess, and you can see the bedroom from here , which I assume is Chads."
    + " \n  The party is still going strong, and you can hear the bass thumping through the walls."
    + "\n > I can see chad in the kitchen, maybe i can get him to ... not notice me snooping but how ??? "
    + "\n  go to the kitchen [k]"
    + "\n  go to the bedroom [u].";
    trickleDisplayString(output, 10);
    return output;
}
void lookKitchenOrBedroom::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
    nextPossibleScenes.clear();
    nextPossibleScenes.push_back(new kitchen('k'));
    nextPossibleScenes.push_back(new bedroomNoPassword('u'));

}

string kitchen::dialogue() {
    string output;

    if(lastChecked == 0 && !checkedKitchenCabinet && !checkedFridge && !checkedSink) {
        output += "\nYou step into the kitchen. It's a mess, but there's work to be done...";
    }
    else if (lastChecked == 'c') {
        output += string("\nChad: (voice sharp now, stepping forward)")
            + "\nChad: Okay, Natalie. What's your deal?"
            + "\nHe's not smiling anymore."
            + "\nYou think this is funny? Snooping through our shit? You wanna get kicked the fuck out?"
            + "\nHis breath reeks of liquor. His eyes are glassy—but alert."
            + "\nSomething behind them is dangerous."
            + "\nNot playful anymore. Just angry. And hiding something."
            + "\nNatalie: Shit I was just looking for chasers, my bad bro."
            + "\nChad: riggghtttt. Well there's limes next to liquor, blind bitch."
            + "\nAlcoholic. I wish there was a way to fuck him up more so he could get off my back for five minutes.";
    }
    else if (lastChecked == 'y') {
        output += string("\nI see a small notepad, inside is a bunch of grocery list items, but one page labeled passwords.")
            + "\nLAPTOP PASSWORD: MYBALLSITCH18"
            + "\nI put the notebook back and close the cabinet.";
          
    }
    else if (lastChecked == 'f') {
        output += string("\nI see lots of wine, beer, and someone's gross leftovers, but behind that all I see ")
            + "\nsome unidentifiable meat that smells like it's been rotting for a while. I feel anxious just looking at it."
            + "\nChad: YO GET THE FUCK OUTTA MY FRIDGE FAT FUCK";
    }
    else if (lastChecked == 's') {
        output += string("\nYou see hair that resembles hers. You miss her.")
            + "\nIt looks like someone tried to shove it down the drain. It looks like it's been burned.";
    }
    else if (lastChecked == 'd') {
        output += string("\nNatalie: I'm going to make another drink, do you want one?")
            + "\nChad: Sure. Maybe then you'll chill out"
            + "\nHe pulls out a geek bar and leans on the counter."
            + "\nI begin pouring the liquor into two red solo cups, "
            + "\nI have to be careful slipping in what I found earlier so he does not notice.";
 
       
        quickTimeEvent roofieEvent(10, "roofie");
        if (!roofieEvent.startEvent()) {
            output += string("\nShit.")
                + "\nChad looks over."
                + "\nChad: WHAT THE FUCK ARE YOU DOING? THAT'S IT GET THE FUCK OUT OF MY HOUSE!"
                + "\nI run out of the kitchen and sprint up to the bedroom, I can't leave yet, not without what I need, I slip the key into the door and lock it behind me.";
        } else {
            output += string("\nHe doesn't notice.")
                + "\nGood."
                + "\nNatalie: Here you go."
                + "\nChad takes it and gulps it down."
                + "\nAfter a few minutes of waiting in the kitchen he begins stumbling even more than before."
                + "\nChad: I nEeD.. tO fInD.. LiLiTh."
                + "\nHe stumbles out of the room. I can open whatever is in that cabinet now.";
                slippedSomethingInDrink = true;
        }
    }
    else if (lastChecked == 'l') {
        output += "\nNatalie: I decide to leave the kitchen.";
    }
    if (!checkedKitchenCabinet) {
        output += "\n  [c] Open cabinet";
    }
    if (checkedKitchenCabinet && slippedSomethingInDrink) {
        output += "\n  [y] Check cabinet again";
    }
    if (!checkedFridge) {
        output += "\n  [f] Open fridge";
    }
    if (!checkedSink) {
        output += "\n  [s] Look in the sink";
    }
    if (checkedKitchenCabinet && !roofieAttempt) {
        output += "\n  [d] Slip something in Chad's drink";
    }
    if (checkedKitchenCabinet && checkedFridge && checkedSink && (slippedSomethingInDrink || roofieAttempt)) {
        output += "\n  [l] Leave kitchen";
    }
 
    trickleDisplayString(output, 1);
    return output;
}void kitchen::updatePossibleScenes(vector<Scene*>& nextPossibleScenes) {
    for (Scene* scene : nextPossibleScenes) {
        delete scene;
    }
    nextPossibleScenes.clear();
    
    if (!checkedKitchenCabinet) {
        nextPossibleScenes.push_back(new kitchen('c', true, checkedFridge, checkedSink, roofieAttempt, slippedSomethingInDrink, 'c', gotPassword));
    }
    
    if (checkedKitchenCabinet && !gotPassword) {
        nextPossibleScenes.push_back(new kitchen('y', checkedKitchenCabinet, checkedFridge, checkedSink, roofieAttempt, slippedSomethingInDrink, 'y', true));
    }
    
    if (!checkedFridge) {
        nextPossibleScenes.push_back(new kitchen('f', checkedKitchenCabinet, true, checkedSink, roofieAttempt, slippedSomethingInDrink, 'f', gotPassword));
    }
    
    if (!checkedSink) {
        nextPossibleScenes.push_back(new kitchen('s', checkedKitchenCabinet, checkedFridge, true, roofieAttempt, slippedSomethingInDrink, 's', gotPassword));
    }
    
    if (checkedKitchenCabinet && !roofieAttempt) {
        nextPossibleScenes.push_back(new kitchen('d', checkedKitchenCabinet, checkedFridge, checkedSink, true, false, 'd', gotPassword));
    }

     if (roofieAttempt && !slippedSomethingInDrink) { 
        cout << "DEBUG: Adding bedroomNoPassword scene" << endl;
        nextPossibleScenes.push_back(new bedroomNoPassword('u'));
    }
       if (roofieAttempt && slippedSomethingInDrink && gotPassword) { 
        cout << "DEBUG: Adding password scene" << endl;
        nextPossibleScenes.push_back(new bedroomPassword('u'));
    }
    else if (checkedKitchenCabinet && checkedFridge && checkedSink && (slippedSomethingInDrink || roofieAttempt)) {
        if (gotPassword && slippedSomethingInDrink) {
            nextPossibleScenes.push_back(new bedroomPassword('k'));
        } else {
            nextPossibleScenes.push_back(new lookKitchenOrBedroom('l'));
        }
    }
}

string bedroomNoPassword:: dialogue(){
    string output = string("> I close the bedroom door behind me and lock it.")
    + "\n > KNOCK KNOCK KNOCK"
    + "\n > I need to hurry."
    + "\n There is a laptop open on the desk, I bet there is some sort of evidence on there."
    + "\n Take the laptop to the police[t]";
    trickleDisplayString(output, 10);
    return output;
} 
void bedroomNoPassword::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
     nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new policeEnding('t');
}


string runQuickTimeEvent:: dialogue(){
    string output = string("> I push the window open frantically and hop out")
    + "> My ankles throb after the landing but I begin sprinting. I hear someone chasing after me."
    + "> RUN.. ";
    quickTimeEvent run(8, "lrlrlrlrlrlr");
    if(run.startEvent()){
        runSuccess = true;
    }else{
        runSuccess = false;
    }
	return output;
}

void runQuickTimeEvent::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
nextPossibleScenes.resize(1);
    if(runSuccess){
        nextPossibleScenes.at(0)=new policeEnding('p');
    }else{
        nextPossibleScenes.at(0)=new failedQuickTimeEvent();
    }
}

string failedQuickTimeEvent:: dialogue(){
    string output = string("My legs give out as I fall and my head slams on the ground.")
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
    trickleDisplayString(output, 10);
    return output;
}

void failedQuickTimeEvent::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
}

string bedroomPassword:: dialogue(){
    string output = string("> I close the bedroom door behind me and lock it.")
    + "\n > KNOCK KNOCK KNOCK"
    + "\n > I need to hurry."
    + "\n There is a laptop open on the desk, I bet there is some sort of evidence on there."
    + "\n Take the laptop to the police[t]"
    + "\n Enter the password you found[e]";
        trickleDisplayString(output, 10);
        return output;
}

void bedroomPassword::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new policeEnding('t');
	nextPossibleScenes.at(1)=new canonEnding('e');
}

string canonEnding:: dialogue(){
    string output = string("> The computer unlocks, the desktop is a chaotic mess of files and folders.")
    + "\n> The file names are written in a different language… is that…Greek? "
    + "\n> I click on a file"
    + "\n> ..."
    + "\n> I found her."
    + "\n> Evelyn.."
    + "\n> ..."
    + "\n> I think I am going to be sick.."
    + "\n>DO YOU REMEMBER WHAT YOU DID ?"
    + "\n> WHO ARE YOU TRYING TO FOOL, NATALIE?"  
    + "\n> YOU TOOK HER THERE."
    + "\n> YOU HEARD THE STORIES"
    + "\n YOU BROKE BREAD WITH THEM"
    +"\n>YOU WERE THERE."
    +"\n>YOU RAN."
    +"\n>YOU RAN."
    +"\n>YOU RAN."
    +"\n>YOU FELT SOMETHING WRONG."
    +"\n>YOU LET HER STAY."
    +"\n>YOU RAN."
    +"\n>YOU RAN."
    +"\n>YOU RAN."
    +"\n> YOU MUST FINISH WHAT HAS BEEN STARTED."
    +"\n>YOU MUST PROTECT OTHERS."
    +"\n>END IT."
    +"\n>END IT."
    +"\n>END IT."
    +"\nεπιστροφή σε μας Διόνυσο"
    +"\nεπιστροφή σε μας Διόνυσο"
    +"\nεπιστροφή σε μας Διόνυσο"
    +"\nεπιστροφή σε μας Διόνυσο"
    +"\n> I lunge the knife into my throat." 
    +"\n> ..."
    +"\n Surprise! :) https://iqnc06.github.io/";
    trickleDisplayString(output, 10);
    return output;
}

void canonEnding:: updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
} 

string policeEnding:: dialogue(){
    string output = string("> I hear voices screaming my name behind me")
    + "\n> but I am able to sprint fast enough out of there."
    + "\n ..."
    +" \n Police Report 2013: Several murders linked to a local university’s fraternity have begun investigation,"
    + "\n students Chadwick Williams, Lilith Catren, and Kevin Chaidez have been brought into custody."
    + "\n Police found footage of the 4 in what looks like a mass homicide. It is rumored that this was a part of a ritual led by Williams as a religious sacrifice to a Roman god named Dionysus."
    + "\n he police found the bodies in the forest after an anonymous individual left a laptop at the Indiana University police department with footage of the suspects brutally murdering"
    + "\n 19-year-old Evelyn Gonzalez , a girl rushing for the frat. Some of the bodies were so dismembered that police only found their identities after a DNA report.";
    trickleDisplayString(output, 10);
    return output;
}

void policeEnding:: updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
} 

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
    trickleDisplayString(output, 10);
    return output;
}
void secondShotOptionScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeSecondShot('t');
	nextPossibleScenes.at(1)=new pressHer('r');
}

string takeSecondShot::dialogue(){
    string output = string("\n Lilith: Well the reason why he’s so drunk is cause he was trying to get the balls to talk to you again. Ever since yall met, he can't shut up about how he wants to get to know you more - you should go and talk to him right now see for yourself!")
    + "\n Leave and look for Kevin[t]"
    + "\n Press her about what happened to[REDACTED][r]";
    trickleDisplayString(output, 10);
    return output;
}

void takeSecondShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new lookForKevinScene('t');
	nextPossibleScenes.at(1)=new pressHer('r');
}

string pressHer::dialogue(){
    string output = string("\n Natalie: What do you know about what happened to [REDACTED]?")
    + "\n Lilith : I did what he would have wanted."
    + "\n ..."
    + "\n Lilith: I told you I don't know already, anyway I'm going back in to distract Chad while you get Kevin's attention, tell me how it goes."
    + "\n Go Look For Kevin [t]";
    trickleDisplayString(output, 10);
    return output;
}

void pressHer::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(1);
	nextPossibleScenes.at(0)=new lookForKevinScene('t');
}

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
    trickleDisplayString(output, 10);
    return output;
}

void lookForKevinScene::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new kevinArgument('t');
	nextPossibleScenes.at(1)=new kevinRomance('r');
}

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
    trickleDisplayString(output, 10);
    return output;
}
void kevinArgument::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
}

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
    trickleDisplayString(output, 10);
    return output;
}

void kevinRomance::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.resize(2);
	nextPossibleScenes.at(0)=new takeThirdShot('t');
	nextPossibleScenes.at(1)=new rejectThirdShot('r'); 
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
    trickleDisplayString(output, 10);
    return output;
}

void takeThirdShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
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
    trickleDisplayString(output, 10);
    return output;
} 

void rejectThirdShot::updatePossibleScenes(vector<Scene*>& nextPossibleScenes){
	nextPossibleScenes.clear();
}

void Scene::trickleDisplayString(const string& inputString, uint8_t delay){
	const size_t BOX_WIDTH = 100;
	const size_t PADDING = 2;
	const size_t MAX_LINE = BOX_WIDTH - PADDING * 4;


	istringstream inputStream(inputString);
	vector<string> lines;
	string rawLine;

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

	const char CORNER = '+';
	const char HORIZONTAL = '=';
	const char VERTICAL = '|';

	cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;

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

	cout << CORNER << string(BOX_WIDTH, HORIZONTAL) << CORNER << endl;
}