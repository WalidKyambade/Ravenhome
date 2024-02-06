#include <iostream>
#include <vector>
using namespace std;

class Customer
{
    private:
        string customer_name;
        string buyer_dialogue;
        string seller_dialogue;
        int customer_level;
        //0 is not evil 1 is evil
        int is_evil;
    public:
        Customer();
        Customer(string customer_name_in, string buyer_dialogue_in, string seller_dialogue, int customer_level_in, int is_evil_in);

        string GetCustomerName();

        string GetBuyerDialogue();

        string GetSellerDialogue();

        int GetCustomerLevel();

        int GetEvil();

        void PrintFormattedBuyerDialogue();

        void PrintFormattedSellerDialogue();
};