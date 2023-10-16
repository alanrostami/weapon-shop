#pragma once

#include <iostream>
#include <vector>

#include "Character.h"
#include "Merchant.h"
#include "Weapon.h"
#include "Race.h"
#include "Class.h"
#include "WeaponType.h"

void StartNewGame()
{
    // 1. Create the first character
    Character RalfTheElf("Ralf", "Elfon", "I drink therefore I am.",
                         100, 5, Race::Elf, Class::Archer);

    // 2. Set character's weapon
    Weapon charaWeapon("Thunder", "The sword is bringing storms to battles.",
                       WeaponType::Sword, 2, 2, 120.0f, 0.7);

    RalfTheElf.SetWeapon(charaWeapon);
    std::string ch_weapon = RalfTheElf.GetWeapon();

    // 3. Introduce
    RalfTheElf.Introduce();
    std::cout << "Weapon name: " << ch_weapon << std::endl;

    // Create the merchant
    Merchant Yaktod("Yaktod", "Yaktod and Associates Weapons",
                    "Welcome to the number one weapon market in the world.",
                    "That's number one!");

    // Create the weapaons
    Weapon firstWeapon("The Dawn", "The lightest and sharpest sword in the entire world.",
                       WeaponType::Sword, 1, 4, 230.0f, 0.9);

    Weapon secondWeapon("Ultimate Sorrow", "The bow whose arrows go farthest.",
                        WeaponType::Bow, 1, 2, 160.0f, 0.8);

    Weapon thirdWeapon("Blind Justice", "The bow whose arrows go farthest.",
                       WeaponType::Bow, 2, 3, 190.0f, 0.3);

    // Add the weapons to merchant inventory
    Yaktod.SetInventory(firstWeapon);
    Yaktod.SetInventory(secondWeapon);
    Yaktod.SetInventory(thirdWeapon);

    int weaponTypeChoice;
    std::cout << "What kind of weapon do you want: " << std::endl;
    std::cout << "1. Bow | 2. Dagger | 3. Staff | 4. Sword" << std::endl;
    std::cin >> weaponTypeChoice;

    int i = 1;
    for (Weapon w : Yaktod.GetInventory())
    {
        if (w.GetType() == RalfTheElf.ChooseWeaponType(weaponTypeChoice))
        {
            std::cout << i++ << std::endl;
            std::cout << w.m_name << std::endl;
            std::cout << "Damage: " << w.m_damge << " | "
                      << "Durability: " << w.m_durability << " | "
                      << "Weight: " << w.m_weight << std::endl;
            std::cout << "Cost: " << w.m_cost << std::endl;
            std::cout << "---------------" << std::endl;
        }
    }

    int weaponChoice;
    std::cout << "Choose a weapon: " << std::endl;
    std::cin >> weaponChoice;

    Weapon selectedWeapon;

    switch (weaponChoice)
    {
    case 1:
        selectedWeapon = secondWeapon;
        break;
    case 2:
        selectedWeapon = thirdWeapon;
        break;
    default:
        break;
    }
    // X3. Buy a new weapon
    // Xa. Choose a weapon
    // Xb. Check character's money: if enough => buy the weapon
    // c. If not enough money => sell a weapon and get money
    // d. Buy the new weapon
    RalfTheElf.BuyWeapon(RalfTheElf, Yaktod, selectedWeapon);
}