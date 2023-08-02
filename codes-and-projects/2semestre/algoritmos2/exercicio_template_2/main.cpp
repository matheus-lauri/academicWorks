#include <iostream>

using namespace std;

//template <typename T, typename T2>
double maxi(int x, double y)
{

return (x > y)? x : y;

}

int main() {

cout << maxi(3, 7) << endl;

cout << maxi(3.0, 7.0) << endl;

cout << maxi(3, 7.0) << endl;

return 0;

}
