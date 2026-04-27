
# 💊 User-Configurable Medicine Reminder System

## 📌 Aim

To develop a **User-Configurable Medicine Reminder System** that allows users to set medicine timings and receive automatic alerts at the scheduled time.

---

## 🎯 Objectives

* Display real-time clock (RTC) on LCD
* Allow user configuration of medicine timings
* Store scheduled medicine times
* Trigger alerts when medicine time occurs

---

## 📖 Project Description

This system is built using an embedded platform where users can set medicine schedules using a keypad/switch interface. The system continuously tracks real time using an RTC module and alerts the user through a buzzer and LCD display when it is time to take medicine.

---

## 🧩 System Architecture

```
4x4 Matrix Keypad  →  
Switches           →   LPC2148 Microcontroller → RTC Module
                                      ↓
                                  LCD Display
                                      ↓
                                    Buzzer
```

---

## ⚙️ Hardware Requirements

* LPC2148 Microcontroller
* 16x2 LCD Display
* 4x4 Matrix Keypad
* RTC Module
* Buzzer
* Switches
* USB-UART Converter / DB9 Cable

---

## 💻 Software Requirements

* Embedded C Programming
* Keil uVision
* Flash Magic

---

## 🔄 Working Principle

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

## ✨ Features

* ⏰ Real-time clock display
* 🔧 User-configurable medicine timings
* 🔔 Automatic alert system
* 📟 LCD-based interface
* 🔁 Continuous monitoring

---

## 🚀 How to Run

1. Connect all hardware components
2. Write and compile code using Keil
3. Flash the program using Flash Magic
4. Set RTC time
5. Configure medicine schedule
6. System runs automatically

---

## 📌 Applications

* Personal healthcare
* Elderly assistance systems
* Hospitals and clinics
* Smart embedded healthcare devices

---


## 👨‍💻

**Jada Praveen**
B.Tech Electronics
Embedded Systems Enthusiast

<img width="1920" height="1200" alt="image" src="https://github.com/user-attachments/assets/7e02e803-1ac8-4c87-8887-d7f1d45a1bfe" />
