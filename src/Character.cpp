#include <iostream>
#include <vector>

#include "Character.h"

Character::Character(const std::string& first_name,
                     const std::string& last_name,
                     const std::string& catch_phrase,
                     int money, int life_points, /*std::vector<Weapon> weapon,*/
                     Race ch_race, Class ch_class)
{
    m_first_name = first_name;
    m_last_name = last_name;
    m_catch_phrase = catch_phrase;
    m_money = money;
    m_life_points = life_points;
    m_race = ch_race;
    m_class = ch_class;
}

//Character::~Character() = default;

std::string Character::GetName()
{
    return m_first_name + " " + m_last_name;
}

std::string Character::GetPhrase()
{
    return m_catch_phrase;
}

int Character::GetMoney()
{
    return m_money;
}

int Character::GetLifePoints()
{
    return m_life_points;
}

void Character::SetWeapon(Weapon weapon) {
    m_weapon.push_back(weapon);
}

std::string Character::GetWeapon()
{
    return m_weapon[0].m_name;
}

std::string Character::GetRace()
{
    std::string chara_race;
    switch (m_race) {
        case Race::Elf:
            return "Elf";
        case Race::Orc:
            return "Orc";
        case Race::Gobelin:
            return "Gobelin";
        case Race::Human:
            return "Human";
        default:
            break;
    }

}

std::string Character::GetClass()
{
    std::string chara_class;

    switch (m_class) {
        case Class::Archer:
            return "Archer";
        case Class::Warrior:
            return "Warrior";
        case Class::Priest:
            return "Priest";
        case Class::Paladin:
            return "Paladin";
        default:
            break;
    }
}

void Character::Introduce()
{
    std::cout << "Hello! My name is " << Character::GetName()
              << " and I am an " << Character::GetRace() << " " << Character::GetClass() << "." << std::endl;
    std::cout << "My catch phrase is " << Character::GetPhrase() << std::endl;
}

WeaponType Character::ChooseWeaponType(int weapon)
{
    switch (weapon) {
        case 1:
            return WeaponType::Bow;
        case 2:
            return WeaponType::Dagger;
        case 3:
            return WeaponType::Staff;
        case 4:
            return WeaponType::Sword;
        default:
            break;
    }
}

void Character::BuyWeapon(Character& character, Merchant& merch_shop, Weapon& merch_weapon)
{
    if (character.m_money >= merch_weapon.m_cost)
    {
        m_weapon.push_back(merch_weapon);
        merch_shop.SellWeapon(character,merch_weapon);
        std::string chara_weapon = Character::GetWeapon();
        std::cout << "Congrats! You bought " << chara_weapon << std::endl;
    } else {
        std::cout << "You don't have enough money." << std::endl;
    }





}

void Character::SellWeapon(Merchant& merch_shop, Weapon& merch_weapon)
{

}

void Character::UseWeapon(Character& enemy)
{

}

void Character::Loot(Character& defeated)
{

}