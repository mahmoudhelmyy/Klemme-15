# Klemme-15 Car Control System

This repository contains the source code and documentation for the Klemme-15 Car Control System project developed by Team MetaWare.

## Table of Contents

- [Team Members](#team-members)
- [Layered Architecture](#Layered-Architecture)
- [Project Overview](#project-overview)
- [Usage](#usage)
- [Dependencies](#dependencies)

## Team Members

![image](https://github.com/mahmoudhelmyy/Klemme-15/assets/52659572/dba39d47-2499-4e88-9f42-3bcaa94839c4)

## Layered Architecture 

![image](https://github.com/mahmoudhelmyy/Klemme-15/assets/52659572/0b063048-3f61-4985-b00e-6d1217b0bcd4)

## Project Overview

The Klemme-15 Car Control System is designed to control the operation of a car based on analog readings from a potentiometer. The system has three main modes: OFF, READY, and IGNITION. The modes are determined by the potentiometer's analog values and are indicated using LEDs and an LCD display.

## Usage

- OFF Mode: All LEDs are turned off, and the LCD display shows "OFF."
- READY Mode: The red LED is turned on, and the system waits for a specified duration before transitioning to ALERT mode.
- IGNITION Mode: The red and blue LEDs are turned on, indicating the ignition state.
## Folder Structure
![Screenshot 2023-08-29 030540](https://github.com/mahmoudhelmyy/Klemme-15/assets/52659572/936ab6bb-ec7b-4c22-86f7-e850933a110f)
## Dependencies

- Microcontroller: AVR (ATmega32)
- Development Environment: (Microchip Studio)

## MISRA C:2012 Rules

We follow a set of MISRA C:2012 rules to ensure code quality and safety. Here are the rules we adhere to:

1. **Rule 7.2**: Function-like macro defined without a braced initializer list.
   - Explanation: Function-like macros should be defined using a braced initializer list to avoid unintended side effects.

2. **Rule 10.1**: Implicit conversion of integer types with loss of data.
   - Explanation: Avoid implicit conversions between integer types that might result in loss of data.

3. **Rule 10.4**: Consistent operand types in expressions.
   - Explanation: Ensure that operands of an operator have compatible types to avoid unexpected behavior.

4. **Rule 11.4**: Conversions shall not be performed between a pointer to object and any type other than an integral type.
   - Explanation: Avoid converting pointers to objects to other types, except integral types.

5. **Rule 11.9**: A function shall not be called through a pointer to a function type.
   - Explanation: Directly call functions, avoid calling through a pointer to a function type.

6. **Rule 12.4**: Expressions with a potential loss of sign-extended bits shall not be used.
   - Explanation: Do not use expressions that may lose sign-extended bits, as it can lead to unexpected behavior.

7. **Rule 14.4**: The controlling expression of an if statement and the controlling expression of an iteration statement shall have essentially Boolean type.
   - Explanation: Use controlling expressions in if and iteration statements with Boolean type.

8. **Rule 15.5**: The goto statement shall jump to a label declared later in the same function.
   - Explanation: Only use `goto` to jump to labels within the same function to maintain code clarity.

9. **Rule 15.6**: The address of an object with automatic storage shall not be assigned to any pointer variable outside the block in which the object is declared.
   - Explanation: Avoid assigning pointers to objects with automatic storage to pointers outside their declaration block.

10. **Rule 16.4**: Every switch statement shall have a default label.
    - Explanation: Provide a default label in every switch statement to handle unspecified cases.

11. **Rule 17.7**: Array indexing shall be the only allowed form of pointer arithmetic.
    - Explanation: Only use array indexing for pointer arithmetic, as it's safer and more predictable.

12. **Rule 20.7**: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
    - Explanation: Always enclose macro parameters in parentheses to ensure correct order of operations.

13. **Rule 20.10**: The # and ## preprocessor operators should not be used.
    - Explanation: Avoid using the # and ## operators in macros, as they can lead to unexpected behavior.

14. **Rule 20.14**: The right-hand operand of a logical && or || operator shall not contain side effects.
    - Explanation: Avoid side effects in the right-hand operand of logical && and || operators to prevent unexpected behavior.

## Contact

If you have any questions or concerns about the project or the MISRA C:2012 rules we follow, please contact us at [mahmoodhelmyy1@gmail.com].

## Class 3 EUI_EME

![image](https://github.com/mahmoudhelmyy/Klemme-15/assets/52659572/90bf5f3e-3c0e-4eae-93f3-3d2bfd4a9c96)

![image](https://github.com/mahmoudhelmyy/Klemme-15/assets/52659572/be5521e5-6aae-4d62-986b-82802e23b376)

*MetaWare LLC, 8/26/2023*
