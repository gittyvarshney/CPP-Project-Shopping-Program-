# Terminal Based Shopping
Simulating Shopping on Terminal by using basic DataStructures and Algorithm <br /> 
The Whole work is Done in C++ <br />

![Terminal Intro](https://github.com/gittyvarshney/CPP-Project-Shopping-Program-/blob/master/cmd_shopping_bg.png?raw=true)

## Based on the prototype of Online Market
-   User have to login by providing his/her mobile number & name.
-   Meanwhile the program create the inventory from `my_listofitems.txt`
-   On login program takes the user into the wide variety of shopping options like Books, laptops, tablets, perfumes, etc.
    ![Shopping Home](https://github.com/gittyvarshney/CPP-Project-Shopping-Program-/blob/master/cmd_shopping_bg_2.png?raw=true)
-   On Choosing a particular option program shows the user the available brands of selected category along with their prices.
-   Any item after selecting gets automatically saved into the carts items.
    ![Ekart](https://github.com/gittyvarshney/CPP-Project-Shopping-Program-/blob/master/cmd_shopping_bg_3.png?raw=true)
-   After finishing the shopping user can view his/her cart & can also add or delete items as per wish & finally pays the total amount.
    ![Delete Item](https://github.com/gittyvarshney/CPP-Project-Shopping-Program-/blob/master/cmd_shopping_bg_4.png?raw=true)
-   The Whole Log of Billing Information is saved to testfile2.txt

### DataStructure Overview
~~~
typedef struct kart
{
    char ecategory[50];
    char ename[50];
    int  equantity;
    int  eprice;
    char eid[10];
    struct kart *next;
}ekart;
ekart *kart1; //Used as a linked list
~~~

### Steps to Run
-   Fork the repo and compile main.cpp
-   If you want to change the Inventory edit `my_listofitems.txt` (note: Keep formating inplace otherwise code will break)


