#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Shop.h"
#include "Map.h"
using namespace std;

int main()
{
//create objects
Shop player_shop;
Player player;
Map player_map;


//set up random numbers
srand(time(0));

//fill up player and Item vectors
player_shop.FillItems("items.txt");
player_shop.FillCustomers("customers.txt");

//any needed variables
bool exit_game = false;
char continue_;
string rocks_left[3] = {"Rock of Fire", "Rock of Gold", "Rock of Night"};
string upgrades_left[2] = {"Bathroom", "Second Floor"};
vector<Item> sold_items;
ofstream shopkeepers_handbook ("SHOPKEEPERS_HANDBOOK.txt");
double selling_bonus;
const double REDUCED_PRICE = 0.65;

//title sequence
cout << endl;
cout << "                                 Welcome to:                                  " << endl;
cout << "██████   █████  ██    ██ ███████ ███    ██ ██   ██  ██████  ███    ███ ███████" << endl;
cout << "██   ██ ██   ██ ██    ██ ██      ████   ██ ██   ██ ██    ██ ████  ████ ██     " << endl;
cout << "██████  ███████ ██    ██ █████   ██ ██  ██ ███████ ██    ██ ██ ████ ██ █████  " << endl;
cout << "██   ██ ██   ██  ██  ██  ██      ██  ██ ██ ██   ██ ██    ██ ██  ██  ██ ██     " << endl;
cout << "██   ██ ██   ██   ████   ███████ ██   ████ ██   ██  ██████  ██      ██ ███████" << endl;
cout << "            [Please drag the terminal to the top of the screen]               " << endl;
cout << endl;

cout << "                          [Press z to contunue]" << endl;
cin >> continue_; 

//pirints the intro story
ifstream intro_input;
string curr_line;
intro_input.open("intro.txt");

for(int i = 0; getline(intro_input, curr_line); i++)
{
    cout << curr_line << endl;
    if(curr_line == "")
    {
        cout << "[Press any button to continue]" << endl;
        cin >> continue_;
    }
}
//warn the player about conniving customers
cout << "*There are some people who wish to make off with the loot of Ravenhome at a decreased price.*" << endl;
cout << "              *If a customer is found conniving, DO NOT sell to them!*                      " << endl;
cout << endl;
cout << "[z] - Continue" << endl;
cin >> continue_;


//give the player random items
player.Get5RandomItems(player_shop.GetItems(), player_shop.GetDecorLevel());


//loop for customer entering store
while(exit_game == false)
{
    //ask player for next customer to come in or to show menu to by stuff, 
    char customer_go;
    cout << endl;
    cout << "≿————————————————- ❈  —————————————————≾" << endl;
    cout << "Would you like to welcome in a traveler?" << endl;
    cout << "   ~~~ [z] - Yes ~~~~ [c] - Menu ~~~   " << endl;
    cin >> customer_go;


    //if the user would like to see the menu
    if(customer_go == 'c')
    {
        int menu_choice;
        bool exit_menu = false;

        //print the menu
        cout << endl;
        cout << "≿————————————————- ❈  —————————————————≾" << endl;
        cout << "[       ☾         Menu         ☾       ]" << endl;
        cout << "|                                      |" << endl;
        cout << "|       [1] - See shop inventory       |" << endl;
        cout << "|                                      |" << endl;
        cout << "|        [2] - Buy Magic Rocks         |" << endl;
        cout << "|    [3] - (What are magic rocks?)     |" << endl;
        cout << "|                                      |" << endl;
        cout << "|       [4] - Upgrade Ravenhome        |" << endl;
        cout << "|     [5] - (What do upgrades do?)     |" << endl;
        cout << "|                                      |" << endl;
        cout << "|      [6] - Shopkeepers Handbook      |" << endl;
        cout << "|                                      |" << endl;
        cout << "|  [7] - Perminantly Close Ravenhome   |" << endl;
        cout << "|                                      |" << endl;
        cout << "|           [0] - exit menu            |" << endl;
        cout << "|                                      |" << endl;
        cout << "≿————————————————- ❈  ————————————————≾" << endl;

        //get the player choice
        cin >> menu_choice;
        
        //for the shop inventory (MAKE ITEMS STACK (DO IT!!!))
        if(menu_choice == 1)
        {
            //code is to deduce how many unique itmes you have, and store them in a vector
            vector<Item> unique_items;
            for(int i = 0; i < player.GetOwnedItems().size(); i++)
            {
                bool add_unique = true;
                for(int j = i; j < player.GetOwnedItems().size() - 1; j++)
                {
                    if(player.GetOwnedItemsAt(i).GetItemName() == player.GetOwnedItemsAt(j + 1).GetItemName())
                    {
                        add_unique = false;
                    }
                }

                if(add_unique == true)
                {
                    unique_items.push_back(player.GetOwnedItemsAt(i));
                }
            }
            
            //prints out all the itmes in the owned_itmes vector
            cout << endl;
            cout << "≿————————————————- ❈  ————————————————≾" << endl;
            cout << "[       ☾        Items         ☾       ]" << endl;
            cout << "|" << endl;
            for(int i = 0; i < unique_items.size(); i++)
            {
                int num_copies = 0;
                for(int j = 0; j < player.GetOwnedItems().size(); j++)
                {
                    if(unique_items.at(i).GetItemName() == player.GetOwnedItemsAt(j).GetItemName())
                    {
                        num_copies++;
                    }
                }
                cout << "| " << unique_items.at(i).GetItemName() << " x " << "[" << num_copies << "]" << endl;
                cout << "|" << endl;
            }
            cout << "≿————————————————- ❈  ————————————————≾" << endl;
            cout << endl;
            cout << "[z] - Continue" << endl;
            cin >> continue_;
        }

        //if the player would like to buy a magic rock
        if(menu_choice == 2)
        {
            //if player has all the rocks
            if(player_shop.GetMagicRocks() == 3)
            {
                player_map.PrintMap();
                cout << "You have all the rocks." << endl;
                cout << endl;
                cout << "[z] - Continue" << endl;
                cin >> continue_;
            }
            else
            {
                //allows the player to choose thier rock
                int what_rock;
                cout << "≿————————————————- ❈  ————————————————≾" << endl;
                cout << "[      ☾       Magic Rocks      ☾      ]" << endl;
                cout << "| " << "[1] " << rocks_left[0] << endl;
                cout << "| " << "[2] " << rocks_left[1] << endl;
                cout << "| " << "[3] " << rocks_left[2] << endl;
                cout << "≿————————————————- ❈  ————————————————≾" << endl;
                cin >> what_rock;

                //asks player if they would like to buy a rock
                char rock_choice;
                cout << "Would you like to buy [" << rocks_left[what_rock-1] << "] for " << fixed << setprecision(0) << player_shop.CalculateMagicRockPrice() << " Gold?" << endl;
                cout << "   ~~~ [z] - Yes ~~~~ [x] - Exit ~~~   " << endl;
                cin >> rock_choice;

                //if the player wants the rock
                if(rock_choice == 'z')
                {
                    if(player.GetMoney() > player_shop.CalculateMagicRockPrice())
                    {
                        //subtract money
                        player.SubtractMoney(player_shop.CalculateMagicRockPrice());
                        //adds one rock
                        player_shop.AddRock();

                        //lets the player place the rock in the shop
                        char player_move = 'p';
                        player_map.PlacePlayer();
                        while(player_move != 'z')
                        {
                            player_map.PrintMap();
                            cout << "[z] - Place Rock ~~~ [wasd] - Move" << endl;
                            cin >> player_move;
                            if(player_move == 'z')
                            {
                                player_map.PlaceItem();
                            }
                            else
                            {
                                player_map.MovePlayer(player_move);
                            }
                        }
                        //displayes buy message
                        cout << "You have bought " << rocks_left[what_rock-1] << "!" << endl;
                        rocks_left[what_rock-1] = "-sold out-";
                        cout << "Customers will now feel compelled to spend more money at your store!" << endl;
                        cout << endl;
                        cout << "[z] - Continue" << endl;
                        cin >> continue_;
                    }
                    else if(player.GetMoney() < player_shop.CalculateMagicRockPrice())
                    {
                        cout << "You do not have enough Gold for the rock." << endl;
                        cout << endl;
                        cout << "[z] - Continue" << endl;
                        cin >> continue_;
                    }
                }
            }
        }


        //if the player would like to know what a magic rock is
        if(menu_choice == 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "According to Ravenhome legend, three magical rocks" << endl;
            cout << "lie within the bounds of the shop. Hidden deeply, It" << endl;
            cout << "is said that the three rocks of Ravenhome will only reveal" << endl;
            cout << "themseves when the one who controls the shop rekindles the" << endl;
            cout << "aincient way of selling magic. Legend has it that these rocks" << endl;
            cout << "will magically make customers pay more gold for the items" << endl;
            cout << "you sell." << endl;
            cout << endl;
            cout << "[z] - Continue" << endl;
            cin >> continue_;
        }
        
        //if the player would like to buy a shop upgrade
        if(menu_choice == 4)
        {
            //if player has all the decoration
            if(player_shop.GetDecorLevel() == 3)
            {
                cout << "You are at the max decoration for Ravenhome!" << endl;
                cout << endl;
                cout << "[z] - Continue" << endl;
                cin >> continue_;
            }
            else
            {
                //allows the player to choose thier upgrade
                int what_upgrade;
                cout << "≿————————————————- ❈  ————————————————≾" << endl;
                cout << "[       ☾       Upgrades      ☾        ]" << endl;
                cout << "| " << "[1] " << upgrades_left[0] << endl;
                cout << "| " << "[2] " << upgrades_left[1] << endl;
                cout << "≿————————————————- ❈  ————————————————≾" << endl;
                cin >> what_upgrade;

                char decor_choice;
                cout << "Would you like purchase [" << upgrades_left[what_upgrade-1] << "] for " << fixed << setprecision(0) << player_shop.CalculateDecorPrice() << " Gold?" << endl;
                cout << "   ~~~ [z] - Yes ~~~~ [x] - Exit ~~~   " << endl;
                cin >> decor_choice;

                //if the player would like to buy the upgrade
                if(decor_choice == 'z')
                {
                    if(player.GetMoney() > player_shop.CalculateDecorPrice())
                    {
                        player.SubtractMoney(player_shop.CalculateDecorPrice());
                        player_shop.DecorUp();
                        upgrades_left[what_upgrade-1] = "-purchased-";
                        cout << endl;
                        cout << "You have upgraded the shop!" << endl;
                        cout << "New people will now come for further off lands to buy and sell" << endl;
                        cout << "items at Ravenhome!" << endl;
                        cout << endl;
                        cout << "You also have recived a strange box at your front door containing " << endl;
                        cout << "items you have never seen before." << endl;
                        player.Get5RandomItems(player_shop.GetItems(), player_shop.GetDecorLevel());
                        cout << endl;
                        cout << "[z] - Continue" << endl;
                        cin >> continue_;
                        
                    }
                    else if(player.GetMoney() < player_shop.CalculateDecorPrice())
                    {
                        cout << "You do not have enough Gold for an upgrade." << endl;
                        cout << endl;
                        cout << "[z] - Continue" << endl;
                        cin >> continue_;
                    }
                }

            }
        }
    
        //if the player would like to know what a shop upgrade does
        if(menu_choice == 5)
        {   
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Upgrading the shop will make the inside look much nicer" << endl;
            cout << "and the items will look better on display. Because of this," << endl;
            cout << "new customers from further off lands may hear about Ravenhome" << endl;
            cout << "and want to check it out for themselves. Who knows, maybe" << endl;
            cout << "they'll bring you stranger and more valueble items to sell." << endl;
            cout << endl;
            cout << "If you upgrade the shop, you will also get a shipment of new and" << endl;
            cout << "exciting items for you to sell." << endl;
            cout << endl;
            cout << "[z] - Continue" << endl;
            cin >> continue_;
        }

        //if the player would like information on the shopkeepers handbook
        if(menu_choice == 6)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "The shopkeepers handbook is one of many secrets held within the" << endl;
            cout << "walls of Ravenhome. It is your most valueble item, and one you" << endl;
            cout << "refuse to sell, no matter the price. The book has the unique " << endl;
            cout << "power of diplaying an items price and how magical the item is" << endl;
            cout << "after you have sold it. You have noticed that, through expirience," << endl;
            cout << "people will sometimes pay double for an item, and the higher the magic" << endl;
            cout << "level of the item, the higher the chance that a customer will pay " << endl;
            cout << "double for it." << endl;
            cout << endl;
            cout << "The back of the book has held a message you have never quite been able " << endl;
            cout << "to crack, although it has always eluded and fascinated you. The back" << endl;
            cout << "reads: \"CHECK THE GAME FILES!\" Curious indeed." << endl; 
            cout << endl;
            cout << "[z] - Continue" << endl;
            cin >> continue_;
        }

        //if the player would like to forefit the game
        if(menu_choice == 7)
        {
            int exit_game_choice;
            cout << "Are you sure you are ready to close Ravenhome FOREVER!" << endl;
            cout << "   ~~~ [z] - Yes ~~~~ [x] - Exit ~~~   " << endl;
            cin >> exit_game_choice;
            if(exit_game_choice == 'z')
            {
                return 0;
            }
        }
        
        //exit menu
        if(menu_choice == 0)
        {
        } 
    }


    //if the user would like to welcome ine a traveler
    if(customer_go == 'z')
    {
        //flip a coin to decide whether
        int seller_buyer = rand() % 10;
        
        //if the customer is a seller
        if(seller_buyer < 4) //40% chance they are a seller
        {
            /*  this line of code picks a random person from the vector of
                customers up to the level decoration of the shop */
            Customer curr_seller = player_shop.GetCustomerAt(rand() % player_shop.DecorLevelToAmtCustomers());

            //play the customers selling dialogue
            cout << endl;
            curr_seller.PrintFormattedSellerDialogue();
            cout << "            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            //pick a random item from the item class and loops until it finds an item that is the same level as the buyer
            Item curr_seller_item;
            do
            {
                curr_seller_item = player_shop.GetItemsAt(rand() % player_shop.GetItemsSize());
            } while(curr_seller_item.GetItemLevel() != curr_seller.GetCustomerLevel());

            //display choice for player
            cout << "Would you like to buy [" << curr_seller_item.GetItemName() << "] from [" << curr_seller.GetCustomerName() << "] for " << curr_seller_item.GetPrice()*REDUCED_PRICE << " Gold." << endl;
            cout << "Your Gold: [" << fixed << setprecision(0) << player.GetMoney() << "]" << endl;
            cout << "   ~~~ [z] - Yes ~~~~ [x] - No ~~~   " << endl;
            
            //get input of choice
            char player_choice;
            cin >> player_choice;

            //if the player says yes
            if(player_choice == 'z')
            {
                //if the player has to little money
                if(curr_seller_item.GetPrice()*REDUCED_PRICE > player.GetMoney())
                {
                    cout << "You do not have the Gold!" << endl;
                    cout << "[z] - Continue" << endl;
                    cin >> continue_;
                }
                else
                {
                    //add the item to the items that the player has
                    player.AddItem(curr_seller_item.GetItemName(), player_shop.GetItems());

                    //subtract money
                    player.SubtractMoney(curr_seller_item.GetPrice()*REDUCED_PRICE);

                    //affermative message
                    cout << "You bought [" << curr_seller_item.GetItemName() << "] for " << fixed << setprecision(0) << curr_seller_item.GetPrice()*REDUCED_PRICE << " Gold." << endl;
                    cout << "Your Gold: [" << fixed << setprecision(0) << player.GetMoney() << "]" << endl;
                    cout << endl;
                    cout << "[z] - Continue" << endl;
                    cin >> continue_;
                }                    
            }
            
            //if the player says no
            if(player_choice == 'x')
            {
                cout << "You have declined [" << curr_seller_item.GetItemName() << "]." << endl;
            }
        }
    
        //if the person is a buyer
        if(seller_buyer >= 4) // 60% chance they are a seller
        {
            //makes sure your selling multiplier is correct
            player_shop.MagicRocksToSellingMultiplier();

            //get a random customer as the buyer
            Customer curr_buyer = player_shop.GetCustomerAt(rand() % player_shop.DecorLevelToAmtCustomers());

            //play buying dialogue
            cout << endl;
            curr_buyer.PrintFormattedBuyerDialogue();
            cout << "            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            //item is chosen at random, loop is broken when item and customer are the same level
            Item curr_buyer_item;
            do
            {
                curr_buyer_item = player_shop.GetItemsAt(rand() % player_shop.GetItemsSize());
            } while(curr_buyer_item.GetItemLevel() != curr_buyer.GetCustomerLevel());

            //check if customer is evil
            int evil = curr_buyer.GetEvil();

            //if they are not evil
            double price;
            if(evil == 0)
            {
                //calculate the price they will buy it for
                selling_bonus = curr_buyer_item.CalculateSellingBonus();
                price = (curr_buyer_item.GetPrice() * player_shop.GetSellingMultiplier() * selling_bonus);
            }
            else if(evil == 1)
            {
                price = (curr_buyer_item.GetPrice() * ((rand() % 100)/100.0));
            }
                
            //as the user if they would like sell an item
            cout << "Would you like to sell [" << curr_buyer_item.GetItemName() << "] to [" << curr_buyer.GetCustomerName() << "] for " << curr_buyer_item.GetPrice() * player_shop.GetSellingMultiplier() << " Gold?" << endl;
            cout << "Your Gold: [" << fixed << setprecision(0) << player.GetMoney() << "]" << endl;
            cout << "   ~~~ [z] - Yes ~~~~ [x] - No ~~~   " << endl;

            //get input of choice
            char player_choice;
            cin >> player_choice;

            //if the player says yes
            if(player_choice == 'z')
            {
                //check if the player has the item, if they do subtract it from their owned_itmes
                bool if_owned = player.SubtractItem(curr_buyer_item.GetItemName());

                

                //if the player owns the item, the money is added to their inventory
                if(if_owned == true)
                {
                    if(curr_buyer_item.GetItemName() == "Jeweled Raven")
                    {
                        cout << "You Win!" << endl;
                        return 0;
                    }
                    //subtract the money
                    player.AddMoney(price);
                    cout << "You sold [" << curr_buyer_item.GetItemName() << "] to [" << curr_buyer.GetCustomerName() << "] for [" << fixed << setprecision(0) << curr_buyer_item.GetPrice() * player_shop.GetSellingMultiplier() << "] Gold." << endl;

                    //update the Shopkeepers Handbook
                    bool have_sold = false;
                    for(int i = 0; i < sold_items.size(); i++)
                    {
                        if(sold_items.at(i).GetItemName() == curr_buyer_item.GetItemName())
                        {
                            have_sold = true;
                        }
                    }
                    if(have_sold == false)
                    {
                        sold_items.push_back(curr_buyer_item);
                        shopkeepers_handbook << curr_buyer_item.GetItemName() << " [Price: " << curr_buyer_item.GetPrice() << " Gold] " << "[How Magic: " << curr_buyer_item.GetRarity() << "]" << endl;
                    }

                    //cout good deal or bad deal
                    if(selling_bonus > 1 && evil == 0)
                    {
                        cout << "[Good deal! +" << fixed << setprecision(0) << price - (curr_buyer_item.GetPrice() * player_shop.GetSellingMultiplier()) << " Gold]" << endl;
                    }
                    if(evil == 1)
                    {
                        cout << "[Conniving Customer! -" << fixed << setprecision(0) << curr_buyer_item.GetPrice() - price << " Gold]" << endl;
                    }
                    cout << "Your Gold: [" << fixed << setprecision(0) << player.GetMoney() << "]" << endl;
                    cout << endl;
                    cout << "[z] - Continue" << endl;
                    cin >> continue_;
                    
                }
                else if(if_owned == false)
                {
                    //if the player does not ahve the item
                    cout << "You do not have [" << curr_buyer_item.GetItemName() << "]." << endl;
                    cout << endl;
                    cout << "[z] - Continue" << endl;
                    cin >> continue_;
                }
            }

            if(player_choice == 'x')
            {
                cout << "You say no to [" << curr_buyer.GetCustomerName() << "]." << endl;
            }
        }
    }
}

//4. balance all values for the game

}