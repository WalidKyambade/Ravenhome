#include <iostream>
#include "Customer.h"
using namespace std;

Customer::Customer()
{
    customer_name = "";
    buyer_dialogue = "";
    seller_dialogue = "";
    customer_level = 0;
    is_evil = 0;
}

Customer::Customer(string customer_name_in, string buyer_dialogue_in, string seller_dialogue_in, int customer_level_in, int is_evil_in)
{
    customer_name = customer_name_in;
    buyer_dialogue = buyer_dialogue_in;
    seller_dialogue = seller_dialogue_in;
    customer_level = customer_level_in;
    is_evil = is_evil_in;
}

string Customer::GetCustomerName()
{
    return customer_name;
}

string Customer::GetBuyerDialogue()
{
    return buyer_dialogue;
}

string Customer::GetSellerDialogue()
{
    return seller_dialogue;
}

int Customer::GetCustomerLevel()
{
    return customer_level;
}

int Customer::GetEvil()
{
    return is_evil;
}

void Customer::PrintFormattedBuyerDialogue()
{
    //print if the dialogue is short
    if(buyer_dialogue.length() < 60)
    {
        cout << buyer_dialogue << endl;
    }
    else
    {
        int i = 0;
        int k = 0;
        //prints the dialogue so that it dont cut off mid word
        while(buyer_dialogue.length() - ((60 * i)+k) > 60)
        {
            string print_string = buyer_dialogue.substr((60 * i)+k,60);
            string curr_letter = "";
            int j = 0;
            while(curr_letter != " ")
            {
                print_string = print_string + curr_letter;
                curr_letter = buyer_dialogue.substr(((60 * (i+1))+k+j),1);
                j++;

            }
            k = k + j;
            cout << print_string << endl;
            i++;

        }
        cout << buyer_dialogue.substr((60 * i)+k,(buyer_dialogue.length() - ((60 * i)-k))) << endl;
    }
}

void Customer::PrintFormattedSellerDialogue()
{
    //print if the dialogue is short
    if(seller_dialogue.length() < 60)
    {
        cout << seller_dialogue << endl;
    }
    else
    {
        int i = 0;
        int k = 0;
        //prints the dialogue so that it dont cut off mid word
        while(seller_dialogue.length() - ((60 * i)+k) > 60)
        {
            string print_string = seller_dialogue.substr((60 * i)+k,60);
            string curr_letter = "";
            int j = 0;
            while(curr_letter != " ")
            {
                print_string = print_string + curr_letter;
                curr_letter = seller_dialogue.substr(((60 * (i+1))+k+j),1);
                j++;

            }
            k = k + j;
            cout << print_string << endl;
            i++;

        }
        cout << seller_dialogue.substr((60 * i)+k,(seller_dialogue.length() - ((60 * i)-k))) << endl;
    }
}


