#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int sum = 0;  

    while (i <= 1000) {
        if (i % 7 == 0) {
            sum += i;
        }
        i += 4;
    }

    cout << "Sum: " << sum << endl;  
    return 0;
}
