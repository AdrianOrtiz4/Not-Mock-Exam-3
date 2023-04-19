#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
enum Material{
    BRICK,
    CONCRETE,
    WOOD,
    STONE,
    GLASS

};


class Registered{
    public:
    virtual string getLocation() = 0;
};


class Building : public Registered{

protected:
    string city;
    int buildingNumber;
    int age; // age of the building in years
    int area; // area in sq. ft.
    Material material;

public:
    Building(){}
    Building(sring city, int buildingNumber, int age, int area, Material material){
        this->city = city;
        this->buildingNumber = buildingNumber;
        this->age = age;
        this->area = area;
        this->material = material;
    }
    string getCity() {return city;}
    int getBuildingNumber() {return buildingNumber;}
    int getAge() {return age;}
    int getArea() {return area;}
    Material getMaterial() {return material;}

    void setCity(string city) {this->city = city;}
    void setBuildingNumber(int buildingNumber) {this->buildingNumber = buildingNumber;}
    void setAge(int age) {this->age = age;}
    void setArea(int area) {this->area = area;}
    void setMaterial(Material material) {this->material = material;}

    /**
     * ! Exercise #4 (Part A):
     * 
     * ADD ABSTRACT METHOD getCapacity() that returns an integer value
     * that represents the max capacity of persons allowed in a property.
     * 
     * Each subclass of Building will implement this method a particular version of this method.
    */
    //  TODO EXERCISE #4 (Part A) -- Add an abstract method (getCapacity) to the Building class,
    //ADD YOUR CODE HERE
    virtual void getCapacity() = 0;
    


    /**
     * ! Exercise #5 IMPLEMENT RECURSIVE MIN METHOD
     * 
     * This method finds the newest Building in an array of Buildings.
     * If the array is empty the method returns - 1.
     * 
     * The method MUST BE RECURSIVE.
    */
    static int findNewestBuilding(vector<Building *> buildings); 


    /**
     * ! Exercise #6 -- IMPLEMENT A RECURSIVE SEARCH METHOD
     * 
     * Returns -true if and only if some building of the specified Material (enum)
     * exists in a given city within the parameter array of Buildings.
     * 
     * 
     * The method MUST BE RECURSIVE.
    */
   static bool existMaterialFromCity(vector<Building *> &buildings, string city, Material material);



    /**
     * ! Exercise #7 -- IMPLEMENT A RECURSIVE SEARCH METHOD
     * 
     * Returns -true if and only if some building of the specified age
     * exists in a given city within the parameter array of Buildings.
     * 
     * 
     * The method MUST BE RECURSIVE.
    */
   static bool existAgeFromCity(vector<Building *> &buildings, string city, int age){

        return true || false;
   }



    /**
     * ! Exercise #8 -- IMPLEMENT A RECURSIVE SEARCH METHOD
     * 
     * Count the buildings that are younger than parameter building.
     * IF the vector is empty the method returns -1.

     * 
     * The method MUST BE RECURSIVE.
    */
   unsigned int countYoungerBuildingsHelper(vector<Building *>  buildings, unsigned int i, unsigned int count);
   unsigned int countYoungerBuildings(vector<Building *>  buildings);



    /**
     * ! Exercise #9 -- IMPLEMENT A RECURSIVE SEARCH METHOD
     * 
     * Count the buildings that are of the same materials the target building.
     * IF the vector is empty the method returns -1.

     * 
     * The method MUST BE RECURSIVE.
    */
   unsigned int countMaterialBuildings(vector<Building *> & buildings){
        
        return 999;
   }


}


    // End of abstract Building class

    int findNextBuilding(vector<Building *> & buildings) {     //Queremos que la funcion tenga volares para que los aguanten dentro de paramentros adicionales, ya que la funcion original solamente tiene un parametro 
        return findNewestBuildingHelper(buildings, 1, 0);      //
    }

    int findNewestBuildingHelper(vector<Building *> & building, unsigned int i, unsigned int minIndex){
        if(building.size() < i){
            return building[minIndex];
        }
        if(building[i] < building[minIndex]){
            return findNewestBuildingHelper(building, i+1, i);
        }

    }


