

```markdown
# 🎫 ScratchSecure System (C Language)

A telecom recharge scratch card management system written in **C**.  
It handles **card generation, user authentication, transaction tracking, statistics, and administrative functions** in a secure way.

---

## ✨ Features
- 🔐 Role-based authentication (Admin/User)
- 🎫 Scratch card generation, deletion, and management
- 📱 User account management with balance tracking
- 🔒 Security features with account lockout system
- 📊 Detailed sales statistics and reporting
- 📝 Transaction history tracking
- 👥 User registration and login system
- 🔍 Search transactions by mobile number
- 💾 Persistent storage (data is saved in text files across sessions)

---

## 🖥 Menu Structure

### Admin Menu Options
| Option | Description |
|--------|-------------|
| 1 | Create new scratch cards |
| 2 | Delete existing card |
| 3 | Unlock locked user accounts |
| 4 | View recharge history |
| 5 | Display sales statistics |
| 6 | Search transaction by mobile number |
| 7 | Exit program |
| 8 | Show all available cards |
| 9 | Search for specific card |
| 10 | Return to main menu |

### User Menu Options
| Option | Description |
|--------|-------------|
| 1 | Sign in to existing account |
| 2 | Create new account |
|   | Recharge with scratch card after login |

---

## 📂 File Structure
```

scratchsecure/
│── scratch\_management.c    # Main source code
│── cards.txt               # Scratch card database
│── users.txt               # User account balances
│── locked.txt              # Locked user accounts
│── history.txt             # Transaction history
│── Statistics.txt          # Sales statistics
│── password.txt            # User credentials
│── README.md               # Project documentation

````

---

## ⚙️ How to Compile & Run

**On Windows (MinGW / Dev-C++ / Code::Blocks):**
```bash
gcc scratch_management.c -o scratchsecure.exe
scratchsecure.exe
````

**On Linux (GCC):**

```bash
gcc scratch_management.c -o scratchsecure
./scratchsecure
```

---

## 🔐 Login System

**Admin Access**

* Default password: `admin123`
* Required for performing administrative functions

**User Access**

* Users can sign up with username/password
* Login is required before recharging with a scratch card
* Accounts are protected with lockout system after failed attempts

---

## 📊 Example Output

```
==================================
||      ScratchSecure System    ||
||      Developed by: SANJID    ||
==================================

*****Main Menu*****
1. Admin
2. User
3. Exit
Enter Option: 
```

---

## 📌 Notes

* Data is **persistently stored** in text files and restored on next execution
* Uses **dynamic memory allocation** with safe reallocation
* Scratch card numbers are generated **randomly and uniquely**
* **Account lockout** occurs after multiple failed attempts
* Keeps track of:

  * Cards sold
  * Cards remaining
  * Total revenue generated

---

## 🛡️ Security Features

* Password-protected **Admin functions**
* User account system with credential storage
* Account lockout for invalid recharge attempts
* Input validation throughout the program

---

## 📜 License

This project is licensed under the **MIT License** — you are free to use, modify, and distribute it.

---

## 👨‍💻 Author

**Sanjid Alam Shadhin**
📧 \[[sanjid01313@gmail.com](mailto:sanjid01313@gmail.com)]
🌐 \[[https://github.com/sanjid-alam-2403057](https://github.com/sanjid-alam-2403057)]

```

---

```
