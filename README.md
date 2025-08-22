
```markdown
# 🎫 ScratchSecure System (C Language)

A comprehensive scratch card management system written in C that handles card distribution, user authentication, transaction tracking, and administrative functions for a telecom recharge system.

## ✨ Features
- 🔐 Role-based authentication (Admin/User)
- 🎫 Scratch card generation and management
- 📱 User account management with balance tracking
- 🔒 Security features with user lockout system
- 📊 Detailed sales statistics and reporting
- 📝 Complete transaction history
- 👥 User registration and login system
- 🔍 Search functionality for transactions
- 💾 Persistent data storage across sessions

## 🖥 Menu Structure

### Admin Menu Options
| Option | Description |
|--------|-------------|
| 1 | Create new scratch cards |
| 2 | Delete existing cards |
| 3 | Unlock locked user accounts |
| 4 | View transaction history |
| 5 | Display sales statistics |
| 6 | Search transactions |
| 7 | Exit program |
| 8 | Show all available cards |
| 9 | Search for specific card |
| 10 | Return to main menu |

### User Menu Options
| Option | Description |
|--------|-------------|
| 1 | Sign in to existing account |
| 2 | Create new account |
| 3 | Recharge using scratch card |

## 📂 File Structure
```
scratchsecure/
│── scratch_management.c    # Main source code
│── cards.txt               # Scratch card database
│── customer.txt            # User account information
│── locked_users.txt        # Locked user accounts
│── history.txt             # Transaction history
│── Statistics.txt          # Sales statistics
│── password_manager.txt    # User credentials
│── README.md               # Project documentation
```

## ⚙️ How to Compile & Run

**On Windows (Code::Blocks / Dev-C++ / MinGW)**
```bash
gcc scratch_management.c -o scratchsecure.exe
scratchsecure.exe
```

**On Linux (GCC)**
```bash
gcc scratch_management.c -o scratchsecure
./scratchsecure
```

## 🔐 Login System

**Admin Access:**
- Default password: `admin123`
- Password is required for administrative functions

**User Access:**
- Users can create accounts or sign in with existing credentials
- Accounts are protected with username/password authentication

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

## 📌 Notes
- Data is persistently stored in text files and maintained between sessions
- Uses dynamic memory allocation with safe reallocation practices
- Includes security features like account lockout after failed attempts
- Generates random card numbers with validation to prevent duplicates
- Tracks comprehensive statistics including cards sold, remaining inventory, and revenue

## 🛡️ Security Features
- Password protection for admin functions
- User account system with secure credential storage
- Account lockout after multiple failed card redemption attempts
- Input validation throughout the system

## 📜 License
This project is licensed under the MIT License — you are free to use, modify, and distribute it.

## 👨‍💻 Author
**Sanjid Alam Shadhin**  
📧 [sanjid01313@gmail.com]  
🌐 [https://github.com/sanjid-alam-2403057]
```