// ?

    bool existMaterialFromCityHelper(vector<Building *> &buildings, string city, Material material, unsigned int i){

        if (i >= buildings.size()) return false;

        if((buildings[i]->getMaterial() == material) && (buildings[i]->getCity().compare(city) == 0)){

            return true;
        }
        return existMaterialFromCityHelper(buildings, city, material, i+1);
    }

    bool Building::existMaterialFromCity(vector<Building *> &buildings, string city, Material material, unsigned int i){    

        if(buildings.size() < 1) return false;
        return existMaterialFromCityHelper(buildings, city, material, 0);
    }

// ?

    unsigned int Building::countYoungerBuildingsHelper(vector<Building*> buildings, unsigned int i , unsigned int count){

        if (i >= buildings.size()) return count;
        if(buildings[i]->getAge() < this->getAge()){

            return countYoungerBuildingsHelper(buildings, i+1, count + 1);
        }
        else{
            return countYoungerBuildingsHelper(buildings, i+1, count);
        }
    }

    unsigned int Building::countYoungerBuildings(vector<Building *> buildings){

        if(buildings.size() < 1) return 0; 
        return countYoungerBuildingsHelper(buildings, 0, 0);
    }

// ?






    class House : public Building{
        private:
            string neighborhood;
            vector<string> residents;

        public:
            using Building::Building;

            House(string city, string neighborhood, int buildingNumber, int age, int area, Material material) : Building(city, neighborhood, buildingNumber, age, area, material){
                this->neighborhood = neighborhood;
            }     

            string getNeighborhood() {return neighborhood;}
            vector<string> getResidents() {return residents;} 

            void setNeighborhood(string n) {neighborhood = n;}
            void setResidents(vector<string> r) {residents = r;}


            /**
             * ! EXERCISE #3 (Part B) -- IMPLEMENT Registered interface method
             * 
             * A house location has the following format:
             *  "neighborhood, buildingNumber, age"
            */
           string getLocation(){
                return ""; // Dummy return
           }

           /**
            * ! EXERCISE #4 (Part B) -- Implement ABSTRACT METHOD getCapacity() in House class
            * 
            * A House's max capacity is twice the amount of residents assigned to a house.
           */
          int getCapacity(){
            return 2 * residents.size();
          }

          //TODO EX #4 (Part B) -- Implement abstract method getCapacity() in House class


    }; // End of House class




    /**
     * Re-factor this class to remove any property or method that was
     * moved to the Abstract Building class.
     * 
     * You should modify the constructor to call the super constructor appropriately.
     * 
     * This class represents a Store Building.
    */

   class Store : public Building {
    private:
        string storeName;
    
    public:
        Store(string storeName, string city, int buildingNumber, int age, int area, Material material) : Building(city, buildingNumber, age, area, material){
            this->storeName = storeName;
        }
        string getStoreName() {return storeName;}

        void setStoreName(string storeName) {this->storeName = storeName;}

    /**
     * ! EXERCISE #3 (Part C) -- IMPLEMENT Registered interface method
     * 
     * A house location has the following format: "city, buildingNumber, area".
    */
   string getLocation(){
        return ""; //Dummy return
   }

   /**
    * ! EXERCISE #4 (Part C) -- Implement ABSTRACT METHOD getCapacity() in Store class
    * 
    * A Store's max capacity is based on it's area (sq. ft.):
    * 2 persons, per each 10ft. by 10ft. block of space in the store.
   */
  int getCapacity(){
    return 2 * area / 100.0;
  }

};  // End of Store class








