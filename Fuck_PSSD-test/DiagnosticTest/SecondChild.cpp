#include <iostream>
#include <string>
using namespace std;

class SecondChild{
    public: 
    string chooseName(string Father, string Mother, string Child1, string Gender){
        string gender1;
        string name; 
        if (Child1[0] == 'A' || Child1[0] == 'E'|| Child1[0] == 'I' || Child1[0] == 'O' || Child1[0] == 'U' || Child1[0] == 'Y'){
            gender1 = "Girl";
        } else {
            gender1 = "Boy";
        }

        int pos= Father.find(" ");
        string firstNameFat = Father.substr(0, pos);
        string lastNameFat = Father.substr(pos + 1);

        int pos1= Mother.find(" ");
        string firstNameMom = Mother.substr(0, pos1);
        string lastNameMom = Mother.substr(pos1 + 1);

        int pos2= Child1.find(" ");
        string firstNameChild = Child1.substr(0, pos2);
        string lastNameChild = Child1.substr(pos2 + 1);   
        
        if (gender1[0] == 'B' && Gender[0] == 'B'){
            // firstname = father, last name = child1
            name = firstNameFat + " " + lastNameChild;
        } else if(gender1[0] == 'G' && Gender[0] == 'G'){
            name = firstNameFat + " " + lastNameChild;
        } else if(gender1[0] == 'G' && Gender[0] == 'B'){
            name = lastNameMom + " " + firstNameMom;
        } else if(gender1[0] == 'B' && Gender[0] == 'G'){
            name = lastNameFat + " " + firstNameFat;
        }
        return name;
    }
};

int main(){
    SecondChild child;
    cout << child.chooseName("Mohammad Reza", "Yasaman Sadat", "Baqer Ali", "Boy") << endl; // Mohammad Ali
    cout << child.chooseName("Mohammad Reza", "Yasaman Sadat", "Baqer Ali", "Girl") << endl; // Sadat Yasaman
    cout << child.chooseName("Mohammad Reza", "Yasaman Sadat", "Umi Kulsum", "Girl") << endl; // Yasaman Kulsum
    cout << child.chooseName("Mohammad Reza", "Yasaman Sadat", "Umi Kulsum", "Boy") << endl; // Reza Mohammad
    cout << child.chooseName("Mohammad Reza", "Yasaman Sadat", "Muhammad Reza", "Boy") << endl;  // Mohammad Reza
    cout << child.chooseName("Dhikrulla Ali", "Umi Kulsum", "Reza Hosseinzade", "Boy") << endl; // Dhikrullah  Hosseinzadeh

}