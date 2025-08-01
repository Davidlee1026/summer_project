#include "GameManager.h"
#include <iostream>
using namespace std;

GameManager::GameManager(const string& playerName) {
    monsterCount = 1;
    turn = 1;
    player = new Player(playerName, 100);
    monster = new Monster("Monster1", 50, 10, 25, 3);
}

GameManager::~GameManager() {
    delete player;
    delete monster;
}

void GameManager::StartGame() {
    cout << "���� ����!\n";
    while (true) {
        cout << "\n===== [Turn " << turn << "] =====\n";
        PrintStatus();

        PlayerTurn();
        if (IsGameover()) break;

        MonsterTurn();
        if (IsGameover()) break;

        turn++;
    }
}

void GameManager::PlayerTurn() {
    int skill;
    while (true) {
        cout << "�÷��̾��� ���Դϴ�. ��ų�� �����ϼ���:\n";
        cout << "1. �⺻ ����\n";
        cout << "2. ��ų (ġ��Ÿ ����)\n";
        cout << "3. �ñر�\n";
        cout << "4. ��\n";
        cout << ">> ";
        cin >> skill;

        if (skill < 1 || skill > 4) {
            cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (skill) {
        case 1:
            player->basicAttack(*monster);
            break;
        case 2:
            player->skill2(*monster);
            break;
        case 3:
            player->ultimateSkill(*monster);
            break;
        case 4:
            player->heal();
            break;
        }

        player->reduceCooldowns();
        break;
    }
}

void GameManager::MonsterTurn() {
    cout << "������ ���Դϴ�.\n";
    int damage = monster->performAction();
    player->takeDamage(damage);
    monster->decreaseCooldown();
}

void GameManager::PrintStatus() {
    cout << "[���� ����]\n";
    player->printStatus();
    monster->printStatus();
}

bool GameManager::IsGameover() {
    if (!player->isAlive()) {
        cout << "�÷��̾ �й��߽��ϴ�. ���� ����.\n";
        return true;
    }

    if (!monster->isAlive()) {
        cout << "���͸� óġ�߽��ϴ�!\n";
        delete monster;
        monsterCount++;
        monster = new Monster("Monster" + to_string(monsterCount), 50 + monsterCount * 10, 10 + monsterCount * 2, 25 + monsterCount * 2, 3);
        cout << monster->getName() << "��/�� ���� �����߽��ϴ�!\n";
    }

    return false;
}
