#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
//for storing variety of items in our online shopping program

// selecting by serial number:
typedef struct
{
    char source_name[50];
    int serial_no;
}serial;

typedef struct
{
    char category[50];
    char name[50];
    int quantity;
    int price;
    char id[10];
}items;

//for storing variety of items in our E-Kart
// Which is a linked list
typedef struct kart
{
    char ecategory[50];
    char ename[50];
    int  equantity;
    int  eprice;
    char eid[10];
    struct kart *next;
}ekart;
ekart *kart1;

void display_inventory(items items1[], int z)
{
     // Displaying our inventory of online shopping program

    cout<<"  /------------------------------------------------------------------------/\n"; // formatting
    cout<<" /-------------------------------------------------------------------------/\n"; // formatting
    cout<<"                          Inventory of our Online Program                   \n"; // formatiing
    cout<<"   Category of items                 Name of Items    Quantity  Price       Id \n"; // formatting
    cout<<"\n";
    int j;
    for(j =0; j<z; j++)
    {
        cout<< setw(20) << "\t" <<items1[j].category;
        cout<< setw(25) << "\t" <<items1[j].name;
        cout<< setw(4) << items1[j].quantity;
        cout<< setw(6) << items1[j].price << "\t";
        cout<< setw(8) << items1[j].id;
        cout<<"\n";
    }
}

char *choose_categories(items items1[], int z)
{
    int choose;
    serial category[20];
    char *choice = (char *) malloc(sizeof(char) * 50);
    int i, j;
    cout<<"\n";
    cout<<"\n";
    cout<<"               |(--------------------------------------------------------)| \n";
    cout<<"                  /********Showing Available Categories***********/  \n";  //formatting
    cout<<"                          S/N                      Category \n"; //formatting
    int count = 1;
    for (i=0; i<z; i++)
    {
        // Check if the picked element is already printed

        for (j=0; j<i; j++)
            if(strcmp(items1[i].category,items1[j].category) == 0)
               break;
        // If not printed earlier, then print it
          if (i == j)
          {
           strcpy(category[count-1].source_name,items1[i].category);
           category[count-1].serial_no = count;
           cout<<"                   -> ";
           cout<< setw(6) <<count;
           cout<< setw(30)<< items1[i].category;
           cout<<"    <- \n";
           count++;
          }
    }
    retry: cout<<"Choose from the above defined items: ";
    cin>>choose;

    // checking the validity of choice
    for(j=0; j<count-1; j++)
    {
    if(choose == category[j].serial_no)
    {
        strcpy(choice, category[j].source_name);
        return choice;
    }
    }
    cin.ignore(50,'\n');
    cout<<"please provide the valid Category: \n";
    goto retry;

}

char *choose_items(items items1[], int z, char defined_category[])
{
    serial category[20];
    char *choice = (char *) malloc(sizeof(char) * 50);
    int i, k, choose;
    int count = 1;
    cout<<"     /******Showing Available Items within Categories***********/  \n";
    cout<<" S/N           Name of Items  Qty   Price           Id \n"; //formatting
    for(i=0; i<z; i++)
    {
        if(strcmp(defined_category, items1[i].category) == 0)
        {
        strcpy(category[count-1].source_name,items1[i].name);
        category[count-1].serial_no = count;
        cout<<setw(3) << count << " \t";
        cout<<setw(21) << items1[i].name;
        cout<<setw(4)<<items1[i].quantity;
        cout<<setw(7)<<items1[i].price << "\t";
        cout<<setw(8)<<items1[i].id;
        cout<<"\n";
        count++;
        }
    }
    tryagain: cout<<"Choose from the above defined items: ";
    cin>>choose;
    for(i=0; i<count - 1; i++)
    {
        if(choose == category[i].serial_no)
        {
            strcpy(choice, category[i].source_name);
            // to decrease the quantity
            for(k=0; k<z; k++)
            {
            if(strcmp(category[i].source_name, items1[k].name) == 0)
            {
                items1[k].quantity = items1[k].quantity - 1;
            }
            }
            return choice;
        }
    }
    cin.ignore(50,'\n');
    cout<<"please provide valid items: \n";
    goto tryagain;
}

