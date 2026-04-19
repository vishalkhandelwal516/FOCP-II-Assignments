#include <iostream>
using namespace std;
int parityXOR(long long n) {
    int r = n % 4;
    if (r == 0) return 0;
    if (r == 1) return 1;
    if (r == 2) return 1;
    return 0; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long L, R;
    cin >> L >> R;
    
    int parity = parityXOR(R) ^ parityXOR(L - 1);
    
    cout << (parity ? "odd" : "even") << endl;
    
    return 0;
}
