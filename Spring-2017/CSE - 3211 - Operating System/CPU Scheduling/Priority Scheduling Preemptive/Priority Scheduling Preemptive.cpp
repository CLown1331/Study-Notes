/// Priority Scheduling Preemptive.cpp
#include <bits/stdc++.h>
using namespace std;

struct process {
    int _id, arrival_time, burst_time, priority;
};

struct cmp {
    bool operator()( const process &a, const process &b ) {
        if( a.priority == b.priority ) {
            return ( a.burst_time > b.burst_time );
        }
        return ( a.priority > b.priority );
    }
};

int main() {

    freopen( "in.txt", "r", stdin );

    queue < process > Q;
    priority_queue < process, vector < process >, cmp > PQ;

    process hand, hand2;

    map < int, int > work;

    int time = 0;

    int n, no = 0;

    double avg_wt = 0.0, avg_tt = 0.0;

    cin >> n;

    vector < process > processList( n );
    vector < int > AT, BT, PT, WT( n ), TT( n );

    for( process &p: processList ) {
        cin >> p.arrival_time >> p.burst_time >> p.priority;
        p._id = ++no;
        work[ p._id ] = no;
        AT.push_back( p.arrival_time );
        BT.push_back( p.burst_time );
        PT.push_back( p.priority );
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
            } break;
        }
        if( !PQ.empty() ) {
            hand2 = PQ.top();
            PQ.pop();
            if( hand2.burst_time > 1 ) {
                hand2.burst_time -= 1;
                PQ.push( hand2 );
            } else {
                int id = work[ hand2._id ] - 1;
                WT[ id ] = time + 1 - hand2.arrival_time - BT[ id ];
                TT[ id ] = WT[ id ] + BT[ id ];
                avg_wt += WT[ id ];
                avg_tt += TT[ id ];
            }
        }
        time++;
    }

    printf("-------------------------------------------------------\n");

    printf( "Process\tA.T\tB.T\tPRT\tW.T\tT.T\tAVG W.T\tAVG T.T\n" );

    for( int i=0; i<n; i++ ) {
        printf( "P%d\t%2d\t%2d\t%2d\t%2d\t%2d", i+1, AT[i], BT[i], PT[i], WT[i], TT[i] );
        if( i == n / 2 ) printf("\t%.2f\t%.2f", avg_wt / n, avg_tt / n );
        printf( "\n" );
    }

    printf("-------------------------------------------------------\n");

    return 0;
}