void e_kart( )
{
    int total_price= 0;
    int total_quantity = 0;
    ekart *temp;
    temp = kart1;
    cout<<"  /------------------------------------------------------------------------/\n"; // formatting
    cout<<" /-------------------------------------------------------------------------/\n"; // formatting
    cout<<"                          Inventory of your E-Kart                          \n"; // formatiing
    cout<<"   Category of items                 Name of Items    Quantity  Price       Id \n"; // formatting
    cout<<"\n";
    if(temp != NULL)
    {
    while(temp->next != NULL)
    {
            cout<< setw(20) << temp->ecategory << " \t";
            cout<< setw(25) << temp->ename << " \t";
            cout<< setw(5)  << temp->equantity;
            cout<< setw(6) << temp->eprice << "\t";
            cout<< setw(8) << temp->eid;
            cout<<"\n";
            total_price = total_price + temp->eprice;
            total_quantity = total_quantity + temp->equantity;
      temp = temp->next;
    }

            cout<< setw(20) << temp->ecategory << " \t";
            cout<< setw(25) << temp->ename << " \t";
            cout<< setw(5)  << temp->equantity;
            cout<< setw(6) << temp->eprice << "\t";
            cout<< setw(8) << temp->eid;
            cout<<"\n";
            total_price = total_price + temp->eprice;
            total_quantity = total_quantity + temp->equantity;
    cout<<"Your Grand Total is : " << setw(39) <<total_quantity << " " << setw(5) << total_price <<"\n";
    }
    else
    {
        cout<<"Your kart is empty: \n";
    }
}

void insert_via_linkedlist(items items1[], int z, char chooseItems[])
{
    int j;
    ekart *newnode, *temp;
    newnode = (ekart*) malloc(sizeof(ekart));
    for(j =0; j<z; j++)
    {
        if(strcmp(chooseItems, items1[j].name) == 0)
        {
            strcpy(newnode->ecategory,items1[j].category);
            strcpy(newnode->ename,items1[j].name);
            newnode->eprice = items1[j].price;
            newnode->equantity = 1;
            strcpy(newnode->eid,items1[j].id);
            newnode->next = NULL;
            if(kart1 == NULL)
            kart1 = newnode;
            else
            {
            temp = kart1;
                while(temp->next != NULL)
                    temp = temp->next;
            temp->next = newnode;
            }
        }
    }
}

void delete_via_linkedlist(int pos, items items1[], int z)
{
    int k;
    char items_inc[40];
    ekart *temp, *oldtemp;
    if(pos == 1)
    {
        strcpy(items_inc,kart1->ename);
        for(k=0; k<z; k++)
        {
           if(strcmp(items_inc, items1[k].name) == 0)
            {
                items1[k].quantity = items1[k].quantity + 1;
            }
        }
        kart1 = kart1->next;
    }
    else
    {
        int count = 1;
        temp = kart1;
        while( count != pos)
        {
            if( temp->next == NULL)
            {
                cout<<"Your Item No " << pos << " is deleted \n";
                return;
            }
            oldtemp = temp;
            temp = temp->next;
            ++count;
        }
        strcpy(items_inc,temp->ename);
        for(k=0; k<z; k++)
        {
           if(strcmp(items_inc, items1[k].name) == 0)
            {
                items1[k].quantity = items1[k].quantity + 1;
            }
        }
        oldtemp->next = temp->next;
    }
}

