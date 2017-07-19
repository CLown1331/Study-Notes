#include <cmath>
#include <stack>
#include <iostream>
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

ll lSqrt( ll x ) {
    ll guess = x / 2LL;
    ll pre = -1LL;
    while( guess * guess != x && guess != 0 && pre != guess ) {
        pre = guess;
        guess =  ( guess + ( x / guess ) ) / 2LL;
    }
    return guess;
}

bool eval( const string &parsed ) {
    stack < ll > st;
    ll hand = 0;
    ll hand2 = 0;
    bool flag = false;
    for( char c: parsed ) {
        if( isdigit( c ) ) {
            hand *= 10LL;
            hand += ( c - '0' );
            flag = true;
        } else {
            if( flag ) {
                st.push( hand );
            }
            flag = false;
            hand = 0LL;
            if( c == '+' ) {
                if( st.size() < 2 ) return false;
                hand = st.top();
                st.pop();
                hand2 = st.top();
                st.pop();
                st.push( hand2 + hand );
            }
            if( c == '-' ) {
                if( st.size() < 2 ) return false;
                hand = st.top();
                st.pop();
                hand2 = st.top();
                st.pop();
                st.push( hand2 - hand );
            }
            if( c == '/' ) {
                if( st.size() < 2 ) return false;
                hand = st.top();
                st.pop();
                hand2 = st.top();
                st.pop();
                st.push( hand2 / hand );
            }
            if( c == '*' ) {
                if( st.size() < 2 ) return false;
                hand = st.top();
                st.pop();
                hand2 = st.top();
                st.pop();
                st.push( hand2 * hand );
            }
            if( c == '^' ) {
                if( st.size() < 2 ) return false;
                hand = st.top();
                st.pop();
                hand2 = st.top();
                st.pop();
                st.push( powl( hand2, hand ) );
            }
            if( c == 'v' ) {
                if( st.size() < 1 ) return false;
                hand = st.top();
                st.pop();
                st.push( lSqrt( hand ) );
            }
        }
    }
    if( st.size() == 1 ) ans = st.top();
    else return false;
    return true;
}

bool parse( string &line, string &parsed ) {
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
                parsed += hand;
            }
            hand.clear();
            flag = false;
            if( c == '(' ) {
                ops.push( c );
            }
            else
            if( c == ')' ) {
                while( !ops.empty() && ops.top() != '(' ) {
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
                    ops.pop();
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
        if( parse( line, parsed ) ) {
            if( eval( parsed ) ) {
                cout << ans << "\n";
            } else {
                cout << "error\n";
            }
        } else {
            cout << "error\n";
        }
        cout << ">>>: ";
    }
    return 0;
}
