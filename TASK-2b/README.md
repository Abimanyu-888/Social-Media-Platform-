# Assignment 2 — Task 2b

**Course:** Data Structures
**Language:** C

---

## 📘 Overview

This assignment implements two C programs that work with **binary trees** and **prime number operations**:

* **`subTask1.c`** – Builds a binary tree from level-order input and computes the **Minimum Vertex Cover** (i.e., the minimum number of phones required to cover all nodes).
* **`subTask2.c`** – Extends `subTask1.c` to perform an additional computation on **prime pairs and XOR operations**.

Both files are located in the `code/` directory.

---

## ⚙️ Project Structure

```
Assignment_2_Task_2b/
│
├── code/
│   ├── subTask1.c
│   └── subTask2.c
│
├── bin/
│   └── (auto-created executables)
│
└── Makefile
```

---

## 🧩 Features

### 🏠 subTask1.c

* Constructs a binary tree using a **level-order array** (1 = node, 0 = NULL).
* Calculates the **Minimum Vertex Cover**, interpreted as the minimum number of phones needed so that every family member (node) is either holding a phone or connected to someone who is.
* Uses a **post-order traversal** with 3 states:

  * `NOT_COVERED` = 0
  * `COVERED_BUT_NO_PHONE` = 1
  * `HAS_PHONE` = 2
* Global counter `phoneCount` tracks the minimum number of phones.

---

### 🔢 subTask2.c

* Reuses all logic from `subTask1.c`.
* After computing `N = minPhone`, it:

  * Finds the first `N` prime numbers.
  * Computes XOR for every **unique pair** of primes.
  * Counts how many XOR results fall **outside** the user-defined range `[l, r]`.

---

## 🧮 Algorithm Summary

### Part 1 — Minimum Phones

* Tree built using a static queue (BFS).
* Recursively evaluates child states:

  * If any child is `NOT_COVERED` → parent needs a phone.
  * If any child `HAS_PHONE` → parent is covered.
  * If both are `COVERED_BUT_NO_PHONE` → parent is not covered.

**Time Complexity:** O(n)

---

### Part 2 — Prime Pair XOR

* Input: number of phones (`N`) and range `[l, r]`.
* Generate first `N` primes via trial division.
* Compute XOR for all pairs `(p_i, p_j)` where `i < j`.
* Count how many results satisfy `(ans < l || ans > r)`.

**Time Complexity:** O(N²)

---

## 🧪 Sample Execution

### ▶️ Example 1 (subTask1)

**Input:**

```
Enter the length of the array
7
Enter the level-order array
1 1 1 0 0 1 0
```

**Output:**

```
MIN NO OF PHONES:2
```

---

### ▶️ Example 2 (subTask2)

**Input:**

```
Enter the length of the array
7
Enter the level-order array
1 1 1 0 0 1 0
Enter l and r values
1 4
```

**Expected Output:**

```
MIN NO OF PHONES:2
the number of pairs of phones that don’t fall under the network range:0
```

Explanation:

* `N = 2`, primes = `{2, 3}`
* `2 ^ 3 = 1`, which is **inside** [1, 4]
* → Count = 0

---

### Another Example

```
n = 9
level-order = 1 1 1 1 1 0 0 1 1
l = 5, r = 10
```

Output:

```
MIN NO OF PHONES:3
the number of pairs of phones that don’t fall under the network range:1
```

Explanation:

* `N = 3`, primes = `{2, 3, 5}`
* Pairs:

  * `2^3 = 1` (outside)
  * `2^5 = 7` (inside)
  * `3^5 = 6` (inside)
* Only one pair outside the range → `1`

---

## 🏗️ Compilation and Running

### Build all programs

```bash
make
```

### Run subTask1

```bash
make run1
```

### Run subTask2

```bash
make run2
```

### Clean executables

```bash
make clean
```

Executables are generated inside the **`bin/`** folder.

---

## ⚠️ Notes

* Level-order input must match binary tree structure: `1` for valid node, `0` for NULL.
* Input and output are text-based via the terminal.
* For `subTask2.c`, ensure proper handling when `N < 2` (no pairs → count = 0).
* Range check should use:

  ```c
  if (ans < l || ans > r)
      count++;
  ```

---

## ✅ Summary

* **subTask1.c** → Binary Tree + Minimum Vertex Cover.
* **subTask2.c** → Adds Prime Pair XOR computation.
* Fully automatable build via the provided **Makefile** using `code/` as the source directory and `bin/` for outputs.
