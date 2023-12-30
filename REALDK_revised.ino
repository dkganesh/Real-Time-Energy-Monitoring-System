char bt = 'o';
const int max = 15;
int limit = 0;
const int load1 = 3;
const int load2 = 5;
const int load3 = 6;
const int load4 = 9;
const int load5 = 10;
const int mpin = 11;
const int ir1=2;
const int ir2=4;
void setup() {
  Serial.begin(9600);
  pinMode(load1, OUTPUT);
  pinMode(load2, OUTPUT);
  pinMode(load3, OUTPUT);
  pinMode(load4, OUTPUT);
  pinMode(load5, OUTPUT);
  pinMode(mpin, OUTPUT);
}

void loop() {
  limit = 0;
  if (Serial.available() > 0) {
    bt = 'o';
    bt = Serial.read();
    switch (bt) {
      case 'M':
        {
          Serial.println("Manual Mode");
          digitalWrite(mpin, HIGH);
          digitalWrite(load1, HIGH);
          digitalWrite(load2, HIGH);
          digitalWrite(load3, HIGH);
          digitalWrite(load4, HIGH);
          digitalWrite(load5, HIGH);
          bt = 'o';
          break;
        }
      case 'S':
        {
          Serial.println("Semi Mode");
          char choice = 'o';
          do {
            digitalWrite(mpin, LOW);
            choice = Serial.read();
            switch (choice) {
              case 'A':
                {
                  Serial.println(choice);
                  digitalWrite(load1, HIGH);
                  break;
                }
              case 'a':
                {
                  Serial.println(choice);
                  digitalWrite(load1, LOW);
                  break;
                }
              case 'B':
                {
                  Serial.println(choice);
                  digitalWrite(load2, HIGH);
                  break;
                }
              case 'b':
                {
                  Serial.println(choice);
                  digitalWrite(load2, LOW);
                  break;
                }
              case 'C':
                {
                  Serial.println(choice);
                  digitalWrite(load3, HIGH);
                  break;
                }
              case 'c':
                {
                  Serial.println(choice);
                  digitalWrite(load3, LOW);
                  break;
                }
              case 'D':
                {
                  Serial.println(choice);
                  digitalWrite(load4, HIGH);
                  break;
                }
              case 'd':
                {
                  Serial.println(choice);
                  digitalWrite(load4, LOW);
                  break;
                }
              case 'E':
                {
                  Serial.println(choice);
                  digitalWrite(load5, HIGH);
                  break;
                }
              case 'e':
                {
                  Serial.println(choice);
                  digitalWrite(load5, LOW);
                  break;
                }
              case 'M':
                {
                  Serial.println(choice);
                  digitalWrite(mpin, HIGH);
                  bt = 'o';
                  break;
                }
              case 'F':
                {
                  Serial.println(choice);
                  bt = 'o';
                  break;
                }
            }
          } while (bt != 'o');
        }
      case 'F':
        {
          limit = limit + 1;
          Serial.println(limit);
          Serial.println("Fully auto Mode");
          char full = 'o';
          do {
            digitalWrite(mpin, LOW);
            limit = limit + 1;
            delay(1000);
              Serial.println(limit);
            Serial.println("before if");
            if (limit < max) {
              full = Serial.read();
              switch (full) {
                case 'A':
                  {
                    Serial.println(full);
                    digitalWrite(load1, HIGH);
                    break;
                  }
                case 'a':
                  {
                    Serial.println(full);
                    digitalWrite(load1, LOW);
                    break;
                  }
                case 'B':
                  {
                    Serial.println(full);
                    digitalWrite(load2, HIGH);
                    break;
                  }
                case 'b':
                  {
                    Serial.println(full);
                    digitalWrite(load2, LOW);
                    break;
                  }
                case 'C':
                  {
                    Serial.println(full);
                    digitalWrite(load3, HIGH);
                    break;
                  }
                case 'c':
                  {
                    Serial.println(full);
                    digitalWrite(load3, LOW);
                    break;
                  }
                case 'D':
                  {
                    Serial.println(full);
                    digitalWrite(load4, HIGH);
                    break;
                  }
                case 'd':
                  {
                    Serial.println(full);
                    digitalWrite(load4, LOW);
                    break;
                  }
                case 'E':
                  {
                    Serial.println(full);
                    digitalWrite(load5, HIGH);
                    break;
                  }
                case 'e':
                  {
                    Serial.println(full);
                    digitalWrite(load5, LOW);
                    break;
                  }
                case 'M':
                  {
                    Serial.println(full);
                    digitalWrite(mpin, HIGH);
                    bt = 'o';
                    break;
                  }
                case 'S':
                  {
                    Serial.println(full);
                    bt = 'o';
                    break;
                  }
              }
            } else if (limit > max) {
              Serial.println("fully-else");
              digitalWrite(load1, LOW);
              digitalWrite(load3, LOW);
              digitalWrite(load5, LOW);
              digitalWrite(load2, digitalRead(ir1));
              digitalWrite(load4, digitalRead(ir2));
              bt = 'o';
            }
          } while (bt != 'o');
        }
    }
  }
}
