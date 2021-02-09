#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class file{
public:
    int num_of_pizzas;
    int t_2; int t_3; int t_4;
    std::list<string> all_pizza_ingredients; int num_of_ingredients = all_pizza_ingredients.size();
    std::string bitmask;
    std::vector<std::string> lines;int amount_of_lines = lines.size();
    std::vector<int> values;
    std::list<std::string> all_ingredients;std::vector<std::string> new_ingred; std::vector<int> combos;


    void removeDupWord(std::string str)
    {
        string word = "";
        for (auto x : str)
        {
            if (x == ' ')
            {
                all_ingredients.push_back(word);
                word = "";


            }
            else {
                word = word + x;

            }

        }
    }
    void print(std::list<std::string> const &list){
        for (auto const& i: list) {
            std::cout << i << "\n";
        }
    }

    void input_file(std::string path){
        ifstream infile;
        infile.open(path);
        string stringFromFile;
        if(infile.fail()){
        cout<<"Input file failed to open";
        }
        else{
            while (getline(infile,stringFromFile) ){
              lines.push_back(stringFromFile);
            }
            infile.close();
        }
    }

    //need to slightly change this to get rid of the numbers
    void get_ingredients(){
        int y = lines.size();
        for(int i =1;i<y;i++){
            lines[1]=lines[1]+" " + lines[i];
        }
        std::string list_all=lines[1];
        removeDupWord(list_all);
        all_ingredients.sort();all_ingredients.unique();
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

    //this would get combos e.g. for 1T2,1T3 so 01 234, 02 134 no repeats,input would be t2,t3,t4,numofpizzas

    void way_of_combinations(){
        for (int i = 0; i<=t_2; i++){
            for (int j = 0;j<=t_3;j++){
                for (int z = 0;z<=t_4;z++){
                    if (2*i+3*j+4*z <= num_of_pizzas){ //adds values of a,b,c that are only less than or equal to amount of pizzas
                        values.push_back(i);values.push_back(j);values.push_back(z);
                    }
                }
            }
        }
        int s = values.size();
        for(int i=0;i<s;i++){
            int d = (i+1)%3;
            if(d==0){
            std::cout<<values[i]<<"\n";
            }
            else{ std::cout<<values[i];}
        }
    }
    void distribute_pizzas_to_groups(){} //for every way_of_combo, find comb for each group.
    void calculate_num_of_ingredients_for_combinations(){} //each possible valid combo from above function, calc num of ingredients for each and square it
    void decide_best_combination(){} //from above function, get largest one and get combo and this is the answer!!
    void create_answer_file(){} //i think we need to make a file w answers, need to check in brief

    };

int main()
{
    file fileobj;

    fileobj.num_of_pizzas=5;
    fileobj.t_2 = 1; fileobj.t_3 = 2; fileobj.t_4 = 1;

    //https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c

    //this bit prints out the combinations from function above
    fileobj.comb(5,2);std::cout<<"oK:";
    int  yx = fileobj.combos.size();
    for(int i=0;i<yx;i++){
        std::cout<< fileobj.combos[i];}
    //fileobj.comb(5,3);
    //fileobj.comb(5,4);

    //let's say for 2(1)+3(1)+4(0) for a,b,c.
    //need to find combs of 2,3 with no repeats, need to change comb function a lil and how its stored
    // e.g 01 234 or 02 134 NOT 12 234 as 2 is repeated

    fileobj.input_file("/Users/apple/Downloads/a_example.txt");
    std::cout<<"lines 0: "<<fileobj.lines[0]<<"\n";
    std::cout<<"lines 1: "<<fileobj.lines[1]<<"\n";
    std::cout<<"lines 2: "<<fileobj.lines[2]<<"\n";
    std::cout<<"lines 3: "<<fileobj.lines[3]<<"\n";
    std::cout<<"lines 4: "<<fileobj.lines[4]<<"\n";
    std::cout<<"lines 5: "<<fileobj.lines[5]<<"\n";

    std::cout<<"bitmask: "<<fileobj.bitmask[0]<<"\n"; //NOT WORKING YET

    fileobj.get_ingredients();
    std::cout<<"Removing repeating ingredients: \n";
    fileobj.print(fileobj.all_ingredients);

    fileobj.way_of_combinations();

    return 0;
}
