#include <iostream>
#include <cstdlib>
#include "Item.h"
using namespace std;

Item::Item()
{
    item_name = "";
    price = 0;
    item_level = 0;
    rarity = 0;
}

Item::Item(string item_name_in, double price_in, int item_level_in, double rarity_in)
{
    item_name = item_name_in;
    price = price_in;
    item_level = item_level_in;
    rarity = rarity_in;
}

string Item::GetItemName()
{
    return item_name;
}

double Item::GetPrice()
{
    return price;
}

int Item::GetItemLevel()
{
    return item_level;
}

double Item::GetRarity()
{
    return rarity;
}



double Item::CalculateSellingBonus()
{
    srand(time(0));
    //rarity is the precent chance that you will get the selling bonus
    if(rand() % (10) < rarity)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}