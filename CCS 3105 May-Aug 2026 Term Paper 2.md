**DEDAN KIMATHI UNIVERSITY OF TECHNOLOGY**

**SCHOOL OF COMPUTER SCIENCE AND INFORMATION TECHNOLOGY**

**BACHELOR OF SCIENCE IN COMPUTER SCIENCE**

**CCS 3105: SYSTEMS PROGRAMMING**

**TERM PAPER – WEEK 6 (MULTITHREADING AND THREAD SYNCHRONIZATION)**

**Total Marks: 100**

**Instructions**

- Answer **ALL FIVE (5)** questions. 

- Each question carries **20 marks**. 

- This is a **practical/application-based** assessment. All programs must be developed, compiled, and executed on a Linux environment using the POSIX Threads (Pthreads) library. 

- Include well-commented source code for every program. 

- **Every question must include screenshots** showing: 

  - Source code in the editor. 

  - Successful compilation. 

  - Program execution/output. 

  - Any relevant terminal commands or observations. 

- All screenshots should be clear and properly labelled. 

- SUBMIT the assignment on or before Monday August 3, 2026 by email (george.musumba@hotmail.com)

**Question One (20 Marks)**

**Thread Creation and Management**

A software company is developing a task scheduling application where multiple tasks must execute concurrently.

Develop a multithreaded C program using POSIX Threads that:

a) Creates **five worker threads**, each displaying:

- Its thread identifier. 

- A unique task number. 

- A message indicating that it has started execution. **(6 Marks)** 

b) The main thread should wait for all worker threads to complete using pthread\_join() before displaying the message:

All scheduled tasks have completed successfully.

**(4 Marks)**

c) Modify the program so that each worker thread receives its task number as an argument instead of using a global variable. Explain the advantages of passing parameters to threads. **(4 Marks)**

d) Include screenshots showing:

- Source code. 

- Successful compilation. 

- Program execution. 

- Output demonstrating that all five threads executed successfully. **(6 Marks)** 

**Question Two (20 Marks)**

**Race Conditions and Mutex Synchronization**

A bank is developing an ATM system where multiple ATM terminals update the same customer account simultaneously.

Develop a multithreaded program that:

a) Creates **four threads**, each depositing KES 1,000 into a shared bank balance 10,000 times **without synchronization**. Display the final account balance and explain your observations. **(6 Marks)**

b) Modify the program by protecting the shared balance using a POSIX mutex (pthread\_mutex\_lock() and pthread\_mutex\_unlock()). **(6 Marks)**

c) Compare the outputs obtained before and after using the mutex, explaining the concept of race conditions and critical sections. **(4 Marks)**

d) Include screenshots showing:

- Compilation. 

- Output before synchronization. 

- Output after synchronization. **(4 Marks)** 


**Question Three (20 Marks)**

**Producer–Consumer Problem**

A warehouse management system receives products from suppliers while customers simultaneously purchase products.

Develop a multithreaded Producer–Consumer application that:

a) Implements:

- One producer thread. 

- One consumer thread. 

- A shared buffer of size **5**. 

- Synchronization using **mutexes and semaphores**. **(10 Marks)** 

b) Display all production and consumption activities, including:

- Product number. 

- Buffer status. 

- Thread performing the operation. **(4 Marks)** 

c) Explain how mutexes and semaphores prevent data inconsistency in the shared buffer. **(2 Marks)**

d) Include screenshots showing:

- Successful compilation. 

- Execution. 

- Producer and consumer operations. 

- Buffer updates. **(4 Marks)** 

**Question Four (20 Marks)**

**Thread Synchronization Using Condition Variables**

A university examination system should generate the final class report **only after all departments have submitted their marks**.

Develop a multithreaded program where:

- Four worker threads represent different academic departments. 

- Each department processes marks independently. 

- A reporting thread waits until all departments complete processing. 

- Synchronization is achieved using **condition variables (pthread\_cond\_wait() and pthread\_cond\_signal())**. 

Your program should:

a) Display the processing progress of each department. **(6 Marks)**

b) Ensure that the reporting thread prints the final report **only after** all departments finish processing. **(6 Marks)**

c) Explain why condition variables are preferred over busy waiting in this scenario. **(2 Marks)**

d) Include screenshots showing:

- Source code. 

- Compilation. 

- Program execution. 

- Final synchronized report. **(6 Marks)** 

**Question Five (20 Marks)**

**Multithreaded Inventory Management System (Mini Project)**

A supermarket wishes to automate stock updates for different product categories.

Develop a complete multithreaded inventory management system that:

a) Creates **four worker threads**, each responsible for updating one of the following categories:

- Electronics 

- Groceries 

- Clothing 

- Stationery 

Each thread should:

- Update inventory quantities. 

- Display the category being processed. 

- Display the updated stock level. 

- Simulate processing delays using sleep(). **(8 Marks)** 

b) Protect all shared inventory data using a mutex and ensure that no race conditions occur. **(4 Marks)**

c) After all worker threads complete, the main thread should display:

- Final inventory summary. 

- Total number of stock updates performed. 

- Confirmation that inventory synchronization completed successfully. **(4 Marks)** 

d) Include screenshots showing:

- Source code. 

- Successful compilation. 

- Thread execution. 

- Final inventory report. **(4 Marks)** 

**Submission Requirements**

Each student must submit a single report containing:

1. **Cover Page** with unit code, unit title, student name, registration number, and date. 

2. **Source Code** for all five questions. 

3. **Screenshots** of: 

   - Source code. 

   - Successful compilation. 

   - Program execution. 

   - Terminal outputs. 

4. **Brief explanation** (150–250 words) for each question describing: 

   - The problem addressed. 

   - The synchronization mechanisms used. 

   - Challenges encountered. 

   - Lessons learned. 

5. **References** (if external resources were consulted including any assistance by Generative AI tools/platforms).

