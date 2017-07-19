#include <bits/stdc++.h>
using namespace std;

int main() {
    vector < string > keywords = { "if", "loop", "for", "while", "integer", "double", "float", "long" };
    vector < bool > fl;
    string line;
    getline( cin, line );
    for( auto s: keywords ) {
        fl.push_back( ( line.find( s ) != string::npos ) );
    }
    for( int i=0; i<int(keywords.size()); i++ ) {
        cout << keywords[i] << ": " << ( fl[i] ? "Yes" : "No" ) << "\n";
    }
    return 0;
}
