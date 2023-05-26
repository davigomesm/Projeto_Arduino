#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pos = 0;
int gasolina;
int tanque = 0;
int viagem;
int posto = 1;
Servo servo_9;

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
}

void loop(){
  	lcd.clear();
  	if (tanque < 0){
    	lcd.setCursor(0, 0);
      	lcd.print("ficou sem");
      	lcd.setCursor(0, 1);
      	lcd.print("gasolina");
      	delay(2000);
  	}
  	lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Vamos viajar");
  	Serial.println("");
  	Serial.println("");
  	Serial.println("Vamos viajar, Qual o custo da viagem em litros de gasolina?");
  	while(!Serial.available());
  	viagem = Serial.parseInt();
  	if (viagem <= 0 || viagem > 10){
      	Serial.println("");
      	Serial.println("Viagem inexistente ou excede a quantidade de gasolina que cade no tanque");
      	Serial.println("Escolha uma viagem que gaste de 1 a 10 litros de gasolina");
      	while(!Serial.available());
  		viagem = Serial.parseInt();
  	}
  	
  	
  	while(true){
      	Serial.println("");
      	Serial.println("Deseja ir no posto de combustivel?");
      	Serial.println("Digite 0 para NAO e 1 para SIM");
      	while(!Serial.available());
      	posto = Serial.parseInt();
      	lcd.clear();
      	if (posto == 0){
        	break;
        }
//-----------------------------------------------------------------------------------
        if (tanque == 0){
            pos = 30;
            servo_9.write(pos);
          	digitalWrite(10, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque vazio!!!");
            lcd.setCursor(0, 1);
            lcd.print("Coloque gasolina");
          	Serial.println("");
            Serial.println("Deseja colocar quanto de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(10, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
//-------------------------------------------------------------------------------------------
        if (tanque == 1){
          	lcd.clear();
            pos = 42;
            servo_9.write(pos);
          	digitalWrite(8, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Na reserva(1/10)");
            lcd.setCursor(0, 1);
            lcd.print("Coloque gasolina"); 
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(8, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }

//----------------------------------------------------------------------------------------------
        if (tanque == 2){
          	lcd.clear();
            pos = 54;
            servo_9.write(pos);
          	digitalWrite(8, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Na reserva(2/10)");
            lcd.setCursor(0, 1);
            lcd.print("Coloque gasolina");
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(8, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//---------------------------------------------------------------------------------------------
        if (tanque == 3){
          	lcd.clear();
            pos = 66;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (3/10)");
            lcd.setCursor(0, 1);
            lcd.print("vai da certin");
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//-------------------------------------------------------------------------------------------
        if (tanque == 4){
          	lcd.clear();
            pos = 78;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (4/10)");
            lcd.setCursor(0, 1);
            lcd.print("Da que sobra");
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//-------------------------------------------------------------------------------------
        if (tanque == 5){
          	lcd.clear();
            pos = 90;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (5/10)");
            lcd.setCursor(0, 1);
            lcd.print("Simbora");  
            delay(3000);
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//----------------------------------------------------------------------------------------------
        if (tanque == 6){
          	lcd.clear();
            pos = 102;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (6/10)");
            lcd.setCursor(0, 1);
            lcd.print("Simbora"); 
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//--------------------------------------------------------------------------------------------
        if (tanque == 7){
          	lcd.clear();
            pos = 114;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (7/10)");
            lcd.setCursor(0, 1);
            lcd.print("Simbora"); 
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//------------------------------------------------------------------------------------------
        if (tanque == 8){
          	lcd.clear();
            pos = 126;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (8/10)");
            lcd.setCursor(0, 1);
            lcd.print("Simbora");  
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.printlm("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//----------------------------------------------------------------------------------------
        if (tanque == 9){
          	lcd.clear();
            pos = 138;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (9/10)");
            lcd.setCursor(0, 1);
            lcd.print("Eu sou ricaaa"); 
          	Serial.println("");
            Serial.println("Quanto deseja colocar de gasolina?");
            Serial.println("Tanque suporta 10 litros");
            Serial.println("Digite 0 para sair");
          	while(!Serial.available());
        	gasolina = Serial.parseInt();
        	if ((gasolina + tanque) > 10){
              	Serial.println("");
        		Serial.println("a gasolina excede a quantidade do tanque");
            	Serial.println("Quanto deseja colocar?");
            	while(!Serial.available());
            	gasolina = Serial.parseInt();
        	}
        	if (gasolina == 0){
        		break;
        	}
        	tanque = (tanque + gasolina);
          	digitalWrite(13, LOW);
          	Serial.println("");
          	Serial.println("Deseja continuar no posto?");
        	Serial.println("Digite 1 para SIM e 0 para NAO");
        	while(!Serial.available());
        	posto = Serial.parseInt();
        	if (posto == 0){
        		break;
        	}
        }
        
//-------------------------------------------------------------------------------------------
        if (tanque == 10){
          	lcd.clear();
            pos = 150;
            servo_9.write(pos);
          	digitalWrite(13, HIGH);
          	lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Tanque (10/10)");
            lcd.setCursor(0, 1);
            lcd.print("Como eh amigo?");
          	delay(2000);
          	digitalWrite(13, LOW);
        	break;
        }
    }
  
//-------------------------------------------------------------------------------------------
  
    if (viagem <= tanque){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Viajando...");
        delay(2500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Viagem bem");
        lcd.setCursor(0, 1);
        lcd.print("Sucedida");
      	delay(2000);
    }

    if (viagem > tanque){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" viagem mal");
        lcd.setCursor(0, 1);
        lcd.print(" Sucedida");
      	delay(2000);
    }
  	tanque = (tanque - viagem);
}