//Projeto 22 - Ligando LED pelo terminal  
 //Este código é de domínio público  
   
 int ledPin = 8;  
 char buffer; //Para salvar o que é digitado  
   
 void setup(){  
  Serial.begin(9600);  //Comunicação via USB  
  pinMode(ledPin, OUTPUT);  
  Serial.println("Deseja Ligar o LED(s/n)");  
 }  
   
 void loop(){  
    
  if(Serial.available()){   //Verifica se tem algo digitado, senão não entra no if  
   buffer = Serial.read();   
   if(buffer == 's'){  
    digitalWrite(ledPin, HIGH); // Liga o LED  
    delay(1000);  
    Serial.println("Deseja manter o LED ligado(s/n)");  
   }  
   else{  
    if(buffer == 'n'){  
     digitalWrite(ledPin, LOW);  // Desliga o LED  
     delay(1000);  
     Serial.println("Deseja Ligar o LED(s/n)");  
    }  
   }  
  }  
 }  
