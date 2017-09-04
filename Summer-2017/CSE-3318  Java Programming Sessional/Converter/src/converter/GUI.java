/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package converter;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

/**
 *
 * @author CLown1331
 */
public class GUI extends JFrame {
    private Converter converter;
    private JButton convert;
    private JTextField input;
    private JTextField output;
    private JPanel panel;         
    private JLabel label1;
    private JLabel label2;
    private JComboBox options;
    
    GUI() {
        super( "Converter" );
        converter = new Converter();
        initUI();
    }
    
    private void initUI() {
        this.setSize( 300, 300 );
        this.setLocationRelativeTo( null );
        this.setDefaultCloseOperation( EXIT_ON_CLOSE );
        
        this.convert = new JButton( "Convert" );
        this.input = new JTextField( 20 );
        this.output = new JTextField( 20 );
        this.label1 = new JLabel( "Celsius" );
        this.label2 = new JLabel( "Fahrenheit" );
        this.panel = new JPanel();
        this.options = new JComboBox();
                
        this.label1.setHorizontalAlignment( SwingConstants.CENTER );
        this.label2.setHorizontalAlignment( SwingConstants.CENTER );
        this.convert.addActionListener( new ConvertAction() );
        this.options.addItem( "Temperature" );
        this.options.addItem( "Distance" );
        this.options.addItemListener( new OptionsAction() );
        
        this.panel.setLayout( new GridLayout( 6, 1 ) );
        
        this.panel.add( options );
        this.panel.add( label1 );
        this.panel.add( input );
        this.panel.add( label2 );
        this.panel.add( output );
        this.panel.add( convert );
        
        this.add( panel );
    }
    
    private class ConvertAction implements ActionListener {

        @Override
        public void actionPerformed( ActionEvent e ) {
            try {
                if( options.getSelectedItem().toString().equals( "Distance" ) ) {
                    output.setText( Double.toString( converter.feetToMeter( Double.parseDouble( input.getText() ) ) ) );
                }
                else {
                    output.setText( Double.toString( converter.celsiusToFahrenheit( Double.parseDouble( input.getText() ) ) ) );
                }
            } catch( NumberFormatException ex ) {
                JOptionPane.showMessageDialog( null, ex );
            }
        }
    }
    
    private class OptionsAction implements ItemListener {

        @Override
        public void itemStateChanged(ItemEvent e) {
            if( options.getSelectedItem().toString().equals( "Distance" ) ) {
                label1.setText( "Feet" );
                label2.setText( "Meter" );
                input.setText( "" );
                output.setText( "" );
            }
            else {
                label1.setText( "Celsius" );
                label2.setText( "Fahrenheit" );
                input.setText( "" );
                output.setText( "" );
            }
        }
        
    }
}
