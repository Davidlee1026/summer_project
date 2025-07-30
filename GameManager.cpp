#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
	monsterCount = 1; 
	turn = 1;
	player = new Player(PlayerName, 100);  
	monster = new Monster(monsterCount);
}

GameManager::~GameManager() {
	delete player;
	delete monster;
}

void GameManager::StartGame() {
	cout << "���� ����\n";
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
		cin.ignore();
		player->reduceCooldowns(); 
		break;
	}
}

void GameManager::MonsterTurn() {
	cout << "������ ���Դϴ�.\n";
	monster->UseSkill(1, *player); //���� UseSkill() �޼ҵ� �߰��ϱ�
}

void GameManager::PrintStatus() {
	cout << "[����]\n" << player->getStatus() << monster->getStatus() << endl;
}

bool GameManager::IsGameover() {
	if (!player->Character::isAlive()) {
		cout << "�÷��̾ �й��߽��ϴ�. Game Over.\n";
		return true;
	}
	if (!monster->Character::isAlive()) {
		cout << "���͸� óġ�߽��ϴ�.\n";
		delete monster;
		monster = new Monster(++monsterCount);
		cout << monster->Character::getName() << "��/�� �����߽��ϴ�.\n"; //getName() ������°� Ȯ���ؾ���
	}
	return false;
}
