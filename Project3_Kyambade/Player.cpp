#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player()
{
    money = 45;
    owned_items.clear();
}

void Player::Get5RandomItems(vector<Item> items_in, int player_level)
{
    //functions fills up the players inventory with 5 random itmes based on the level the player is 
    srand(time(0));
    
    for(int i = 0; i < 5; i++)
    {
        owned_items.push_back(items_in.at((rand() % 10) + ((player_level-1) * 10))); 
    }
}


double Player::GetMoney()
{
    return money;
}

void Player::AddMoney(double a_money_in)
{
    money = money + a_money_in;
}

void Player::SubtractMoney(double s_money_in)
{
    money = money - s_money_in;
}

vector<Item> Player::GetOwnedItems()
{
    return owned_items;
}


Item Player::GetOwnedItemsAt(int item_index)
{
    return owned_items.at(item_index);
}

void Player::AddItem(string item_name_in2, vector<Item> items_in)
{
    //adds an item to the players inventory
    for(int i = 0; i < items_in.size(); i++)
    {
        if(items_in.at(i).GetItemName() == item_name_in2)
        {
            owned_items.push_back(items_in.at(i));
            i = items_in.size();
        }
    }
}

bool Player::SubtractItem(string item_name_in3)
{
    //subtracts an item from the player
    for(int i = 0; i < owned_items.size(); i++)
    {
        if(owned_items.at(i).GetItemName() == item_name_in3)
        {
            owned_items.erase(owned_items.begin() + i);
            return true;
        }
    }
    return false;
}