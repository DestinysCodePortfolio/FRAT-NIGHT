# CS 100 Programming Project: Rush Week

## Group Members:
• Ava Williams - https://github.com/avamwilliams

• Pedro Chaidez - https://github.com/PedroChaidez

• Destiny Gonzalez - https://github.com/DestinysCodePortfolio

• Ian Catren - https://github.com/iqnc06

## Project Description:
Rush Week is an interactive story-driven mystery game built in C++. The narrative follows Natalie, a college student searching for her missing friend Evelyn, who vanished after rushing for a fraternity. As Natalie explores the campus and uncovers secrets, players will be presented with choices that impact the storyline and determine which ending they receive.

## Why this project is important to us
We wanted to create a game that blends the excitement of college life with the suspense of a mystery thriller. Rush Week allows us to practice our C++ programming skills while exploring storytelling, game design, and character development in an interactive format. This project also gives us the chance to integrate art and creativity through custom-drawn sprites and (potentially) a graphical UI in the future.

## Languages, Tools, and Technologies
• C++ – Main programming language
• Custom Hand-Drawn Sprites – For character and scene visuals (optional for terminal version)
• Terminal/Console – Primary UI for this project
• (Optional in future): UI framework for adding a graphical interface

## Input/Output
Input: Player decisions made through text-based prompts
Output: Branching story paths and multiple unique endings depending on player choices

## Features:
• 10 minute single user experience

• No save progess since the game is quick to finish and reseting the game is advised to reach the multiple endings of the game

• Player actions will be supported through a limited selection of actions depending on the player's current scenario

• Interactive storytelling with branching paths

• The player can collect items that will unlock different options that they can choose that can lead to different endings

• Players are encouraged to search rooms while they explore the mystery of the game's lore

• The areas of the game will be descriced through text and characters will be able to interact with the player to further progress in the story

• The Story's scenerios will be displayed word by word instead of all at once

• 3 possible endings based on player decisions

• A mysterious link will be provided to the user for one of the endings, copying and pasting this link into your browser will show a wesbite that pertains to the plot.

• Terminal-based user interface for simplicity and accessibility

## Descrition Detail
The Game will have a time complexity of O(n) since displaying each word separetly in a string will have a time complexity O(n). Players actions will be O(1) through the use of a switch statement to determine the branching of the story. File.txt manipulation will also be O(n) since each file's words will be changed completely to display new sentences. 

## Navigation Diagram 
[Rush Week Navigation Diagram.pdf](https://github.com/user-attachments/files/20130168/Rush.Week.Navigation.Diagram.pdf)

• On and Off states are when the program is running the game or is being closed.

• The Title Screen state displays the title of the game as well as options to start a new game or to conitnue an old save of the game, the user also has the option to close the game.

• The New Game state starts the game and deletes old save data and creates an empty one

• The Load game state uses the save data in a txt file to continue the game

• The Print Game Screen state is in the current game and outputs the current story the user is currently playing

• The Read User Input State prompts the user either an action or urgently requires the player to commit an action to progress in the game. Faluire to commit the action or chooses the wrong one will get to the game over screen then closes the game

• The Ending states are similar to the print game screen state, but they display their respective ending. They will all exit the game and delete the save file to start a new game.

## Class Diagram (Original)
![OG Rush Week UML.pdf](https://github.com/user-attachments/assets/eb263937-e597-4754-b73a-55eee32d53cd)

## Class Diagram (Updated)
![Class Diagram Rush Week drawio](https://github.com/user-attachments/assets/434b5bad-c6b9-482d-8c7b-ee373642a6ce)
![gameplay](https://github.com/user-attachments/assets/c4e32ad9-ad8a-4731-ba5c-85d0f8730725)

• Completed quickTimeEvent to SOLID standards  
  • QuickTimeEvent in accordance with the single responsibility principle  
    • Doesn’t have its own output, was written to only fulfill the objective of timing an input event  
  • Liskov substitution satisfied thru policeRunnningScene and roofieActionScene  
  • Only has necessary methods to fulfill ISP  

• Added instances of the scene class   
• Removed item and player classes due to unneccessary nature, both could be incorporated as choices in the dialogueTree  
• Updated relation arrows to accurately reflect the nature of class interaction  



Screenshot of Input/Output
![OG Rush Week UML.pdf](terminal.png)

Example gameplay showing the terminal 
interface with story text and player choice
![gameplay](https://github.com/user-attachments/assets/76553f9d-1eef-4073-820f-55dbd2e4c22e)

Installation and Usage Instructions
Prerequisites

C++ compiler (g++ recommended)
Terminal/Command prompt access
Git (for cloning the repository)


## No dependecies required


## Installation/Usage Instructions
• 1.) Enter "cmake ." into the terminal

• 2.) Enter "make" into the terminal

• 3.) Enter "./bin/Rush_Week" into the terminal

• 4.) To run tests enter "./bin/runAllTests

• How To Play: Enter the prompted characters into the terminal depending on the choice you want to make.

## TESTING
Story Flow Testing

Verified all story branches lead to valid outcomes
Confirmed text displays correctly word-by-word
Tested timing mechanisms for quick-time events

Dialogue Tree testing

Confirmed the name of the scenes inside the dialogue tree

UI screen testing

Confirmed that userinput was correctly taken from uiScreen



Validation Results:

All story paths function correctly
Input validation prevents crashes from invalid entries
All three endings are accessible through different choice combinations
Performance meets expected time complexity requirements


Why this project is important to us
We wanted to create a game that blends the excitement of college life with the suspense of a mystery thriller. Rush Week allows us to practice our C++ programming skills while exploring storytelling, game design, and character development in an interactive format. This project also gives us the chance to integrate art and creativity through custom-drawn sprites and (potentially) a graphical UI in the future.
Languages, Tools, and Technologies
