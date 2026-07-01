#include <iostream>
using namespace std;

class Grocery
{
private:
    int id[100];
    string name[100];
    float price[100];
    int quantity[100];
    int count = 0;

public:

    void addProduct()
    {
        cout << "\nEnter Product ID : ";
        cin >> id[count];

        cout << "Enter Product Name : ";
        cin >> name[count];

        cout << "Enter Product Price : ";
        cin >> price[count];

        cout << "Enter Quantity : ";
        cin >> quantity[count];

        count++;

        cout << "\nProduct Added Successfully!\n";
    }

    void displayProducts()
    {
        if (count == 0)
        {
            cout << "\nNo Products Available.\n";
            return;
        }

        cout << "\n---------------------------------------------\n";
        cout << "ID\tName\tPrice\tQuantity\n";
        cout << "---------------------------------------------\n";

        for (int i = 0; i < count; i++)
        {
            cout << id[i] << "\t"
                 << name[i] << "\t"
                 << price[i] << "\t"
                 << quantity[i] << endl;
        }
    }

    void searchProduct()
    {
        int searchId;

        cout << "\nEnter Product ID to Search : ";
        cin >> searchId;

        for (int i = 0; i < count; i++)
        {
            if (id[i] == searchId)
            {
                cout << "\nProduct Found\n";
                cout << "ID       : " << id[i] << endl;
                cout << "Name     : " << name[i] << endl;
                cout << "Price    : " << price[i] << endl;
                cout << "Quantity : " << quantity[i] << endl;

                return;
            }
        }

        cout << "\nProduct Not Found.\n";
    }

    void updateProduct()
    {
        int updateId;

        cout << "\nEnter Product ID to Update : ";
        cin >> updateId;

        for (int i = 0; i < count; i++)
        {
            if (id[i] == updateId)
            {
                cout << "Enter New Name : ";
                cin >> name[i];

                cout << "Enter New Price : ";
                cin >> price[i];

                cout << "Enter New Quantity : ";
                cin >> quantity[i];

                cout << "\nProduct Updated Successfully!\n";

                return;
            }
        }

        cout << "\nProduct Not Found.\n";
    }

    void deleteProduct()
    {
        int deleteId;

        cout << "\nEnter Product ID to Delete : ";
        cin >> deleteId;

        for (int i = 0; i < count; i++)
        {
            if (id[i] == deleteId)
            {
                for (int j = i; j < count - 1; j++)
                {
                    id[j] = id[j + 1];
                    name[j] = name[j + 1];
                    price[j] = price[j + 1];
                    quantity[j] = quantity[j + 1];
                }

                count--;

                cout << "\nProduct Deleted Successfully!\n";
                return;
            }
        }

        cout << "\nProduct Not Found.\n";
    }
};

int main()
{
    Grocery g;
    int choice;

    do
    {
        cout << "\n\n===== GROCERY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                g.addProduct();
                break;

            case 2:
                g.displayProducts();
                break;

            case 3:
                g.searchProduct();
                break;

            case 4:
                g.updateProduct();
                break;

            case 5:
                g.deleteProduct();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}