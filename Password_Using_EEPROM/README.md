Password Using EEPROM in Arduino UNO

Overview

This project demonstrates how to use EEPROM memory in an Arduino UNO to permanently store and update a binary password using push buttons.

The project helped in understanding:

- Arduino UNO architecture
- ATmega328P microcontroller
- Types of memory in microcontrollers
- EEPROM working principle
- MOSFET-based memory storage concept
- Address and value storage
- EEPROM read/write operations
- Password storage and reset mechanism using Arduino

---

Arduino UNO

Arduino UNO uses the ATmega328P microcontroller.

Inside the microcontroller, we have:

- CPU
- ADC (Analog to Digital Converter)
- DAC (Digital to Analog Converter)
- Oscillator
- Memory units

---

Types of Memory in Microcontrollers

Memory Type   | Purpose
----------------------------------------
SRAM          | Temporary runtime memory
FLASH         | Stores program/code
EEPROM        | Stores permanent data

---

EEPROM Memory

EEPROM stands for:

Electrical Erasable Programmable Read Only Memory

EEPROM is a non-volatile memory, meaning the data remains stored even after power is turned OFF.

---

EEPROM Size

In Arduino UNO

- EEPROM size = 1024 bytes

In Arduino Mega

- EEPROM size = 4096 bytes

---

EEPROM Internal Working

EEPROM internally uses a large number of MOSFET transistors.

Each transistor can store:

- "1"
- "0"

So binary data is stored using transistor charge states.

---

EEPROM Storage Concept

Each EEPROM cell stores:

- 1 byte = 8 bits

A byte can store values from:

- Decimal: "0 to 255"

Binary representation example:

00000000 → 0
11111111 → 255

---

EEPROM Addressing

EEPROM memory locations are called addresses.

For Arduino UNO:

0 → 1023

Total:

1024 addresses

Each address stores:

1 byte

---

Transistor Requirement Calculation

Since:

1 byte = 8 bits

And:

1024 bytes EEPROM

Total bits:

1024 × 8 = 8192 bits

If one memory cell uses approximately 2 transistors:

2 × 8192 = 16384 transistors

Approximate transistor count:

16384 transistors

---

EEPROM Functions in Arduino

To use EEPROM:

#include <EEPROM.h>

Main functions learned:

Function| Purpose
EEPROM.write(address, value)| Store data
EEPROM.read(address)| Read data

---

Project: Password Using EEPROM

Objective

Store a binary password inside EEPROM and allow:

- Reading password
- Clearing password
- Resetting password using buttons

---

Components Used

- Arduino UNO
- Push Buttons
- Breadboard
- Jumper Wires
- USB Cable

---

Pin Connections

Component   | Pin
Button A    | Pin 2
Button B    | Pin 3
Clear Button| Pin 5

---

Initial Password

The initial password stored:

10110

Stored using EEPROM:

EEPROM.write(0,1);
EEPROM.write(1,0);
EEPROM.write(2,1);
EEPROM.write(3,1);
EEPROM.write(4,0);

---

Code Explanation

Header File

#include <EEPROM.h>

Includes EEPROM library functions.

---

Variables

const int button_A = 2;
const int button_B = 3;
const int clear_button = 5;

Defines button pins.

---

Serial Communication

Serial.begin(9600);

Starts serial monitor communication.

---

Reading EEPROM Values

int bit_val = EEPROM.read(i);

Reads stored value from EEPROM.

---

Writing EEPROM Values

EEPROM.write(counter,1);

Stores value at a specific EEPROM address.

---

Password Printing Function

void print_eeprom_val()

Purpose:

- Reads all stored bits
- Prints password in serial monitor

---

EEPROM Clear Function

void eeprom_clear()

Purpose:

- Clears old password
- Writes "0" into all locations

---

Reset Mode Logic

When clear button is pressed:

if(clear_state == 1 && reset_mode == false)

The system:

1. Prints old password
2. Clears EEPROM
3. Enables reset mode

---

New Password Entry

During reset mode:

- Button A → stores "0"
- Button B → stores "1"

Example:

EEPROM.write(counter,0);
EEPROM.write(counter,1);

Counter increments after every button press.

---

Password Update Completion

When 5 bits are entered:

if(counter >= 5)

The system:

- Prints new password
- Exits reset mode
- Resets counter

---

Important Concepts Learned

Microcontroller Architecture

Understanding internal hardware blocks.

---

Memory Management

Difference between:

- SRAM
- FLASH
- EEPROM

---

Non-Volatile Storage

EEPROM retains data after power OFF.

---

Address-Based Storage

Data is accessed using memory addresses.

---

Binary Data Representation

Using "0" and "1" for password storage.

---

EEPROM Read/Write Operations

Practical implementation using Arduino library.

---

Advantages of EEPROM

- Permanent storage
- Easy read/write
- Useful for passwords/settings
- Data retained without power

---

Limitations of EEPROM

- Limited write cycles
- Slower than SRAM
- Small memory size

---

Applications of EEPROM

- Password systems
- Device settings
- Calibration data
- Sensor thresholds
- IoT configuration storage

---

Sample Output

Reset Mode On:
Old Password: 10110

0 entered
1 entered
1 entered
0 entered
1 entered

New Password: 01101
Password Updated!

---

Final Outcome

By completing this project, I learned:

- Internal working of EEPROM
- EEPROM memory organization
- Binary storage concepts
- Address-value mapping
- Arduino EEPROM programming
- Password storage and reset implementation
- Serial monitor debugging
- Button interfacing with Arduino

---

Conclusion

This project provided practical understanding of how non-volatile memory works inside microcontrollers and how EEPROM can be used for real-world embedded applications such as password storage systems.

