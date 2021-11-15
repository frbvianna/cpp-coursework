#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> vector1 {};
    vector <int> vector2 {};
    
    const unsigned short ten {10};
    const unsigned short twenty {20};
    
    vector1.push_back(ten);
    vector1.push_back(twenty);
    
    cout << "The elements in vector1 are:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "The size of vector1 is: " << vector1.size() << endl;
    
    vector2.push_back(10*ten);
    vector2.push_back(10*twenty);
    
    cout << "\n";
    cout << "The elements in vector2 are:" << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "The size of vector2 is: " << vector2.size() << endl;
    
     vector <vector<int>> vector_2d {};
     
     vector_2d.push_back(vector1);
     vector_2d.push_back(vector2);
     
    cout << "\n";
    cout << "The elements in vector_2d are:" << endl;
    cout << vector_2d[0][0] << " " << vector_2d[0][1] << endl;
    cout << vector_2d[1][0] << " " << vector_2d[1][1] << endl;
    cout << "The size of vector_2d is: " << vector_2d.size() << endl;
    
    vector1.at(0) = 100*ten;
    
    cout << "\n";
    cout << "The elements in vector_2d after vector1 change are:" << endl;
    cout << vector_2d[0][0] << " " << vector_2d[0][1] << endl;
    cout << vector_2d[1][0] << " " << vector_2d[1][1] << endl;
    cout << "The size of vector_2d after vector1 change is: " << vector_2d.size() << endl;
    
    cout << "\n";   
    cout << "The elements in changed vector1 are:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "The size of changed vector1 is: " << vector1.size() << endl;
    
    return 0;
}
