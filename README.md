
#  User-Configurable Medicine Reminder System
<img width="1672" height="941" alt="heading img5" src="https://github.com/user-attachments/assets/d99c3429-60ab-4e03-9000-e6b5ba9f3523" />


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
![IMG_4369](https://github.com/user-attachments/assets/7034c0e0-5247-4421-b9d6-80bbd9c1d60a)

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
### Output
<img width="2000" height="1333" alt="Beautiful Natural Sunset Aesthetics Mood Photo Collage (1)" src="https://github.com/user-attachments/assets/d06a0165-6be6-4ead-a412-19a3d5b231a8" />

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


## 

**Jada Praveen**
B.Tech Electronics
Embedded Systems Enthusiast

