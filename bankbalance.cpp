#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    long long accounts[100001];
    bool account_exists[100001];
    
public:
    Bank() {
        for (int i = 0; i < 100001; i++) {
            accounts[i] = 0;
            account_exists[i] = false;
        }
    }
    
    bool create(int user_id, long long amount) {
        if (account_exists[user_id]) {
            accounts[user_id] += amount;
            return false;
        }
        
        accounts[user_id] = amount;
        account_exists[user_id] = true;
        return true;
    }
    
    bool debit(int user_id, long long amount) {
        if (!account_exists[user_id]) {
            return false;
        }
        
        if (accounts[user_id] < amount) {
            return false;
        }
        
        accounts[user_id] -= amount;
        return true;
    }
    
    bool credit(int user_id, long long amount) {
        if (!account_exists[user_id]) {
            return false;
        }
        
        accounts[user_id] += amount;
        return true;
    }
    
    long long balance(int user_id) {
        if (!account_exists[user_id]) {
            return -1;
        }
        
        return accounts[user_id];
    }
};

int main() {
    int q;
    cin >> q;
    
    Bank bank;
    
    while (q--) {
        string operation;
        cin >> operation;
        
        if (operation == "CREATE") {
            int x;
            long long y;
            cin >> x >> y;
            if (bank.create(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (operation == "DEBIT") {
            int x;
            long long y;
            cin >> x >> y;
            if (bank.debit(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (operation == "CREDIT") {
            int x;
            long long y;
            cin >> x >> y;
            if (bank.credit(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (operation == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.balance(x) << endl;
        }
    }
    
    return 0;
}
