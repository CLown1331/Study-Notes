/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package converter;

/**
 *
 * @author CLown1331
 */
public class Converter {
       
    Converter() {
        
    }
    
    double celsiusToFahrenheit( double celsius ) {
        return ( celsius * 1.8d ) + 32.0d;
    }
    
    double fahrenheitToCelsius( double fahrenheit ) {
        return ( fahrenheit - 32.0d ) / 1.8d;
    }
    
    double feetToMeter( double feet ) {
        return feet * 0.3048d;
    }
    
    double meterToFeet( double meter ) {
        return meter * 3.28084d;
    }
}
