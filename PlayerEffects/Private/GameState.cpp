

#include "../Public/GameState.h"
#include "../Public/Input.h"
#include "../Public/UserInterface.h"

void GameState::run() {
    while (true/*input->IsRunning()*/) {
        readInput();
        executePlayerActions();
        executeEnemyActions();
        //userInterface->SendData();
    }
}

void GameState::executePlayerActions() {
}

void GameState::readInput() {
}

void GameState::executeEnemyActions() {
}
