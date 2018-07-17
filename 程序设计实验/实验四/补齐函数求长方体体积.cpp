#include<iostream> 
#include<iomanip>  

using namespace std; 

float cube(float, float, float); 

int main() 
{   
    float length, width, heigh; 
    float volume; 
    cin >> length >> width >>heigh; 
    volume = cube(length, width, heigh); 
        cout << setiosflags(ios::fixed) << setprecision(2); 
        cout << "length=" << length << ",width=" << width << ",height=" << heigh << endl;
    cout << "the volume of cube is " << volume; 
    return 0; 
} 

float cube(float x, float y, float z)
{ 
    
	return (x * y * z);
 
}
