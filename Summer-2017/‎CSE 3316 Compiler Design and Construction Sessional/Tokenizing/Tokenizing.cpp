#include <iostream>

using namespace std;

int main() {
    string line;
    string hand;
    int op_count, var_count, const_count;
    bool flag;
    while( getline( cin, line ) ) {
        op_count = 0;
        var_count = 0;
        const_count = 0;
        hand.clear();
        for( char c: line ) {
            if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '^' ) {
                if( hand.empty() == false ) {
                    flag = true;
                    for( char ca: hand ) {
                        if( isdigit( ca ) == false ) {
                            flag = false;
                        }
                    }
                    if( flag ) {
                        const_count++;
                    } else {
                        var_count++;
                    }
                }
                hand.clear();
                op_count++;
            }
            else
            if( c == ' ' ) {
                if( hand.empty() == false ) {
                    flag = true;
                    for( char ca: hand ) {
                        if( isdigit( ca ) == false ) {
                            flag = false;
                        }
                    }
                    if( flag ) {
                        const_count++;
                    } else {
                        var_count++;
                    }
                }
                hand.clear();
            } else {
                hand += c;
            }
        }
        if( hand.empty() == false ) {
            flag = true;
            for( char ca: hand ) {
                if( isdigit( ca ) == false ) {
                    flag = false;
                }
            }
            if( flag ) {
                const_count++;
            } else {
                var_count++;
            }
        }
        cout << "Variable Count: " << var_count << "\n";
        cout << "Operator Count: " << op_count << "\n";
        cout << "Constant Count: " << const_count << "\n";
    }
    return 0;
}
