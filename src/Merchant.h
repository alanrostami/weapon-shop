#pragma once

#include <iostream>
#include <vector>

#include "Weapon.h"

class Character;

class Merchant
{
private:
    std::string m_name;
    std::string m_shop_name;
    std::string m_description;
    std::string m_catch_phrase;
    int m_money = 2000;
    std::vector<Weapon> m_inventory;

public:
    Merchant() = default;
    Merchant(std::string name, std::string shop_name, std::string description, std::string catch_phrase);
    ~Merchant();
    std::string GetName();
    std::string GetShopName();
    std::string GetDescription();
    std::string GetPhrase();
    int GetMoney();

    void SetInventory(Weapon weapon);
    void DisplayInventory();
    std::vector<Weapon> GetInventory();

    void BuyWeapon(Character& character, Weapon& chara_weapon); // from Character
    void SellWeapon(Character& character, Weapon& chara_weapon); // to Character
};