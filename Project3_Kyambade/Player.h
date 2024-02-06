#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Player
{
    private:
        double money;
        vector<Item> owned_items;
    public:
        Player();
        void Get5RandomItems(vector<Item> items_in, int player_level);
        
        double GetMoney();
        void AddMoney(double a_money_in);
        void SubtractMoney(double s_money_in);

        vector<Item> GetOwnedItems();
        Item GetOwnedItemsAt(int item_index);

        void AddItem(string item_name_in2, vector<Item> items_in);
        bool SubtractItem(string item_name_in3);
};