    /*Version 1.0. 
      TNS SAS*/
    
    
    // Incluye la libreria para el control de servomotores
    #include <Servo.h>
    
    // Define la constante para la lectura de la bateria, sensor y el led del boton 
    #define VBATPIN  9
    #define SENSORPIN  A1
    #define LEDPIN 12
    
    // Crea los objetos Servo para control de los dedos
    // TODO nombrar los dedos puntualmente
    Servo myservo;  
    Servo myservo1;  
    Servo myservo2;  
    Servo myservo3;  
    Servo myservo4;  
    
    //Crea las diferentes variables y se inicializan
    int sensorValue = 0;
    int contador = 1;
    String estadoMano = "";
    
    void setup() {
    
    
      // Inicializa la comunicacion por puerto serial a 9600 baudios
      Serial.begin(9600);
    
      // initialize digital pin 13 as an output.
      pinMode(LEDPIN, OUTPUT);
      digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    
      // Se asignan los servos a sus puertos digitales correspondientes
      myservo.attach(2);  
      myservo1.attach(3);  
      myservo2.attach(5);  
      myservo3.attach(6);  
      myservo4.attach(11);  
    
      // Llevan los servos a "Home"
      myservo.write(100);              
      myservo1.write(100);              
      myservo2.write(100);              
      myservo3.write(100);              
      myservo4.write(100);              
      estadoMano = "Home";
    
      delay(1000);

      // Se liberan los servos
      myservo.detach();  
      myservo1.detach();  
      myservo2.detach();    
      myservo3.detach();  
      myservo4.detach();  
    }
    
    void loop() {

      //WARNING: No poner delays afuera del trigger del sensor
      //TODO blink if low batery
      
    
      // Lectura y escritura de estado de bateria, sensor y mano
      float measuredvbat = analogRead(VBATPIN);
      measuredvbat *= 2;    // we divided by 2, so multiply back
      measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
      measuredvbat /= 1024; // convert to voltage
      Serial.print("VBat: " ); Serial.println(measuredvbat);
    
      sensorValue = analogRead(SENSORPIN);
      Serial.print("Sensor: " ); Serial.println(sensorValue);
    
      Serial.print("Estado Mano: " ); Serial.println(estadoMano);
    
      
      
          if(sensorValue > 1000){
        
            // Se asignan los servos a sus puertos digitales correspondientes
            myservo.attach(2);  
            myservo1.attach(3);  
            myservo2.attach(5);  
            myservo3.attach(6);  
            myservo4.attach(11);  
        
            
        
            if(contador == 1 && (estadoMano == "Abierta" || estadoMano == "Home")){
              // TODO revisar los limites
              myservo.write(180);              
              myservo1.write(180);              
              myservo2.write(180);              
              myservo3.write(180);              
              myservo4.write(180);              
              
              // Espera por 15 milisegundos que los servos lleguen a la posicion
              delay(15);                      
              estadoMano = "Cerrada";
            }
            
            else if(contador == 1 && estadoMano == "Cerrada"){
              // TODO revisar los limites
              myservo.write(0);              
              myservo1.write(0);              
              myservo2.write(0);              
              myservo3.write(0);              
              myservo4.write(0);   
        
              // Espera por 15 milisegundos que los servos lleguen a la posicion           
              delay(15);                       
              
              estadoMano = "Abierta";
            }
        
            delay(1000);
            
            // Se liberan los servos
            myservo.detach();  
            myservo1.detach();  
            myservo2.detach();    
            myservo3.detach();  
            myservo4.detach();  
      }
    
      Serial.println("////////////////////////////////////////////" ); 
    }
