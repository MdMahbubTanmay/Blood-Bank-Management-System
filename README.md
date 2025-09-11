# Blood Bank Management System

This is a simple, console-based Blood Bank Management System written in C. It's designed to help manage donor information, including their name, mobile number, blood group, location, and last donation date. The system is built for easy use, allowing donors to register, log in, find other donors, and update their own details.
[![mainmenu.jpg](https://i.postimg.cc/mgVf8JXy/Screenshot-20250911-170053.jpg)](https://postimg.cc/hXJ5GyqX)
## ✨ Features

-   **User Authentication**: Secure login and new user registration.
[![register.jpg](https://i.postimg.cc/3NhtMJW4/Screenshot-20250911-165920.jpg)](https://postimg.cc/ftHcmscD)
-   **Donor Management**:
    -   View a list of all registered donors.
    [![DonorList.jpg](https://i.postimg.cc/T3VBhFvX/Screenshot-20250911-170821.jpg)](https://postimg.cc/pmds60d0)   
    -   Filter donors by blood group and area to find specific matches.
    -   Update your last donation date to keep your profile current.
-   **Data Persistence**: All donor information is saved to a binary file (`blood_data.bin`), so your data is safe and available for future use.
-   **Backup & Restore**: Easily create a backup of the database or restore from a previous backup file.

## 🛠️ How to Compile and Run

You'll need a C compiler like GCC to build and run the program.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/MdMahbubTanmay/Blood-Bank-Management-System.git](https://github.com/MdMahbubTanmay/Blood-Bank-Management-System.git)
    cd Blood-Bank-Management-System
    ```

2.  **Compile the code:**
    The program uses `windows.h` for Windows-specific functions. If you are on a Linux or macOS system, you may need to modify the code to remove this dependency.

    ```bash
    gcc -o blood_bank main.c
    ```

3.  **Run the application:**
    ```bash
    ./blood_bank
    ```

## 🖥️ Usage

When you start the program, you'll see a main menu with options to login, register, or manage backups.

-   **Register**: Create a new donor profile.
-   **Login**: Access the **User Panel** with your registered mobile number and password.
-   **User Panel**: From here, you can display all donors, filter for specific matches, view your profile, and update your last donation date.

---

Feel free to open an issue or submit a pull request if you have any suggestions or find a bug. Your contributions are welcome!
