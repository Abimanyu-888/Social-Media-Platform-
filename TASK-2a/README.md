# 🧩 Social Media Platform ADT Implementation

## 📘 Project Overview
This project is a **C implementation** of a basic **Social Media Platform Abstract Data Type (ADT)**.  
It utilizes **linked lists** to manage a platform that supports **posts**, **comments**, and **replies**.  
The platform is operated through a **command-line interface (CLI)** that parses a defined set of commands to **add**, **delete**, **view**, and **navigate** content.

---

## ⚙️ Features Implemented

### 🏠 Platform
- Create and manage a **global platform instance**.

### 📝 Posts
- `add_post`: Add a new post.
- `delete_post`: Delete the *nᵗʰ* recent post.
- `view_post`: View the *nᵗʰ* recent post.
- Navigation using `last_viewed` pointer:
  - `current_post`: View the last viewed post.
  - `next_post`: Move to and view the older post (added before current).
  - `previous_post`: Move to and view the newer post (added after current).

### 💬 Comments
- `add_comment`: Add a comment to the currently viewed post.
- `delete_comment`: Delete the *nᵗʰ* recent comment.
- `view_comments`: View all comments for the current post.

### 🔁 Replies (Bonus)
- `add_reply`: Add a reply to the *nᵗʰ* recent comment.
- `delete_reply`: Delete the *mᵗʰ* reply from the *nᵗʰ* comment.

---

## 📂 File Structure

| File | Description |
|------|--------------|
| `main.c` | Main driver program. Parses user input and calls platform functions. |
| `platform.h / platform.c` | Defines and implements the **Platform ADT** managing the list of posts and top-level operations. |
| `post.h / post.c` | Defines and implements the **Post structure** (including comments) and helper functions. |
| `comment.h / comment.c` | Defines and implements the **Comment structure** (including replies) and helper functions. |
| `reply.h / reply.c` | Defines and implements the **Reply structure** and its helper functions. |
| `Makefile` | For compiling, running, and cleaning the project easily. |

---

## 🧱 Compilation and Execution

### 🏗️ Compile
```bash
make
