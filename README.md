

---

```markdown
# ScratchSecure System

ScratchSecure System is a C-based program for managing scratch cards, mobile recharges, user accounts, and administrative operations. It is designed to simulate a prepaid recharge system with features like **card generation, user sign-in/sign-up, recharge history, statistics, account locking/unlocking, and persistent file storage**.

---

## 📌 Features

### 👨‍💼 Admin
- Login with admin password (`admin123` by default).
- Add new recharge cards (40, 60, 100 minutes, or custom).
- Delete cards.
- Unlock locked users.
- View recharge history.
- Check system statistics (sold cards, remaining cards, total revenue).
- Search by mobile number or specific card number.
- View all available cards.

### 👤 User
- Sign Up with username & password.
- Sign In with existing credentials.
- Recharge balance using scratch card numbers.
- Maintain individual balance.
- Mobile numbers automatically locked after **3 wrong attempts**.

### 📂 File Management
The system automatically stores and loads data from:
- `cards.txt` → Stores available scratch cards.
- `users.txt` → Stores user balances.
- `locked.txt` → Stores locked mobile numbers.
- `history.txt` → Stores recharge transaction history.
- `Statistics.txt` → Stores sales & revenue statistics.
- `password.txt` → Stores registered usernames & passwords.

---

## ⚙️ How It Works

1. **Startup**  
   - Loads existing data from text files.  
   - If no data exists, generates default sets of cards.

2. **Main Menu**  
   - Choose **Admin**, **User**, or **Exit**.  

3. **Admin Login**  
   - Enter password to access admin operations.  

4. **User Login / Signup**  
   - Create a new account or login with username & password.  
   - Recharge by entering mobile number & scratch card number.  

5. **Locking System**  
   - A mobile number is locked after 3 wrong card attempts.  
   - Admin can unlock locked numbers.  

6. **Exit**  
   - On exit, all changes are saved to files.  

---

## 🗂️ Project Structure

```

ScratchSecure/
│
├── main.c             # Core source code
├── cards.txt          # Scratch card database
├── users.txt          # User balances
├── locked.txt         # Locked mobile numbers
├── history.txt        # Recharge history
├── Statistics.txt     # Sales and statistics
└── password.txt       # User credentials

````

---

## 🚀 Compilation & Execution

### Compile:
```bash
gcc main.c -o scratchsecure
````

### Run:

```bash
./scratchsecure
```

---

## 🔑 Default Credentials

* **Admin Password**: `admin123`
* **User**: Must register first via Sign Up option.

---

## 📊 Example Workflow

1. Run the program → Main Menu.
2. As Admin → Add 10 cards of 40 minutes each.
3. As User → Sign Up (`username: test, password: 1234`).
4. Enter mobile number & scratch card → Balance recharged.
5. Check statistics → Revenue & remaining cards updated.
6. On exit → All data stored in `.txt` files.

---

## 🛠️ Author

**Developed by:** *Sanjid Alam*
Department of CSE, RUET

---

```

---

