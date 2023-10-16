#include <iostream>

#include "Weapon.h"
#include "WeaponType.h"

Weapon::Weapon(std::string name, std::string description,
               WeaponType type, int weight, int damage,
               float cost, float durability)
{
    m_name = name;
    m_description = description;
    m_type = type;
    m_weight = weight;
    m_damge = damage;
    m_cost = cost;
    m_durability = durability;
}

Weapon::~Weapon() {}

WeaponType Weapon::GetType()
{
    return m_type;
}