char *choose_from_sort_inc(items items_inc[], int z, char choosen_category[], items items1[])
{
    serial category[20];
    int i, k, choose;
    char *choice = (char *) malloc(sizeof(char) * 50);
    int count=1;
    //insertion sort in increasing order
    for(i=1; i<z; i++)
    {
    items temp = items_inc[i];
    int j = i -1;
    while(j >=0 && items_inc[j].price > temp.price)
    {
        items_inc[j+1] = items_inc[j];
        j--;
    }
    items_inc[j+1] = temp;
    }

    cout<<"     /******Showing Available Items within Categories***********/  \n";
    cout<<" S/N           Name of Items  Qty   Price           Id \n"; //formatting
    for(i=0; i<z; i++)
    {
        if(strcmp(choosen_category, items_inc[i].category) == 0)
        {
        strcpy(category[count-1].source_name,items_inc[i].name);
        category[count-1].serial_no = count;
        cout<< setw(4)  << count << "\t";
        cout<< setw(21) << items_inc[i].name;
        cout<< setw(4) << items1[i].quantity;
        cout<< setw(7) << items_inc[i].price;
        cout<<"\t";
        cout<< setw(8) << items_inc[i].id;
        cout<<"\n";
        count++;
        }
    }
    tryagain: cout<<"Choose from the above defined items: ";
    cin>>choose;
    for(i=0; i<count-1; i++)
    {
        if(choose == category[i].serial_no)
        {
           strcpy(choice, category[i].source_name);
            for(k=0; k<z; k++)
            {
                if(strcmp(choice, items1[k].name) == 0)
                {
                    items1[k].price = items1[k].price - 1;
                }
            }
            return choice;
        }
    }
    cin.ignore(50,'\n');
    cout<<"please provide valid items: \n";
    goto tryagain;

}

char *choose_from_sort_dec(items items_dec[], int z, char choosen_category[], items items1[])
{
    serial category[20];
    int i, k, choose;
    char *choice = (char *) malloc(sizeof(char) * 50);
    int count=1;
    for(i=1; i<z; i++)
    {
    items temp = items_dec[i];
    int j = i -1;
    // Insertion sort in decreasing order
    while(j >=0 && items_dec[j].price < temp.price)
    {
        items_dec[j+1] = items_dec[j];
        j--;
    }
    items_dec[j+1] = temp;
    }
    cout<<"     /******Showing Available Items within Categories***********/  \n";
    cout<<" S/N           Name of Items  Qty   Price           Id \n"; //formatting

    for(i=0; i<z; i++)
    {
        if(strcmp(choosen_category, items_dec[i].category) == 0)
        {
        strcpy(category[count-1].source_name,items_dec[i].name);
        category[count-1].serial_no = count;
        cout<< setw(4)  << count << " \t";
        cout<< setw(21) << items_dec[i].name;
        cout<< setw(5) << items_dec[i].quantity;
        cout<< setw(7) << items_dec[i].price;
        cout<<"\t";
        cout<< setw(8) << items_dec[i].id;
        cout<<"\n";
        count++;
        }
    }
    tryagain: cout<<"Choose from the above defined items: ";
    cin>>choose;
    for(i=0; i<count-1; i++)
    {
        if(choose == category[i].serial_no)
        {
            strcpy(choice, category[i].source_name);
            for(k=0; k<z; k++)
            {

                if(strcmp(choice, items1[k].name) == 0)
                {
                    items1[k].price = items1[k].price - 1;
                }
            }
            return choice;
        }
    }
    cin.ignore(50,'\n');
    cout<<"please provide valid items: \n";
    goto tryagain;

}

void search_for_Item(items items1[], int z, char chooseItem[])
{
int i;
int count = 0;
    for(i=0; i<z; i++)
    {
        if(strcmp(chooseItem, items1[i].name) == 0)
        {
            cout<<"Your desired item is available in our program: \n";
            cout<<"It is in Category: " << setw(10) << items1[i].category << "\n";
            cout<<"It's price is: " << setw(4) << items1[i].price << "\n",
            cout<<"It's Id is: " << setw(7) << items1[i].id << "\n";
            count++;
        }
    }
    if(count == 0)
    {
        cout<<"Sorry the item is not available try something different: \n";
    }
}



