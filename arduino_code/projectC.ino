boolean num1[10][7] = {
  1, 1, 1, 1, 1, 1, 0, // 0
  0, 1, 1, 0, 0, 0, 0, // 1
  1, 1, 0, 1, 1, 0, 1, // 2
  1, 1, 1, 1, 0, 0, 1, // 3
  0, 1, 1, 0, 0, 1, 1, // 4
  1, 0, 1, 1, 0, 1, 1, // 5
  1, 0, 1, 1, 1, 1, 1, // 6
  1, 1, 1, 0, 0, 1, 0, // 7
  1, 1, 1, 1, 1, 1, 1, // 8
  1, 1, 1, 1, 0, 1, 1 // 9
};

int digit1, digit2; 

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A1, OUTPUT);
  Serial.begin(9600);
    for (int i = 6; i < 13; i++) {
    pinMode(i, OUTPUT); // รับค่า pins 2-9 output
  }

  pinMode(A2, OUTPUT); // ไฟเลขตัวที่ 1
  pinMode(A3, OUTPUT); // ไฟเลขตัวที่ 2
}

void loop() {
  trafficRed();
  trafficYellow();
  trafficGreen();
  trafficYellow();
  
}
//เปิด/ปิด ไฟทาง
int nightlight(int val){
  if(val <= 75){
    Serial.print(" Light OFF : ");
    Serial.println(val);
    digitalWrite(A1, LOW);
  }else{
    Serial.print("Light ON : ");
    Serial.println(val);
    digitalWrite(A1, HIGH);
  }
}


//คำนวณแสงไฟ
int findlight(){
  int val = map(analogRead(A0), 0, 1024, 0, 255);
  return val;
}


//เปิดไฟแดง
void trafficRed(){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  redfunc();
}
//เปิดไฟเหลือง
void trafficYellow(){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
    digitalWrite(5, HIGH); 
  yellowfunc();
}
//เปิดไฟเขียว
void trafficGreen(){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  greenfunc();
}
// ฟังก์ชันอ่านเลข
void show_num(int row) {
  for (int i = 6; i < 13; i++) {
    digitalWrite(i, num1[row][i-6]); // i = port, i-6 = หลัก
  }
}


// ฟังก์ชันไฟแดง 15 วิ
void redfunc(){
  for (int j = 15; j >= 0; j--) { // นับถอยหลัง 0 - 15
    digit2 = j / 10;
    digit1 = j % 10;

    for (int k = 0; k < 50; k++) { // หน่วงเวลา
      nightlight(findlight());
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      show_num(digit2);
      delay(10); 

      digitalWrite(A3, HIGH);
      digitalWrite(A2, LOW);
      show_num(digit1);
      delay(10);
      
    }
  }
}


// ฟังก์ชันไฟเหลือง 3 วิ
void yellowfunc(){
  for (int j = 3; j >= 0; j--) { // นับถอยหลัง 0 - 3
    digit2 = j / 10;
    digit1 = j % 10;

    for (int k = 0; k < 50; k++) { // หน่วงเวลา
      nightlight(findlight());
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      show_num(digit2);
      delay(10); 

      digitalWrite(A3, HIGH);
      digitalWrite(A2, LOW);
      show_num(digit1);
      delay(10);
      
    }
  }
}


// ฟังก์ชันไฟเขียว 10 วิ
void greenfunc(){
  for (int j = 10; j >= 0; j--) { // นับถอยหลัง 0 - 10
    digit2 = j / 10;
    digit1 = j % 10;

    for (int k = 0; k < 50; k++) { // หน่วงเวลา
      nightlight(findlight());
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      show_num(digit2);
      delay(10); 

      digitalWrite(A3, HIGH);
      digitalWrite(A2, LOW);
      show_num(digit1);
      delay(10);
      
    }
  }
}