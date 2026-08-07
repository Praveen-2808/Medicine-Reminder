
#  User-Configurable Medicine Reminder System
<img width="1774" height="887" alt="heading img4" src="https://github.com/user-attachments/assets/1c4875ca-aba4-4833-a4e6-25c6c234cafb" />


##  Aim

To develop a **User-Configurable Medicine Reminder System** that allows users to set medicine timings and receive automatic alerts at the scheduled time.

---

##  Objectives

* Display real-time clock (RTC) on LCD
* Allow user configuration of medicine timings
* Store scheduled medicine times
* Trigger alerts when medicine time occurs

---

##  Project Description

This system is built using an embedded platform where users can set medicine schedules using a keypad/switch interface. The system continuously tracks real time using an RTC module and alerts the user through a buzzer and LCD display when it is time to take medicine.

---

##  System Architecture

```
4x4 Matrix Keypad  →  
Switches           →   LPC2148 Microcontroller → RTC Module
                                      ↓
                                  LCD Display
                                      ↓
                                    Buzzer
```
<img width="1536" height="1024" alt="components_img2" src="https://github.com/user-attachments/assets/ca4dce4e-9c8a-4672-b609-c28a8ec82a84" />

---

##  Hardware Requirements

* LPC2148 Microcontroller
* 16x2 LCD Display
* 4x4 Matrix Keypad
* RTC Module
* Buzzer
* Switches
* USB-UART Converter / DB9 Cable
<img width="1220" height="785" alt="controller" src="https://github.com/user-attachments/assets/53a3849c-0ece-4a92-8b11-86bf9fc7aba0" />

---

##  Software Requirements

* Embedded C Programming
* Keil uVision
* Flash Magic

---

##  Working Principle
<img width="1024" height="900" alt="workflow" src="https://github.com/user-attachments/assets/e6baf8b1-695a-4f65-b191-9cab84ab7d48" />


### 1. Configuration Mode (Switch-1)

* System enters setup mode
* LCD shows configuration options:

  * Edit RTC Time
  * Configure Medicine Schedule
* User sets time and medicine timings
* Data is stored in RTC

### 2. Normal Mode (Switch-2)

* LCD continuously displays current time
* System checks medicine schedule

### 3. Alert Mechanism

* When RTC time matches medicine time:

  * Buzzer is activated
  * Alert message displayed on LCD
* User acknowledges alert

---

---
### output
<img width="1536" height="1024" alt="lcdimg3" src="https://github.com/user-attachments/assets/a8c9c238-0f21-44b2-9a5c-586a66ddbeb2" />
---

##  Features

* ⏰ Real-time clock display
* 🔧 User-configurable medicine timings
* 🔔 Automatic alert system
* 📟 LCD-based interface
* 🔁 Continuous monitoring

---

##  How to Run

1. Connect all hardware components
2. Write and compile code using Keil
3. Flash the program using Flash Magic
4. Set RTC time
5. Configure medicine schedule
6. System runs automatically

---

##  Applications

* Personal healthcare
* Elderly assistance systems
* Hospitals and clinics
* Smart embedded healthcare devices

---


## 👨‍💻

**Jada Praveen**
B.Tech Electronics
Embedded Systems Enthusiast

