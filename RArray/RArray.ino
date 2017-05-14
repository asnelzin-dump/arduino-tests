// RArray.ino

int capacity = 1;
int length = 0;
int rarray[capacity]; 

void resize(int newCapacity) {
    int temp[newCapacity];
    for (int i = 0; i < length; i++)
        temp[i] = rarray[i];
    rarray = temp;
    capacity = newCapacity;
}

void addElement(int e) {
    if (length >= capacity)
        resize(capacity * 2);
    rarray[length++] = e;
}


void setup() {
    addElement(5);
    Serial.print(rarray[0]);

}

void loop() {

}

