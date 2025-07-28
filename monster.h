#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h" // Character Ŭ������ ��ӹޱ� ���� ����
#include <string>

class Monster : public Character { // Character Ŭ���� ���
public:
    // ������: Character �����ڸ� ȣ���ϰ� ���� ������ �Ӽ��� �ʱ�ȭ
    Monster(const std::string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    // ������ �� �ൿ (��ų ���). Character Ŭ�������� ���� Monster ������ ���
    int performAction(); // ���Ͱ� ���ϴ� ���ط��� ��ȯ

    // ��Ÿ�� ����. Character Ŭ�������� ���� Monster ������ ���
    void decreaseCooldown();

private:
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax; // �ñر� �ִ� ��Ÿ��
    int ultimateCooldownCurrent; // �ñر� ���� ��Ÿ��
};

#endif