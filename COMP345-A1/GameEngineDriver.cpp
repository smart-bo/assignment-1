#include <iostream>
#include "GameEngine.h"
#include "GameEngineDriver.h"

using namespace std;

// GameEngine Driver

GameEngineCommand getCommandFromUser()
{
	cout << "Enter a command " << endl;
	string userInput;
	cin >> userInput;

	if (userInput.compare("loadMap") == 0)
		return loadMap;
	else if (userInput.compare("validateMap") == 0)
		return validateMap;
	else if (userInput.compare("addPlayer") == 0)
		return addPlayer;
	else if (userInput.compare("assignCountries") == 0)
		return assignCountries;
	else if (userInput.compare("issueOrder") == 0)
		return issueOrder;
	else if (userInput.compare("endIssueOrders") == 0)
		return endIssueOrders;
	else if (userInput.compare("execOrder") == 0)
		return execOrder;
	else if (userInput.compare("endExecOrders") == 0)
		return endExecOrders;
	else if (userInput.compare("winGame") == 0)
		return winGame;
	else if (userInput.compare("endGame") == 0)
		return endGame;
	else if (userInput.compare("playGame") == 0)
		return playGame;

	// commands that can be run multiple times
	while (userInput.compare("execOrder") == 0) {
		return execOrder;
	}

	while (userInput.compare("issueOrder") == 0) {
		return issueOrder;
	}

	while (userInput.compare("addPlayer") == 0) {
		return addPlayer;
	}

	while (userInput.compare("loadMap") == 0) {
		return loadMap;
	}

	return invalidCommand;
}

void testGameEngine()
{
	cout << "===================" << endl;
	cout << "Welcome to Warzone" << endl;
	cout << "===================\n" << endl;
	cout << "Testing game engine\n" << endl;

	GameEngine* gameEngine = new GameEngine();

	while (true)
	{
		//take in commands

		GameEngineCommand latestUserCommand = getCommandFromUser();

		//send the user's command to the engine
		gameEngine->sendCommand(latestUserCommand);
	}

	// delete gameEngine that was created
	delete gameEngine;
}


