#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"  // Character Ŭ���� ��ӹޱ� ���� ����
#include <string>

class Player : public Character {
private:
    int ultimateCooldown;  // �ñر� ��Ÿ��
    int healCooldown;      // �� ��Ÿ��

public:
    Player(const std::string& name, int hp);

    void basicAttack(Character& target);
    void skill2(Character& target);     // ġ��Ÿ ����
    void ultimateSkill(Character& target); // �ñر� (��Ÿ�� ����)
    void heal();                        // �� (��Ÿ�� ����)

    void reduceCooldowns();  // ��Ÿ�� 1�� ���̱� (�ϸ��� ȣ��)

    bool canUseUltimate() const;
    bool canUseHeal() const;
};

#endif
