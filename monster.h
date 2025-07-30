#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h" // Character Ŭ������ ��ӹޱ� ���� ����
#include <string>

using namespace std;

class Monster : public Character {
public:
    // ������
    Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    // performAction �Լ��� ���� �Լ��� �����Ͽ� �Ļ� Ŭ�������� �������̵� �����ϰ� ��
    // virtual Ű���� �߰�
    virtual int performAction(); // ���Ͱ� ���ϴ� ���ط��� ��ȯ

    void decreaseCooldown();

protected: // �ڽ� Ŭ�������� ������ �� �ֵ��� protected�� ����
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax;
    int ultimateCooldownCurrent;
};

#endif