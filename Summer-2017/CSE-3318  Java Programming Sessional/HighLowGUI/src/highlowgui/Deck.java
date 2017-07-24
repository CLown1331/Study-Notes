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
package highlowgui;

import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
/**
 *
 * @author Araf A1-Jami
 */
public class Deck {
    private ArrayList < Card > deck;
    private String[] cardNames = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    private int currentIndex;
    
    Deck() {
        deck = new ArrayList < Card > ();
        build();
        currentIndex = 0;
    }
    
    void build() {
        addSuit( "Hearts" );
        addSuit( "Diamonds" );
        addSuit( "Clubs" );
        addSuit( "Spades" );
    }
    
    void addSuit( String suitName ) {
        for( int i=0; i<cardNames.length; i++ ) {
            deck.add( new Card( suitName, cardNames[i], i ) );
        }
    }
    
    public void shuffleDeck() {
        Random rand = new Random();
        int index;
        Card hand;
        for( int i=deck.size()-1; i>0; i-- ) {
            index = rand.nextInt( i + 1 );
            hand = deck.get( index );
            deck.set( index, deck.get( i ) );
            deck.set( i, hand );
        }
    }
    
    public boolean hasNext() {
        return currentIndex + 1 < deck.size() ? true : false;
    }
    
    public Card getNow() {
        return deck.get( currentIndex );
    }
    
    public Card getNext() {
        return deck.get( currentIndex + 1 );
    }
    
    public void next() {
        currentIndex++;
    }
}
