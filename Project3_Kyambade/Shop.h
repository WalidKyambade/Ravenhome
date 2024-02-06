#include <iostream>
#include <vector>
#include "Player.h"
#include "Customer.h"
using namespace std;

class Shop
{
    private:
        int decor_level;
        int magic_rocks;
        double selling_multiplier;
        vector<Item> items;
        vector<Customer> customers;
    public:
        Shop();

        int GetDecorLevel();
        void SetDecorLevel(int decor_level_in);
        int CalculateDecorPrice();
        void DecorUp();
        
        int GetMagicRocks();
        void SetMagicRocks(int magic_rocks_in);
        int CalculateMagicRockPrice();
        void AddRock();

        vector<Item> GetItems();
        Item GetItemsAt(int index);
        int GetItemsSize();

        Customer GetCustomerAt(int index);

        double GetSellingMultiplier();
        void SetSellingMultiplier(double selling_multiplier_in);
        void MagicRocksToSellingMultiplier();
        int DecorLevelToAmtCustomers();

        void FillItems(string file_name);

        void FillCustomers(string file_name);

};