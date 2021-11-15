#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

double area_circle(double  radius) 
{
    return M_PI*pow(radius,2);
}

double volume_cylinder(double radius, double height)
{
    return area_circle(radius)*height;
}

int main()
{
    double radius {}, height {};
    cout << "Enter the radius and height of the cylinder (space separated): ";
    cin >> radius >> height;
    cout << endl;
    cout << "Area of the circle: " << area_circle(radius) << endl;
    cout << "Volume of the cylinder: " << volume_cylinder(radius, height) << endl;
    cout << endl;
}
