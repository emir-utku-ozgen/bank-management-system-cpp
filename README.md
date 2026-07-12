# Bank Management System C++

A lightweight, clean, and object-oriented Bank Management System built in C++17. This project demonstrates core OOP principles, clean structural design using CMake, dynamic memory management with raw pointers, and file-based data persistence.

## 🚀 Features
- **Account Management:** Open new accounts dynamically with a unique ID, customer name, and initial balance.
- **Account Lookup:** Fast sequential scanning through data structures utilizing raw pointer returns.
- **Fund Transfers (Havale):** Safe atomic transactions between accounts with strict boundary and balance checks.
- **Data Persistence:** Automatically saves account records to a local text file (`.txt`) on exit and reloads the entire state upon startup.
- **Comprehensive Unit Tests:** Robust verification using standard `assert` macros to ensure logic coverage across all operations.

## 📁 Project Structure
```text
BankaSistemi/
├── CMakeLists.txt         # Build configuration
├── include/
│   └── Banka.h           # Class declarations (Hesap & Banka structs/classes)
├── src/
│   ├── Banka.cpp         # Core business logic implementation
│   └── main.cpp          # Interactive Console UI 
├── tests/
│   └── banka_tests.cpp   # Assert-based test suite
└── build/                # Compilation binaries