#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

//this is just for the simple example

//print list of strings
void print(std::list<std::string> const &list)
{
    for (auto const& i: list) {
        std::cout << i << "\n";
    }
}

//print list of integers
void print1(std::list<int> const &list)
{
    for (auto const& i: list) {
        std::cout << i << ",";
    }
}

//function to find combinations. e.g. if you have N things and want to organise them in groups of K
//e.g 5 things organised in 3 slots
//comb(5,3) = 0 1 2, 0 1 3 etc
void comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) std::cout << " " << i;
        }
        std::cout << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}
//void formula(int t_2,int t_3,int t_4, int num_of_pizzas){
//    int a,b,c;
//    std::list<int> values;
//    num_of_pizzas = 2*a + 3*b + 4*c;
//    for (int i = 0; t_2; i++){
//        for (int j = 0;t_3;j++){
//            c=(2*i+3*j-num_of_pizzas)/4;
//            values.push_back(i);values.push_back(j);values.push_back(c);
//        }
//    }
//}

int main()
{
    //setting variables
    int num_of_pizzas=5;
    int t_2 = 1; int t_3 = 2; int t_4 = 1;

    //setting pizzas + ingredients
    //later I will work on inputting the file and getting the format correct for vars
    //for now, just set them
    std::list<string> p1 = {"onion","pepper","olive"};
    std::list<string> p2 = {"mushroom","tomato","basil"};
    std::list<string> p3 = {"chicken","mushroom","pepper"};
    std::list<string> p4 = {"tomato","mushroom","basil"};
    std::list<string> p5 = {"chicken","basil"};

    //add each pizza's ingredients to one list, p1
    p1.merge(p2); p1.merge(p3);p1.merge(p4);p1.merge(p5);

    //get rid of repeats so there are no repeated ingredients
    p1.sort();
    p1.unique();
    std::list<string> all_pizza_ingredients = p1;
    print(all_pizza_ingredients);

    //size of new list is num of diff ingredients
    int num_of_ingredients = all_pizza_ingredients.size();
    std::cout<<"size:"<<num_of_ingredients<<"\n";

    //IGNORE------
    //formula(1,2,1,5);
    std::vector<int> values;
    //---------------------


    //check combos of pizzas and people

    //have equation numofpizzas <= 2T2 + 3T3 +4T4.
    //let T2=a, T3=b,T4=c.
    //finds all a,b,c where 2a+3b+4c <= 5 (num of pizzas) where a,b,c are INTEGERS>=0;
    //probs a quicker way to do this, but it works
    for (int i = 0; i<= t_2; i++){
        for (int j = 0;j<=t_3;j++){
            for (int z = 0;z<=t_4;z++){
                if (2*i+3*j+4*z <= num_of_pizzas){ //adds values of a,b,c that are only less than or equal to amount of pizzas
                    values.push_back(i);values.push_back(j);values.push_back(z);
                }
            }
        }
    }
    //print1(values);

    //IGNORE-----------
    //for every three values, assign a pizza to each person.
    int factor = (values.size())/3;
    //int matrix[factor][3];
    //for(int j=0;j<factor;j++){
    //    for (int i =0;i<3;i++){
    //        matrix[factor][i]=values[i];
    //    }
    //}
    //NEEd TO STORE EACH COMBO IN ITS OWN / MATRIX
    //-------------------


    //need to take values and take every three elements and store them in a proper place
    std::vector<int> each_combo = {values[3],values[4],values[5]};//just one example
    int total_people = 2*each_combo[0]+3*each_combo[1]+4*each_combo[2];
    //https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c

    //this bit prints out the combinations from function above
    comb(5,2);comb(5,3);comb(5,4);
    //let's say for 2(1)+3(1)+4(0) for a,b,c.
    //need to find combs of 2,3 with no repeats, need to change comb function a lil and how its stored
    // e.g 01 234 or 02 134 NOT 12 234 as 2 is repeated
    ifstream infile; //Container for the file
    infile.open("/Users/apple/Downloads/a_example.txt"); //Name of the file you want to open
    string stringFromFile; //string variables to store extracted strings

    //INPUTTING FILE, this works
    //adds each file line by line to a vector
    std::vector<std::string> lines;
    if(infile.fail())
    {
    cout<<"Input file failed to open";
    }
    else
    {
        while (getline(infile,stringFromFile) )
        {
          lines.push_back(stringFromFile);
        }
        infile.close();
    }
    //need to split files
    return 0;
}
