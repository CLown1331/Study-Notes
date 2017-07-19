#include <cmath>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
ll ans;

bool op_prec( char c, char o ) {
    if( c == 'v' ) {
        if( o == '^' ) return false;
        if( o == 'v' ) return false;
        if( o == '*' ) return false;
        if( o == '/' ) return false;
        if( o == '+' ) return false;
        if( o == '-' ) return false;
        return false;
    }
    if( c == '^' ) {
        if( o == '^' ) return false;
        if( o == 'v' ) return false;
        if( o == '*' ) return false;
        if( o == '/' ) return false;
        if( o == '+' ) return false;
        if( o == '-' ) return false;
        return false;
    }
    if( c == '*' ) {
        if( o == '^' ) return true;
        if( o == 'v' ) return true;
        if( o == '*' ) return true;
        if( o == '/' ) return false;
        if( o == '+' ) return false;
        if( o == '-' ) return false;
        return false;
    }
    if( c == '/' ) {
        if( o == '^' ) return true;
        if( o == 'v' ) return true;
        if( o == '*' ) return true;
        if( o == '/' ) return true;
        if( o == '+' ) return false;
        if( o == '-' ) return false;
        return false;
    }
    if( c == '+' ) {
        if( o == '^' ) return true;
        if( o == 'v' ) return true;
        if( o == '*' ) return true;
        if( o == '/' ) return true;
        if( o == '+' ) return true;
        if( o == '-' ) return false;
        return false;
    }
    if( c == '-' ) {
        if( o == '^' ) return true;
        if( o == 'v' ) return true;
        if( o == '*' ) return true;
        if( o == '/' ) return true;
        if( o == '+' ) return true;
        if( o == '-' ) return true;
        return false;
    }
}

bool parse( string &line, string &parsed ) {
    reverse( line.begin(), line.end() );
    string hand;
    bool flag;
    stack < char > ops;
    parsed.clear();
    line += " ";
    flag = false;
    for( char c: line ) {
        if( isdigit( c ) ) {
            hand += c;
            flag = true;
        } else {
            if( flag ) {
                parsed += " ";
                reverse( hand.begin(), hand.end() );
                parsed += hand;
            }
            hand.clear();
            flag = false;
            if( c == ')' ) {
                ops.push( c );
            }
            else
            if( c == '(' ) {
                while( !ops.empty() && ops.top() != ')' ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.pop();
            }
            else
            if( c == '+' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops .pop();
                }
                ops.push( c );
            }
            else
            if( c == '-' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.push( c );
            }
            else
            if( c == '/' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.push( c );
            }
            else
            if( c == '*' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.push( c );
            }
            else
            if( c == '^' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.push( c );
            }
            else
            if( c == 'v' ) {
                while( !ops.empty() && op_prec( c, ops.top() ) ) {
                    parsed += " ";
                    parsed += ops.top();
                    ops.pop();
                }
                ops.push( c );
            }
        }
    }
    while( !ops.empty() ) {
        parsed += " ";
        parsed += ops.top();
        ops.pop();
    }
    parsed += " ";
    return true;
}

int main() {
    string line, parsed;
    cout << ">>>: ";
    while( getline( cin, line ) ) {
        cout << "]: ";
        parse( line, parsed );
        cout << parsed << "\n";
        cout << ">>>: ";
    }
    return 0;
}
