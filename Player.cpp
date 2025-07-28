#include "Player.h"
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

Player::Player(const std::string& name, int hp)
    : Character(name, hp), ultimateCooldown(0), healCooldown(0) {
    std::srand(std::time(nullptr));  // ġ��Ÿ Ȯ���� �õ� �ʱ�ȭ
}

void Player::basicAttack(Character& target) {
    int damage = 10;
    std::cout << getName() << " uses Basic Attack!\n";
    target.takeDamage(damage);
}

void Player::skill2(Character& target) {
    std::cout << getName() << " uses Skill2 (Critical Attack)!\n";
    int critChance = std::rand() % 100;  // 0~99
    int damage = (critChance < 30) ? 30 : 15;  // 30% Ȯ���� ġ��Ÿ
    if (critChance < 30)
        std::cout << "Critical Hit!\n";
    else
        std::cout << "Normal Hit.\n";
    target.takeDamage(damage);
}

void Player::ultimateSkill(Character& target) {
    if (canUseUltimate()) {
        std::cout << getName() << " uses Ultimate Skill!\n";
        target.takeDamage(50);
        ultimateCooldown = 5;  // ��Ÿ�� 5��
    }
    else {
        std::cout << "Ultimate Skill is on cooldown (" << ultimateCooldown << " turns left).\n";
    }
}

void Player::heal() {
    if (canUseHeal()) {
        int healAmount = (getMaxHP() - getHP()) * 0.5;  // ���� ü���� 50% ȸ��
        if (healAmount <= 0) healAmount = 0;
        std::cout << getName() << " heals for " << healAmount << " HP!\n";
        Character::heal(healAmount);
        healCooldown = 4;  // ��Ÿ�� 4��
    }
    else {
        std::cout << "Heal is on cooldown (" << healCooldown << " turns left).\n";
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
