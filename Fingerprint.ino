#define MAX_EMPLOYEE_NUMBER 3  // Maximum employees

typedef struct {
  String name;
  int id;
  bool assigned;
} EMPLOYEE;

EMPLOYEE employeestruct[MAX_EMPLOYEE_NUMBER];  // Array of employee structures

void setup() {
  Serial.begin(115200);
  Serial.println("Enter Employee Details (ID then Name):");
}

void loop() {
  for (int i = 0; i < MAX_EMPLOYEE_NUMBER; i++) {
    Serial.print("Enter ID for Employee "); Serial.println(i + 1);
    while (!Serial.available());  // Wait for input
    int tempID = Serial.readStringUntil('\n').toInt();  // Read ID

    // --- ID Duplication Check Using if-else ---
    bool idExists = false;
    for (int j = 0; j < i; j++) {  // Check WITH previous employees AS INDEX on the basis of i value.
      if (employeestruct[j].id == tempID) {
        idExists = true;
        break;
      }
    }

    if (idExists) {
      Serial.println("This ID is already registered. Please enter a different ID.");
      i--;  // Decrement i so taking input again using for loop for that employee otherwise no id is assigned for new employee

    } 

    else {
      employeestruct[i].id = tempID;

      Serial.print("Enter Name for Employee "); Serial.println(i + 1);
      while (!Serial.available());  // Wait for input
      employeestruct[i].name = Serial.readStringUntil('\n');  // Read Name

      employeestruct[i].assigned = true;  // Mark as assigned
      Serial.println("Employee Added Successfully!\n");
    }
  }

  // --- Display Final Employee List ---
  Serial.println("Final Employee List:");
  for (int i = 0; i < MAX_EMPLOYEE_NUMBER; i++) {
    Serial.print("ID: "); Serial.print(employeestruct[i].id);
    Serial.print(", Name: "); Serial.println(employeestruct[i].name);
  }

  while (true);  // Stop execution after all employees are added
}