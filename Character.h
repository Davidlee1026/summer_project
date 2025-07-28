#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int maxHp;

public:
    Character(const std::string& name, int hp);
    virtual ~Character() = default;

    // ���� ���
    virtual void takeDamage(int damage);
    virtual void heal(int amount);

    // ���� ����
    bool isAlive() const;
    std::string getName() const;
    int getHP() const;
    int getMaxHP() const;

    // �� ĳ������ �ൿ - �������̵� ����
    virtual void printStatus() const = 0;
};

#endif
