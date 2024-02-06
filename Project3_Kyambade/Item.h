#include <iostream>
#include <vector>
using namespace std;

class Item
{
    private:
        string item_name;
        double price;
        int item_level;
        double rarity; // (selling_bonus x selling_multplier x price) = how much the people will buy the item for
    public:
        Item();
        Item(string item_name_in, double price_in, int item_level_in, double rarity_in);

        string GetItemName();

        double GetPrice();

        int GetItemLevel();

        double GetRarity();
        //selling bonus is the amount the total get multiplied by, the higher the rarity, the higher the selling bonus has a chance of being
        double CalculateSellingBonus();
};