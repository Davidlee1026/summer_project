#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include <string>
using namespace std;

class Monster : public Character {
public:
    Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    int performAction();     // ���� ���� �� ������ ��ȯ
    void decreaseCooldown(); // ��Ÿ�� ����

    void printStatus() const override;

protected:
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax;
    int ultimateCooldownCurrent;
};

#endif
