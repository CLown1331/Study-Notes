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

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import java.awt.*;
import java.awt.event.*;;
/**
 *
 * @author Araf A1-Jami
 */
public class HighLow extends JFrame {
    private Deck deck;
    private int score;
    
    HighLow() {
        deck = new Deck();
        deck.shuffleDeck();
        initUI();
        score = 0;
    }
    
    void evaluate( int type, Card now, Card next ) {
        if( type == 1 ) {
            if( now.getCardValue() <= next.getCardValue() ) {
                JOptionPane.showMessageDialog( this, "Correct!");
                score++;
            } else {
                JOptionPane.showMessageDialog( this, "Wrong!");
                score--;
            }
        } else {
            if( now.getCardValue() >= next.getCardValue() ) {
                JOptionPane.showMessageDialog( this, "Correct!");
                score++;
            } else {
                JOptionPane.showMessageDialog( this, "Wrong!");
                score--;
            }
        }
    }
    
    private void initUI() {
        JPanel panel = new JPanel();
        JLabel label = new JLabel( deck.getNow().toString() );
        JLabel scoreLabel = new JLabel( "Score: " + score );
        JButton High = new JButton( "High" );
        JButton Low = new JButton( "Low" );
        
        High.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                if( deck.hasNext() ) {
                    evaluate( 1, deck.getNow(), deck.getNext() );
                    deck.next();
                    label.setText( deck.getNow().toString() );
                    scoreLabel.setText( "Score: " + score );
                }
            } 
        });
        
        Low.addActionListener( new ActionListener() {
            public void actionPerformed( ActionEvent e ) {
                if( deck.hasNext() ) {
                    evaluate( 0, deck.getNow(), deck.getNext() );
                    deck.next();
                    label.setText( deck.getNow().toString() );
                    scoreLabel.setText( "Score: " + score );
                }
            } 
        });
        
        panel.add( label );
        panel.add( scoreLabel );
        panel.add( High );
        panel.add( Low );
        
        this.add( panel );
        
        setTitle( "High Low");
        setSize( 300, 100 );
        setLocationRelativeTo( null );
        setDefaultCloseOperation( EXIT_ON_CLOSE );
    }
}
