#include "Player.h"
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
using namespace std;

Player::Player(const std::string& name, int hp)
    : Character(name, hp), ultimateCooldown(0), healCooldown(0) {
    srand(std::time(nullptr));  // ġ��Ÿ Ȯ���� �õ� �ʱ�ȭ
}

void Player::basicAttack(Character& target) {
    int damage = 10;
    cout << getName() << "��/�� �⺻������ ����߽��ϴ�!\n";
    target.takeDamage(damage);
}

void Player::skill2(Character& target) {
    cout << getName() << "��/�� ��ȭ ��ų�� ����߽��ϴ�!!(ġ��Ÿ)\n";
    int critChance = std::rand() % 100;  // 0~99
    int damage = (critChance < 30) ? 30 : 15;  // 30% Ȯ���� ġ��Ÿ
    if (critChance < 30)
        cout << "ġ��Ÿ ����!!\n";
    else
        cout << "���� ����!.\n";
    target.takeDamage(0);
}

void Player::ultimateSkill(Character& target) {
    if (canUseUltimate()) {
        cout << getName() << "��/�� �ñر⸦ ����߽��ϴ�!!\n";
        target.takeDamage(50);
        ultimateCooldown = 5;  // ��Ÿ�� 5��
    }
    else {
        cout << "�ñر�� ���� ��Ÿ���Դϴ�! (" << ultimateCooldown << " ��ŭ ���� ���ҽ��ϴ�.).\n";
    }
}

void Player::heal() {
    if (canUseHeal()) {
        int healAmount = (getMaxHP() - getHP()) * 0.5;  // ���� ü���� 50% ȸ��
        if (healAmount <= 0) healAmount = 0;
        cout << getName() << "��/�� ü���� ȸ���Ͽ����ϴ�!" << healAmount << " ��ŭ ü�� ȸ��!!\n";
        Character::heal(healAmount);
        healCooldown = 3;  // ��Ÿ�� 4��
    }
    else {
        cout << "�� ��ų�� ���� ��Ÿ���Դϴ�!!(" << healCooldown << " ��ŭ ���ҽ��ϴ�!).\n";
    }
}

void Player::reduceCooldowns() {
    if (ultimateCooldown > 0) ultimateCooldown--;
    if (healCooldown > 0) healCooldown--;
}

bool Player::canUseUltimate() const {
    return ultimateCooldown == 0;
}

bool Player::canUseHeal() const {
    return healCooldown == 0;
}
