/*
 * The MIT License
 *
 * Copyright 2017 Araf A1-Jami.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package highlow;

import java.util.Scanner;
/**
 *
 * @author Araf A1-Jami
 */
public class HighLow {
    private Deck deck;
    private Scanner in;
    private int score;
    
    HighLow() {
        deck = new Deck();
        in = new Scanner( System.in );
        score = 0;
    }
    
    public void play() {
        deck.shuffleDeck();
        int type;
        while( deck.hasNext() == true ) {
            System.out.printf( "Current Card: %s\n", deck.getNow() );
            do {
                System.out.printf( "Type 1 for High and 0 for Low\n" );
                type = in.nextInt();
            } while( type > 1 || type < 0 );
            evaluate( type, deck.getNow(), deck.getNext() );
            System.out.printf( "Score: %d\n", score );
            deck.next();
        }
    }
    
    void evaluate( int type, Card now, Card next ) {
        if( type == 1 ) {
            if( now.getCardValue() <= next.getCardValue() ) {
                System.out.printf( "Correct, " );
                score++;
            } else {
                System.out.printf( "Wrong, " );
                score--;
            }
        } else {
            if( now.getCardValue() >= next.getCardValue() ) {
                System.out.printf( "Correct, " );
                score++;
            } else {
                System.out.printf( "Wrong, " );
                score--;
            }
        }
    }
}
