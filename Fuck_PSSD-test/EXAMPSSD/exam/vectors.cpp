#include <iostream>
#include <vector>

//With the help of the champ chat gpt, we will attempt to learn vectors and then recreate the test question of the bag of items.

using namespace std;

class Item {
    public:
    string name;
    float price;
    public:
    Item(const string& name, float price): name(name), price(price) {};
    string getName(){return name;};
    float getPrice(){return price;};
    void setprice(float newprice){price = newprice;};

};

vector<Item> BagOfItems;

void addItem(const string& name, float price){
    Item newItem(name,price);
    BagOfItems.push_back(newItem);
}

void removeItem(const string&name){
    for (auto it = BagOfItems.begin(); it != BagOfItems.end();it++){
        if(it->getName() == name){
            BagOfItems.erase(it);
            break;
        }
    }
}


int main(){
    
    addItem("Book", 10.99);
    addItem("Laptop", 899.99);
    for (int i = 0; i < BagOfItems.size(); i++) {
        // Access elements using the loop variable i
        cout << "Name: " << BagOfItems[i].getName() << ", Price: $" << BagOfItems[i].getPrice() << endl;
    }

    // Remove an item from the bagOfItems
    removeItem("Laptop");

       cout << "space" << endl;
   
        for (int i = 0; i < BagOfItems.size(); i++) {
        // Access elements using the loop variable i
        cout << "Name: " << BagOfItems[i].getName() << ", Price: $" << BagOfItems[i].getPrice() << endl;
    }



    return 0;
}

