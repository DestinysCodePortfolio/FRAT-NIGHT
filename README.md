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
• 10 minute single user expiernence
• No save progess since the game is quick to finish and reseting the game is advised to reach the multiple endings of the game
• Player actions will be supported through a limited selection of actions depending on the player's current scenerio
• Interactive storytelling with branching paths
• Each branching path won't lead to an ending but to a early game over screen depening on player's actions
• The player can collect items that will unlock different options that they can choose that can lead to different endings
• Players are encouraged to search rooms while they explore the mystery of the game's lore
• The areas of the game will be descriced through text and characters will be able to interact with the player to further progress in the story
• The Story's scenerios will be displayed word by word instead of all at once
• 3 possible endings based on player decisions
• One secret ending will be achieved by looking through the files of the game and decrypting the messages to unlock the ending in game through in game user input
• Mystery-solving mechanics through dialogue and file.txt manipulation
• Hand-drawn character sprites (with possible future UI integration)
• Terminal-based user interface for simplicity and accessibility

## Descrition Detail
The Game will have a time complexity of O(n) since displaying each word separetly in a string will have a time complexity O(n). Players actions will be O(1) through the use of a switch statement to determine the branching of the story. File.txt manipulation will also be O(n) since each file's words will be changed completely to display new sentences. 

## Navigation Diagram
![Navigation Diagram - Rush Week](https://github.com/user-attachments/assets/07e3f148-fa0a-4020-b021-f1f1d70caffe)

• On and Off states are when the program is running the game or is being closed.
• The Title Screen state displays the title of the game as well as options to start a new game or to conitnue an old save of the game, the user also has the option to close the game.
• The New Game state starts the game and deletes old save data and creates an empty one
• The Load game state uses the save data in a txt file to continue the game
• The Print Game Screen state is in the current game and outputs the current story the user is currently playing
• The Read User Input State prompts the user either an action or urgently requires the player to commit an action to progress in the game. Faluire to commit the action or chooses the wrong one will get to the game over screen then closes the game
• The Ending states are similar to the print game screen state but they display their respective ending

## Class Diagram

[Class Diagram Rush Week.pdf](https://github.com/user-attachments/files/20052960/Class.Diagram.Rush.Week.pdf)
