#include <bits/stdc++.h>
using namespace std;

struct process {
    int _id, arrival_time, burst_time;
};

struct cmp {
    bool operator()( const process &a, const process &b ) {
        return ( a.burst_time > b.burst_time );
    }
};

int main() {

    freopen( "in.txt", "r", stdin );

    queue < process > Q, PQ;

    process hand, hand2;

    map < int, int > work;

    int time = 0;

    int n, time_slice, min_slice, no = 0;

    double avg_wt = 0.0, avg_tt = 0.0;

    cin >> n >> time_slice;

    vector < process > processList( n );
    vector < int > AT, BT, WT( n ), TT( n );

    for( process &p: processList ) {
        cin >> p.arrival_time >> p.burst_time;
        p._id = ++no;
        work[ p._id ] = no;
        AT.push_back( p.arrival_time );
        BT.push_back( p.burst_time );
    }

    sort( processList.begin(), processList.end(),
        []( const process &a, const process &b ) -> bool{ return a.arrival_time < b.arrival_time; } );

    for( process p: processList ) {
        Q.push( p );
    }

    while( !Q.empty() || !PQ.empty() ) {
        while( !Q.empty() ) {
            hand = Q.front();
            if( hand.arrival_time <= time ) {
                Q.pop();
                PQ.push( hand );
            } else break;
        }
        for( int i=0,sz=int(PQ.size()); i<sz; i++ ) {
            hand2 = PQ.front();
            PQ.pop();
            min_slice = min( hand2.burst_time, time_slice );
            hand2.burst_time -= min_slice;
            time += min_slice;
            if( hand2.burst_time ) {
                PQ.push( hand2 );
            } else {
                int id = work[ hand2._id ] - 1;
                WT[ id ] = time - hand2.arrival_time - BT[ id ];
                TT[ id ] = WT[ id ] + BT[ id ];
                avg_wt += WT[ id ];
                avg_tt += TT[ id ];
            }
        }
    }

    printf("-------------------------------------------------------\n");

    printf( "Process\tA.T\tB.T\tW.T\tT.T\tAVG W.T\tAVG T.T\n" );

    for( int i=0; i<n; i++ ) {
        printf( "P%d\t%2d\t%2d\t%2d\t%2d", i+1, AT[i], BT[i], WT[i], TT[i] );
        if( i == n / 2 ) printf("\t%.2f\t%.2f", avg_wt / n, avg_tt / n );
        printf( "\n" );
    }

    printf("-------------------------------------------------------\n");

    return 0;
}
