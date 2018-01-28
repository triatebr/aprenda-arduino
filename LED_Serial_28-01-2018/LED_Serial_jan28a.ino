//varíavel que guarda o dado vindo da serial
char leitura; 

//define os pinos onde os LEDs estão conectados 
#define ledRed 8  
#define ledGreen 9 
#define ledYellow 10 

void setup() {   

//Inicializa comunicação Serial a 9600   
Serial.begin(9600);   

//Configura os pinos dos LEDs como saída   
pinMode(ledRed, OUTPUT);   
pinMode(ledGreen, OUTPUT);   
pinMode(ledYellow,OUTPUT);    

//Mantém os LEDs desligados assim que iniciar o programa    
digitalWrite (ledRed, LOW);    
digitalWrite (ledGreen, LOW);    
digitalWrite (ledYellow, LOW); 
} 

void loop() {    
//Verifica se há algum dado no conector serial   
while (Serial.available() > 0) {     
//Lê o dado vindo da Serial e armazena na variável leitura     
leitura = Serial.read();      

//Se a variável leitura for igual a 'r' ou 'R' Inverte o valor do LED vermelho     
if (leitura == 'r' || leitura =='R'){// As duas || é a operação booleana OU       
digitalWrite(ledRed,!digitalRead(ledRed));     
} 

//Se ela for igual a  'g' ou 'G' Inverte o valor do LED Verde     
else if (leitura == 'g' || leitura =='G'){       
digitalWrite(ledGreen,!digitalRead(ledGreen));     
} 

//Se ela for igual a  'y' ou 'Y' Inverte o valor do LED Verde     
else if (leitura == 'y' || leitura =='Y'){       
digitalWrite(ledYellow,!digitalRead(ledYellow));     
}     

Serial.println(leitura);   
} 

}