int main() {

    vector<Building *> allBuildings;
    vector<Building *> oneBuildings;
    vector<Building *> noBuildings;
    vector<Building *> stores;
    vector<Building *> houses;
    vector<Building *> empty;

    stores.push_back(new Store("Pharmacy", "Mayaguez", 1, 25, 200000, Material::CONCRETE));
    stores.push_back(new Store("Bookstore", "Aguada", 1, 20, 150000, Material::CONCRETE));
    stores.push_back(new Store("Boutique", "Cabo Rojo", 1, 10, 15000, Material::CONCRETE));
    stores.push_back(new Store("Tailor", "Aguada", 2, 15, 13000, Material::STONE));
    stores.push_back(new Store("Barber Shop", "Ponce", 1, 7, 12000, Material::CONCRETE));

    houses.push_back(new House("Terrace", "Mayaguez", 2, 55, 3000, Material::CONCRETE));
    houses.push_back(new House("Miradero", "Mayaguez", 3, 45, 4000, Material::CONCRETE));
    houses.push_nack(new House("Junquito", "Ponce", 2, 20, 2500, Material::BRICK));
    houses.push_back(new House("Villa Lobo", "Cabo Rojo", 2, 22, 1000, Material::WOOD));
    houses.push_back(new House("Tras Talleres", "Cabo Rojo", 3, 10, 2100,  Material::BRICK));


    for (Store *s : stores)
        allBuildings.push_back(s);
    
    for (Store *h : houses)
        allBuildings.push_back(h);
    oneBuilding.push_back(stores[0]);

    cout << boolalpha;
 
    cout << "================== EXERCISE #5 =================" << endl;
    cout << "Youngest in stores: " << Building::findNewestBuilding(allBuildings) << endl; // 4
    cout << "Youngest in houses: " << Building::findNewestBuilding(oneBuildings) << endl; // 0
    cout << "Youngest in houses: " << Building::findNewestBuilding(noBuildings) << endl; // -1
  
    cout << "================== EXERCISE #6 =================" << endl;
    cout << "Aguada contains a GLASS building? " << Building::existMaterialFromCity(allBuildings) << endl; // 
    cout << "Aguada contains a BRICK building? " << Building::existMaterialFromCity(allBuildings) << endl; // 

    cout << "================== EXERCISE #7 =================" << endl;
    cout << "Aguada contains a 15 y/o building? " << Building::existAgeFromCity(allBuildings, "Aguada", 15) << endl; // 
    cout << "Aguada contains a 8 y/o building? " << Building::existAgeFromCity(allBuildings, "Caguas", 8) << endl; // 

    cout << "================== EXERCISE #8 =================" << endl;
    House *myHouseYoung = new House("Hormigueros", "Lavadero", 6405, 9, 10000, Material::CONCRETE);
    cout << "How many buildings are younger than myHose? " << myHouseYoung->countYoungerBuildings(allBuildings) << endl; // 1
    House *myHouseOld = new House("Hormigueros", "Lavadero", 6405, 999, 10000, Material::CONCRETE);
    cout << "How many buildings are younger than myHose? " << myHouseOld->countYoungerBuildings(allBuildings) << endl; // 10
    cout << "How many buildings are younger than myHose? " << myHouseYoung->countYoungerBuildings(empty) << endl; // 0

    cout << "================== EXERCISE #9 =================" << endl;
    House *myHouseConcrete = new House("Hormigueros", "Lavadero", 6405, 9, 10000, Material::CONCRETE);
    cout << "How many buildings are younger than myHose? " << myHouseConcrete->countYoungerBuildings(allBuildings) << endl; // 6
    House *myHouseGlass = new House("Hormigueros", "Lavadero", 6405, 9, 10000, Material::GLASS);
    cout << "How many buildings are younger than myHose? " << myHouseGlass->countYoungerBuildings(allBuildings) << endl; // 0
    cout << "How many buildings are younger than myHose? " << myHouseConcrete->countYoungerBuildings(allBuildings) << endl; // 
    return 0;





}