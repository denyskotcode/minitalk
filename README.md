# 📞 Minitalk - Inter-Process Communication

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language C">
  <img src="https://img.shields.io/badge/School-42-black.svg" alt="School 42">
  <img src="https://img.shields.io/badge/Concept-UNIX%20Signals-yellow.svg" alt="UNIX Signals">
</p>

> *"Communication is key, even between processes."*

## 🌟 About the Project

**Minitalk** is a project from the **School 42** curriculum. The purpose of this project is to code a small data exchange program using UNIX signals. It consists of a **client** and a **server** communicating with each other. 

The main constraint and learning objective is to use strictly only two signals: `SIGUSR1` and `SIGUSR2`.

## ⚙️ How it works

1. The **Server** is started first. Upon launch, it prints its PID (Process ID) and waits indefinitely for incoming signals.
2. The **Client** takes two arguments: the server's PID and a string (the message to send).
3. The client converts each character of the message into an 8-bit binary format.
4. It then transmits the message bit-by-bit to the server:
   * `SIGUSR1` represents the `0` bit.
   * `SIGUSR2` represents the `1` bit.
5. The server receives the signals, reconstructs the bytes, and prints the string once the null terminator (`\0`) is received.

*Note: The server handles large strings and prints them instantaneously upon receiving the full message.*

## 🚀 Build and Usage

**1. Clone the repository:**
```bash
git clone [https://github.com/YOUR_USERNAME/minitalk.git](https://github.com/YOUR_USERNAME/minitalk.git)
cd minitalk