int main()                                                                                    // shreyash
{
    char user_name[50];
    char mnumber[11];
    int i, choice;
    char search_item[50];
    int quit = 1;
    char ChooseCategory[50];
    char ChooseItems[50];
    items items1[50];
    cout<<"This is an online shopping Program \n";


    // reading form a file /*
    FILE *fp = fopen("my_listofitems.txt", "r");             // Garvit
    int z = 0;
    while (fscanf(fp, "%s %s %d %d %s", items1[z].category, items1[z].name, &items1[z].quantity, &items1[z].price, items1[z].id) != EOF)
    {
    z++;
    }
    fclose(fp);
    // End of reading */
    system("color F9");
    cout<<"|-----------------------------------------------------------------------------------|\n";
    cout<<"|     /***** You have to give name & mobile No in order to shop with us ******/     |\n";
    cout<<"|-----------------------------------------------------------------------------------|\n";
    cout<<"       Your Name:  ";
    system("color A2");
    cin>>user_name;
    cout<<"       Your mobile number: ";
    system("color F3");
    cin>>mnumber;
    system("color F9");
    cout<<"       Press Enter to continue... \n";
    getch();
    system("cls");
    items items_inc[50];
    items items_dec[50];

    for(i=0; i<z; i++)
    {
    items_inc[i] = items1[i];
    items_dec[i] = items1[i];
    }

     cout<<"    /------------------------------------------------------------------------/             \n"; // formatting
     cout<<"    /------------------------------------------------------------------------/            \n"; // formatting
     cout<<" Hello this is a program of Online shopping which provide you Choices of Various \n"; // formatting
     cout<<"                                 BRANDS                                          \n"; // formatting
     cout<<"                                                           Hope You will Enjoy!!\n "; // formatting

     do{
     system("color F0");
     cout<<"   @ $ @ $ @ :-) IF You Can't Stop Thinking about it then Buy it (-: @ $ @ $ @ "; // formatting
     cout<<"        |--------------------------------------------------------------------|\n"; // formatting
     cout<<"        |Press 1 to start shopping:                                          |\n"; // formatting
     cout<<"        |Press 2 to view cart:                                               |\n"; // formatting
     cout<<"        |Press 3 to delete an item from Kart:                                |\n"; // formatting
     cout<<"        |Press 4 to view Items from increasing to decreasing price order:    |\n"; // formatting
     cout<<"        |Press 5 to view Items from decreasing to increasing price order:    |\n"; // formatting
     cout<<"        |Press 6 to search for an particular item in a category:             |\n"; // formatting
     cout<<"        |/****Or Can exit as per your wish****/ :-( press 0 )-:              |\n"; // formatting
     cout<<"        |--------------------------------------------------------------------|\n"; // formaatting
     cout<<"                          Your Choice: ";
     system("color F2");
     cin>>choice;
     system("color F0");
     system("cls");


     switch(choice)
     {
     case 0:
        {
            system("color F4");
            cout<<"Oops You goned for quit are you sure to finalize and go for billing: ";
            cin>>quit;
             break;
        }

     case 1:
        {
            system("color F0");
            strcpy(ChooseCategory,choose_categories(items1, z));
            cout<<"You Choosen " << ChooseCategory << "\n";
            cout<<"Press enter to continue...\n";
            system("color FD");
            getch();
            system("cls");
            system("color F0");
            strcpy(ChooseItems,choose_items(items1, z, ChooseCategory));
            cout<<"You Choosen "<<  ChooseItems << "\n";
            insert_via_linkedlist(items1, z, ChooseItems);
            cout<<"The item is stored in Your E-kart \n";
            cout<<"Press enter to continue...\n";
            system("color FD");
            getch();
            system("cls");
            break;
        }
     case 2:
        {
            system("color FD");
            e_kart();
            cout<<"Press enter to continue...\n";
            getch();
            system("cls");
            break;
        }
     case 3:
        {
            system("color FD");
            int position;
            e_kart();
            retry: cout<<"Please specify which item you Want to delete:";
            cin>>position;
            system("color F1");
            if(position >= 1)
            {
            delete_via_linkedlist(position, items1, z);
            e_kart();
            cout<<"Press enter to continue...\n";
            getch();
            system("cls");
            }
            else
            {
                cin.ignore(50,'\n');
                cin.ignore(50,'\n');
                cout<<"please specify valid delete position \n";
                goto retry;
            }
            break;
        }
     case 4:
        {
            system("color F0");
            strcpy(ChooseCategory,choose_categories(items1, z));
            cout<<"You Choosen " << ChooseCategory  <<" \n";
            cout<<"Press enter to continue...\n";
            system("color F2");
            getch();
            system("cls");
            system("color F0");
            strcpy(ChooseItems,choose_from_sort_inc(items_inc, z, ChooseCategory, items1));
            cout<<"You Choosen " << ChooseItems << "\n";
            insert_via_linkedlist(items_inc, z, ChooseItems);
            cout<<"The Item is Stored in your E-kart \n";
            cout<<"Press enter to continue...\n";
            system("color F2");
            getch();
            system("cls");
            break;
        }
     case 5:
        {
            system("color F0");
            strcpy(ChooseCategory,choose_categories(items1, z));
            cout<<"You Choosen "<< ChooseCategory<<"\n";
            cout<<"Press enter to continue...\n";
            system("color F2");
            getch();
            system("cls");
            system("color F0");
            strcpy(ChooseItems,choose_from_sort_dec(items_inc, z, ChooseCategory, items1));
            cout<<"You Choosen " << ChooseItems << "\n";
            insert_via_linkedlist(items_dec, z, ChooseItems);
            cout<<"The item is stored in Your E-kart \n";
            cout<<"Press enter to continue...\n";
            system("color F2");
            getch();
            system("cls");
            break;
        }
     case 6:
        {
            system("color F1");
            cout<<"\n\n";
            cout<<"      Please provide the Item you want to search for: ";
            cin>>search_item;
            search_for_Item(items1, z, search_item);
            cout<<"Press enter to continue...\n";
            getch();
            system("cls");
            break;
        }
     default :
        {
            system("color F4");
            cout<<"please provide the valid input: \n";
        }
     }
     cin.ignore(50,'\n');

     }while(quit != 0);
     system("color F1");
    cout<<" Thank you for Shopping with us hope you enjoyed :-) \n\n";
    cout<<"           [ . ]                 [ . ]               \n";
    cout<<"                                                     \n\n";
    cout<<"                       {   }                         \n";
    cout<<"                                                     \n";
    cout<<"                    ''''''''''''                     \n\n";

    cout<<"your billing information about shopping is saved in a file \n" ;
     //Billing using writing to file and linked list
                                                                                // Garvit
    char myTxt[1000];
    FILE *out = fopen("testfile2.txt", "a+");
    myTxt[0] = 0;
    // Adding user information to the file
    strcat(myTxt, user_name);
    strcat(myTxt, "\n");
    strcat(myTxt, mnumber);
    strcat(myTxt, "\n");
    strcat(myTxt, "Description of items");
    strcat(myTxt, "\n");

    // Adding items information to the file
    ekart *temp;
    temp = kart1;
    int total=0;
    int quantity=0;
    char total_s[7];
    char quantity_s[3];
    while(temp != NULL)
    {
    char price_s[4];
    strcat(myTxt, "Item Category: ");
    strcat(myTxt, temp->ecategory);
    strcat(myTxt, "\t");
    strcat(myTxt, "Item Name: ");
    strcat(myTxt, temp->ename);
    strcat(myTxt, "\t");
    sprintf(price_s, "%d", temp->eprice);
    strcat(myTxt, "Item price: ");
    strcat(myTxt, price_s);
    strcat(myTxt, "\t");
    strcat(myTxt, "Item Id ");
    strcat(myTxt, temp->eid);
    strcat(myTxt, "\n");
    total = total + temp->eprice;
    temp = temp->next;
    quantity++;
    }
    strcat(myTxt, "Grand Total ");
    sprintf(total_s, "%d", total);
    strcat(myTxt, total_s);
    sprintf(quantity_s, "%d", quantity);
    strcat(myTxt, " Quantity  ");
    strcat(myTxt, quantity_s);
    fprintf(out, "%s\n", myTxt);
    fclose(out);
    return 0;

}

