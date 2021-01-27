// File Name: assign2_rjr110.cpp
//
// Author: Ricardo Reyna
// Date: 10/03/2017
// Assignment Number: 2
// CS 2308.256 Fall 2017
// Instructor: Yijuan Lu
//
// Initializes a new datatype called Inventory for each product from the input
// file and is saved into an array.
// Then a function sorts SKU from small to big. Another

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

    struct Inventory
    {
        string product_name;
        int sku;
        int quantity;
        float price;

    };


    const int inventory_size = 7; // Size of the Inventory that will go into an
                                  // array

    Inventory file[inventory_size]; // Array of products

    //Function Prototypes
    void bubbleSort_sku(Inventory file[], const int);
    int binarySearch_sku(Inventory file[], const int, int);
    int linearSearch(Inventory file[], const int, string );
    void showArrayBySku(Inventory file[], const int);


int main()
{
    ifstream fin;
    fin.open("inventory.dat");

    // Checks if Input file open
    if(!fin)
    {
        cout << "ERROR - Failed to open inventory file. Terminating Program.\n";
        return -1;
    }


    //Constants for Menu Choices
    const int DISPLAY_BY_SKU = 1,
              LOOKUP_BY_SKU  = 2,
              LOOKUP_BY_NAME = 3,
              QUIT           = 4;

    int choice, // Menu Choice
        position_of_array, // Position of the SKU in the array
        target; // SKU user target

    string name_target; // User product name target


    // Loop gets info from input file and puts it into a structure
    for(int i = 0; i < inventory_size; i++)
    {
        fin >> file[i].product_name >> file[i].sku >> file[i].quantity
            >> file[i].price;
    }

    // Function that sorts SKU from smallest to biggest
    bubbleSort_sku(file, inventory_size);

    do
    {
        cout << "Press the matching number on your keyboard of the desired "
        "option that you want to access followed by an Enter." << endl
             << endl << "1. Display the inventory sorted by sku."
             << endl << "2. Lookup a product by sku.            "
             << endl << "3. Lookup a product by name.           "
             << endl << "4. Quit                                " << endl
             << endl;

        cin >> choice;
        cout << endl;

// Menu Option 1
        if (choice == DISPLAY_BY_SKU)
        {
            cout << "You picked choice: " << choice << endl;

            showArrayBySku(file, inventory_size);
            cout << endl;
        }

// Menu Option 2
        else if (choice == LOOKUP_BY_SKU)
        {
            cout << "You picked choice: " << choice << endl;

            cout << "Please type the SKU of the item you are searching: ";
            cin >> target;

            position_of_array = binarySearch_sku(file, inventory_size, target);

            // If position_of_array is not -1 then it will display the product
            // the user searched by SKU.
            if (position_of_array != -1)
            {
                cout << left << setw(6) << "SKU" << left << setw(20)
                << "Product Name" << setw(10) << "Quantity" << setw(8)
                << "Price" << endl;

                cout << left << setw(6) << file[position_of_array]. sku
                << left << setw(20) <<  file[position_of_array].product_name
                << setw(10) <<  file[position_of_array].quantity << setw(8)
                << file[position_of_array].price << endl << endl;
            }

            // If position_of_array is -1 then it means than the product name
            // was not found and will cout that.
            else
            {
                cout << "Product was not found with SKU: " << target << "."
                     << endl << endl;
            }

        }

// Menu Option 3
        else if ( choice == LOOKUP_BY_NAME)
        {
            cout << "You picked choice: " << choice << endl;

            cout << "Please type the product name you want"
            " to search without spaces : ";
            cin >> name_target;
            cout << endl;

            position_of_array = linearSearch(file, inventory_size, name_target);

            // If position_of_array is not -1 then it will display the product
            // the user searched by product name.
            if (position_of_array != -1)
            {
                cout << left << setw(6) << file[position_of_array]. sku
                << left << setw(20) <<  file[position_of_array].product_name
                << setw(10) <<  file[position_of_array].quantity << setw(8)
                << file[position_of_array].price << endl << endl;
            }

            // If position_of_array is -1 then it means than the product name
            // was not found and will cout that.
            else
            {
                cout << name_target << " was not found." << endl << endl;
            }



        }

 // Menu Option 4
        else if( choice == QUIT)
        {
            cout << "You picked choice: " << choice << endl;

            cout << "Terminating Program";

            fin.close();

            return -1;
        }


// Menu Option 5
        else if (choice != 1,2,3,4)
        {
            cout << "Invalid Menu Choice. Try Again." << endl << endl;

        }

    }while(choice != 4);

    fin.close();

    return 0;
}


//*******************************************************************************
// bubbleSort_sku:Sorts SKU by using bubble sort algorithm
//
// file[] where SKU information is located
// inventory_size is the size of the file[] array
//
//*******************************************************************************
void bubbleSort_sku(Inventory file[], const int inventory_size)
{
    bool finished;
    int hold;

    do
    {
        finished = false;

        for(int i = 0; i < (inventory_size - 1) ; i++)
        {
            if(file[i].sku > file[i+1].sku)
            {
                hold = file[i].sku;
                file[i].sku = file[i+1].sku;
                file[i+1].sku = hold;
                finished = true;
            }
        }

    } while (finished);
}


//*******************************************************************************
// binarySearch_sku: Searches for SKU using binary search algorithm
//
// file[] where SKU information is located
// inventory_size is the size of the file[] array
// target is the SKU that the user wants to find
//
// returns: position of the array where the user SKU is located
//*******************************************************************************
int binarySearch_sku(Inventory file[], const int inventory_size, int target)
{

    int first = 0,
        last  = inventory_size - 1,
        middle,
        position = -1;

    bool found = false;


    while(first <= last && !found)
    {
        middle = (first + last) / 2 ;

        if(file[middle].sku == target)
        {
            found = true;
            position = middle;
        }
        else if(target < file[middle].sku)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

return position;

}


//*******************************************************************************
// linearSearch: Searches for product name
//
// file[] where SKU information is located
// inventory_size is the size of the file[] array
// name_target is the product name that the user wants to find
//
// returns: position of the array where the user product name is located
//*******************************************************************************
int linearSearch(Inventory file[], const int inventory_size, string name_target)
{

    int position = -1,
        index    = 0;
    bool finished = false;

    while( index < inventory_size && !finished)
    {
        if(name_target == file[index].product_name)
        {
        position = index;
        finished = true;
        }

        index++;
    }

return position;
}


//*******************************************************************************
// showArrayBySku: It will show the product inventory by SKU
//
// file[] where SKU information is located
// inventory_size is the size of the file[] array
//
//*******************************************************************************
void showArrayBySku(Inventory file[], const int inventory_size)
{
    for(int i = 0; i < inventory_size; i++)
    {
        cout << left << setw(6) << file[i]. sku << left << setw(20) <<
        file[i].product_name << setw(4) <<  file[i].quantity << setw(8)
        << file[i].price << endl;
    }
}


